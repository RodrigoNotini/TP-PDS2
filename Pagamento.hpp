#include <string>
#include"Voo.hpp"
#include"Usuario.hpp"
using namespace std;
class Pagamento{
    private:
    bool sit_pagamento;
    string forma_pagamento;
    int id_pagamento;
    int preço_pagamento;
    public:
    Pagamento(Gerenciador_Sistema sistema,bool _sit_pagamento,const string& _forma_pagamento,int _id_pagamento,int _preço_pagamento);
    int GetPreço_Pagamento();
    int GetId ();
    void Comprar_Passagem(Usuario* cliente,Voo* voo_desejado,string _forma_pagamento);
    string Reembolso(Usuario* cliente,Gerenciador_Sistema* sistema,int _id_pagamento,string _forma_pagamento);
};
