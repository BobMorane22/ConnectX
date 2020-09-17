/**************************************************************************************************
 *  This file is part of Connect X.
 *
 *  Connect X is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Connect X is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Connect X. If not, see <https://www.gnu.org/licenses/>.
 *
 *************************************************************************************************/
/**********************************************************************************************//**
 * @file GameView.cpp
 * @date 2020
 *
 *************************************************************************************************/

#include <iostream>

#include <gtkmm/window.h>

#include <cxinv/include/assertion.h>
#include <cxmodel/include/IChip.h>

#include <DiscChip.h>
#include <GameView.h>

cxgui::GameView::GameView(IGameViewPresenter& p_presenter,
                          Gtk::Grid& p_mainLayout,
                          int p_viewLeft,
                          int p_viewTop)
: m_presenter{p_presenter}
, m_mainLayout{p_mainLayout}
, m_viewLeft{p_viewLeft}
, m_viewTop{p_viewTop}
, m_activePlayerChip{std::make_unique<cxgui::DiscChip>(cxmodel::MakeTransparent(), cxmodel::MakeTransparent())}
, m_nextPlayerChip{std::make_unique<cxgui::DiscChip>(cxmodel::MakeTransparent(), cxmodel::MakeTransparent())}
, m_board{std::make_unique<cxgui::Board>(6, 7)}
{
    PRECONDITION(m_activePlayerChip != nullptr);
    PRECONDITION(m_nextPlayerChip != nullptr);

    SetLayout();
    PopulateWidgets();
    ConfigureWidgets();

    // Get a reference to the parent window:
    m_parent = dynamic_cast<Gtk::Window*>(m_mainLayout.get_parent());

    POSTCONDITION(m_parent != nullptr);
}

void cxgui::GameView::Activate()
{
    // Override default signal handler to catch keyboard events:
    if(ASSERT(m_parent))
    {
        // Remove when uninit!
        m_parent->add_events(Gdk::KEY_PRESS_MASK);
        m_parent->signal_key_press_event().connect([this](GdkEventKey* p_event){return OnKeyPressed(p_event);}, false);
    }

    auto* currentViewLayout = m_mainLayout.get_child_at(m_viewLeft, m_viewTop);

    if(!currentViewLayout)
    {
        ASSERT_ERROR_MSG("Current view should be valid.");
        return;
    }

    // Remove previous view layout:
    m_mainLayout.remove(*currentViewLayout);

    // Add new view layout:
    m_mainLayout.attach(m_viewLayout, m_viewLeft, m_viewTop, 2, 1);

    // Resize parent:
    if(ASSERT(m_parent))
    {
        // Here we use a trick: in order resize the window, we first remove the
        // main layout and add it back before calling 'show all'. This enables
        // resizing the window to smaller sizes:
        m_parent->remove();
        m_parent->add(m_mainLayout);
        m_parent->resize(m_mainLayout.get_width(), m_mainLayout.get_height());
    }
}

void cxgui::GameView::SetLayout()
{
    constexpr int TOTAL_WIDTH = 2;

    m_viewLayout.attach(m_title, 0, 0, TOTAL_WIDTH, 1);
    m_viewLayout.attach(m_message, 0, 1, TOTAL_WIDTH, 1);

    if(ASSERT(m_activePlayerChip != nullptr))
    {
        m_viewLayout.attach(*m_activePlayerChip, 0, 2, TOTAL_WIDTH, 1);
    }

    if(ASSERT(m_nextPlayerChip != nullptr))
    {
        m_viewLayout.attach(*m_nextPlayerChip, 0, 3, TOTAL_WIDTH, 1);
    }

    if(ASSERT(m_board != nullptr))
    {
        m_viewLayout.attach(*m_board, 0, 4, TOTAL_WIDTH, 1);
    }
}

void cxgui::GameView::PopulateWidgets()
{
    m_title.set_text(m_presenter.GetGameViewTitle());
    m_message.set_text(m_presenter.GetGameViewMessage());
    m_activePlayerChip->ChangeColor(m_presenter.GetActivePlayerChipColor());
    m_nextPlayerChip->ChangeColor(m_presenter.GetNextPlayerChipColor());
}

void cxgui::GameView::ConfigureWidgets()
{
    if(ASSERT(m_activePlayerChip != nullptr))
    {
        m_activePlayerChip->set_hexpand(true);
        m_activePlayerChip->set_vexpand(true);
    }

    if(ASSERT(m_nextPlayerChip != nullptr))
    {
        m_nextPlayerChip->set_hexpand(true);
        m_nextPlayerChip->set_vexpand(true);
    }
}

bool cxgui::GameView::OnKeyPressed(GdkEventKey* p_event)
{
    if(!p_event)
    {
        return true; // Do not propagate...
    }

    const auto strategy = m_keyEventStrategyFactory.Create(p_event->keyval);

    if(!strategy || !m_board)
    {
        return false;
    }

    return strategy->Handle(*m_board);
}
