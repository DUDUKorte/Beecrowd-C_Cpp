#include <bits/stdc++.h>

using namespace std;

int main(){

    int number;
    cout << "Enter a number: ";
    cin >> number;

    printf("The number is %s\n", number%2 == 0 ? "Even" : "Odd");

    return 0;
}