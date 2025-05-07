#include <bits/stdc++.h>

using namespace std;

int fibo(int n, int fibo_i = 1, int fibo_j = 1){
    cout << fibo_i << endl;
    if(n <= 0){
        return 0;
    }
    
    return fibo(n - 1, fibo_i + fibo_j, fibo_i);
}

int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;

    fibo(n);

    return 0;
}