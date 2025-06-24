#include<bits/stdc++.h>

using namespace std;

// Lista Simplesmente encadeada
template <typename T>
struct Node {
    T dado;
    Node* next;
    Node(T valor) : dado(valor), next(nullptr) {}
};

template <typename T>
class ListaEncadeada {
    private:
    Node<T>* head;

    public:
    ListaEncadeada() : head(nullptr) {}

    void insertStart(T valor) {
        Node<T>* novo = new Node<T>(valor);
        novo->next = head;
        head = novo;
    }

    void insertEnd(T valor) {
        Node<T>* novo = new Node<T>(valor);
        if (!head) {
            head = novo;
            return;
        }
        Node<T>* atual = head;
        while (atual->next != nullptr) {
            atual = atual->next;
        }
        atual->next = novo;
    }

    void removeStart() {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void removePorNome(const string& nome) {
        Node<T>* atual = head;
        Node<T>* anterior = nullptr;

        while (atual) {
            string tmpName = atual->dado.getNome();
            transform(tmpName.begin(), tmpName.end(), tmpName.begin(), ::tolower);

            if (tmpName == nome) {
                if (anterior == nullptr) {
                    head = atual->next;
                } else {
                    anterior->next = atual->next;
                }
                delete atual;
                return;
            }

            anterior = atual;
            atual = atual->next;
        }
    }

    Node<T>* getHead() const {
        return head;
    }

    T getFirst(){
        return head->dado;
    }

    ~ListaEncadeada() {
        while (head) removeStart();
    }
};
// Fim da lista simplesmente encadeada

class CMusica{
    private:
    string sTitulo;
    string sArtista;

    public:
    CMusica() : sTitulo("NULL"), sArtista("NULL") {}

    CMusica(string titulo, string artista) : sTitulo(titulo), sArtista(artista) {}

    string getTitulo(){ return sTitulo; }

    string getArtista(){ return sArtista; }
};

class CPlaylist{
    private:
    ListaEncadeada<CMusica> lPrivList;
    CMusica tocando;

    public:
    CPlaylist() {}

    void adicionarMusica(CMusica musica){
        lPrivList.insertStart(musica);
        if(tocando.getTitulo() == "NULL"){
            tocando = musica;
        }
    }

    CMusica tocarProxima(){
        CMusica tempMusic = lPrivList.getFirst();
        lPrivList.removeStart();
        tocando = tempMusic;
        return tempMusic;
    }

    void mostrarTocando(){
        cout << "Tocando: " << endl << "Titulo: " << tocando.getTitulo() << " - " << tocando.getArtista() << endl;
    }
};


int main(){

    CPlaylist myPlaylist;
    myPlaylist.adicionarMusica(CMusica("Sad but true", "Metallica"));
    myPlaylist.adicionarMusica(CMusica("Lonely Day", "System of a down"));
    myPlaylist.adicionarMusica(CMusica("Enter Sandman", "Metallica"));

    myPlaylist.mostrarTocando();
    
    myPlaylist.tocarProxima();
    myPlaylist.mostrarTocando();
    myPlaylist.tocarProxima();
    myPlaylist.mostrarTocando();

    return 0;
}