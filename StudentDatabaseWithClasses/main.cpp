#include <iostream>
#include <string>
#include "StudentDatabase.h"
#define MAXSUB  5 // Five subjects
#define MaxStu 70 //Maximum Students
using namespace std;
// Students Database
// Define the structure for a date and Students

int main()
{
    Students s[MaxStu];
    int ch{}, n{}, sinfo{}, index{};
    do
    {
        cout << "\n\nStudents Database Menu:" << endl
            << "1. Create Data Base" << endl
            << "2. Append a record" << endl
            << "3. Search a record" << endl
            << "4. Delete a record" << endl
            << "5. Update a record" << endl
            << "6. Display Result" << endl
            << "7. Exit" << endl
            << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1: // Create DB
            cout << "Enter how many Studentss are [MAX. 70]: ";
            cin >> n;
            create_database(s, n);
            break;
        case 2:
            append_record(s, n);
            break;
        case 3:
            cout << "Search Record.\n**********************************************\n";
            cout << "Enter reg. number to search: ";
            cin >> sinfo;
            index = search_record(s, sinfo, n);
            if (index >= 0) {
                cout << "Record is found at index: " << index << endl;
            }
            else {
                cout << "Record is not found" << endl;
            }
            break;
        case 4: {
            bool found = false;
            cout << "Delete Record.\n**********************************************\n";
            cout << "Enter reg. number to delete: ";
            cin >> sinfo;
            found = delete_record(s, sinfo, n);
            if (found) {
                cout << "Record is deleted sucessfully" << endl;
            }
            else {
                cout << "Record is not found" << endl;
            }
            break;
        }
        case 5:
            cout << "Enter reg. number to update: ";
            cin >> sinfo;
            index = update_record(s, sinfo, n);
            if (index >= 0) {
                cout << "Record is updated at index: " << index << endl;
            }
            else {
                cout << "Record is not found" << endl;
            }
            break;
        case 6:
            cout << "Displaying Studentss result Card\n";
            for (int i = 0; i < n; i++) {
                s[i].getter();
                cout << endl;
            }
            break;
        case 7: // Exit
            cout << " ALLAH HAFIZ..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Enter again..." << endl;
        } // end of switch
    } while (true);

    return 0;
} // end of main