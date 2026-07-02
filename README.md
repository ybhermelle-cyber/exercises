# PROG2 Module 4 - Palindrome Checker Challenge

## Description

This program checks if an array of integers is a palindrome using the two-pointer technique. One pointer starts at the beginning of the array, and the other starts at the end. The program compares the values while both pointers move toward the middle.

If all values match, the array is a palindrome. If a pair of values is different, the array is not a palindrome.

## Features

* Uses pointers to traverse the array
* Uses the two-pointer technique
* Returns `1` if the array is a palindrome
* Returns `0` if the array is not a palindrome
* Includes 7 test cases

## How to Compile

Using GCC:

```bash
gcc palindrome_checker.c -o palindrome_checker
```

## How to Run

Windows:

```bash
palindrome_checker
```

Linux/macOS:

```bash
./palindrome_checker
```

## Sample Output

```
Array: {1, 2, 3, 2, 1} -> PALINDROME
Array: {5, 4, 4, 5} -> PALINDROME
Array: {1, 2, 3, 4, 5} -> NOT PALINDROME
Array: {7} -> PALINDROME
Array: {9, 9} -> PALINDROME
Array: {3, 7} -> NOT PALINDROME
Array: {1, 2, 3, 4, 5, 4, 3, 2, 1} -> PALINDROME
```

## File

* `palindrome_checker.c` - Source code for the palindrome checker.
