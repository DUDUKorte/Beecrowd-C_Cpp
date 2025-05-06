#include <bits/stdc++.h>

using namespace std;

int main(){

    int size = 5;
    int spaces = size * 2 + size;

    cout << endl;
    for(int i = 0; i < size*4; i++){
        for(int y = 0; y < spaces; y++){
            cout << " ";
        }
        if(i < size){
            cout << "*" << endl;
            spaces--;
        }else if(i <= size*2){
            spaces -= 2;
            cout << "**" << endl;
        }else if(i < size*3){
                      
        }
    }

    return 0;
}