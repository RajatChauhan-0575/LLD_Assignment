#include "LiftMoveBySortedFloor.h"

void LiftMoveBySortedFloor::addFloor(int floor)
{
    pq.push(floor);
}

bool LiftMoveBySortedFloor::getNextFloor(int& floor)
{
    bool ret = false;
    
    if (!pq.empty())
    {
        floor = pq.top();
        pq.pop();

        ret = true;
    }
    else
    {
        floor = -1;
    }

    return ret;
}