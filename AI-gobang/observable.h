#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <QList>
#include "observer.h"
class Observer;
class Observable
{
public:
   Observable();
   virtual void addObserver(Observer *);

   virtual void delObserver(Observer *);
   virtual void notifyObservers();
   virtual ~Observable();
private:
    std::list<Observer *> observers;
};

#endif // OBSERVABLE_H
