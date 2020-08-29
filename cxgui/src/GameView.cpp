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

#include <gtkmm/window.h>

#include <cxinv/include/assertion.h>

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
, m_chip{std::make_unique<cxgui::DiscChip>(cxmodel::MakeRed(), cxmodel::MakeTransparent())}
{
    PRECONDITION(m_chip != nullptr);

    SetLayout();
    PopulateWidgets();
    ConfigureWidgets();
}

void cxgui::GameView::Activate()
{
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
    Gtk::Window* window = dynamic_cast<Gtk::Window*>(m_mainLayout.get_parent());

    if(ASSERT(window))
    {
        // Here we use a trick: in order resize the window, we first remove the
        // main layout and add it back before calling 'show all'. This enables
        // resizing the window to smaller sizes:
        window->remove();
        window->add(m_mainLayout);
        window->resize(m_mainLayout.get_width(), m_mainLayout.get_height());
    }
}

void cxgui::GameView::SetLayout()
{
    constexpr int TOTAL_WIDTH = 2;

    m_viewLayout.attach(m_title, 0, 0, TOTAL_WIDTH, 1);
    m_viewLayout.attach(m_message, 0, 1, TOTAL_WIDTH, 1);

    if(ASSERT(m_chip != nullptr))
    {
        m_viewLayout.attach(*m_chip, 0, 2, TOTAL_WIDTH, 1);
    }
}

void cxgui::GameView::PopulateWidgets()
{
    m_title.set_text(m_presenter.GetGameViewTitle());
    m_message.set_text(m_presenter.GetGameViewMessage());
}

void cxgui::GameView::ConfigureWidgets()
{
    if(ASSERT(m_chip != nullptr))
    {
        m_chip->set_hexpand(true);
        m_chip->set_vexpand(true);
    }
}
