#pragma once
#include "Lift.h"
#include "../Strategies/StrategyTypes.h"
#include "../Strategies/LiftMoveStrategy.h"
#include <queue>

class LiftController
{
    public:

        LiftController(Lift* lft, const Strategy strategyType);
        ~LiftController() 
        {
            delete strategy;
        }

        void pressKey(int floor, int persons);
        bool moveLift();

    private:
        Lift* lift;
        LiftMoveStrategy* strategy = nullptr;
};