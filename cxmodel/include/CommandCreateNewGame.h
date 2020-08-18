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
 * @file CommandCreateNewGame.h
 * @date 2020
 *
 *************************************************************************************************/

#ifndef COMMANDCREATENEWGAME_H_42E0AF3C_C0D0_44F7_B472_9F2E0E11216D
#define COMMANDCREATENEWGAME_H_42E0AF3C_C0D0_44F7_B472_9F2E0E11216D

#include <vector>

#include <cxlog/include/ILogger.h>

#include "ICommand.h"
#include "NewGameInformation.h"
#include "Player.h"
#include "Subject.h"

namespace cxmodel
{

class CommandCreateNewGame : public ICommand
{

public:

    CommandCreateNewGame(std::vector<Player>& p_players,
                         size_t& p_gridWidth,
                         size_t& p_gridHeight,
                         size_t& p_inARowValue,
                         NewGameInformation p_newGameInformation);

    virtual void Execute() override;
    virtual void Undo() override;

private:

    std::vector<Player>& m_modelPlayers;
    size_t& m_modelGridWidth;
    size_t& m_modelGridHeight;
    size_t& m_modelInARowValue;

    NewGameInformation m_newGameInformation;

};

} // namespace cxmodel

#endif // COMMANDCREATENEWGAME_H_42E0AF3C_C0D0_44F7_B472_9F2E0E11216D
