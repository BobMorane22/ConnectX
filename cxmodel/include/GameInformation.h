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
 * @file GameInformation.h
 * @date 2020
 *
 *************************************************************************************************/

#ifndef GAMEINFORMATION_H_BE24FB43_1A63_4A5D_BA34_DA52C92DFB4A
#define GAMEINFORMATION_H_BE24FB43_1A63_4A5D_BA34_DA52C92DFB4A

#include <string>
#include <vector>

namespace cxmodel
{

struct PlayerInformation
{

    PlayerInformation(const std::string& p_name, const std::string& p_discColor)
    : m_name(p_name)
    , m_discColor(p_discColor)
    {
        // Nothing to do...
    }

    std::string m_name;
    std::string m_discColor;
};

class GameInformation
{

public:

    using PlayersInformation = std::vector<PlayerInformation>;

    std::size_t AddPlayer(const PlayerInformation& p_playerInformation)
    {
        m_playersInformation.push_back(p_playerInformation);

        return m_playersInformation.size();
    }

    PlayersInformation GetPlayersInformation() const
    {
        return m_playersInformation;
    }

public:

    size_t m_gridWidth;
    size_t m_gridHeight;
    size_t m_inARowValue;

private:

    PlayersInformation m_playersInformation;
};

} // namespace cxmodel

#endif // GAMEINFORMATION_H_BE24FB43_1A63_4A5D_BA34_DA52C92DFB4A
