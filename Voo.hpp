#pragma once

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Voo {
private:
    string origem;
    string destino;
    int horas;
    int minutos;
    int numAssentos;
    int preco;
    int idVoo;
    vector<bool> assentos;

public:
    // Construtor com validações
    Voo(const string& _origem, const string& _destino, int _horas, int _minutos, int _numAssentos, const vector<bool>& _assentos, int _preco, int _idVoo)
        : origem(_origem), destino(_destino), horas(_horas), minutos(_minutos), numAssentos(_numAssentos), preco(_preco), idVoo(_idVoo), assentos(_assentos) {
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

    // Métodos 'get'
    int GetHoras() const {
        return horas;
    }

    int GetMinutos() const {
        return minutos;
    }

    int GetPreco() const {
        return preco;
    }

    int GetIdVoo() const {
        return idVoo;
    }

    const string& GetOrigem() const {
        return origem;
    }

    const string& GetDestino() const {
        return destino;
    }

    int GetNumAssentos() const {
        return numAssentos;
    }

    const vector<bool>& GetAssentos() const {
        return assentos;
    }

    // Métodos 'set' com validações
    void SetHoras(int _horas) {
        if (_horas < 0 || _horas > 23) {
            throw invalid_argument("Horas devem estar entre 0 e 23");
        }
        horas = _horas;
    }

    void SetMinutos(int _minutos) {
        if (_minutos < 0 || _minutos > 59) {
            throw invalid_argument("Minutos devem estar entre 0 e 59");
        }
        minutos = _minutos;
    }

    void SetPreco(int _preco) {
        if (_preco < 0) {
            throw invalid_argument("Preço deve ser não-negativo");
        }
        preco = _preco;
    }

    void SetOrigem(const string& _origem) {
        origem = _origem;
    }

    void SetDestino(const string& _destino) {
        destino = _destino;
    }

    void SetAssentos(const vector<bool>& _assentos) {
        if (_assentos.size() != static_cast<size_t>(numAssentos)) {
            throw invalid_argument("Tamanho do vetor de assentos deve ser igual ao número de assentos");
        }
        assentos = _assentos;
    }

    // Método para verificar se há assentos disponíveis
    bool ChecarAssentos() const {
        for (bool assento : assentos) {
            if (!assento) {
                return true;
            }
        }
        return false;
    }

    // Método para exibir os dados do voo
    void ExibirVoo() const {
        cout << "Origem: " << origem << endl;
        cout << "Destino: " << destino << endl;
        cout << "Horário: " << horas << ":" << minutos << endl;
        cout << "Número de Assentos: " << numAssentos << endl;
        cout << "Preço: " << preco << endl;
        cout << "ID do Voo: " << idVoo << endl;
    }
};
