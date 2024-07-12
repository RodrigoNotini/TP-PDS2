#ifndef VOO_HPP
#define VOO_HPP

#include <iostream>
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
    Voo(const string& _origem, const string& _destino, int _horas, int _minutos, int _numAssentos, const vector<bool>& _assentos, int _preco, int _idVoo);

    // Métodos 'get'
    int GetHoras() const;
    int GetMinutos() const;
    int GetPreco() const;
    int GetIdVoo() const;
    const string& GetOrigem() const;
    const string& GetDestino() const;
    int GetNumAssentos() const;
    const vector<bool>& GetAssentos() const;

    // Métodos 'set' com validações
    void SetHoras(int _horas);
    void SetMinutos(int _minutos);
    void SetPreco(int _preco);
    void SetOrigem(const string& _origem);
    void SetDestino(const string& _destino);
    void SetAssentos(const vector<bool>& _assentos);

    // Método para verificar se há assentos disponíveis
    bool Checar_assentos() const;

    // Método para exibir os dados do voo
    void ExibirVoo() const;
};

#endif
