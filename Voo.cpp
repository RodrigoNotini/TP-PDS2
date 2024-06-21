#include "Voo.hpp"
using namespace std;
Voo::Voo(Gerenciador_Sistema* sistema,const string& _origem,const string& _destino,int _horas,int _minutos,int _num_assentos,vector<bool>_assentos,int _preço)
        :origem(_origem),destino(_destino),horas(_horas),minutos(_minutos),num_assentos(_num_assentos),assentos(_assentos),preço(_preço){
            sistema->adicionar_voo(*this);
        }
int Voo::GetPreço(){
    return preço;
}
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
