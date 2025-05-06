#include <bits/stdc++.h>

using namespace std;

float convert_to_fahrenheit(float celsius){
    float fahreneit = (celsius * (9.0/5.0)) + 32.0;
    return fahreneit;
}

int main(){
    float temperature;

    cout << "Enter temperature in degrees celsius: ";
    cin >> temperature;

    float temperatureConverted = convert_to_fahrenheit(temperature);

    printf("%.1f degrees celsius ==> %.1f degrees Fahrenheit\n", temperature, temperatureConverted);
    return 0;
}