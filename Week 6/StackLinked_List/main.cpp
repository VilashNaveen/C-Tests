#include <iostream>
#include <chrono>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack_LL {
private:
    Node* top;

public:
    Stack_LL() {
        top = NULL;
    }

    void push(int x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << top->data << " " << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {

    auto start_time = std::chrono::high_resolution_clock::now();

    Stack_LL myStack;
    myStack.push(8);
    myStack.push(10);
    myStack.push(5);
    myStack.push(11);
    myStack.push(15);
    myStack.push(23);
    myStack.push(6);
    myStack.push(18);
    myStack.push(20);
    myStack.push(17);
    myStack.display();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.display();
    myStack.push(4);
    myStack.push(30);
    myStack.push(3);
    myStack.push(1);
    myStack.display();

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_taken = std::chrono::duration_cast<std::chrono::microseconds >(end_time - start_time).count();
    std::cout << "Time taken: " << time_taken << " microseconds" << std::endl;

    return 0;
}
