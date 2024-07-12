#ifndef GERENCIADOR_SISTEMA_HPP
#define GERENCIADOR_SISTEMA_HPP

#include <vector>
#include <iostream>
#include "Pagamento.hpp"
#include "Voo.hpp"
#include "Usuario.hpp"

using namespace std;

class Gerenciador_Sistema {
private:
    vector<Usuario> Usuarios;
    vector<Pagamento> Pagamentos;
    vector<Voo> Voos;
    vector<Voo> voos;

public:
    vector<Usuario>& GetUsuarios();
    void adicionar_usuario(Usuario& usuario);
    void remover_usuario(string nome_remov);
    void remover_pagamento(int _id); // apaga pagamentos aprovados do vetor para nao ocupar tanta memória.
    vector<Pagamento>* GetPagamentos();
    string MostrarHorarios();// mostra os horários de todos os voos.
    void MostrarIdVoos(); 
    bool ConfereReembolso(Pagamento* pagamento);
    void adicionar_voo(Voo& voo);
    void criarVoosDeTeste();
    const vector<Voo>& getVoos() const;
    vector<Voo>& GetVoos();
    void adicionar_pagamento(Pagamento& pagamento);
};

#endif
