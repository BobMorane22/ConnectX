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
 * @file ModelMockController.h
 * @date 2019
 *
 *************************************************************************************************/

#ifndef MODELMOCKCONTROLLER_H_A4A9F6D9_7463_47D5_A25A_00880ACB678C
#define MODELMOCKCONTROLLER_H_A4A9F6D9_7463_47D5_A25A_00880ACB678C

#include <cxmodel/include/IModel.h>

class ModelMockController : public cxmodel::IModel
{

public:

    ModelMockController();

    // IModel
    std::string GetName() const override;
    std::string GetVersionNumber() const override;

    void CreateNewGame(const cxmodel::NewGameInformation& p_gameInformation) override;
    cxmodel::NewGameInformation GetGameInformation() const override;

    virtual void Undo() override;
    virtual void Redo() override;

    virtual void Signal() override;


    // Mock helpers
    bool GetIncremented() const;
    bool GetReinitialized() const;
    bool GetUndoed() const;
    bool GetRedoed() const;
    bool GetSignaled() const;


private:

    bool m_undoed;
    bool m_redoed;
    bool m_signaled;

};

#endif // MODELMOCK_H_A4A9F6D9_7463_47D5_A25A_00880ACB678C
