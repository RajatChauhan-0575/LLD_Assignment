#include <string>
#include <vector>
#include <utility>
#include "doctor.h"
#include <iostream>

using namespace std;

Doctor::Doctor()
{

}

bool Doctor::SetAvailability(vector<pair<float, float> > slts)
{
    bool ret = true;

    for (auto slot: slts)
    {
        if ((slot.second - slot.first) == 1.0)
        {
            if (slots.count(slot) == 0)
            {
                slots[slot] = true;
            }
        }
        else
        {
            ret = false;
        }
    }

    return ret;
}

void Doctor::GetAvailabilty()
{
    for(auto ele : slots)
    {
        if (ele.second)
            std::cout << name << " from: " << ele.first.first << "To: " << ele.first.second << endl;
    }
}

bool Doctor::MarkBooked(pair<float, float> slot)
{
    if (slots.count(slot) > 0)
    {
        slots[slot] = false;
        return true;
    }
    else
    {
        return false;
    }
}

bool Doctor::MarkCancelled(pair<float, float> slot)
{
    //cout << " here *** \n";
    if (slots.count(slot) > 0)
    {
        //cout << " here *** \n";
        slots[slot] = true;
        return true;
    }
    else
    {
        return false;
    }
}

