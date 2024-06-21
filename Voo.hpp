#include <string>
#include <vector>
#include "Gerenciador_sistema.hpp"
using namespace std;
class Voo{
    private:
    string origem;
    string destino;
    int horas;
    int minutos;
    int num_assentos;
    int preço;
    vector<bool>assentos;
    public:
    Voo(Gerenciador_Sistema* sistema,const string& _origem,const string& _destino,int _horas,int _minutos,int _num_assentos,vector<bool>_assentos,int _preço);
    int GetPreço();
    bool Checar_assentos();

    



};
