
#include "LiftMoveStrategy.h"
#include <queue>
using namespace std;

class LiftMoveByOrder: public LiftMoveStrategy
{
    public:
        void addFloor(int) override;
        bool getNextFloor(int& floor) override;
    
    private:
        queue<int> pressQueue;
};