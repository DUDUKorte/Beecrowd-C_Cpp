#include <bits/stdc++.h>

using namespace std;

int main(){

    double num, result = 0.0;

    while(result <= 100.0){
        cout << "Enter a number: ";
        cin >> num;
        result += num;
    }

    cout << "Result: " << result << endl;

    return 0;
}