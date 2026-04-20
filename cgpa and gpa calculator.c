/* NAMBATYA BUSHIRAT
Registration Number: 25/U/BIO/01405/PD */

#include <stdio.h>
#include <stdlib.h>

char getGrade(int score) {
    if (score >= 80) return 'A';
    else if (score >= 70) return 'B';
    else if (score >= 60) return 'C';
    else if (score >= 50) return 'D';
    else return 'F';
}

int getGradePoint(int score) {
    if (score >= 80) return 5;
    else if (score >= 70) return 4;
    else if (score >= 60) return 3;
    else if (score >= 50) return 2;
    else return 0;
}

int main() {
    int scores[16];
    int credits[16] = {4,3,3,3,3,3,2,3, 4,3,3,3,3,3,3,3};

    char *course_codes[16] = {
        "TEMB1101","TEMB1102","TEMB1103","TEMB1104","TEMB1105","TEMB1106","TEMB1107","TEMB1108",
        "TEMB1201","TEMB1202","TEMB1203","TEMB1204","TEMB1205","TEMB1206","TEMB1207","TEMB1208"
    };

    int grade_point;
    float total1 = 0, total2 = 0;
    int credit1 = 0, credit2 = 0;

    float gpa1, gpa2, cgpa;

    // Input scores
    for (int i = 0; i < 16; i++) {
        printf("Enter score for %s: ", course_codes[i]);
        if(scanf("%d", &scores[i]) != 1 || scores[i] < 0 || scores[i] > 100) {
            printf("Invalid score entered\n");
            exit(0); // terminate immediately on invalid input
        }
    }

    printf("\n===== ACADEMIC REPORT =====\n");

    // Semester I
    printf("\n--- Semester I ---\n");
    printf("Course Code  Score  Grade  GP  CU  W\n");
    for (int i = 0; i < 8; i++) {
        grade_point = getGradePoint(scores[i]);
        char grade = getGrade(scores[i]);
        float weighted = grade_point * credits[i];
        total1 += weighted;
        credit1 += credits[i];

        printf("%-11s  %3d    %c     %d   %d  %.2f\n", course_codes[i], scores[i], grade, grade_point, credits[i], weighted);
    }

    // Semester II
    printf("\n--- Semester II ---\n");
    printf("Course Code  Score  Grade  GP  CU  W\n");
    for (int i = 8; i < 16; i++) {
        grade_point = getGradePoint(scores[i]);
        char grade = getGrade(scores[i]);
        float weighted = grade_point * credits[i];
        total2 += weighted;
        credit2 += credits[i];

        printf("%-11s  %3d    %c     %d   %d  %.2f\n", course_codes[i], scores[i], grade, grade_point, credits[i], weighted);
    }

    // GPA calculations
    gpa1 = total1 / credit1;
    gpa2 = total2 / credit2;
    cgpa = (total1 + total2) / (credit1 + credit2);

    // Displays  GPA and CGPA
    printf("\nSemester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);

    // Classification
    if (cgpa >= 4.40) {
        printf("Classification: First Class\n");
    } else if (cgpa >= 3.60) {
        printf("Classification: Second Class Upper\n");
    } else if (cgpa >= 2.80) {
        printf("Classification: Second Class Lower\n");
    } else if (cgpa >= 2.00) {
        printf("Classification: Pass\n");
    } else {
        printf("Classification: Fail\n");
    }

    return 0;
}