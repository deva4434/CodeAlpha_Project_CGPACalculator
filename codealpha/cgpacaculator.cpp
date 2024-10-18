#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to calculate grade points based on the grade
double getGradePoint(char grade) {
    switch (grade) {
        case 'A': return 10.0;
        case 'B': return 8.0;
        case 'C': return 6.0;
        case 'D': return 4.0;
        case 'E': return 2.0;
        case 'F': return 0.0;
        default: return 0.0;
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<string> courseNames(numCourses);
    vector<char> grades(numCourses);
    vector<int> credits(numCourses);

    // Input for course details
    for (int i = 0; i < numCourses; ++i) {
        cout << "\nEnter course name for course " << i + 1 << ": ";
        cin >> courseNames[i];
        cout << "Enter grade for " << courseNames[i] << " (A/B/C/D/E/F): ";
        cin >> grades[i];
        cout << "Enter credits for " << courseNames[i] << ": ";
        cin >> credits[i];
    }

    double totalGradePoints = 0.0;
    int totalCredits = 0;

    // Display individual course grades and calculate total grade points
    cout << "\nCourse Grades and Credits:\n";
    cout << setw(15) << "Course" << setw(10) << "Grade" << setw(10) << "Credits\n";
    
    for (int i = 0; i < numCourses; ++i) {
        double gradePoint = getGradePoint(grades[i]);
        totalGradePoints += gradePoint * credits[i];
        totalCredits += credits[i];

        cout << setw(15) << courseNames[i] 
             << setw(10) << grades[i] 
             << setw(10) << credits[i] << endl;
    }

    // Calculate GPA for the current semester
    double GPA = totalGradePoints / totalCredits;

    // Display total credits, total grade points, and GPA
    cout << fixed << setprecision(2);
    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "GPA for this semester: " << GPA << endl;

    // For CGPA, assume it's based on a single semester for simplicity
    // If you want to add multiple semesters, you'll need to accumulate this GPA across multiple inputs
    cout << "CGPA (same as GPA if single semester): " << GPA << endl;

    return 0;
}
