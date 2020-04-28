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
 * @file MainWindowPresenter.cpp
 * @date 2019
 *
 *************************************************************************************************/

#include <sstream>

#include <cxmodel/include/Model.h>

#include <MainWindowPresenter.h>

void cxgui::MainWindowPresenter::Update(cxmodel::NotificationContext p_context, cxmodel::Subject* p_subject)
{
    if(p_subject)
    {
        if(p_context == cxmodel::NotificationContext::CREATE_NEW_GAME)
        {
            cxmodel::IModel* model = static_cast<cxmodel::IModel*>(p_subject);

            cxmodel::NewGameInformation gameInformation = model->GetGameInformation();

            std::ostringstream stream;

            stream << "A new game has been created with the following parameters: " << std::endl
                   << std::endl
                   << "  In-a-row value : " << gameInformation.m_inARowValue << std::endl
                   << "  Grid width     : " << gameInformation.m_gridWidth << std::endl
                   << "  Grid height    : " << gameInformation.m_gridHeight << std::endl
                   << "  Players        : " << std::endl;

            for(const auto& player : gameInformation.GetPlayersInformation())
            {
                stream << player.m_name << ", ";
            }

            m_gameViewMessage = stream.str();
        }

        Notify(p_context);
    }
}

std::string cxgui::MainWindowPresenter::GetWindowTitle() const
{
    return "Connect X";
}

std::string cxgui::MainWindowPresenter::GetMenuLabel(MenuItem p_menuItem) const
{
    return MakeLabel(p_menuItem);
}

std::string cxgui::MainWindowPresenter::GetNewGameViewTitle() const
{
    return "New Game";
}

std::string cxgui::MainWindowPresenter::GetNewGameViewGameSectionTitle() const
{
    return "Game";
}

std::string cxgui::MainWindowPresenter::GetNewGameViewInARowLabelText() const
{
    return "In a row:";
}

std::string cxgui::MainWindowPresenter::GetNewGameViewGridSectionTitle() const
{
    return "Grid";
}

std::string cxgui::MainWindowPresenter::GetNewGameViewWidthLabelText() const
{
    return "Width:";
}

std::string cxgui::MainWindowPresenter::GetNewGameViewHeightLabelText() const
{
    return "Height:";
}

std::string cxgui::MainWindowPresenter::GetNewGameViewPlayersSectionTitle() const
{
    return "Players";
}

std::string cxgui::MainWindowPresenter::GetNewGameViewNameColumnHeaderText() const
{
    return "Name";
}

std::string cxgui::MainWindowPresenter::GetNewGameViewDiscColumnHeaderText() const
{
    return "Disc";
}

std::string cxgui::MainWindowPresenter::GetNewGameViewStartButtonText() const
{
    return "Start";
}

std::string cxgui::MainWindowPresenter::GetGameViewTitle() const
{
    return "Game";
}

std::string cxgui::MainWindowPresenter::GetGameViewMessage() const
{
    return m_gameViewMessage;
}
