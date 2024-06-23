#include "Voo.hpp"
using namespace std;
//construtor
Voo::Voo(const string& _origem,const string& _destino,int _horas,int _minutos,int _num_assentos,vector<bool>_assentos,int _preço)
        :origem(_origem),destino(_destino),horas(_horas),minutos(_minutos),num_assentos(_num_assentos),assentos(_assentos),preço(_preço){ 
        }
//retorna o horario em horas do voo
int Voo::GetHoras(){
    return horas;
}
//retorna o horario em minutos do voo
int Voo::GetMinutos(){
    return minutos;
}
//retorna o preço do Voo
int Voo::GetPreço(){
    return preço;
}

//função para checar a disponibilidade de assentos
bool Voo::Checar_assentos() {
        auto it= assentos.begin();
        while (it != assentos.end()) {
            if (*it != 1) {
                return false;  // Retorna falso se encontrar um assento não ocupado
            }
            it++;  // Avança para o próximo assento
        }
        return true;  // Retorna verdadeiro se todos os assentos estiverem ocupados
    };
