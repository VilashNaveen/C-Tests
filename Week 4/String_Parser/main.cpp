#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element
        // with the first element
        if (min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
}

//Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        cout << arr[i] << " ";
        cout << endl;
    }
}

int main()
{
    //starting the clock

    // Seed the random number generator
    srand(time(0));
    // Declare variables for array length and max random value
    int length, max_value;
    max_value = 100;
    cout << "Enter the length of the array: ";
    cin >> length;
    // Declare the integer array of given length
    int arr[length];

    // Fill the array with random values
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % max_value;
    }
    int N = sizeof(arr) / sizeof(arr[0]);

    auto start = high_resolution_clock::now();

    selectionSort(arr, N);

    auto stop = high_resolution_clock::now();

    printArray(arr, N);

    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by program: " << duration.count() << "nanoseconds" << endl;

    return 0;
}