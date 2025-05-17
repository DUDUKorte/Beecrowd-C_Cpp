/*Crie uma classe chamada Produto que represente itens em um estoque de loja.
Atributos privados:
string nome
int codigo
int quantidade
float preco
Atributo static:
static int totalProdutos; → contador de quantos objetos da classe foram criados.
Requisitos:
Construtor para inicializar todos os atributos.
Métodos:
void entradaEstoque(int qtd) → adiciona itens ao estoque
bool saidaEstoque(int qtd) → remove itens, mas retorna false se não houver estoque suficiente
float calcularValorTotal() → retorna o valor total do estoque do produto (quantidade × preço)
static int getTotalProdutos() → retorna a quantidade total de produtos criados
No programa principal:
Crie três objetos Produto diferentes.
Faça entradas e saídas de estoque em cada um.
Exiba o valor total de cada item em estoque.
Mostre quantos produtos foram criados ao final usando o método getTotalProdutos().
*/

#include <bits/stdc++.h>

using namespace std;

class Produto{
    private:
        string sNome;
        int iCodigo;
        int iQuantidade;
        float fPreco;
        static int siTotalProdutos;
    
    public:

        // Constructor
        Produto(string p_Nome, int p_Codigo, int p_Quantidade, float p_Preco) : 
        sNome(p_Nome), iCodigo(p_Codigo), iQuantidade(p_Quantidade), fPreco(p_Preco) { siTotalProdutos++; }

        // Destructor
        ~Produto(){
            siTotalProdutos--;
        }

        void EntradaEstoque(int p_Quantidade){
            iQuantidade += p_Quantidade;
        }

        bool SaidaEstoque(int p_Quantidade){
            if(iQuantidade < p_Quantidade){
                return false; // Estoque insuficiente
            }
            iQuantidade -= p_Quantidade;
            return true;
        }

        float CalcularValorTotal(){
            return iQuantidade * fPreco;
        }

        static int getTotalProdutos(){
            return siTotalProdutos;
        }

};
    
int Produto::siTotalProdutos = 0;

int main(){
    Produto prod1("Livro", 021, 4, 23.50), prod2("Celular", 34, 2, 250.0), prod3("Notebook", 834, 8, 130.0);
    vector<Produto*> produtos = {&prod1, &prod2, &prod3};
    
    prod1.EntradaEstoque(2);
    prod2.EntradaEstoque(3);
    prod3.EntradaEstoque(5);
    prod1.SaidaEstoque(1);
    prod2.SaidaEstoque(4);
    prod3.SaidaEstoque(6);

    for(int i = 0; i < 3; i++){
        cout << "PRODUTO " << i << ": " << produtos[i]->CalcularValorTotal() << endl;
    }
    
    cout << "Foram feitos " << Produto::getTotalProdutos() << " produtos" << endl;
    
    return 0;
}