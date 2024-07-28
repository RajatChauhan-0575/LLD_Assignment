#include <vector>
using namespace std;

class Lift
{
    public: 
        Lift(int floors, int maxPerson)
        {
            totalFloors = floors;
            this->maxPerson = maxPerson;
            floorDetails.resize(totalFloors, 0);
        }

        ~Lift()
        {

        }

        int getFloor();
        void setFloor(int);
        int getPersonOnFloor(int);
        void setPersonsOnFloor(int, int);
        bool isMaxCapacityReached() { return totalPersons >= maxPerson; };
        void printState();
        int getNumPersonsInLift();
    
    private:
        int totalFloors = 0;
        int currentFloor = 0;
        int maxPerson = 0;
        int totalPersons = 0;
        vector<int> floorDetails;
};