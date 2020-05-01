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
 * @file MainWindowPresenterTest.cpp
 * @date 2019
 *
 *************************************************************************************************/

#include <gtest/gtest.h>

#include "MainWindowPresenterTestFixture.h"

TEST_F(MainWindowPresenterTestFixture, GetWindowTitle_GetWindowTitle_GetWindowTitleLabelReturned)
{
    ASSERT_EQ(GetPresenter().GetWindowTitle(), "Connect X");
}

TEST_F(MainWindowPresenterTestFixture, GetMenuLabel_GameMenu_GameMenuLabelReturned)
{
    ASSERT_EQ(GetPresenter().GetMenuLabel(cxgui::MenuItem::GAME), "Game");
}

TEST_F(MainWindowPresenterTestFixture, GetMenuLabel_QuitMenu_QuitMenuLabelReturned)
{
    ASSERT_EQ(GetPresenter().GetMenuLabel(cxgui::MenuItem::QUIT), "Quit");
}

TEST_F(MainWindowPresenterTestFixture, GetMenuLabel_HelpMenu_HelpMenuLabelReturned)
{
    ASSERT_EQ(GetPresenter().GetMenuLabel(cxgui::MenuItem::HELP), "Help");
}

TEST_F(MainWindowPresenterTestFixture, GetMenuLabel_AboutMenu_AboutMenuLabelReturned)
{
    ASSERT_EQ(GetPresenter().GetMenuLabel(cxgui::MenuItem::ABOUT), "About");
}

TEST_F(MainWindowPresenterTestFixture, Update_CreateNewGame_NewGameInformationupdate)
{
    auto& presenter = GetPresenter();
    auto& model = GetModel();
    presenter.Update(cxmodel::NotificationContext::CREATE_NEW_GAME, &model);

    const std::string expectedMsg{
        "A new game has been created with the following parameters: \n"
        "\n"
        "  In-a-row value : 4\n"
        "  Grid width     : 7\n"
        "  Grid height    : 6\n"
        "  Players        : \nJohn Doe, Jane Doe, "
    };

    const std::string resultMsg = presenter.GetGameViewMessage();

    ASSERT_EQ(resultMsg, expectedMsg);
}
