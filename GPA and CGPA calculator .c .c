#include <stdio.h>
/*
Full Name: NAMBATYA BUSHIRAT 
Registration Number : 25/U/BIO/01405/PD
*/

// Function to get grade point
int getGradePoint(int score) {
    if (score >= 80) return 5;
    else if (score >= 70) return 4;
    else if (score >= 60) return 3;
    else if (score >= 50) return 2;
    else return 0;
}

// Function to get grade letter
char getGrade(int score) {
    if (score >= 80) return 'A';
    else if (score >= 70) return 'B';
    else if (score >= 60) return 'C';
    else if (score >= 50) return 'D';
    else return 'F';
}

int main() {

    int sem1_scores[8], sem2_scores[8];

    // Credit units
    int sem1_credits[8] = {4,3,3,3,3,3,2,3};
    int sem2_credits[8] = {4,3,3,3,3,3,3,3};

    char *sem1_codes[8] = {
        "TEMB1101","TEMB1102","TEMB1103","TEMB1104",
        "TEMB1105","TEMB1106","TEMB1107","TEMB1108"
    };

    char *sem2_codes[8] = {
        "TEMB1201","TEMB1202","TEMB1203","TEMB1204",
        "TEMB1205","TEMB1206","TEMB1207","TEMB1208"
    };

    int i;

    // INPUT SEM 1
    printf("Enter Semester I scores:\n");
    for(i=0;i<8;i++){
        scanf("%d",&sem1_scores[i]);
        if(sem1_scores[i] < 0 || sem1_scores[i] > 100){
            printf("Invalid score entered\n");
            return 0;
        }
    }

    // INPUT SEM 2
    printf("Enter Semester II scores:\n");
    for(i=0;i<8;i++){
        scanf("%d",&sem2_scores[i]);
        if(sem2_scores[i] < 0 || sem2_scores[i] > 100){
            printf("Invalid score entered\n");
            return 0;
        }
    }

    float total1 = 0, total2 = 0;
    int credit1 = 0, credit2 = 0;

    printf("\n===== ACADEMIC REPORT =====\n");

    // OUTPUT SEMESTER I 
    printf("\n--- Semester I ---\n");
    for(i=0;i<8;i++){
        int gp = getGradePoint(sem1_scores[i]);
        char grade = getGrade(sem1_scores[i]);
        float weighted = gp * sem1_credits[i];

        printf("%s  Score:%d  Grade:%c  GP:%d  CU:%d  W:%.2f\n",
        sem1_codes[i], sem1_scores[i], grade, gp, sem1_credits[i], weighted);

        total1 += weighted;
        credit1 += sem1_credits[i];
    }

    // OUTPUT SEMESTER II
    printf("\n--- Semester II ---\n");
    for(i=0;i<8;i++){
        int gp = getGradePoint(sem2_scores[i]);
        char grade = getGrade(sem2_scores[i]);
        float weighted = gp * sem2_credits[i];

        printf("%s  Score:%d  Grade:%c  GP:%d  CU:%d  W:%.2f\n",
        sem2_codes[i], sem2_scores[i], grade, gp, sem2_credits[i], weighted);

        total2 += weighted;
        credit2 += sem2_credits[i];
    }

    float gpa1 = total1 / credit1;
    float gpa2 = total2 / credit2;
    float cgpa = (total1 + total2) / (credit1 + credit2);

    // CLASSIFICATION( getting the class)
    char *class;

    if (cgpa >= 4.40) class = "First Class";
    else if (cgpa >= 3.60) class = "Second Class Upper";
    else if (cgpa >= 2.80) class = "Second Class Lower";
    else if (cgpa >= 2.00) class = "Pass";
    else class = "Fail";

    printf("\nSemester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", class);

    return 0;
}