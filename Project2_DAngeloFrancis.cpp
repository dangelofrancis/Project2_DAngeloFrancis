//************************************************
// TITLE: Course Grade                           *
// FILE NAME: Project1_DAngeloFrancis.cpp        *
// PROGRAMMER: D'Angelo Francis                  *
// DATE: February 24th, 2025                     *
// REQUIREMENTS: Make revisions of the grade book*
// project to use structs instead                *
//************************************************

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int idNum;
    double* pTestScores;
    double average;
    char grade;
};

//************************************************
// Description of the function getData           *
// This function reads data from a file          *
//************************************************

Student* getData(ifstream& file, int& studentCount, int& testCount);

//************************************************
// Description of the function calculateAverage   *
// This function calculates the grade average     *
//************************************************

void calculateAverage(Student* pStudents, int studentCount, int testCount);

//************************************************
// Description of the function getLetterGrade    *
// This function gives a letter grade for average*
//************************************************

char getLetterGrade(double average);

//************************************************
// Description of the function displayGrades     *
// This function displays the name and grade     *
//************************************************

void displayGrades(Student* pStudents, int studentCount);

//************************************************
// Description of the function cleanUp           *
// This function cleans up the memory            *
//************************************************

void cleanUp(Student* pStudents, int studentCount);

//************************************************
// the main function.                            *
//************************************************

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

    Student* pStudents = getData(inputFile, numStudents, numTests);
    inputFile.close();

    calculateAverage(pStudents, numStudents, numTests);
    displayGrades(pStudents, numStudents);
    cleanUp(pStudents, numStudents);

    return 0;
}

Student* getData(ifstream& file, int& studentCount, int& testCount) {
    file >> studentCount >> testCount;
    Student* pStudents = new Student[studentCount];

    for (int i = 0; i < studentCount; i++) {
        file >> pStudents[i].name >> pStudents[i].idNum;
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
    if (average >= 91) return 'A';
    else if (average >= 81) return 'B';
    else if (average >= 71) return 'C';
    else if (average >= 61) return 'D';  
    else return 'F';
}

void displayGrades(Student* pStudents, int studentCount) {
    cout << "Name\n\nID\nAverage\nGrade" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << pStudents[i].name << "\n"
            << pStudents[i].idNum << "\n"
            << pStudents[i].average << "\n"
            << pStudents[i].grade << endl;
    }
}

void cleanUp(Student* pStudents, int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        delete[] pStudents[i].pTestScores;
    }
    delete[] pStudents;
}
