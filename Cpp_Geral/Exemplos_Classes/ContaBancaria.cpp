#include<bits/stdc++.h>

using namespace std;
#define ANY_ERROR false

class BankAccount{
    // atributos: número, titular, saldo
    // métodos: depositar, sacar, exibir extrato
    private:
    string sHolder, sNumber;
    double dBalance;
    map<string, double> mStatement;

    public:
    BankAccount(string p_sHolder){
        this->sHolder = p_sHolder;
        
        // Generate account number
        this->sNumber = GenerateAccountNumber();
        dBalance = 0.0;
    }

    private:
    string GenerateAccountNumber(){
        srand(time(0));
        string sGeneratedNumber = "";
        
        for(int i = 0; i <= 11; i++){
            int iRandomNumber = rand() % 10; // Generate random number between 0-9
            sGeneratedNumber += i == 10 ? '-' : ('0' + iRandomNumber);
        }

        StatementRegister("Accont: "+ sGeneratedNumber + " created", 0.0);

        return sGeneratedNumber;
    }

    void StatementRegister(string p_sDescription, double p_dAmount){
        string sFinalDescription = "";

        // Register timestamp
        time_t tTimestamp;
        time(&tTimestamp);
        // Convert to string
        string sTime = ctime(&tTimestamp);
        sTime[sTime.size()-1] = '\0'; // Fix annoying bug with \n on the end
        
        // Final adjustments
        sFinalDescription += "==========================\n|";
        sFinalDescription += sTime + (string)"|\n";
        sFinalDescription += "Desc.: " + p_sDescription + "\n";
        sFinalDescription += "Value Moved: " + to_string(p_dAmount) + "\n";
        sFinalDescription += "==========================\n";

        // Save to statement
        this->mStatement.insert({sFinalDescription, p_dAmount});

        //cout << sFinalDescription << endl;
    }

    public:
    int Deposit(double p_dAmount){
        if(ANY_ERROR){
            cout << "ERROR: SOMETHING WENT WRONG" << endl;
            StatementRegister("Attempt to deposit: "+ to_string(p_dAmount) + " but something went wrong, operation canceled", p_dAmount);
            return 1;
        }

        this->dBalance += p_dAmount;
        StatementRegister("Deposit: "+ to_string(p_dAmount), p_dAmount);
        return 0;
    }

    int Withdraw(double p_dAmount){
        if(p_dAmount > this->dBalance){
            cout << "ERROR: Insufficient balance" << endl;
            StatementRegister("Attempt to withdraw: "+ to_string(p_dAmount) + " | Insufficient balance", p_dAmount);
            return 1;
        }

        // Creditar do saldo
        this->dBalance -= p_dAmount;
        // Comunicar máquina para entregar o dinheiro ao cliente
        // Se ocorreu tudo bem, return 0, se não, cancela a operação e devolve o saldo
        if(ANY_ERROR){
            this->dBalance += p_dAmount;
            cout << "ERROR: SOMETHING WENT WRONG" << endl << "Operation canceled" << endl;
            StatementRegister("Attempt to withdraw: "+ to_string(p_dAmount) + " | Something went wrong, operation canceled", p_dAmount);
            return 1;
        }

        StatementRegister("Withdraw: "+ to_string(p_dAmount), p_dAmount);
        return 0;
    }

    void ShowStatement(){
        cout << "| Account: " << this->sNumber << " | " << this->sHolder << " |" << endl;
        cout << "| Balance: " << this->dBalance << endl;
        cout << "| Statement |" << endl;
        for(auto i : this->mStatement){
            cout << i.first << endl;
        }
    }

};


int main(){

    BankAccount c_Conta1("Esquilo");
    c_Conta1.Deposit(1000.0);
    c_Conta1.Withdraw(2000.0);
    c_Conta1.Withdraw(900.0);
    c_Conta1.ShowStatement();

    return 0;
}