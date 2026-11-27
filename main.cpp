// Grade Calculator
// Author: Sandzhar Tabyldiyev, group sw1-25
// The teacher enters a name and 5 scores for each student. The program
// prints the average and the grade. The word "end" finishes the program.
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

const int NUMBER_OF_SCORES = 5;
const int LOWEST_SCORE = 0;
const int HIGHEST_SCORE = 100;

// Asks for one score until the teacher enters a valid whole number
int askForScore(int scoreNumber) {
    int value = 0;
    bool accepted = false;

    while (!accepted) {
        cout << "Score " << scoreNumber << ": ";
        bool readOk = static_cast<bool>(cin >> value);

        if (!readOk && cin.eof()) {
            exit(0);                  // input is closed, nothing to read
        }
        if (!readOk) {
            cin.clear();              // letters were typed: reset the stream
        }
        cin.ignore(1000, '\n');       // throw away the rest of the line

        if (readOk && value >= LOWEST_SCORE && value <= HIGHEST_SCORE) {
            accepted = true;
        } else {
            cout << "Invalid score. Enter a value from " << LOWEST_SCORE
                 << " to " << HIGHEST_SCORE << "." << endl;
        }
    }
    return value;
}

// Converts an average to a grade letter
char gradeFor(double average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 75) {
        return 'B';
    } else if (average >= 60) {
        return 'C';
    }
    return 'F';
}

int main() {
    int studentTotal = 0;
    double averagesSum = 0.0;
    string name;

    cout << fixed << setprecision(1);

    cout << "Student name (or end to finish): ";
    getline(cin, name);

    while (cin && name != "end") {
        int pointsSum = 0;

        for (int number = 1; number <= NUMBER_OF_SCORES; number++) {
            pointsSum += askForScore(number);
        }

        double average = (double)pointsSum / NUMBER_OF_SCORES;
        cout << name << ": average " << average
             << ", grade " << gradeFor(average) << endl << endl;

        studentTotal++;
        averagesSum += average;

        cout << "Student name (or end to finish): ";
        getline(cin, name);
    }

    if (studentTotal == 0) {
        cout << "No students entered" << endl;
    } else {
        cout << "Students entered: " << studentTotal << endl;
        cout << "Class average: " << averagesSum / studentTotal << endl;
    }
    return 0;
}
