/* Emanuel Girolami - EDI 3 - Patrón Observer */

#ifndef CHANGEMANAGER_H
#define CHANGEMANAGER_H

#include "IAscriber.h"
#include "INotifier.h"
#include "IObserver.h"
#include <list>

using namespace std;

class ChangeManager : public IAscriber, public INotifier
{

    public:
        static ChangeManager* getInstance();
        virtual ~ChangeManager();

        void attach(IObserver* observer);

        void detach(IObserver* observer);

        void notify( void );

    protected:
        ChangeManager(void);

    private:
        static ChangeManager* m_instance;
        list<IObserver*> m_observersList;
};

#endif // CHANGEMANAGER_H
