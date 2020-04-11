#include "observable.h"

Observable::Observable()
{

}
void Observable::addObserver(Observer *ob)
{
    observers.push_back(ob);
}
void Observable::delObserver(Observer *ob)
{
    for(auto it=observers.begin();it!=observers.end();)
    {
            if(*it==ob)
                it=observers.erase(it);
            else
                ++it;
    }
}
void Observable::notifyObservers()
{
    for(auto it=observers.begin();it!=observers.end();++it)
    {
        Observer * ob =*it;
        if(! ob->isStop())
            ob->receiveMessage(this);
    }
}
Observable::~Observable()
{

}
