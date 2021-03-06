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
 * @file ConcreteObserverMock.h
 * @date 2019
 *
 *************************************************************************************************/

#ifndef CONCRETEOBSERVERMOCK_H_E0703323_22B8_40E1_8225_57CD5FDCFF45
#define CONCRETEOBSERVERMOCK_H_E0703323_22B8_40E1_8225_57CD5FDCFF45

#include <IObserver.h>

class ConcreteObserverMock : public cxmodel::IObserver
{

public:

    ConcreteObserverMock();

    int GetData() const;

    void Update(cxmodel::NotificationContext p_context, cxmodel::Subject* p_subject) override;

private:

    int m_data;

};

#endif // CONCRETEOBSERVERMOCK_H_E0703323_22B8_40E1_8225_57CD5FDCFF45
