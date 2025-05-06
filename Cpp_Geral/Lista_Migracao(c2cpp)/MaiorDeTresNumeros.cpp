#include <bits/stdc++.h>

using namespace std;

int main(){

    int num[3];
    cout << "Type 3 numbers: " << endl;
    cin >> num[0] >> num[1] >> num[2];

    int greater;
    if(num[0] > num[1] && num[0] > num[2]){
        greater = num[0];
    }else if(num[1] > num[0] && num[1] > num[2]){
        greater = num[1];
    }else{
        greater = num[2];
    }
    
    cout << greater;

    return 0;
}