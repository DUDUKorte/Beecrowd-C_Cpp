#include <bits/stdc++.h>

using namespace std;

class Client{
    // atributos: nome, cpf, telefone
    // métodos: mostrar dados, atualizar telefone
    private:
    string sName, sCPF, sCellphone;

    public:
    Client(string p_sName, string p_sCPF, string p_sCellphone){
        this->sName = p_sName;
        this->sCPF = p_sCPF;
        this->sCellphone = p_sCellphone;
    }

    void ShowData(){
        cout << "Name: " << this->sName << endl;
        cout << "CPF: " << this->sCPF << endl;
        cout << "Cellphone: " << this->sCellphone << endl;
    }

    int ChangeCellphone(string p_sNewCellphone){
        if(this->sCellphone == p_sNewCellphone){
            cout << "Same number" << endl;
            return 1;
        }

        this->sCellphone = p_sNewCellphone;
        return 0;
    }

};

int main(){
    Client c_Mattsu("mattsu", "12345678900", "4599912345678");
    c_Mattsu.ShowData();
    cout << endl;
    c_Mattsu.ChangeCellphone("4599912345678");
    cout << endl;
    c_Mattsu.ChangeCellphone("4799978456123");
    c_Mattsu.ShowData();

    return 0;
}