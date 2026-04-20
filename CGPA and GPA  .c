/*Name:  NAMBATYA BUSHIRAT 
Registration Number: 25/U/BIO/ 01405/PD*/

#include <stdio.h>

int main() {
    int scores[16];
    int credits[16] = {4,3,3,3,3,3,2,3, 4,3,3,3,3,3,3,3};

    int grade_point;
    float total1 = 0, total2 = 0;
    int credit1 = 0, credit2 = 0;

    float gpa1, gpa2, cgpa;

    // Input 
    for (int i = 0; i < 16; i++) {
        printf("Enter score %d: ", i + 1);
        scanf("%d", &scores[i]);

        if (scores[i] < 0 || scores[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
    }

    //  Semester I (first 8 course units)
    for (int i = 0; i < 8; i++) {

        if (scores[i] >= 80) grade_point = 5;
        else if (scores[i] >= 70) grade_point = 4;
        else if (scores[i] >= 60) grade_point = 3;
        else if (scores[i] >= 50) grade_point = 2;
        else grade_point = 0;

        total1 += grade_point * credits[i];
        credit1 += credits[i];
    }

    // Semester II (next 8 course units)
    for (int i = 8; i < 16; i++) {

        if (scores[i] >= 80) grade_point = 5;
        else if (scores[i] >= 70) grade_point = 4;
        else if (scores[i] >= 60) grade_point = 3;
        else if (scores[i] >= 50) grade_point = 2;
        else grade_point = 0;

        total2 += grade_point * credits[i];
        credit2 += credits[i];
    }

    // GPA calculations
    gpa1 = total1 / credit1;
    gpa2 = total2 / credit2;
    cgpa = (total1 + total2) / (credit1 + credit2);

    // output display 
    printf("Semester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);

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