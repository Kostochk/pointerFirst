#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int students, subjects;
    cout << "Enter number of students: ";
    cin >> students;
    cout << "Enter number of subjects (up to 13): ";
    cin >> subjects;

    int** grades = new int* [students];
    for (int i = 0; i < students; i++) {
        grades[i] = new int[subjects];
    }

    cout << "Student Grades:\n";
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            grades[i][j] = rand() % 12 + 1;
        }
    }

    for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < subjects; j++) {
            cout << grades[i][j] << " ";
        }
        cout << endl;
    }

    double* averages = new double[students];
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < subjects; j++) {
            sum += grades[i][j];
        }
        averages[i] = static_cast<double>(sum) / subjects;
        cout << "Average grade for Student " << i + 1 << ": " << averages[i] << endl;
    }

    for (int i = 0; i < students; i++) {
        if (averages[i] < 6) {
            cout << "Student " << i + 1 << " is not certified.\n";
        }
    }

    int honorsCount = 0;
    for (int i = 0; i < students; i++) {
        if (averages[i] > 8) {
            honorsCount++;
        }
    }
    if (honorsCount > students / 2) {
        cout << "The class is an honors class.\n";
    }

    for (int i = 0; i < students; i++) {
        int highGradeCount = 0;
        cout << "Grades above 9 for Student " << i + 1 << ": ";
        for (int j = 0; j < subjects; j++) {
            if (grades[i][j] > 9) {
                cout << grades[i][j] << " ";
                highGradeCount++;
            }
        }
        cout << endl;
        if (highGradeCount > subjects / 2) {
            cout << "Student " << i + 1 << " is an honors student.\n";
        }
    }

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            int attempts = 0;
            while (grades[i][j] < 9 && attempts < 3) {
                grades[i][j] = rand() % 4 + 9;
                attempts++;
            }
        }
    }

    cout << "\nGrades after correction:\n";
    for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < subjects; j++) {
            cout << grades[i][j] << " ";
        }
        cout << endl;
    }

    for (int j = 0; j < subjects; j++) {
        bool allBelowNine = true;
        for (int i = 0; i < students; i++) {
            if (grades[i][j] >= 9) {
                allBelowNine = false;
                break;
            }
        }
        if (allBelowNine) {
            cout << "All students scored below 9 in subject " << j + 1 << endl;
        }
    }

    for (int i = 0; i < students; i++) {
        delete[] grades[i];
    }
    delete[] grades;
    delete[] averages;

    return 0;
}
