#include <bits/stdc++.h>

using namespace std;

int main(){

    int size;

    cout << "Enter a star size: ";
    cin >> size;

    int spaces = size * 2 + size + 1;
    
    cout << endl;
    for(int i = 0; i <= size*4; i++){
        int margin_spaces = (size * 2 + size + 1) - spaces;

        for(int y = 0; y < spaces; y++){
            cout << " ";
        }

        if(i < size){
            string margin(margin_spaces * 2, ' ');
            cout << "*" << margin << "*" << endl;
            spaces -= i+1 == size ? 2 : 1;
        }else if(i < size*2){
            string margin((margin_spaces-1) * 2, ' ');
            spaces -= i+1 == size*2 ? -2 : 2;
            cout << "**" << margin << "**" << endl;
        }else if(i+1 < size*3){
            string margin((margin_spaces-1) * 2, ' ');
            cout << "**" << margin << "**" << endl;
            spaces += 2;
        }else if(i+1 < size*4){
            string margin(margin_spaces * 2, ' ');
            cout << "*" << margin << "*" << endl;
            spaces += 1;
        }
    }

    return 0;
}