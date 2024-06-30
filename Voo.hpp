
#ifndef VOO_HPP
#define VOO_HPP

#include <string>
#include <vector>
using namespace std;
class Voo{
private:
    string origem;
    string destino;
    int horas;
    int minutos;
    int num_assentos;
    int preco;
    int id_voo;
    vector<bool> assentos;

public:
    Voo(const string& _origem, const string& _destino, int _horas, int _minutos, int _num_assentos, vector<bool> _assentos, int _preco,int id_voo);
    int GetHoras();
    int GetMinutos();
    int GetPreco();
    int GetId_Voo();
    bool Checar_assentos();
};

#endif
