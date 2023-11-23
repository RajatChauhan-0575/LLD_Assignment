#include <string>
#include <vector>
#include <utility>
#include <map>

using namespace std;

class Appointment
{
    public:
        enum Status
        {
            BOOKED,
            CANCELLED
        };

        Appointment();
        Appointment(int id, int time, string user, string doctor)
        {
            this->id = id;
            this->time = time;
            this->user = user;
            this->doctor = doctor;
        }

        void Cancel() { status = CANCELLED; }

        string getDoctorName() { return doctor; }
        string getUserName() { return user; }
        int getTime() { return time; }
        bool isCancelled() { return (status == CANCELLED) ? true : false; }

    private:
        int id;
        int time;
        Status status = Status::BOOKED;
        string user;
        string doctor;
};