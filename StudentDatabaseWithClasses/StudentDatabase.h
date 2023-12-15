#pragma once
#include <string>
#define MAXSUB 5
class AirTime {
private:
    int hour;
    int minute;
    int second;
public:
    AirTime(int h = 00, int m = 00, int s = 00);
    AirTime operator +(const AirTime&);

    void operator +=(const AirTime&);
    AirTime operator ++();
    AirTime operator ++(int);
    void setter();
    void getter();
};

struct Date
{
    int dd, mm, yy;
};
class Students
{
    int regNum{};
    std::string name;
    std::string fname;
    int marks[MAXSUB]{};
    Date dob{}, doa{};
    float cgpa{};
    AirTime At, Dt;
public:
    Students();
    void setter();
    void getter();
    bool search(int);
};

void create_database(Students ss[], int nn);
void append_record(Students ss[], int& nn);
int search_record(Students ss[], int sinfo, int nn);
int update_record(Students ss[], int sinfo, int nn);
bool delete_record(Students ss[], int sinfo, int& nn);
