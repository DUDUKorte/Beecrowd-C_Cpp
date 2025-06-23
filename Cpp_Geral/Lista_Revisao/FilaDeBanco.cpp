#include <bits/stdc++.h>

using namespace std;

class Cliente{
    public:
    static int iGlobalNum;
    string sName;
    int iMyNum;

    public:

    Cliente(){
        this->sName = "None";
    }

    Cliente(string nome) {
        this->sName = nome;
    }

    int getNumber(){
        return this->iMyNum;
    }

    string getName(){
        return this->sName;
    }

    void pegarSenha(){
        this->iMyNum = iGlobalNum;
        iGlobalNum++;
    }

};

template <typename T>
class FilaBanco{
    private:
    T TData;
    queue<T> qPrivQueue;

    public:

    void entrarNaFila(T cliente){
        cliente.pegarSenha();
        qPrivQueue.push(cliente);
    }

    Cliente atenderCliente(){
        T tempCliente = qPrivQueue.front();
        qPrivQueue.pop();
        return tempCliente;
    }

    int tamanhoFila(){
        return qPrivQueue.size();
    }

    void mostrarFila(){
        queue<T> tempCopy = qPrivQueue;
        int size = tempCopy.size();
        cout << "=====================================" << endl;
        cout << "Fila de espera: " << endl << endl;
        for(int i = 0; i < size; i++){
            Cliente tempClient = tempCopy.front();
            cout << "Nome: " << tempClient.getName() << endl << "Senha: " << tempClient.getNumber() << endl << "================" << endl;
            tempCopy.pop();
        }
        cout << "=====================================" << endl;
    }

};


int Cliente::iGlobalNum = 1;
int main(){

    // Bank queue creation
    FilaBanco<Cliente> fila1;
    
    // Users creation
    Cliente cliente1("esquilo");
    Cliente cliente2("eduardo");
    Cliente cliente3("bonnie");
    Cliente cliente4("gordo");
    
    fila1.entrarNaFila(cliente2);
    fila1.entrarNaFila(cliente3);
    fila1.entrarNaFila(cliente1);
    fila1.entrarNaFila(cliente4);

    fila1.mostrarFila();

    int size = fila1.tamanhoFila();
    for(int i = 0; i < size; i++){
        Cliente tempClient = fila1.atenderCliente();
        cout << "Atendendo: " << endl << "Nome: " << tempClient.getName() << endl << "Senha: " << tempClient.getNumber() << endl << "================" << endl;
    }

    return 0;
}