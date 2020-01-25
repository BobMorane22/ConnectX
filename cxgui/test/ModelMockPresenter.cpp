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
 * @file ModelMockPresenter.cpp
 * @date 2020
 *
 *************************************************************************************************/

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
 * @file ModelMockPresenter.h
 * @date 2020
 *
 *************************************************************************************************/

#include <gtest/gtest.h>

#include "ModelMockPresenter.h"

unsigned int ModelMockPresenter::GetCurrentValue() const
{
    return m_currentValue;
}

void ModelMockPresenter::Increment()
{
    ++m_currentValue;

    Notify();
}

void ModelMockPresenter::Reinitialize()
{
    m_currentValue = 0;

    Notify();
}

void ModelMockPresenter::Undo()
{
    // Nothing to do for now...
}

void ModelMockPresenter::Redo()
{
    // Nothing to do for now...
}