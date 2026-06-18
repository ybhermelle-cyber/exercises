# Grade Calculator System

## About

This program calculates a student's final grade using a quiz score and an exam score.

The quiz is worth 40% and the exam is worth 60%.

The program also shows the letter grade.

## Functions

* `inputScore()` - gets the quiz and exam scores from the user.
* `calculateFinalGrade()` - calculates the final grade.
* `getLetterGrade()` - finds the letter grade.
* `displayReport()` - displays the results.

## How to Compile

```bash
gcc grade_calculator.c -o grade_calculator
```

## How to Run

```bash
./grade_calculator
```

For Windows:

```bash
grade_calculator.exe
```

## Sample Output

```text
Enter Quiz Score (0-100): 85
Enter Exam Score (0-100): 92

========== GRADE REPORT ==========
Quiz Score:       85.00
Exam Score:       92.00
Final Grade:      89.20
Letter Grade:     B
==================================
```
