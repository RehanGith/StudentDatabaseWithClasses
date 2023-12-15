#include <iostream>
#include "StudentDatabase.h"

using namespace std;
// Function definitions
Students::Students() {
    regNum = 0;
    name = ' ';
    fname = ' ';
    for (int i = 0; i < MAXSUB; i++) {
        marks[i] = 0;
    }
    dob.dd = 0;
    dob.mm = 0;
    dob.yy = 0;
    doa.dd = 0;
    doa.mm = 0;
    doa.yy = 0;
    cgpa = 0;
}
void Students::setter() {

    cout << "Enter Students reg number: ";
    cin >> regNum;
    cout << "Enter Students name: ";
    cin >> name;
    cin.ignore(30, '\n');
    cout << "Enter Students father name: ";
    cin >> fname;
    cin.ignore(30, '\n');
    cout << "Enter marks (out of 100):" << endl;
    for (int j = 0; j < MAXSUB; j++)
    {
        cout << "Marks in Subject " << j + 1 << ": ";
        cin >> marks[j];
    } // end of for - j
    cout << "Enter Date of Birth: " << endl;
    cout << "Enter Day: ";
    cin >> dob.dd;
    cout << "Enter Month: ";
    cin >> dob.mm;
    cout << "Enter Year: ";
    cin >> dob.yy;

    cout << "Enter Date of Admission: " << endl;
    cout << "Enter Day: ";
    cin >> doa.dd;
    cout << "Enter Month: ";
    cin >> doa.mm;
    cout << "Enter Year: ";
    cin >> doa.yy;

    cout << "Enter CGPA: ";
    cin >> cgpa;
    cout << "\nEnter Arrival Time of Student: " <<  endl;
    At.setter();
    cout << "\nEnter Depearture Time of Student: " << endl;
    Dt.setter();
}
void Students::getter() {
    cout << "Arivial Time:" << endl;
    At.getter();
    cout << "Deperature time:" << endl;
    Dt.getter();
    cout << "Result Card for Students: " << regNum << endl;
    cout << "-----------------------------------------------------\n";
    cout << "| Name:  " << name << " " << regNum << endl;
    cout << "| Father Name: " << fname << endl;
    cout << endl;

    cout << "| Subject          " << "|  Marks  " << endl;
    int sum{};
    for (int j{ 0 }; j < MAXSUB; j++) {
        cout << "| Subject" << j + 1 << "         " << "|  " << marks[j] << endl;
        sum += marks[j];
    }
    cout << "======================================================\n";
    cout << "|  Total Marks:            " << "|  " << sum << endl;
    cout << "| CGPA:            " << "|  " << cgpa << endl;

}
bool Students::search(int sinfo) {
    if (sinfo == regNum) {
        return true;
    }
    return false;
}


AirTime::AirTime(int h, int m, int s) : hour(h), minute(m), second(s) {

}
AirTime AirTime::operator + (const AirTime& TT) {
    int h = hour + TT.hour;
    if (h > 24)
        h = h - 24;
    int m = minute + TT.minute;
    if (m >= 60) {
        m -= 60;
        h++;
    }
    int s = second + TT.second;
    if (s >= 60) {
        s -= 60;
        m++;
    }
    return AirTime(h, m, s);
}
void AirTime::operator +=(const AirTime& TT) {
    hour += TT.hour;
    if (hour > 24)
        hour = hour - 24;
    minute += TT.minute;
    if (minute >= 60) {
        minute -= 60;
        hour++;
    }
    second += TT.second;
    if (second >= 60) {
        second -= 60;
        minute++;
    }
}
AirTime AirTime::operator++() {
    hour++;
    if (hour > 24)
        hour = hour - 24;
    minute++;
    if (minute >= 60) {
        minute -= 60;
        hour++;
    }
    second++;
    if (second >= 60) {
        second -= 60;
        minute++;
    }
    return *this;
}
AirTime AirTime::operator ++(int) {
    AirTime temp = *this;
    hour++;
    if (hour > 24)
        hour = hour - 24;
    minute++;
    if (minute >= 60) {
        minute -= 60;
        hour++;
    }
    second++;
    if (second >= 60) {
        second -= 60;
        minute++;
    }
    return temp;
}
void AirTime::setter() {
    while (true) {
        cout << "Enter hour: ";
        cin >> hour;
        if (hour < 7 && hour > 20) {
            cout << "University Hour should be [7,20]. Please correct it" << endl;
            continue;
        }
        cout << "Enter minute: ";
        cin >> minute;
        if (minute > 60) {
            cout << "Please provide correct minutes. Provide again" << endl;
            continue;
        }
        cout << "Enter second: ";
        cin >> second;
        if (second > 60) {
            cout << "Please Provid correct second. Provide again" << endl;
            continue;
        }
        break;
    }
}
void AirTime::getter() {
    cout << hour << " : " << minute << " : " << second << endl;
}

void create_database(Students ss[], int nn) {
    for (int i = 0; i < nn; i++) {
        cout << "Create Record for Students no: " << i + 1 << endl;
        cout << endl;
        ss[i].setter();
        cout << "\nSucessfully Created Student Record.\n";

    }
}
void append_record(Students ss[], int& nn) {
    if (!nn) {
        cout << "Database have not created yet.\n";
        return;
    }
    cout << "Append Record.\n**********************************************\n";
    ss[nn].setter();
    nn++;
    cout << "Record Added Sucessfully." << endl;
}

int search_record(Students ss[], int sinfo, int nn) {
    if (!nn) {
        cout << "Database have not created yet.\n";
        return -1;
    }
    bool index = false;
    for (int i = 0; i < nn; i++) {
        index = ss[i].search(sinfo);
        if (index == true) {
            return i + 1;
        }
    }
    return -1;
}
int update_record(Students ss[], int sinfo, int nn) {
    if (!nn) {
        cout << "Database have not created yet.\n";
        return -1;
    }
    bool index = false;
    for (int i = 0; i < nn; i++) {
        index = ss[i].search(sinfo);
        if (index == true) {
            ss[i].setter();
            return i + 1;
        }
    }
    return -1;
}
bool delete_record(Students ss[], int sinfo, int& nn) {
    if (!nn) {
        cout << "Database have not created yet.\n";
        return false;
    }
    for (int i = 0; i < nn; i++) {
        if (ss[i].search(sinfo)) {
            for (int j = i; j < nn; j++) {
                ss[i] = ss[j + 1];
                i++;
            }
            --nn;
            return true;
        }
    }
    return false;
}