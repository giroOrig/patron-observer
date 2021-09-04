/* Emanuel Girolami - EDI 3 - Patrón Observer */

#include "../include/Timer.h"

Timer::Timer(INotifier* notifier)
{
    m_notifier = notifier;
}

Timer::~Timer()
{
    do
    {
        m_tick();
        m_delay(1000);

        #ifdef __unix__
            system("clear");
        #elif defined(_WIN32) || defined(WIN32)
            system("cls");
        #endif // defined
    }
    while(m_startState);
}


void Timer::m_delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}


int Timer::getHours()
{
    return m_hours;
}

int Timer::getMinutes()
{
    return m_minutes;
}

int Timer::getSeconds()
{
    return m_seconds;
}

void Timer::start()
{
    m_startState = true;
}

void Timer::stop()
{
    m_startState = false;
}

void Timer::m_tick()
{
    time_t timer;
    struct tm * timeinfo;
    time ( &timer );
    timeinfo = localtime ( &timer );

    m_seconds = timeinfo->tm_sec;
    m_minutes = timeinfo->tm_min;
    m_hours = timeinfo->tm_hour;

    mktime ( timeinfo );

    m_notifier->notify();
}

