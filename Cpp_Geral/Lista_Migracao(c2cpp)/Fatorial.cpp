#include <bits/stdc++.h>

using namespace std;

int main(){

    int num;
    double result = 0.0;
    cout << "Enter a number: ";
    cin >> num;

    result = num;
    while(num > 1){
        result *= --num;
    }
    cout << "Result: " << result << endl;

    return 0;
}