#include <bits/stdc++.h>
#include <format>

using namespace std;

int main(){

    char option;
    double num1, num2;
    double result;

    cout << "Enter the operation (x + y):" << endl;
    cin >> num1 >> option >> num2;

    switch (option)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        cout << "Invalid operator, please try again." << endl;
        return 0;
        break;
    }

    cout << "Result: " << num1 << " " << option << " " << num2 << " = " << result << endl;

    return 0;
}