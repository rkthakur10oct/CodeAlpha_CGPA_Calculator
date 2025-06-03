#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Course {
    string name;
    double grade;
    int credit;
};

int main() {
    int n;
    cout << "Enter the number of courses: ";
    cin >> n;

    vector<Course> courses(n);
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < n; ++i) {
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Course name: ";
        cin.ignore();
        getline(cin, courses[i].name);
        cout << "Grade (on a 10.0 scale): ";
        cin >> courses[i].grade;
        cout << "Credit hours: ";
        cin >> courses[i].credit;

        totalGradePoints += courses[i].grade * courses[i].credit;
        totalCredits += courses[i].credit;
    }

    double cgpa = totalGradePoints / totalCredits;

    cout << "\n========== RESULT ==========\n";
    cout << left << setw(20) << "Course" 
         << setw(10) << "Grade" 
         << setw(10) << "Credits" << endl;

    for (const auto& course : courses) {
        cout << left << setw(20) << course.name 
             << setw(10) << course.grade 
             << setw(10) << course.credit << endl;
    }

    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nTotal Grade Points: " << totalGradePoints;
    cout << fixed << setprecision(2);
    cout << "\nFinal CGPA: " << cgpa << endl;

    return 0;
}
// This program calculates the CGPA based on user input for course names, grades, and credit hours.