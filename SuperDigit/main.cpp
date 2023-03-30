//function to find Super Digit
#include <iostream>
using namespace std;

int superDigit(string n, int k) {
    string digit;
    long temp = 0;
    long temp2 = 0;
    int super = 0;
    for (char c : n) {
        temp = temp + (int(c)-48);
    }

    temp2 = temp * k;
    digit = to_string(temp2);
    //cout << digit;
    while (digit.length()>1) {
        temp = 0;
        for (char c : digit ) {
            temp = temp + (int(c)-48);
        }
        digit = to_string(temp);
    }
    super = stoi(digit);
    return super;

}

int main() {
    string str = "9875";
    cout << superDigit(str,4);
    return 0;
}
//vilash Naveen
