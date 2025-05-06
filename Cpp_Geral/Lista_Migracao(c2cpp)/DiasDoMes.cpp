#include <bits/stdc++.h>

using namespace std;

int main(){

    int month, odd;
    cout << "Enter the month number (1-12): ";
    cin >> month;
    
    if(month == 2){
        cout << "This month have 28 days" << endl;
        return 0;
    }

    odd = month%2 == 0;
    month > 7 ? odd = !odd : odd = odd;
    
    switch (odd)
    {
    case true:
        cout << "This month have 30 days" << endl;
        break;
    case false:
        cout << "This month have 31 days" << endl;
        break;
    }

    return 0;
}