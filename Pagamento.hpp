#include <string>
#include"Voo.hpp"
#include"Usuario.hpp"
using namespace std;
class Pagamento{
    private:
    bool sit_pagamento;
    string forma_pagamento;
    int id_pagamento;
    public:
    Pagamento(bool _sit_pagamento,const string& _forma_pagamento,int _id_pagamento);
    int GetId ();
    void Comprar_Passagem(Usuario* cliente,Voo* voo_desejado,string _forma_pagamento);
    void Reembolso(Usuario* cliente,int _id_pagamento,string _forma_pagamento);
};
