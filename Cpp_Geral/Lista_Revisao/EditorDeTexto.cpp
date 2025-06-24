#include <bits/stdc++.h>

using namespace std;

class CGaleria{
    private:
    list<string> lPrivGaleria;
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
    

    return 0;
}