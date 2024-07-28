#pragma once
#include "LiftController.h"
#include "../Strategies/LiftMoveByOrder.h"
#include "../Strategies/LiftMoveBySortedFloor.h"
#include <iostream>

LiftController::LiftController(Lift* lft, const Strategy strategyType): lift(lft)
{
    if (strategyType == Strategy::MOVE_BY_ORDER)
    {
        strategy = new LiftMoveByOrder();
    }
    else if (strategyType == Strategy::MOVE_BY_SORTED_FLOOR)
    {
        strategy = new LiftMoveBySortedFloor();
    }
}

void LiftController::pressKey(int floor, int persons)
{
    strategy->addFloor(floor);
    lift->setPersonsOnFloor(floor, persons);
}

bool LiftController::moveLift()
{
    bool ret = false;

    while (true)
    {
        int floor = -1;
        bool retVal = strategy->getNextFloor(floor);

        if (retVal && !lift->isMaxCapacityReached())
        {
            lift->setFloor(floor);
            lift->setPersonsOnFloor(floor, 0);
        }
        else
        {
            if (lift->isMaxCapacityReached())
            {
                cout << "Maximum capacity reached ..." << endl;
            }   
            
            break;
        }
    }
}