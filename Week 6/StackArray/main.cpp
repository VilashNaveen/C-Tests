#include <iostream>
#include <chrono>
using namespace std;

class Stack_Array {

private:
    int* arr;
    int top =0;
    int size = 0;

public:
    Stack_Array(int n) : arr(new int[n]), size(n) {

    }
     void Push (int num) {
        if (top >= size - 1) {
            cout << "Stack Overflow" << endl;
        }
        else {
            arr[top] = num;
            top++;
        }
    }
    void Pop() {
        if (top <= 0) {
            cout << "Stack Underflow" << endl;
        }
        else {
            int ret = arr[--top];
            cout << ret << endl;

        }
    }
    bool isEmpty() {
        if (top <= 0) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isFull() {
        if (top >= size-1) {
            return true;
        }
        else {
            false;
        }
    }
    void StackTop() {
        cout << arr[top-1];
    }
    void Display() {
        for (int i = 0; i<top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    auto start_time = std::chrono::high_resolution_clock::now();

    Stack_Array myStack(20);
    myStack.Push(8);
    myStack.Push(10);
    myStack.Push(5);
    myStack.Push(11);
    myStack.Push(15);
    myStack.Push(23);
    myStack.Push(6);
    myStack.Push(18);
    myStack.Push(20);
    myStack.Push(17);
    myStack.Display();
    myStack.Pop();
    myStack.Pop();
    myStack.Pop();
    myStack.Pop();
    myStack.Pop();
    myStack.Display();
    myStack.Push(4);
    myStack.Push(30);
    myStack.Push(3);
    myStack.Push(1);
    myStack.Display();

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    std::cout << "Time taken: " << time_taken << " microseconds" << std::endl;

    return 0;
}
