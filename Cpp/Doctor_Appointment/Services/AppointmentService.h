#include <string>
#include <vector>
#include <utility>
#include <map>
#include "../Entities/Appointment.h"
#include "../Entities/Doctor.h"
#include "../Entities/User.h"

using namespace std;

class AppointmentService
{
    public:
        bool RegisterUser(User user);
        bool ResisterDoctor(Doctor doctor);
        void MarkDoctorAvail(string name, vector< pair<float, float> > slots);
        int  BookAppointment(string user, string doctor, int time);
        bool CancelBooking(int id);
        void ShowAvailability();
        void ShowActiveAppointmentByPatient(string name);

    private:
        map<string, User> registeredUsers;
        map<string, Doctor> registerDoctors;
        map<int, Appointment> bookings;
        map<string, vector<int> > idToUser;
};