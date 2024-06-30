#include "gerenciador_sistema.hpp"
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>  
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
string Gerenciador_Sistema::MostrarHorarios(){
    for(auto it:Voos){
        cout<<it.GetHoras()<<"h:"<<it.GetMinutos()<<"min"<<endl;
    }
}
void Gerenciador_Sistema::MostrarIdVoos(){
    cout<<"Os horarios de voo disponiveis sao: "<<endl;
    for(auto it:Voos){
        cout<<it.GetId_Voo()<<endl;
    }
}
bool Gerenciador_Sistema::ConfereReembolso(Pagamento* pagamento){
    for(auto it:Pagamentos){
        if (it.GetId()==pagamento->GetId()){
            return true;
        }
    }
}
void Gerenciador_Sistema::adicionar_voo(Voo& voo){
    Voos.push_back(voo);
}

void Gerenciador_Sistema::criarVoosDeTeste() {
    srand(time(0));  // Inicializa a semente do gerador de números aleatórios

    // Voo 1
    vector<bool> assentos1(100, true); // Todos os assentos estão livres
    int id1 = rand();
    Voo voo1("São Paulo", "Rio de Janeiro", 10, 30, 100, assentos1, 300,id1);
    adicionar_voo(voo1);

    // Voo 2
    vector<bool> assentos2(150, true);
    int id2 = rand();
    Voo voo2("Belo Horizonte", "Salvador", 14, 45, 150, assentos2, 400,id2);
    adicionar_voo(voo2);

    // Voo 3
    vector<bool> assentos3(120, true);
    int id3 = rand();
    Voo voo3("Curitiba", "Brasília", 18, 00, 120, assentos3, 350,id3);
    adicionar_voo(voo3);

    // Voo 4
    vector<bool> assentos4(200, true);
    int id4 = rand();
    Voo voo4("Porto Alegre", "Fortaleza", 9, 15, 200, assentos4, 500,id4);
    adicionar_voo(voo4);

    // Voo 5
    vector<bool> assentos5(80, true);
    int id5 = rand();
    Voo voo5("Manaus", "Recife", 7, 50, 80, assentos5, 450,id5);
    adicionar_voo(voo5);

    cout << "Voos de teste criados e adicionados ao sistema." << endl;
}
