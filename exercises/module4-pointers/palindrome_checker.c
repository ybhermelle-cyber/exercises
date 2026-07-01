#include <stdio.h>

int isPalindrome(int *arr, int size)
{
    int *left = arr;
    int *right = arr + size - 1;

    while (left < right)
    {
        if (*left != *right)
        {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}

void testArray(int arr[], int size)
{
    int i;

    printf("Array: {");

    for (i = 0; i < size; i++)
    {
        printf("%d", arr[i]);

        if (i < size - 1)
        {
            printf(", ");
        }
    }

    printf("}");

    if (isPalindrome(arr, size))
    {
        printf(" -> PALINDROME\n");
    }
    else
    {
        printf(" -> NOT PALINDROME\n");
    }
}

int main()
{
    // Test Case 1
    int arr1[] = {1, 2, 3, 2, 1};

    // Test Case 2
    int arr2[] = {5, 4, 4, 5};

    // Test Case 3
    int arr3[] = {1, 2, 3, 4, 5};

    // Test Case 4
    int arr4[] = {7};

    // Test Case 5
    int arr5[] = {9, 9};

    // Test Case 6
    int arr6[] = {3, 7};

    // Test Case 7
    int arr7[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};

    testArray(arr1, 5);
    testArray(arr2, 4);
    testArray(arr3, 5);
    testArray(arr4, 1);
    testArray(arr5, 2);
    testArray(arr6, 2);
    testArray(arr7, 9);

    return 0;
}
