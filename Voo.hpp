#include <string>
#include <vector>
//problemas com nome//função nao chamando estao relacionados a problemas de include
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
    Voo(const string& _origem,const string& _destino,int _horas,int _minutos,int _num_assentos,vector<bool>_assentos,int _preço);
    int GetHoras();
    int GetMinutos();
    int GetPreço();
    bool Checar_assentos();
};
