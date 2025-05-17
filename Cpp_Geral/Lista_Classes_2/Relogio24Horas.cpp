#include <bits/stdc++.h>

using namespace std;

class Relogio24H{
    private:
    int iHora;
    int iMinuto;
    int iSegundo;

    public:
    Relogio24H() : iHora(0), iMinuto(0), iSegundo(0) {}

    void ImprimeHora(){
        cout << setfill('0')
        << setw(2) << iHora << ":"
        << setw(2) << iMinuto << ":"
        << setw(2) << iSegundo << endl;
    }

    void IncrementaSegundo(){
        iSegundo++;
        if(iSegundo >= 60){
            iSegundo = 0;
            IncrementaMinuto();
        }
    }

    void IncrementaHora(){
        iHora++;
        if(iHora >= 24){
            iHora = 0;
        }
    }

    void IncrementaMinuto(){
        iMinuto++;
        if(iMinuto >= 60){
            iMinuto = 0;
            IncrementaHora();
        }
    }

    void SetHora(int p_hora){
        if(!(p_hora>=0 && p_hora<=23)){throw invalid_argument("VALOR INVÁLIDO");}
        iHora = p_hora;
    }

    void SetMinuto(int p_minuto){
        if(!(p_minuto>=0 && p_minuto<=59)){throw invalid_argument("VALOR INVÁLIDO");}
        iMinuto = p_minuto;
    }

    void SetSegundo(int p_segundo){
        if(!(p_segundo>=0 && p_segundo<=59)){throw invalid_argument("VALOR INVÁLIDO");}
        iSegundo = p_segundo;
    }

    bool operator==(Relogio24H c_Outro){
        return c_Outro.iHora == iHora && c_Outro.iMinuto == iMinuto && c_Outro.iSegundo == iSegundo;
    }

};

int main(){

    Relogio24H relogio1, relogio2;
    relogio1.SetHora(23);
    relogio1.SetMinuto(59);
    relogio1.SetSegundo(59);
    // relogio2 already initialize in 00:00:00
    
    relogio1.IncrementaSegundo();
    relogio1.ImprimeHora();

    cout << "Iguais: " << (relogio1 == relogio2) << endl;

    return 0;
}
