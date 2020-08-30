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
 * @file IGameActions.h
 * @date 2020
 *
 *************************************************************************************************/

#ifndef IGAMEACTIONS_H_49B2D12C_4951_4989_AFE9_870A3940ED8F
#define IGAMEACTIONS_H_49B2D12C_4951_4989_AFE9_870A3940ED8F

#include "NewGameInformation.h"

namespace cxmodel
{

/*********************************************************************************************//**
 * @brief Interface for Connect X user game actions.
 *
 * This interface is a collection of all actions a user can do.
 *
 ************************************************************************************************/
class IConnectXGameActions
{

public:

    /******************************************************************************************//**
     * @brief Destructor.
     *
     ********************************************************************************************/
    virtual ~IConnectXGameActions() = default;

    /******************************************************************************************//**
     * @brief Creates a new game.
     *
     * @param p_gameInformation The necessary information to create a game.
     *
     ********************************************************************************************/
    virtual void CreateNewGame(const NewGameInformation& p_gameInformation) = 0;

};

} // namespace cxmodel

#endif // IGAMEACTIONS_H_49B2D12C_4951_4989_AFE9_870A3940ED8F