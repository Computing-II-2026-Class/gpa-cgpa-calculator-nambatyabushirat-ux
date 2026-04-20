/*
Name: NAMBATYA BUSHIRAT
Registration Number: 25/U/BIO/01405/PD
*/

#include <stdio.h>

int getGradePoint(int score, char *grade) {
    if (score >= 80) {
        *grade = 'A';
        return 5;
    } else if (score >= 70) {
        *grade = 'B';
        return 4;
    } else if (score >= 60) {
        *grade = 'C';
        return 3;
    } else if (score >= 50) {
        *grade = 'D';
        return 2;
    } else {
        *grade = 'F';
        return 0;
    }
}

int main() {

    int scores[16];
    int credits[16] = {
        4,3,3,3,3,3,2,3,
        4,3,3,3,3,3,3,3
    };

    char *courses[16] = {
        "TEMB1101","TEMB1102","TEMB1103","TEMB1104",
        "TEMB1105","TEMB1106","TEMB1107","TEMB1108",
        "TEMB1201","TEMB1202","TEMB1203","TEMB1204",
        "TEMB1205","TEMB1206","TEMB1207","TEMB1208"
    };

    char grade;
    int grade_point;

    float sem1_total = 0, sem1_credits = 0;
    float sem2_total = 0, sem2_credits = 0;
    float all_total = 0, all_credits = 0;

    // INPUT
    for (int i = 0; i < 16; i++) {
        printf("Enter score for %s: ", courses[i]);
        scanf("%d", &scores[i]);

        if (scores[i] < 0 || scores[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
    }

    printf("\n========== ACADEMIC REPORT ==========\n\n");

    // PROCESS & OUTPUT
    for (int i = 0; i < 16; i++) {

        grade_point = getGradePoint(scores[i], &grade);
        int weighted = grade_point * credits[i];

        printf("%s\t%d\t%c\t%d\t%d\t%d\n",
               courses[i],
               scores[i],
               grade,
               grade_point,
               credits[i],
               weighted);

        all_total += weighted;
        all_credits += credits[i];

        if (i < 8) {
            sem1_total += weighted;
            sem1_credits += credits[i];
        } else {
            sem2_total += weighted;
            sem2_credits += credits[i];
        }
    }

    float gpa1 = sem1_total / sem1_credits;
    float gpa2 = sem2_total / sem2_credits;
    float cgpa = all_total / all_credits;

    // CLASSIFICATION
    char *classif;

    if (cgpa >= 4.40)
        classif = "First Class";
    else if (cgpa >= 3.60)
        classif = "Second Class Upper";
    else if (cgpa >= 2.80)
        classif = "Second Class Lower";
    else if (cgpa >= 2.00)
        classif = "Pass";
    else
        classif = "Fail";

    // SUMMARY OUTPUT (IMPORTANT FOR AUTOGRADING)
    printf("\nSemester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classif);

    return 0;
}