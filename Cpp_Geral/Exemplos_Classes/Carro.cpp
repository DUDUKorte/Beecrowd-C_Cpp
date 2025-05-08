/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Carro{
    
    private:
        string marca, modelo;
        int ano, velocidade;
    
    public:
        Carro(string marca, string modelo, int ano){
            this->marca = marca;
            this->modelo = modelo;
            this->ano = ano;
            this->velocidade = 0;
        }
        
        void showAttributes(){
            cout << "Marca: " << this->marca << endl << "Modelo: " << this->modelo << endl << "Ano: " << this->ano << endl << "Velocidade: " << this->velocidade << endl;
        }
        
        int accelerate(int acceleration){
            this->velocidade += acceleration;
            return this->velocidade;
        }
        
        int breaks(int breakForce){
            this->velocidade -= breakForce;
            return this->velocidade;
        }
};

int main()
{
    Carro novoCarro("Marca", "Modelo", 123);
    novoCarro.showAttributes();
    int vel = novoCarro.accelerate(5);
    cout << vel << endl;
    vel = novoCarro.breaks(2);
    cout << vel << endl;
    vel = novoCarro.breaks(3);
    cout << vel << endl;
    

    return 0;
}
