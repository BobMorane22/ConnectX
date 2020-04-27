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
 * @file ModelMock.h
 * @date 2019
 *
 *************************************************************************************************/

#ifndef MODELMOCK_H_CCCA3271_7466_48B8_B57F_5D37825DFECE
#define MODELMOCK_H_CCCA3271_7466_48B8_B57F_5D37825DFECE

#include <cxmodel/include/IModel.h>

class ModelMock : public cxmodel::IModel
{

public:

    void CreateNewGame(const cxmodel::GameInformation& p_gameInformation) override;
    cxmodel::GameInformation GetGameInformation() const override;

    std::string GetName() const override;
    std::string GetVersionNumber() const override;

    void Undo() override;
    void Redo() override;

    void Signal() override;
};

#endif // MODELMOCK_H_CCCA3271_7466_48B8_B57F_5D37825DFECE
