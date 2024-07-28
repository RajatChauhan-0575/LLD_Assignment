#include "Entities/LiftController.h"

int main()
{
    int numFloors = 10;
    int maxCap = 16;

    Lift* pLift = new Lift(numFloors, maxCap);
    LiftController* pController = new LiftController(pLift, Strategy::MOVE_BY_SORTED_FLOOR);
    //LiftController* pController = new LiftController(pLift, Strategy::MOVE_BY_ORDER);
    pLift->printState();

    // T1
    pController->pressKey(6, 2);
    pController->pressKey(1, 5);
    pController->pressKey(2, 3);
    pController->moveLift();
    pLift->printState();

    // T2
    pController->pressKey(8, 2);
    pController->pressKey(2, 13);
    pController->pressKey(1, 1);
    pController->moveLift();
    pLift->printState();


    return 0;
}