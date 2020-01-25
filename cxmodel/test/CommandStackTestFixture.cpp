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
 * @file CommandStackTestFixture.cpp
 * @date 2020
 *
 *************************************************************************************************/

#include <gtest/gtest.h>

#include "CommandStackTestFixture.h"

CommandStackTestFixture::CommandStackTestFixture()
 : m_STACK_SIZE{200}
 , m_stack{std::make_unique<cxmodel::CommandStack>(m_STACK_SIZE)}
{
    EXPECT_TRUE(m_stack);
    EXPECT_TRUE(m_stack->IsEmpty());
}

cxmodel::ICommandStack* CommandStackTestFixture::GetCommandStack()
{
    EXPECT_TRUE(m_stack);

    return m_stack.get();
}

size_t CommandStackTestFixture::GetCommandStackSize() const
{
    EXPECT_TRUE(m_STACK_SIZE > 1);

    return m_STACK_SIZE;
}