#include <string>
#include <vector>
#include <utility>
#include <map>
#include "AppointmentService.h"
#include "../Helper/BookingIDGenerator.h"
#include <iostream>

using namespace std;

bool AppointmentService::RegisterUser(User user)
{
    registeredUsers[user.getName()] = user;

    cout << "Welcome" << user.getName() << "!!" << endl;
}

bool AppointmentService::ResisterDoctor(Doctor doctor)
{
    registerDoctors[doctor.getName()] = doctor;
}

void AppointmentService::MarkDoctorAvail(string name, vector<pair<float, float> > slots)
{
    if (registerDoctors[name].SetAvailability(slots))
    {
        cout << "Done Doc!" << endl;
    }
    else
    {
        cout << "Sorry! Doctor " << name << "slots are 1 hr only" << endl;
    }
}

int AppointmentService::BookAppointment(string user, string doctor, int time)
{
    int id =  BookingIDGenerator();
    Appointment ap(id, time, user, doctor);

    bookings[id] = ap;
    idToUser[user].push_back(id);

    registerDoctors[doctor].MarkBooked(make_pair(time, time + 1));
    return id;
}

bool AppointmentService::CancelBooking(int id)
{
    int time = bookings[id].getTime();
    //cout << time << "*****/n";
    registerDoctors[bookings[id].getDoctorName()].MarkCancelled(make_pair(time, time + 1));
    bookings[id].Cancel();
    return true;
}

void AppointmentService::ShowAvailability()
{
    for(auto doctor: registerDoctors)
    {
        doctor.second.GetAvailabilty();
    }
}

void AppointmentService::ShowActiveAppointmentByPatient(string name)
{
    for(auto id : idToUser[name])
    {
        if (!bookings[id].isCancelled())
        cout << bookings[id].getDoctorName() << " : " << bookings[id].getTime() << endl;
    }
}