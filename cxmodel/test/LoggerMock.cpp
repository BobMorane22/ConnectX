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
 * @file LoggerMock.cpp
 * @date 2020
 *
 *************************************************************************************************/

#include "LoggerMock.h"

void LoggerMock::Log(const cxlog::VerbosityLevel p_verbosityLevel,
                     const std::string& p_fileName,
                     const std::string& p_functionName,
                     const size_t p_lineNumber,
                     const std::string& p_message)
{
    // Unused for testing...
    (void)p_verbosityLevel;
    (void)p_fileName;
    (void)p_functionName;
    (void)p_lineNumber;
    (void)p_message;
}

void LoggerMock::SetVerbosityLevel(const cxlog::VerbosityLevel p_verbosityLevel)
{
    m_verbosityLevel = p_verbosityLevel;
}

cxlog::VerbosityLevel LoggerMock::GetVerbosityLevel() const
{
    return m_verbosityLevel;
}
