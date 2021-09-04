/* Emanuel Girolami - EDI 3 - Patrón Observer */

#include "../include/ChangeManager.h"

ChangeManager* ChangeManager::m_instance = 0;

ChangeManager::ChangeManager()
{
    //ctor
}

ChangeManager::~ChangeManager()
{
    //dtor
}

ChangeManager* ChangeManager::getInstance()
{
    if(m_instance == 0)
    {
        m_instance = new ChangeManager();
    }
    return m_instance;
}

void ChangeManager::attach(IObserver* observer)
{
    m_observersList.push_front(observer);
}

void ChangeManager::detach(IObserver* observer)
{
    m_observersList.remove(observer);
}

void ChangeManager::notify( void )
{
    list<IObserver*>::iterator it;

    for (it =  m_observersList.begin() ; it !=  m_observersList.end(); ++it)
    {
       (*it)->update();
    }
}
