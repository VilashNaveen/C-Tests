#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <iomanip>
using namespace std;

void QuickSort(int (&arr)[], int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = end;
    int temp = 0;
    int i = start - 1;
    int j = start;
    while (j != pivot) {
        if (arr[j] < arr[pivot]) {
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }
    i++;
    temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;
    pivot = i;

    QuickSort(arr, start, pivot - 1);
    QuickSort(arr, pivot + 1, end);
}

int main() {
    int arr[] = {3,5,7,8,2,3,4,10,1,2};

    QuickSort(arr,0,9);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    vector<int> left;
    return 0;
}
