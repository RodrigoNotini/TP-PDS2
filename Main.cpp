#include <iostream>
#include <string>
#include <limits>
#include "Usuario.hpp"
#include "Voo.hpp"
#include "Gerenciador_sistema.hpp"
#include "Pagamento.hpp"

using namespace std;

void cadastrarUsuario(Gerenciador_Sistema& sistema) {
    string nome, gmail;
    int id, senha, saldo;

    cout << "Digite seu nome: ";
    getline(cin, nome);
    cout << "Digite seu email: ";
    getline(cin, gmail);
    cout << "Digite o ID do usuário: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite a senha (em números) do usuário: ";
    cin >> senha;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite o saldo do usuário: ";
    cin >> saldo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Usuario novoUsuario(nome, gmail, id, senha, saldo);
    sistema.adicionarUsuario(novoUsuario);
    cout << "Usuário cadastrado com sucesso!" << endl;
}

void trocarSenha(Gerenciador_Sistema& sistema) {
    int id, senha_atual, nova_senha;

    cout << "Digite o ID do usuário: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite a senha atual: ";
    cin >> senha_atual;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite a nova senha: ";
    cin >> nova_senha;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool usuario_encontrado = false;
    for (auto &usuario : sistema.getUsuarios()) {
        if (usuario.getId() == id) {
            usuario.trocarSenha(senha_atual, nova_senha);
            cout << "Senha trocada com sucesso!" << endl;
            usuario_encontrado = true;
            break;
        }
    }

    if (!usuario_encontrado) {
        cout << "Usuário não encontrado." << endl;
    }
}

void trocarNome(Gerenciador_Sistema& sistema) {
    int id, senha_atual;
    string novo_nome;

    cout << "Digite o ID do usuário: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite a senha atual: ";
    cin >> senha_atual;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite o novo nome: ";
    getline(cin, novo_nome);

    bool usuario_encontrado = false;
    for (auto &usuario : sistema.getUsuarios()) {
        if (usuario.getId() == id) {
            usuario.trocarNome(novo_nome, senha_atual);
            cout << "Nome trocado com sucesso!" << endl;
            usuario_encontrado = true;
            break;
        }
    }

    if (!usuario_encontrado) {
        cout << "Usuário não encontrado ou senha incorreta." << endl;
    }
}

void comprarVoo(Gerenciador_Sistema& sistema) {
    cout << "Guarde o id do voo que você tem interesse" << endl;
    sistema.mostrarIdVoos();
    cout << "Insira seu Id de usuário: ";
    int id, id_voo;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Insira o id do voo desejado: ";
    cin >> id_voo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Lógica para processar a compra do voo
}

int main() {
    string operacao;
    Gerenciador_Sistema sistema;
    sistema.criarVoosDeTeste();

    while (true) {
        cout << "Bem vindo ao Sistema de Reserva de Passagens Aéreas, qual operação deseja realizar?" << endl;
        cout << "Digite a operação desejada: (cadastrar, trocar senha, trocar nome, mostrar horários, comprar) ou sair quando já tiver feito as operações necessárias" << endl;
        getline(cin, operacao);

        if (operacao == "cadastrar") {
            cadastrarUsuario(sistema);
        } else if (operacao == "trocar senha") {
            trocarSenha(sistema);
        } else if (operacao == "trocar nome") {
            trocarNome(sistema);
        } else if (operacao == "mostrar horários") {
            cout << "Segue os horários dos voos disponíveis:" << endl;
            sistema.mostrarHorarios();
        } else if (operacao == "comprar") {
            comprarVoo(sistema);
        } else if (operacao == "sair") {
            break;
        } else {
            cout << "Operação inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
