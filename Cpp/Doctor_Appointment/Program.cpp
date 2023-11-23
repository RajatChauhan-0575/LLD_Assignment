#include <iostream>
#include "Services/AppointmentService.h"

using namespace std;

int main()
{
    AppointmentService service;

    // T1
    Doctor d("Curious");
    service.ResisterDoctor(d);

    //T2
    vector<pair<float, float> > s;
    s.push_back(make_pair(9.0, 9.5));
    service.MarkDoctorAvail("Curious", s);

    //T3
    vector<pair<float, float> > s1;
    s1.push_back(make_pair(9.0, 10.0));
    s1.push_back(make_pair(12.0, 13.0));
    s1.push_back(make_pair(16.0, 17.0));
    service.MarkDoctorAvail("Curious", s1);

    //T4
    Doctor d2("Dreadfull");
    service.ResisterDoctor(d2);

    //T5
    vector<pair<float, float> > s2;
    s2.push_back(make_pair(11.0, 12.0));
    service.MarkDoctorAvail("Dreadfull", s2);

    //T6
    service.ShowAvailability();

    //T7
    User u("PatientA", 20, 'M');
    service.RegisterUser(u);
    int id = service.BookAppointment("PatientA", "Curious", 12.0);
    cout << "Booked, booking id : " << id << endl;

    //T8
    service.ShowAvailability();

    //T9
    if (service.CancelBooking(id))
    {
        cout << "Booking Cancelled! \n";
    }

    //T10
    service.ShowAvailability();

    //T11
    User u2("PatientB", 30, 'M');
    service.RegisterUser(u2);
    int id2 = service.BookAppointment("PatientB", "Curious", 12.0);
    cout << "Booked, booking id : " << id2 << endl;

    //T12
    cout << "PatientA \n";
    service.ShowActiveAppointmentByPatient("PatientA");

    //T13
    cout << "PatientB \n";
    service.ShowActiveAppointmentByPatient("PatientB");

    return 0;
}