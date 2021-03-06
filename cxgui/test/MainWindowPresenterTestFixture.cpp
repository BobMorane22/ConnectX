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
 * @file MainWindowPresenterTestFixture.cpp
 * @date 2019
 *
 *************************************************************************************************/

#include <gtest/gtest.h>

#include <cxgui/include/MainWindowPresenter.h>

#include "MainWindowPresenterTestFixture.h"

MainWindowPresenterTestFixture::MainWindowPresenterTestFixture()
{
    m_model = std::make_unique<MainWindowPresenterModelMock>();
    EXPECT_TRUE(m_model);

    m_presenter = std::make_unique<cxgui::MainWindowPresenter>(*m_model, *m_model, *m_model);
    EXPECT_TRUE(m_presenter);

    m_model->Attach(m_presenter.get());
}

void MainWindowPresenterTestFixture::SendNotification(cxmodel::NotificationContext p_context)
{
    EXPECT_TRUE(m_model);
    m_model->SendNotification(p_context);
}

cxgui::IMainWindowPresenter& MainWindowPresenterTestFixture::GetPresenter()
{
    EXPECT_TRUE(m_presenter);

    return *m_presenter;
}

cxgui::IGameViewPresenter& MainWindowPresenterTestFixture::GetGameViewPresenter()
{
    EXPECT_TRUE(m_presenter);

    return *m_presenter;
}

cxgui::INewGameViewPresenter& MainWindowPresenterTestFixture::GetNewGameViewPresenter()
{
    EXPECT_TRUE(m_presenter);

    return *m_presenter;
}

cxmodel::IConnectXGameActions& MainWindowPresenterTestFixture::GetActionsModel()
{
    EXPECT_TRUE(m_model);

    return *m_model;
}

cxmodel::IConnectXGameInformation& MainWindowPresenterTestFixture::GetGameInformationModel()
{
    EXPECT_TRUE(m_model);

    return *m_model;
}

cxmodel::IConnectXLimits& MainWindowPresenterTestFixture::GetLimitsModel()
{
    EXPECT_TRUE(m_model);

    return *m_model;
}

void MainWindowPresenterTestFixture::MainWindowPresenterModelMock::SendNotification(cxmodel::NotificationContext p_context)
{
    Notify(p_context);
}

void MainWindowPresenterTestFixture::MainWindowPresenterModelMock::CreateNewGame(const cxmodel::NewGameInformation& p_gameInformation)
{
    (void)p_gameInformation;

    // Here we only notify and let the presenter feed from the hardcoded
    // model mock values. The values in themselves are not important.
    Notify(cxmodel::NotificationContext::CREATE_NEW_GAME);
}

void MainWindowPresenterTestFixture::MainWindowPresenterModelMock::DropChip(const cxmodel::IChip& /*p_chip*/, size_t p_column)
{
    ASSERT_TRUE(p_column < GetCurrentGridWidth());

    Notify(cxmodel::NotificationContext::CHIP_DROPPED);
}

const cxmodel::IChip& MainWindowPresenterTestFixture::MainWindowPresenterModelMock::GetChip(size_t p_row, size_t p_column) const
{
    EXPECT_TRUE(p_row < GetCurrentGridHeight());
    EXPECT_TRUE(p_column < GetCurrentGridWidth());

    return m_ACTIVE_PLAYER.GetChip();
}

void MainWindowPresenterTestFixture::MainWindowPresenterModelMock::EndCurrentGame()
{
    Notify(cxmodel::NotificationContext::GAME_ENDED);
}

void MainWindowPresenterTestFixture::MainWindowPresenterModelMock::ReinitializeCurrentGame()
{
    // Here we only notify and let the presenter feed from the hardcoded
    // model mock values. The values in themselves are not important.
    Notify(cxmodel::NotificationContext::GAME_REINITIALIZED);
}

