#include <string>
#include <vector>
using namespace std;
class Voo{
    private:
    string origem;
    string destino;
    int num_assentos;
    vector<bool>assentos;
    public:
    Voo(const string& _origem,const string& _destino,int _num_assentos,vector<bool>_assentos);
    bool Checar_assentos();

    



};
