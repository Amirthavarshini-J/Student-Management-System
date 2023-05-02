
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string dob;
    string parentName;
    string department;
    double cgpa;
    string phoneNumber;
    string address;
    string gender;
    bool isHosteler;
};

void printStudentDetails(const Student& student) {
    cout << "Name: " << student.name << endl;
    cout << "Date of Birth: " << student.dob << endl;
    cout << "Parent Name: " << student.parentName << endl;
    cout << "Department: " << student.department << endl;
    cout << "CGPA: " << student.cgpa << endl;
    cout << "Phone Number: " << student.phoneNumber << endl;
    cout << "Address: " << student.address << endl;
    cout << "Gender: " << student.gender << endl;
    cout << (student.isHosteler ? "Hosteler" : "Day Scholar") << endl;
}

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student* students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "Enter details for student #" << (i+1) << ":" << endl;

        cout << "Name: ";
        cin.ignore();
        getline(cin, students[i].name);

        cout << "Date of Birth (DD/MM/YYYY): ";
        getline(cin, students[i].dob);

        cout << "Parent Name: ";
        getline(cin, students[i].parentName);

        cout << "Department: ";
        getline(cin, students[i].department);

        cout << "CGPA: ";
        cin >> students[i].cgpa;

        cout << "Phone Number: ";
        cin.ignore();
        getline(cin, students[i].phoneNumber);

        cout << "Address: ";
        getline(cin, students[i].address);

        cout << "Gender: ";
        getline(cin, students[i].gender);

        char isHostelerChoice;
        do {
            cout << "Is the student a hosteler? (Y/N): ";
            cin >> isHostelerChoice;
        } while (isHostelerChoice != 'Y' && isHostelerChoice != 'N');
        students[i].isHosteler = (isHostelerChoice == 'Y');

        cout << endl;
    }

    cout << endl << "Student Details:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Student #" << (i+1) << ":" << endl;
        printStudentDetails(students[i]);
        cout << endl;
    }

    delete[] students;
    return 0;
}
