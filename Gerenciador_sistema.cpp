#include "gerenciador_sistema.hpp"
#include <algorithm>
#include <vector>
// Retorna uma referência para o vetor de usuários
vector<Usuario>& Gerenciador_Sistema::GetUsuarios() {
    return Usuarios;
}

// Adiciona um usuário ao vetor de usuários
void Gerenciador_Sistema::adicionar_usuario(Usuario& usuario){
    Usuarios.push_back(usuario);
}

// Remove um usuário pelo nome
void Gerenciador_Sistema::remover_usuario(string nome_remov){
    auto it = Usuarios.begin();
    while (it != Usuarios.end()) {
        if (it->GetNome() == nome_remov) {
            it = Usuarios.erase(it);  // Remove o usuário do vetor
            cout << "Usuario '" << nome_remov << "' removido com sucesso." << endl;
            return;  // Retorna após remover o usuário
        } else {
            ++it;
        }
    }
    // Se chegou aqui, significa que o usuário não foi encontrado
    cout << "Usuario '" << nome_remov << "' nao encontrado." << endl;
}

// Remove um pagamento pelo ID
void Gerenciador_Sistema::remover_pagamento(int _id){
    auto it = remove_if(Pagamentos.begin(), Pagamentos.end(),
    [_id](Pagamento& pagamento) {
        return pagamento.GetId() == _id;
    });

    if (it != Pagamentos.end()) {
        Pagamentos.erase(it, Pagamentos.end());
        std::cout << "Pagamento com ID " << _id << " removido com sucesso." << std::endl;
    } else {
        std::cout << "Pagamento com ID " << _id << " não encontrado." << std::endl;
    }
}

// Retorna um ponteiro para o vetor de pagamentos
vector<Pagamento>* Gerenciador_Sistema::GetPagamentos() {
    return &Pagamentos;
}

// Mostra os horários dos voos disponíveis
string Gerenciador_Sistema::MostrarHorários(){
    for(auto it:Voos){
        cout<<it.GetHoras()<<"horas"<<it.GetMinutos()<<"minutos"<<endl;
    }
}
