#include <iostream>
#include <string>
using namespace std;
int main() {
    string Enter;
    string grade;
    char keepGoing = 'x';
    int creditamount;
    int classtotal = 0;
    double gradepoint;
    double allPoints = 0;
    double allcredits = 0;
    double gpa;
    double roundedgpa;
    bool validgrade;

    cout << "Welcome to GPA Calculator" << endl;
    cout << "This program will calculate your cumulative GPA." << endl;
    cout << "Enter your credit amount and letter grade together, no spaces." << endl;

    while (keepGoing == 'x' || keepGoing == 'X') {
        cout << endl;
        cout << "Input";
        cin >> Enter;

        
        creditamount = Enter[0] - '0';
        grade = Enter.substr(1);

        validgrade = true;
        gradepoint = 0.0;

        switch (grade[0]) {
            case 'A':
            case 'a':
                if (grade == "A" || grade == "a" || grade == "A+" || grade == "a+") {
                    gradepoint = 4.0;
                } else if (grade == "A-" || grade == "a-") {
                    gradepoint = 3.7;
                } else {
                    validgrade = false;
                }
                break;
            
            case 'B':
            case 'b':
                if (grade == "B+" || grade == "b+") {
                    gradepoint = 3.3;
                }
                else if (grade == "B" || grade == "b") {
                    gradepoint = 3.0;
                }
                else if (grade == "B-" || grade == "b-") {
                    gradepoint = 2.7;
                }
                else {
                    validgrade = false;
                }
                break;

            case 'C':
            case 'c':
                if (grade == "C+" || grade == "c+") {
                    gradepoint = 2.3;
                }
                else if (grade == "C" || grade == "c") {
                    gradepoint = 2.0;
                }
                else {
                    validgrade = false;
                }
                break;

            case 'D':
            case 'd':
                if (grade == "D" || grade == "d") {
                    gradepoint = 1.0;
                }
                else {
                    validgrade = false;
                }
                break;

            case 'F':
            case 'f':
                if (grade == "F" || grade == "f" || grade == "FIN" || grade == "fin" || grade == "FAB" || grade == "fab") {
                    gradepoint = 0.0;
                } else {
                    validgrade = false;
                }
                break;

            case 'W':
            case 'w':
                if (grade == "WU" || grade == "wu") {
                    gradepoint = 0.0;
                } else {
                    validgrade = false;
                }
                break;
            default:
                validgrade = false;
        }
        if (creditamount <= 0 || creditamount >= 10) {
            cout << "Invalid credit amount input" << endl;
        }
        else if (validgrade == false) {
            cout << "Invalid grade input, credits have to be greater than 0 and less than 10" << endl;
        } else {
            allcredits = allcredits + creditamount;
            allPoints = allPoints + (creditamount * gradepoint);
            classtotal = classtotal + 1;
            gpa = allPoints / allcredits;
            roundedgpa = (int)(gpa * 100 + 0.5) / 100.0;
            cout << "Classes taken: " << classtotal << endl;
            cout << "Semester Gpa: " << roundedgpa << endl;

        }
        cout << "Press x on your keybaord to continue or any other key to stop: ";
        cin >> keepGoing;
        cout << "Program finished" << endl;
        
    }
    return 0;
}
