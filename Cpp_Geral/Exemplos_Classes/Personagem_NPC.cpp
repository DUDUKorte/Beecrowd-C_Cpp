#include <bits/stdc++.h>

using namespace std;
// Atributos: nome, vida, ataque, defesa.
// métodos: atacar, sofrer dano, exibir status

class NPC{
    private:
    string name;
    int max_life, life, attack, protection;
    int alive;

    public:
    NPC(string name, int max_life, int attack,int protection){
        this->name = name;
        this->max_life = max_life;
        this->life = this->max_life;
        this->attack = attack;
        this->protection = protection;
        alive = true;
    }

    int handleDamage(int damage){
        if(this->protection <= 0){
            this->life -= damage;            
            
            if(this->life <= 0){
                this->alive = false;
            }
        }else{
            this->protection -= damage;
        }

        //cout << "Handle Damage: " << this->name << " Damage: " << damage << " life: " << this->life << " Protection: " << this->protection << endl;

        return this->life;
    }

    int handleAttack(NPC *other){
        int other_damage = other->handleDamage(this->attack);
        
        return other_damage;
    }

    void status(){
        // Return map structure with {name, other status}
        map<string, int> status = {{"Life", this->life},
                                    {"Max Life", this->max_life},
                                    {"Attack", this->attack},
                                    {"Protection", this->protection},
                                    {"Alive?", this->alive}};

        cout << "Name: " << this->name << endl;
        for(auto i : status){
            cout << i.first << ": " << i.second << endl;
        }
        cout << endl;
    }


};


int main(){

    NPC npc_1("Esquilo", 10, 3, 5);
    NPC npc_2("Venilso", 10, 5, 3);

    npc_1.status();
    cout << endl;
    npc_2.status();

    cout << endl << "Esquilo attack" << endl;
    npc_1.handleAttack(&npc_2);
    npc_2.status();
    npc_1.status();

    cout << endl<< "Vencilso attack" << endl;
    npc_2.handleAttack(&npc_1);
    npc_1.status();
    npc_2.status();


    return 0;
}