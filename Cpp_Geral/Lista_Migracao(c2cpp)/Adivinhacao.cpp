#include <bits/stdc++.h>

using namespace std;

int main(){

    srand(time(NULL));
    int randomNum = rand() %100 + 1;
    int guessThis;

    for(int i = 0; i < randomNum; i++){
        guessThis = rand();
    }

    int geussTry = 0;

    while(geussTry != guessThis){
        cout << "Try a number: ";
        
        cin >> geussTry;

        if(guessThis > geussTry){
            cout << "Try higher!" << endl;
        }else{
            cout << "Try lower!" << endl;
        }
    }

    cout << "Congratulations, you guess the right number!" << endl;

    return 0;
}