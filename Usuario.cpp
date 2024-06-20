#include <iostream>
#include "usuario.hpp"
using namespace std;
Usuario::Usuario(const string& _nome, const string& _gmail, int _id, int _senha)
     :nome(_nome), gmail(_gmail), id(_id), senha(_senha){}
string Usuario::GetNome(){
    return nome;
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
