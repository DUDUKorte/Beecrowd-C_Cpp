#include <bits/stdc++.h>

using namespace std;

class CFoto{
    private:
    string sFileName;

    public:
    CFoto() : sFileName("NULL") {}

    CFoto(string fileName) : sFileName(fileName) {}

    string getFileName(){
        return sFileName;
    }
};

class CGaleria{
    private:
    list<CFoto> lPrivGaleria;
    list<CFoto>::iterator fotoAtual;
    
    public:
    CGaleria() {}

    void adicionarFoto(CFoto foto){
        lPrivGaleria.push_back(foto);
        if(lPrivGaleria.size() == 1){
            fotoAtual = lPrivGaleria.begin();
        }
    }

    void proximaFoto(){
        if(fotoAtual == lPrivGaleria.end() || lPrivGaleria.empty()) { return; }
        
        auto temp = fotoAtual;
        temp++;
        if(temp != lPrivGaleria.end()){
            fotoAtual++;
        }
        
    }

    void fotoAnterior(){
        if(fotoAtual == lPrivGaleria.begin() || lPrivGaleria.empty()) { return; }
        
        auto temp = fotoAtual;
        temp--;
        if(temp != lPrivGaleria.begin()){
            fotoAtual--;
        }
    }

    void mostrarFoto(){
        if(lPrivGaleria.empty()) { return; }
        cout << "Foto: " << fotoAtual->getFileName() << endl;
    }

};

int main(){
    CGaleria myGaleria;
    myGaleria.adicionarFoto(CFoto("foto1.png"));
    myGaleria.adicionarFoto(CFoto("foto2.png"));
    myGaleria.adicionarFoto(CFoto("foto3.png"));

    myGaleria.mostrarFoto();
    myGaleria.proximaFoto();
    myGaleria.mostrarFoto();
    myGaleria.proximaFoto();
    myGaleria.mostrarFoto();
    myGaleria.fotoAnterior();
    myGaleria.mostrarFoto();
    myGaleria.proximaFoto();
    myGaleria.mostrarFoto();
    myGaleria.proximaFoto();
    myGaleria.mostrarFoto();
    myGaleria.proximaFoto();
    myGaleria.mostrarFoto();

    return 0;
}