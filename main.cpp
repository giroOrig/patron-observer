/* Emanuel Girolami - EDI 3 - Patrón Observer */

#include <iostream>

#include "include/ITimer.h"
#include "include/IAscriber.h"
#include "include/INotifier.h"
#include "include/IWidget.h"
#include "include/Timer.h"
#include "include/ChangeManager.h"
#include "include/AnalogClock.h"
#include "include/DigitalClock.h"

using namespace std;

int main()
{
    INotifier* notifier = ChangeManager::getInstance();

    ITimer* timer = new Timer(notifier);

    timer->start();

    IAscriber* ascriber = ChangeManager::getInstance();

    IWidget* analogClock = new AnalogClock(timer, ascriber);
    IWidget* digitalClock = new DigitalClock(timer, ascriber);

    delete timer;
    delete analogClock;
    delete digitalClock;

    return 0;
}
