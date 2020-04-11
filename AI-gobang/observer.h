#ifndef OBSERVER_H
#define OBSERVER_H
#include "observable.h"
class Observable;
class Observer
{
public:
   Observer();
   virtual void receiveMessage(Observable *)=0;
   virtual void setStop();
   virtual void setAwake();
   virtual bool isStop();
 private:
    bool is_stop;
};

#endif // OBSERVER_H
