#include "Lift.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int Lift::getFloor()
{
    return currentFloor;
}

int Lift::getPersonOnFloor(int floor)
{
    return floorDetails[floor];
}

void Lift::setPersonsOnFloor(int floor, int person)
{
    totalPersons += person - floorDetails[floor];
    floorDetails[floor] = person;
}

void Lift::setFloor(int floor)
{
    currentFloor = floor;
    this_thread::sleep_for(std::chrono::milliseconds(1000));
    printState();
}

int Lift::getNumPersonsInLift()
{
    return totalPersons;
}

void Lift::printState()
{
    cout << "*************STATUS***********" << endl;
    cout << "Floor : " << getFloor() << endl;
    cout << "People : " << getNumPersonsInLift() << endl;
    cout << "******************************" << endl;
}