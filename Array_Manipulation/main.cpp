#include <iostream>

using namespace std;

int main() {
    // getting array length and number of queries
    int arrlength, querylength;
    cin >> arrlength >> querylength;

    long arr[arrlength];
    for (int i = 0; i< arrlength; i++) {
        arr[i] = 0;
    }
    long max = 0;

    for (int i = 0; i < querylength; i++) {
        int start, end, val;
        cin >> start >> end >> val;

        // apply the query to the array
        for (int j = start-1; j < end; j++) {
            arr[j] += val;
            if (arr[j] > max) {
                max = arr[j];
            }
        }
    }

    cout << max;

    return 0;
}
