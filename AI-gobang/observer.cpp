#include "observer.h"

Observer::Observer():is_stop(false)
{

}
void Observer::setStop()
{
    is_stop=true;
}
void Observer::setAwake()
{
    is_stop=false;
}
bool Observer::isStop()
{
     return is_stop;
}
