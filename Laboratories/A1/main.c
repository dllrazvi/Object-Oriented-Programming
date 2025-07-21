#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

// Function declarations
double sqrtApprox(double num, double precision);
bool isPrime(int n);
void longestPrimeDiffSubsequence(int arr[], int n);
void readVector(int arr[], int *n);

int main()
{
    int choice;
    int arr[100], n = 0;
    double num, precision;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Compute square root approximation\n");
        printf("2. Read vector of numbers\n");
        printf("3. Find longest prime difference subsequence\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a positive number: ");
            scanf("%lf", &num);
            printf("Enter precision (e.g., 0.0001): ");
            scanf("%lf", &precision);
            printf("Approximated square root: %lf\n", sqrtApprox(num, precision));
            break;
        case 2:
            readVector(arr, &n);
            break;
        case 3:
            if (n > 0)
                longestPrimeDiffSubsequence(arr, n);
            else
                printf("Vector is empty! Please read values first.\n");
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

// Function to approximate square root
double sqrtApprox(double num, double precision)
{
    if (num < 0)
    {
        printf("Error: Negative input not allowed!\n");
        return -1;
    }
    if (num == 0 || num == 1)
        return num;

    double x = num;
    double root;
    while (1)
    {
        root = 0.5 * (x + (num / x));
        if (fabs(root - x) < precision)
            break;
        x = root;
    }
    return root;
}

// Function to check if a number is prime
bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Function to find the longest contiguous subsequence with prime differences
void longestPrimeDiffSubsequence(int arr[], int n)
{
    if (n == 0)
        return;

    int maxLen = 1, currentLen = 1, bestStart = 0, start = 0;

    for (int i = 1; i < n; i++)
    {
        if (isPrime(abs(arr[i] - arr[i - 1])))
        {
            currentLen++;
        }
        else
        {
            if (currentLen > maxLen)
            {
                maxLen = currentLen;
                bestStart = start;
            }
            start = i;      // Start new sequence
            currentLen = 1; // Reset length
        }
    }

    // Final check in case the longest sequence is at the end
    if (currentLen > maxLen)
    {
        maxLen = currentLen;
        bestStart = start;
    }

    // Printing the longest sequence
    printf("Longest subsequence with prime differences: ");
    for (int i = bestStart; i < bestStart + maxLen; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to read vector
void readVector(int arr[], int *n)
{
    printf("Enter the number of elements in the vector: ");
    scanf("%d", n);
    printf("Enter the elements: ");
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
