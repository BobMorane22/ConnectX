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
 * @file IMainWindowController.h
 * @date 2019
 *
 *************************************************************************************************/

#ifndef IMAINWINDOWCONTROLLER_H_B4A715D5_611A_42C2_8C60_16C5C14FD28A
#define IMAINWINDOWCONTROLLER_H_B4A715D5_611A_42C2_8C60_16C5C14FD28A

#include "INewGameViewController.h"

namespace cxgui
{

/*********************************************************************************************//**
 * @brief Interface for creating a main window controller.
 *
 * The main window controller is responsible to handle all user events directed on the main
 * window. It is the controller which calls the right operations sequence on the model to
 * reflect what the user is doing on the UI.
 *
 ************************************************************************************************/
class IMainWindowController : public INewGameViewController
{

public:

    /******************************************************************************************//**
     * @brief Default destructor.
     *
     ********************************************************************************************/
    virtual ~IMainWindowController() = default;

///@{ @name Main Window
// ------------------------------------------------------------------------------------------------

    /******************************************************************************************//**
     * @brief Reacts to changes on the "About" menu item.
     *
     ********************************************************************************************/
    virtual void OnAboutMenuPressed() = 0;

///@}

///@{ @name New Game View
// ------------------------------------------------------------------------------------------------

    /******************************************************************************************//**
     * @brief Reacts to a game start.
     *
     * @param p_gameInformation the game information the user input.
     *
     * Reacts to a user creating and starting a new game.
     *
     ********************************************************************************************/
    void OnStart(const cxmodel::GameInformation p_gameInformation) override = 0;

///@}

};

} // namespace cxgui

#endif // IMAINWINDOWCONTROLLER_H_B4A715D5_611A_42C2_8C60_16C5C14FD28A
