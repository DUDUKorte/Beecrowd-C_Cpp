#include <bits/stdc++.h>

using namespace std;

class CTicket{
    public:
    bool bPrioritario;
    int iNumero;

    CTicket(){}

    CTicket(int numero, bool prioritario){
        iNumero = numero;
        bPrioritario = prioritario;
    }

    bool isPrioritario(){
        return bPrioritario;
    }

    int getNum(){ return iNumero; }

};

class CSistema{
    private:
    deque<CTicket> dPrivDeque;

    public:
    CSistema(){

    }

    void adicionarTicket(CTicket ticket){
        if(ticket.isPrioritario()){
            dPrivDeque.push_front(ticket);
        }else{
            dPrivDeque.push_back(ticket);
        }
    }

    void atenderTicket(){
        CTicket tempTicket = dPrivDeque.front();
        cout << "Ticket atendido: " << tempTicket.getNum() << endl << "Prioritário: " << tempTicket.isPrioritario() << endl;
        dPrivDeque.pop_front();
    }

};

int main(){

    CTicket ticket1(1, true);
    CTicket ticket2(2, false);
    CTicket ticket3(3, true);
    CTicket ticket4(4, false);
    CTicket ticket5(5, true);
    CTicket ticket6(6, true);

    CSistema meuSistema;

    meuSistema.adicionarTicket(ticket1);
    meuSistema.adicionarTicket(ticket2);
    meuSistema.adicionarTicket(ticket3);
    meuSistema.adicionarTicket(ticket4);
    meuSistema.adicionarTicket(ticket5);
    meuSistema.adicionarTicket(ticket6);

    for(int i = 0; i < 6; i++){
        meuSistema.atenderTicket();
    }

    return 0;
}