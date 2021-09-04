/* Emanuel Girolami - EDI 3 - Patrón Observer */

#ifndef IOBSERVER_H
#define IOBSERVER_H

class IObserver
{
    public:
            virtual ~IObserver(){};
            virtual void update() = 0;
};

#endif // IOBSERVER_H
