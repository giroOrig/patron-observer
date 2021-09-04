/* Emanuel Girolami - EDI 3 - Patrón Observer */

#ifndef IASCRIBER_H
#define IASCRIBER_H

#include "IObserver.h"

class IAscriber
{
    public:
            virtual  ~IAscriber(){};
            virtual void attach( IObserver* observer) = 0;
            virtual void detach( IObserver* observer) = 0;
};

#endif // IASCRIBER_H
