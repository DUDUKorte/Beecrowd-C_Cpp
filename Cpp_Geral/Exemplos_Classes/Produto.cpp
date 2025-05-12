#include <bits/stdc++.h>

using namespace std;

class Produto{
    // atributos: nome, preço, quantidade em estoque
    // métodos: vender, repor estoque, exibir dados
    private:
    string sName; // s = string
    float fPrice; // f = float
    int iQuantity, iMaxQuantity; // i = int

    public:
    Produto(string p_sName, float p_fPrice, int p_iQuantity){ // p_ = parâmetro/parameter (pra diferenciar do que não é parâmetro)
        this->sName = p_sName;
        this->fPrice = p_fPrice;
        this->iQuantity = p_iQuantity;
        this->iMaxQuantity = this->iQuantity;
    }

    int SellProduct(int p_iQuantity){
        if(p_iQuantity > this->iQuantity){
            cout << "Not enough stock" << endl << "Attempt to buy: " << p_iQuantity << endl << "Avaible: " << this->iQuantity << endl;
            return 1;
        }

        this->iQuantity -= p_iQuantity;
        return 0; // 0 -- success | 1 -- fail
    }

    int RefillStock(){
        if(this->iQuantity == this->iMaxQuantity){
            cout << "Stock already refilled" << endl;
            return this->iQuantity;
        }

        this->iQuantity = this->iMaxQuantity;
        cout << "Stock refilled" << endl;
        return this->iQuantity;
    }

    void ShowStatus(){
        map<string, float> status = {{"Price", this->fPrice}, {"Quantity", this->iQuantity}, {"MaxQuantity", this->iMaxQuantity}};
        cout << "Prduct: " << this->sName << endl;
        for(auto i : status){
            cout << i.first << ": " << i.second << endl;
        }
        cout << endl;
    }

};


int main(){
    Produto c_Caneta("Bic", 1.50, 12);
    c_Caneta.SellProduct(3);
    c_Caneta.ShowStatus();
    c_Caneta.SellProduct(3);
    c_Caneta.SellProduct(3);
    c_Caneta.ShowStatus();
    c_Caneta.SellProduct(4);
    cout << endl;
    c_Caneta.RefillStock();
    cout << endl;
    c_Caneta.ShowStatus();
    c_Caneta.RefillStock();

    return 0;
}