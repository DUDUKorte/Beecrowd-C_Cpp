#include <bits/stdc++.h>

using namespace std;

bool verify_prime_number(int number){
    int current = number - 1;
    do{
        if(number%current == 0 && current != 1){
            return false;
        }

        current--;
    }while(current > 1);

    return true;
}

int main(){

    int num, current;
    cout << "Enter a number: ";
    cin >> num;

    if(verify_prime_number(num)){
        cout << num << " is Prime" << endl;
    }else{
        cout << num << " is not a Prime number" << endl;
    }

    return 0;
}