#include "LiftMoveByOrder.h"

void LiftMoveByOrder::addFloor(int floor)
{
    pressQueue.push(floor);
}

bool LiftMoveByOrder::getNextFloor(int& floor)
{
    bool ret = false;
    
    if (!pressQueue.empty())
    {
        floor = pressQueue.front();
        pressQueue.pop();

        ret = true;
    }
    else
    {
        floor = -1;
    }

    return ret;
}