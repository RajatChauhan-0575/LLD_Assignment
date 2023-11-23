#include <string>
using namespace std;

class User
{
    private: 
        int age;
        std::string name;
        char gender;
    
    public:
        string getName() { return name; }

        User();
        User(std::string name, int age, char gender)
        {
            this->age = age;
            this->name = name;
            this->gender = gender;
        }
};