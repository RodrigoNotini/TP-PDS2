#include "usuario.hpp"
using namespace std;

// Construtor da classe Usuario
Usuario::Usuario(const std::string& _nome, const std::string& _gmail, int _id, int _senha, int _saldo)
    : nome(_nome), gmail(_gmail), id(_id), senha(_senha), saldo(_saldo) {
}

// Método MostrarSaldo para exibir o saldo do usuário
string Usuario::MostrarSaldo() {
    cout << "Seu saldo é: " << saldo << endl;
}

// Métodos Get para retornar informações do usuário

// Retorna a senha do usuário
int Usuario::GetSenha() {
    return senha;
}

// Retorna o ID do usuário
int Usuario::GetId() {
    return id;
}

// Retorna o nome do usuário
string Usuario::GetNome() {
    return nome;
}

// Retorna o saldo do usuário
int Usuario::GetSaldo() {
    return saldo;
}

// Métodos para modificar o saldo do usuário

// Adiciona um valor ao saldo atual
void Usuario::Setsaldo(int valor) {
    saldo = saldo + valor;
}

// Subtrai um valor do saldo atual
void Usuario::PerdeSaldo(int valor) {
    saldo = saldo - valor;
}

// Método Trocar_Senha para alterar a senha do usuário

// Verifica a senha atual e atualiza para a nova senha se correta
void Usuario::Trocar_Senha(int senha_atual, int nova_senha) {
    if (senha_atual == senha) {
        senha = nova_senha;
        cout << "Senha alterada com sucesso!" << endl;
    } else {
        cout << "Você não pode alterar sua senha pois errou sua senha atual." << endl;
    }
}

// Método Trocar_Nome para alterar o nome do usuário

// Verifica a senha atual e atualiza o nome se correta
void Usuario::Trocar_Nome(string novo_nome, int _senha) {
    if (_senha == senha) {
        nome = novo_nome;
    }
}


