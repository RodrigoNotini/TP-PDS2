#ifndef PAGAMENTO_HPP
#define PAGAMENTO_HPP

#include <string>
#include "Usuario.hpp"
#include"Voo.hpp"

using namespace std;

class Pagamento {
private:
    bool sit_pagamento;
    string forma_pagamento;
    int id_pagamento;
    int preco_pagamento;

public:
    Pagamento(bool _sit_pagamento, const string& _forma_pagamento, int _id_pagamento, int _preco_pagamento);
    int GetPreco_Pagamento();
    int GetId();
    void Comprar_Passagem(Usuario* cliente, Voo* voo_desejado, string _forma_pagamento);
    
};

#endif // PAGAMENTO_HPP
