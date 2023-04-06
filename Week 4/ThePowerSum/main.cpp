#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Combinations(vector<int>& arr, int index, vector<int>& subset, int sum,int X, int &Flag) {
    if (index == arr.size()) {
        if (sum == X ) {
            Flag = Flag+1;
        }
    } else {
        // recursive case: consider current element and skip it
        subset.push_back(arr[index]);
        Combinations(arr, index+1, subset, sum+arr[index],X,Flag);
        subset.pop_back();
        Combinations(arr, index+1, subset, sum,X,Flag);
    }
}


int powerSum(int X, int N) {
    int sum = 0;
    int flag = 0;
    double Root = pow(X,1.0/N);
    vector<int> Values;
    vector<int> Subset;

    for (int i =1; i < Root+1; i++) {
        int l = pow(i,N);
        Values.push_back(l);
    }

    Combinations(Values,0,Subset,sum,X,flag);
    return flag;

}

int main() {
    cout << powerSum(100,2);
    return 0;
}
