/* Emanuel Girolami - EDI 3 - Patrón Observer */

#ifndef TIMER_H
#define TIMER_H

#ifdef __unix__
    #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif // defined

#include <ctime>

#include <iostream>
#include "ITimer.h"
#include "INotifier.h"

using namespace std;

class Timer : public ITimer
{
    public:
        Timer(INotifier* notifier);
        virtual ~Timer();

        int getHours();
        int getMinutes();
        int getSeconds();

        void start();
        void stop();

    private:
        bool m_startState;
        void m_delay(int milliseconds);
        int m_hours;
        int m_minutes;
        int m_seconds;
        void m_tick();


        INotifier* m_notifier;

};

#endif // TIMER_H
