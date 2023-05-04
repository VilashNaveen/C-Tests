#include <iostream>
#include <vector>

using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largerIndex = root;

   int leftIndex = root * 2 + 1;
   if (leftIndex < n && arr[leftIndex ] > arr[largerIndex]) {
       largerIndex = leftIndex;
   }
   int rightIndex = root* 2 + 2;
   if (rightIndex < n && arr[rightIndex] > arr[largerIndex]) {
       largerIndex = rightIndex;
   }
   if (root == largerIndex)
       return;

    swap(arr[largerIndex],arr[root]);
    heapify(arr,n,largerIndex);
}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
   // extracting elements from heap one by one
   int j = 0;
    int arr_out[n];
   for (int i = n-1; i >= 0; i--) {
       swap(arr[0],arr[i]);
       heapify(arr,i,0);
   }

}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
//    int arr2[] = {20,11,4,5,7,9,12,15,1};
//    int n = 9;
//    heapSort(arr2,n);
//    displayArray(arr2,n);


   vector<int> num_list;

   int x;
   while (true) {
       cout << "Enter Value / Enter -1 to break" << endl;
       cin >> x;
       if (x == -1) {
           break;
       }
       else {
           num_list.push_back(x);
       }
   }

   int arr[num_list.size()];
   for (int i = 0; i < num_list.size(); i++) {
       arr[i] = num_list[i];
   }
    heapSort(arr,num_list.size());

    displayArray(arr,num_list.size());

}
