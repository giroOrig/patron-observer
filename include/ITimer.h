/* Emanuel Girolami - EDI 3 - Patrón Observer */

#ifndef ITIMER_H
#define ITIMER_H

class ITimer
{
    public:
        virtual ~ITimer() {}

        virtual int getHours() = 0;
        virtual int getMinutes() = 0;
        virtual int getSeconds() = 0;

        virtual void start() = 0;
        virtual void stop() = 0;

};

#endif // ITIMER_H
