#include <stdio.h>

float inputScore(char label[]);
float calculateFinalGrade(float quiz, float exam);
char getLetterGrade(float finalGrade);
void displayReport(float quiz, float exam, float finalGrade, char letterGrade);

int main() {
    float quizScore, examScore, finalGrade;
    char letterGrade;

    quizScore = inputScore("Quiz");
    examScore = inputScore("Exam");
    finalGrade = calculateFinalGrade(quizScore, examScore);
    letterGrade = getLetterGrade(finalGrade);
    displayReport(quizScore, examScore, finalGrade, letterGrade);

    return 0;
}

float inputScore(char label[]) {
    int score;
    int result;

    do {
        printf("Enter %s Score (0-100): ", label);

        result = scanf("%d", &score);

        if (result != 1) {
            printf("INVALID\n");

            while (getchar() != '\n');
            continue;
        }

        if (score < 0 || score > 100) {
            printf("INVALID\n");
        }

    } while (result != 1 || score < 0 || score > 100);

    return (float)score;
}

float calculateFinalGrade(float quiz, float exam) {
    return (quiz * 0.4) + (exam * 0.6);
}

char getLetterGrade(float finalGrade) {
    if (finalGrade >= 90)
        return 'A';
    else if (finalGrade >= 80)
        return 'B';
    else if (finalGrade >= 70)
        return 'C';
    else if (finalGrade >= 60)
        return 'D';
    else
        return 'F';
}

void displayReport(float quiz, float exam, float finalGrade, char letterGrade) {
    printf("\n========== GRADE REPORT ==========\n");
    printf("Quiz Score:       %.2f\n", quiz);
    printf("Exam Score:       %.2f\n", exam);
    printf("Final Grade:      %.2f\n", finalGrade);
    printf("Letter Grade:     %c\n", letterGrade);
    printf("==================================\n");
}
