/* Emanuel Girolami - EDI 3 - Patrón Observer */
 
#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

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

class AnalogClock : public IWidget, public IObserver
{
    public:
        AnalogClock(ITimer* timer, IAscriber* ascriber);
        virtual ~AnalogClock();
        void update();
        void draw();

    private:
        ITimer* m_timer;
        IAscriber* m_ascriber;
        int m_hours;
        int m_minutes;
        int m_seconds;
};

#endif // ANALOGCLOCK_H
