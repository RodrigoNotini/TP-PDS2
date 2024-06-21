#include <vector>
#include<iostream>
#include "Pagamento.hpp"
#include "Voo.hpp"
class Gerenciador_Sistema{
    private:
    vector<Usuario>Usuarios;
    vector<Pagamento>Pagamentos;
    vector<Voo>Voos;
    public:
    void adicionar_usuario(Usuario& usuario);
    void adicionar_pagamento(Pagamento& pagamento);
    void adicionar_voo(Voo& voo);
    void remover_usuario(string nome_remov);
    void remover_pagamento(int _id); //apaga pagamentos aprovados do vetor para nao ocupar tanta memória.
    vector<Pagamento>* GetPagamentos();
    string MostrarHorários();//mostra os horários de todos os voos.
    
};
