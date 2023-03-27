#include <iostream>
#include <limits.h>
using namespace std;

int max_crossing_sum(int arr[], int low, int mid, int high) {
    int left_sum = INT_MIN, right_sum = INT_MIN;
    int sum = 0;
    cout << "left side, mid  " <<mid <<" low "<< low<<" high "<<high << endl;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        cout << arr[i] << " ";
        if (sum > left_sum) {
            left_sum = sum;
        }
    }
    cout << endl;
    sum = 0;

    cout << "Right side, mid  " <<mid <<" low "<< low<<" high "<<high << endl;
    for (int i = mid+1; i <= high; i++) {
        sum += arr[i];
        cout << arr[i] << " ";
        if (sum > right_sum) {
            right_sum = sum;
        }
    }
    cout << endl;
    return left_sum + right_sum;
}

int max_subarray_sum(int arr[], int low, int high) {
    if (low == high) {
        cout << "return " << arr[low] << endl;
        return arr[low];
    }
    int mid = (low + high) / 2;
    cout << "mid " << mid << endl;
    int left_sum = max_subarray_sum(arr, low, mid);
    int right_sum = max_subarray_sum(arr, mid+1, high);
    int cross_sum = max_crossing_sum(arr, low, mid, high);
    return max(max(left_sum, right_sum), cross_sum);
}

int main() {
    int arr[] = {2, -5, 4, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_sum = max_subarray_sum(arr, 0, n-1);
    cout << "Maximum subarray sum is " << max_sum << endl;
    return 0;
}