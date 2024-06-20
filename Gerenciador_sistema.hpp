#include <vector>
#include<iostream>
#include "Usuario.hpp"
#include "Pagamento.hpp"
class Gerenciador_Sistema{
    private:
    vector<Usuario>Usuarios;
    vector<Pagamento>Pagamentos;
    public:
    void remover_usuario(string nome_remov);
    void remover_pagamento(int _id); //apaga pagamentos aprovados do vetor para nao ocupar tanta memória
    
};
