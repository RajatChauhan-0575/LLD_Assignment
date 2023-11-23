#include <string>
#include <vector>
#include <utility>
#include <map>

using namespace std;
class Doctor
{
    private:
        std::string name;
        map<pair<float, float>, bool> slots;
    
    public:
        string getName() { return name; }

        Doctor();
        Doctor(string name, vector< pair<float, float> > slots)
        {
            this->name = name;
            SetAvailability(slots);
        }

        Doctor(string name)
        {
            this->name = name;
        }

        bool SetAvailability(vector< pair<float, float> > slts);
        void GetAvailabilty();
        bool MarkBooked(pair<float, float> slot);
        bool MarkCancelled(pair<float, float> slot);
};