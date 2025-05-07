#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> numbers;
    for(int i = 0; i < 10; i++){
        int num;
        cin >> num;
        numbers.insert(numbers.begin() + i, num);
    }

    for(int i = 9; i >= 0; i--){
        cout << numbers[i] << endl;
    }

    return 0;
}