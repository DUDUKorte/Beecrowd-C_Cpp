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

    ~ListaEncadeada() {
        while (head) removeStart();
    }
};
// Fim da lista simplesmente encadeada

class CTarefa {
private:
    string sNome;
    string sDescription;

public:
    CTarefa() {}
    CTarefa(string nome, string description) : sNome(nome), sDescription(description) {}

    string getNome() const { return sNome; }
    string getDesc() const { return sDescription; }
};

class Tarefas {
private:
    ListaEncadeada<CTarefa> lPrivList;

public:
    Tarefas() {}

    void adicionarTarefa(const CTarefa& tarefa) {
        lPrivList.insertStart(tarefa);
    }

    void removerTarefa() {
        listarTarefas();
        cout << "Por favor, insira o nome da tarefa que deseja excluir: ";
        string refName;
        cin >> refName;

        transform(refName.begin(), refName.end(), refName.begin(), ::tolower);
        lPrivList.removePorNome(refName);
    }

    void listarTarefas() {
        Node<CTarefa>* atual = lPrivList.getHead();
        while (atual) {
            cout << "Nome: " << atual->dado.getNome() << endl
                 << "Descrição: " << atual->dado.getDesc() << endl
                 << "=============" << endl;
            atual = atual->next;
        }
    }
};

int main() {
    Tarefas t;

    t.adicionarTarefa(CTarefa("Prova", "Estudar para a prova de C++"));
    t.adicionarTarefa(CTarefa("Trabalho", "Finalizar o projeto da disciplina"));
    t.adicionarTarefa(CTarefa("Jogar", "Zerar aquele jogo que tá pendente"));

    t.listarTarefas();
    
    cout << endl << endl;
    t.removerTarefa();
    cout << "\nTarefas após remoção:\n";
    t.listarTarefas();

    return 0;
}