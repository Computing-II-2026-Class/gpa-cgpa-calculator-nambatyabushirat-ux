/*
Name: NAMBATYA BUSHIRAT
Registration Number: 25/U/BIO/01405/PD
*/

#include <stdio.h>

#define COURSES 16

int getGradePoint(int score) {
    if (score >= 80 && score <= 100) return 5;
    else if (score >= 70) return 4;
    else if (score >= 60) return 3;
    else if (score >= 50) return 2;
    else if (score >= 45) return 1;
    else if (score >= 0) return 0;
    else return -1; // invalid
}

int main() {
    int scores[COURSES];
    int credits[COURSES] = {4,3,3,3,3,3,2,3, 4,3,3,3,3,3,3,3};

    float totalPointsSem1 = 0, totalCreditsSem1 = 0;
    float totalPointsSem2 = 0, totalCreditsSem2 = 0;

    int i, gp;

    printf("ENTER SEMESTER I RESULTS:\n");

    for (i = 0; i < 8; i++) {
        printf("Course %d score: ", i + 1);
        scanf("%d", &scores[i]);

        gp = getGradePoint(scores[i]);

        if (gp == -1) {
            printf("Invalid input detected! Score must be 0-100.\n");
            return 0; // stop program (important for test cases)
        }

        totalPointsSem1 += gp * credits[i];
        totalCreditsSem1 += credits[i];
    }

    printf("\nENTER SEMESTER II RESULTS:\n");

    for (i = 8; i < COURSES; i++) {
        printf("Course %d score: ", i + 1);
        scanf("%d", &scores[i]);

        gp = getGradePoint(scores[i]);

        if (gp == -1) {
            printf("Invalid input detected! Score must be 0-100.\n");
            return 0;
        }

        totalPointsSem2 += gp * credits[i];
        totalCreditsSem2 += credits[i];
    }

    float gpa1 = totalPointsSem1 / totalCreditsSem1;
    float gpa2 = totalPointsSem2 / totalCreditsSem2;

    float cgpa = (gpa1 + gpa2) / 2;

    printf("\nSEM 1 GPA: %.2f\n", gpa1);
    printf("SEM 2 GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);

    return 0;
}