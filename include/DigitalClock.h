/* Emanuel Girolami - EDI 3 - Patrón Observer */

#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <sstream>
#define TO_STRING( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

#include <iostream>
#include <string>
#include "IWidget.h"
#include "ITimer.h"
#include "IObserver.h"
#include "IAscriber.h"

using namespace std;

class DigitalClock : public IWidget, public IObserver
{
    public:
        DigitalClock(ITimer* timer, IAscriber* ascriber);
        virtual ~DigitalClock();
        void update();
        void draw();

    private:
        ITimer* m_timer;
        IAscriber* m_ascriber;
        int m_hours;
        int m_minutes;
        int m_seconds;
};

#endif // DIGITALCLOCK_H
