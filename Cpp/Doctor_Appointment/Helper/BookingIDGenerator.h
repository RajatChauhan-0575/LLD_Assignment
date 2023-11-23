#include <string>
#include <vector>
#include <utility>
#include <map>

using namespace std;

int BookingIDGenerator()
{
    static int id = 1;
    return id++;
}