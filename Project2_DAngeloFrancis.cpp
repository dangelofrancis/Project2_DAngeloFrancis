//************************************************
// TITLE: Course Grade                           *
// FILE NAME: Project1_DAngeloFrancis.cpp        *
// PROGRAMMER: D'Angelo Francis                  *
// DATE: February 24th, 2025                     *
// REQUIREMENTS:                         *
//************************************************
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    string name;
    double* pTestScores;
    double average;
    char grade;
};

Student* pGetData(ifstream& file, int& studentCount, int& testCount);
void calculateAverage(Student* pStudents, int studentCount, int testCount);
char getLetterGrade(double average);
void displayGrades(Student* pStudents, int studentCount);
void cleanUp(Student* pStudents, int studentCount);

int main() {
    ifstream inputFile;
    string fileName;
    int numStudents, numTests;

    cout << "Enter the file name: ";
    cin >> fileName;

    inputFile.open(fileName);
    if (!inputFile) {
        cout << "Error: Could not open file." << endl;
        return 1;
    }

    Student* pStudents = pGetData(inputFile, numStudents, numTests);
    inputFile.close();

    calculateAverage(pStudents, numStudents, numTests);
    displayGrades(pStudents, numStudents);
    cleanUp(pStudents, numStudents);

    return 0;
}

Student* pGetData(ifstream& file, int& studentCount, int& testCount) {
    studentCount = 0;
    testCount = 0;
    string tempName;
    double tempScore;
    int currentTestCount = 0;

    Student* pStudents = new Student[studentCount];

    for (int i = 0; i < studentCount; i++) {
        file >> pStudents[i].name;
        pStudents[i].pTestScores = new double[testCount];

        for (int j = 0; j < testCount; j++) {
            file >> pStudents[i].pTestScores[j];
        }
    }

    return pStudents;
}
void calculateAverage(Student* pStudents, int studentCount, int testCount) {
    for (int i = 0; i < studentCount; i++) {
        double total = 0;
        for (int j = 0; j < testCount; j++) {
            total += pStudents[i].pTestScores[j];
        }
        pStudents[i].average = total / testCount;
        pStudents[i].grade = getLetterGrade(pStudents[i].average);
    }
}
char getLetterGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}
void displayGrades(Student* pStudents, int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        cout << pStudents[i].name << " " << pStudents[i].average << " " << pStudents[i].grade << endl;
    }
}
void cleanUp(Student* pStudents, int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        delete[] pStudents[i].pTestScores;
    }
    delete[] pStudents;
}
