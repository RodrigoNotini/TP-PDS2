#include <vector>
#include<iostream>
#include "Pagamento.hpp"
#include "Voo.hpp"
#include "Usuario.hpp"
class Gerenciador_Sistema{
    private:
    vector<Usuario>Usuarios;
    vector<Pagamento>Pagamentos;
    vector<Voo>Voos;
    public:
    vector<Usuario>& GetUsuarios();
    void adicionar_usuario(Usuario& usuario);
    void remover_usuario(string nome_remov);
    void remover_pagamento(int _id); //apaga pagamentos aprovados do vetor para nao ocupar tanta memória.
    vector<Pagamento>* GetPagamentos();
    string MostrarHorários();//mostra os horários de todos os voos.
    
};
