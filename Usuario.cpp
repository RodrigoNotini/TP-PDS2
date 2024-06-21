#include <iostream>
#include "usuario.hpp"
using namespace std;
Usuario::Usuario(Gerenciador_Sistema sistema,const string& _nome, const string& _gmail, int _id, int _senha,int _saldo)
     :nome(_nome), gmail(_gmail), id(_id), senha(_senha), saldo(_saldo){
        sistema->adicionar_usuario(*this);
     }
string Usuario::GetNome(){
    return nome;
}
int Usuario::GetSaldo(){
    return saldo;
}
void Usuario::Setsaldo(int valor){
    saldo=saldo+valor;
}
void Usuario::PerdeSaldo(int valor){
    saldo=saldo-valor;
}
void Usuario::Trocar_Senha(int senha_atual, int nova_senha) {
    if (senha_atual == senha) {
    senha = nova_senha;
    cout << "Senha alterada com sucesso!" << endl;
    } else {
    cout << "Você não pode alterar sua senha pois errou sua senha atual." << endl;
    }
}
void Usuario::Trocar_Nome(string novo_nome){
    nome=novo_nome;
} 


