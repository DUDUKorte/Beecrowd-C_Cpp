#include <bits/stdc++.h>

using namespace std;

class CDocumento{
    public:
    string sTitulo;
    int iNumeroDePaginas;
    int iPrioridade;

    CDocumento(){}

    CDocumento(string titulo, int numeroDePaginas, int prioridade) : sTitulo(titulo), iNumeroDePaginas(numeroDePaginas), iPrioridade(prioridade) {}

    string getTitle(){
        return sTitulo;
    }

    int getPages(){
        return iNumeroDePaginas;
    }

    int getPriority(){
        return iPrioridade;
    }

};

template <typename T>
class FilaBanco{
    private:
    T TData;
    queue<T> qPrivQueue;

    public:

    void adicionarDocumento(T doc){
        qPrivQueue.push(doc);
    }

    T imprimirProximo(){
        T tempDoc = qPrivQueue.front();
        qPrivQueue.pop();
        return tempDoc;
    }

    int totalDocsRestantes(){
        return qPrivQueue.size();
    }

    void listarDocumentos(){
        queue<T> tempCopy = qPrivQueue;
        int size = tempCopy.size();
        cout << "=====================================" << endl;
        cout << "Fila de impressão: " << endl << endl;
        for(int i = 0; i < size; i++){
            CDocumento tempDoc = tempCopy.front();
            cout << "Título: " << tempDoc.getTitle() << endl << "Número de páginas: " << tempDoc.getPages() << endl << "Priodidade: " << tempDoc.getPriority() << endl << "================" << endl;
            tempCopy.pop();
        }
        cout << "=====================================" << endl;
    }

};


int main(){

    // Bank queue creation
    FilaBanco<CDocumento> fila1;
    
    // Users creation
    CDocumento documento1("Titulo1", 10, 0);
    CDocumento documento2("Titulo2", 15, 3);
    CDocumento documento3("Titulo3", 4, 2);
    CDocumento documento4("Titulo4", 20, 1);
    
    fila1.adicionarDocumento(documento2);
    fila1.adicionarDocumento(documento3);
    fila1.adicionarDocumento(documento1);
    fila1.adicionarDocumento(documento4);

    fila1.listarDocumentos();

    int size = fila1.totalDocsRestantes();
    for(int i = 0; i < size; i++){
        CDocumento tempDoc = fila1.imprimirProximo();
        cout << "Imprimindo: " << endl << "Título: " << tempDoc.getTitle() << endl << "Páginas: " << tempDoc.getPages() << endl << "================" << endl;
    }

    return 0;
}