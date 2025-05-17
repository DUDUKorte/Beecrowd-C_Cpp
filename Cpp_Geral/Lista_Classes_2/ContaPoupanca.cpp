#include<bits/stdc++.h>
using namespace std;

class ContaPoupanca{
    static int iTaxaDeJurosAnual;
    private:
    double dSaldoDaPoupanca;

    public:
    static void ModifiqueTaxaDeJuros(int iNewTaxaDeJuros){
        iTaxaDeJurosAnual = iNewTaxaDeJuros;
    }

    static void CacularRendimentoMensal(ContaPoupanca *conta){
        conta->dSaldoDaPoupanca += conta->dSaldoDaPoupanca * iTaxaDeJurosAnual / 12.0;
    }

    void SetDSaldoPoupanca(double newSaldo){
        this->dSaldoDaPoupanca = newSaldo;
    }

    double GetSaldoPoupanca(){
        return dSaldoDaPoupanca;
    }
};

int ContaPoupanca::iTaxaDeJurosAnual = 0;

int main(){
    ContaPoupanca pessoa1, pessoa2;
    pessoa1.SetDSaldoPoupanca(2000.0);
    pessoa2.SetDSaldoPoupanca(3000.0);

    ContaPoupanca::ModifiqueTaxaDeJuros(6);
    ContaPoupanca::CacularRendimentoMensal(&pessoa1);
    ContaPoupanca::CacularRendimentoMensal(&pessoa2);
    cout << "Saldo pessoa1: " << pessoa1.GetSaldoPoupanca() << endl;
    cout << "Saldo pessoa2: " << pessoa2.GetSaldoPoupanca() << endl;
    
    ContaPoupanca::ModifiqueTaxaDeJuros(8);
    ContaPoupanca::CacularRendimentoMensal(&pessoa1);
    ContaPoupanca::CacularRendimentoMensal(&pessoa2);
    cout << "Saldo pessoa1: " << pessoa1.GetSaldoPoupanca() << endl;
    cout << "Saldo pessoa2: " << pessoa2.GetSaldoPoupanca() << endl;

    return 0;
}