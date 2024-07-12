#include "Voo.hpp"
using namespace std;

// Construtor
Voo::Voo(const string& _origem, const string& _destino, int _horas, int _minutos, int _numAssentos, const vector<bool>& _assentos, int _preco, int _idVoo)
    : origem(_origem), destino(_destino), horas(_horas), minutos(_minutos), numAssentos(_numAssentos), assentos(_assentos), preco(_preco), idVoo(_idVoo) {
    if (_horas < 0 || _horas > 23) {
        throw invalid_argument("Horas devem estar entre 0 e 23");
    }
    if (_minutos < 0 || _minutos > 59) {
        throw invalid_argument("Minutos devem estar entre 0 e 59");
    }
    if (_numAssentos < 0) {
        throw invalid_argument("Número de assentos deve ser não-negativo");
    }
    if (_assentos.size() != static_cast<size_t>(_numAssentos)) {
        throw invalid_argument("Tamanho do vetor de assentos deve ser igual ao número de assentos");
    }
    if (_preco < 0) {
        throw invalid_argument("Preço deve ser não-negativo");
    }
}

// Retorna o horário em horas do voo
int Voo::GetHoras() const {
    return horas;
}

// Retorna o horário em minutos do voo
int Voo::GetMinutos() const {
    return minutos;
}

// Retorna o preço do Voo
int Voo::GetPreco() const {
    return preco;
}

// Retorna o ID do voo
int Voo::GetIdVoo() const {
    return idVoo;
}

// Função para checar a disponibilidade de assentos
bool Voo::Checar_assentos() const {
    auto it = assentos.begin();
    while (it != assentos.end()) {
        if (*it != 1) {
            return false;  // Retorna falso se encontrar um assento não ocupado
        }
        it++;  // Avança para o próximo assento
    }
    return true;  // Retorna verdadeiro se todos os assentos estiverem ocupados
}

// Método para exibir os dados do voo
void Voo::ExibirVoo() const {
    cout << "Origem: " << origem << endl;
    cout << "Destino: " << destino << endl;
    cout << "Horário: " << horas << ":" << minutos << endl;
    cout << "Número de Assentos: " << numAssentos << endl;
    cout << "Preço: " << preco << endl;
    cout << "ID do Voo: " << idVoo << endl;
}
