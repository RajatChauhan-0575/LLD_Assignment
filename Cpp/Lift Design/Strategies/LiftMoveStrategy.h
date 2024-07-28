
#pragma once
class LiftMoveStrategy
{
    public:
        virtual void addFloor(int floor) = 0;
        virtual bool getNextFloor(int& floor) = 0;
};