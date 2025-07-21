#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to approximate the square root using Newton's method
double sqrtApprox(double num, double precision)
{
    if (num < 0)
    {
        printf("Error: Negative input not allowed!\n");
        return -1;
    }
    if (num == 0 || num == 1) return num;

    double x = num; // Initial guess
    double root;

    while (1)
    {
        root = 0.5 * (x + (num / x));
        if (fabs(root - x) < precision) break;
        x = root;
    }
    return root;
}

// Function to check if a number is prime
bool isPrime(int n)
{
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Function to find the longest contiguous subsequence with prime differences
void longestPrimeDiffSubsequence(int arr[], int n)
{
    if (n == 0) return;

    int maxLen = 1, start = 0, bestStart = 0;
    int i;
    for (i = 1; i < n; i++)
    {
        if (isPrime(abs(arr[i] - arr[i - 1])))
        {
            maxLen++;
        }
        else
        {
            if (maxLen > (bestStart - start + 1))
            {
                bestStart = start;
            }
            start = i;
            maxLen = 1;
        }
    }

    if (maxLen > (bestStart - start + 1))
    {
        bestStart = start;
    }

    printf("Longest subsequence with prime differences: ");
    for (i = bestStart; i < bestStart + maxLen; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int Main()
{
    // Part (a): Square root approximation
    double num, precision;
    printf("Enter a positive number: ");
    scanf("%lf", &num);
    printf("Enter precision (e.g., 0.0001): ");
    scanf("%lf", &precision);
    double sqrtValue = sqrtApprox(num, precision);
    printf("Approximated square root: %lf\n", sqrtValue);

    // Part (b): Longest contiguous subsequence with prime differences
    int n, i;
    printf("\nEnter the number of elements in the vector: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    longestPrimeDiffSubsequence(arr, n);

    return 0;
}
