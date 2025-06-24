#include <bits/stdc++.h>

using namespace std;

class CSite{
    public:
    string sAddress;

    CSite(){}

    CSite(string address){
        sAddress = address;
    }

    string getAddress(){
        return sAddress;
    }

};

class CHistorico{
    private:
    deque<CSite> dPrivDeque;
    CSite siteAtual;
    int indexSiteAtual;

    public:
    CHistorico(){

    }

    void visitarSite(CSite siteNovo){
        dPrivDeque.push_front(siteNovo);
        siteAtual = dPrivDeque.at(0);
        indexSiteAtual = 0;
    }

    void voltar(){
        if(indexSiteAtual >= dPrivDeque.size() - 1) { return; }
        
        siteAtual = dPrivDeque.at(++indexSiteAtual);
        showSiteAtual();
    }

    void avancar(){
        if(indexSiteAtual <= 0) { return; }

        siteAtual = dPrivDeque.at(--indexSiteAtual);
        showSiteAtual();
    }

    void limparHistorico(){
        dPrivDeque.clear();
    }

    void showSiteAtual(){
        cout << "Site Atual: ";
        cout << siteAtual.getAddress() << endl;
    }

};

int main(){

    CSite Youtube("youtube.com");
    CSite Facebook("facebook.com");
    CSite Instagram("instagram.com");
    CSite Spotify("spotify.com");
    CSite EsquiloSite("esquilo.com");

    CHistorico meuHistorico;

    meuHistorico.visitarSite(Spotify);
    meuHistorico.visitarSite(Facebook);
    meuHistorico.visitarSite(Instagram);
    meuHistorico.visitarSite(Youtube);

    meuHistorico.voltar();
    meuHistorico.voltar();
    meuHistorico.voltar();
    meuHistorico.voltar();
    meuHistorico.voltar();
    meuHistorico.voltar();
    
    meuHistorico.avancar();
    meuHistorico.avancar();
    meuHistorico.avancar();
    meuHistorico.avancar();
    meuHistorico.avancar();
    meuHistorico.avancar();
    meuHistorico.avancar();
    
    meuHistorico.limparHistorico();
    meuHistorico.visitarSite(EsquiloSite);
    meuHistorico.showSiteAtual();
    meuHistorico.avancar();
    meuHistorico.voltar();

    return 0;
}