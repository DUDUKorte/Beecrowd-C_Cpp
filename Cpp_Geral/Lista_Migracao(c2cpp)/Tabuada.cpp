#include <bits/stdc++.h>

using namespace std;

int main(){

    int num;
    cout << "Enter a number: ";
    cin >> num;

    for(int i = 1; i <= 10; i++){
        cout << i << " x " << num << " = " << num*i << endl;
    }

    return 0;
}