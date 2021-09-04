/* Emanuel Girolami - EDI 3 - Patrón Observer */

#include "../include/DigitalClock.h"

DigitalClock::DigitalClock(ITimer* timer, IAscriber* ascriber)
{
    m_timer = timer;
    m_ascriber = ascriber;
    m_ascriber->attach(this);
}

DigitalClock::~DigitalClock()
{
    m_ascriber->detach(this);
}

void DigitalClock::update()
{
    m_hours = m_timer->getHours();
    m_minutes = m_timer->getMinutes();
    m_seconds = m_timer->getSeconds();
    draw();
}

void DigitalClock::draw()
{
    string hours = TO_STRING(m_hours);
    string minutes = TO_STRING(m_minutes);
    string seconds = TO_STRING(m_seconds);

    if(hours.size() == 1){hours = "0"+hours;}
    if(minutes.size() == 1){minutes = "0"+minutes;}
    if(seconds.size() == 1){seconds = "0"+seconds;}

    cout <<"I am Digital: "<< hours <<":"<< minutes <<":"<< seconds <<endl;
}
