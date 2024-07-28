
#include "LiftMoveStrategy.h"
#include <queue>
using namespace std;

class LiftMoveBySortedFloor: public LiftMoveStrategy
{
    public:
        void addFloor(int) override;
        bool getNextFloor(int& floor) override;
    
    private:
        priority_queue<int, vector<int>, greater<int> > pq;
};