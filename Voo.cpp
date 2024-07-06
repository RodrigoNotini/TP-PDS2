#include "Voo.hpp"
#include <vector>
#include <string>
using namespace std;

// Construtor
Voo::Voo(const string& _origem, const string& _destino, int _horas, int _minutos, int _num_assentos, vector<bool> _assentos, int _preco, int _id_voo)
    : origem(_origem), destino(_destino), horas(_horas), minutos(_minutos), num_assentos(_num_assentos), assentos(_assentos), preco(_preco), id_voo(_id_voo) {}

// Retorna o horário em horas do voo
int Voo::GetHoras() const {
    return horas;
}

// Retorna o horário em minutos do voo
int Voo::GetMinutos() const {
    return minutos;
}

// Retorna o preço do voo
int Voo::GetPreco() const {
    return preco;
}

// Retorna o ID do voo
int Voo::GetId_Voo() const {
    return id_voo;
}

// Função para checar a disponibilidade de assentos
bool Voo::Checar_assentos() const {
    for (bool assento : assentos) {
        if (!assento) {
            return false;  // Retorna falso se encontrar um assento disponível
        }
    }
    return true;  // Retorna verdadeiro se todos os assentos estiverem ocupados
}
