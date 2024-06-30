#include <iostream>
#include <string>
#include <limits>
#include "Usuario.hpp"
#include "Voo.hpp"
#include "Gerenciador_sistema.hpp"
#include "Pagamento.hpp"

using namespace std;

int main() {
    // Setar os voos disponíveis
    string operacao;
    Gerenciador_Sistema sistema;
    sistema.criarVoosDeTeste();

    do {
        cout << "Bem vindo ao Sistema de Reserva de Passagens Aéreas, qual operação deseja realizar?" << endl;
        cout << "Digite a operação desejada: (cadastrar, trocar senha, trocar nome, mostrar horarios, comprar) ou sair quando já tiver feito as operações necessárias" << endl;
        getline(cin, operacao);

        if (operacao == "cadastrar") {
            string nome, gmail;
            int id, senha, saldo;

            // Solicitar informações ao usuário
            cout << "Digite seu nome: ";
            getline(cin, nome);
            cout << "Digite seu email: ";
            getline(cin, gmail);
            cout << "Digite o ID do usuário: ";
            cin >> id;
            cin.ignore(); // Limpar o buffer de entrada
            cout << "Digite a senha (em números) do usuário: ";
            cin >> senha;
            cin.ignore(); // Limpar o buffer de entrada
            cout << "Digite o saldo do usuário: ";
            cin >> saldo;
            cin.ignore(); // Limpar o buffer de entrada

            // Criar instância de Usuario
            Usuario novoUsuario(nome, gmail, id, senha, saldo);

            // Adicionar o usuário ao sistema
            sistema.adicionar_usuario(novoUsuario);

            cout << "Usuário cadastrado com sucesso!" << endl;

        } else if (operacao == "trocar senha") {
            int id, senha_atual, nova_senha;

            // Solicitar informações ao usuário
            cout << "Digite o ID do usuário: ";
            cin >> id;
            cin.ignore(); // Limpar o buffer de entrada
            cout << "Digite a senha atual: ";
            cin >> senha_atual;
            cin.ignore(); // Limpar o buffer de entrada
            cout << "Digite a nova senha: ";
            cin >> nova_senha;
            cin.ignore(); // Limpar o buffer de entrada

            // Encontrar o usuário pelo ID
            bool usuario_encontrado = false;
            for (auto& usuario : sistema.GetUsuarios()) {
                if (usuario.GetId() == id) {
                    usuario.Trocar_Senha(senha_atual, nova_senha);
                    usuario_encontrado = true;
                    break;
                }
            }
            if (!usuario_encontrado) {
                cout << "Usuário não encontrado." << endl;
            }

        } else if (operacao == "trocar nome") {
            int id, senha_atual;
            string novo_nome;

            // Solicitar informações ao usuário
            cout << "Digite o ID do usuário: ";
            cin >> id;
            cin.ignore(); // Limpar o buffer de entrada
            cout << "Digite a senha atual: ";
            cin >> senha_atual;
            cin.ignore(); // Limpar o buffer de entrada
            cout << "Digite o novo nome: ";
            getline(cin, novo_nome);

            // Encontrar o usuário pelo ID
            bool usuario_encontrado = false;
            for (auto& usuario : sistema.GetUsuarios()) {
                if (usuario.GetId() == id) {
                    usuario.Trocar_Nome(novo_nome, senha_atual);
                    cout << "Nome trocado com sucesso!" << endl;
                    usuario_encontrado = true;
                    break;
                }
            }
            if (!usuario_encontrado) {
                cout << "Usuário não encontrado ou senha incorreta." << endl;
            }

        } else if (operacao == "mostrar horarios") {
            cout << "Segue os horários dos voos disponíveis:" << endl;
            sistema.MostrarHorarios();

        } else if (operacao == "comprar") {
            cout << "Guarde o id do voo que você tem interesse" << endl;
            sistema.MostrarIdVoos();
            cout << "Insira seu Id de usuário: ";
            int id, id_voo;
            cin >> id;
            cin.ignore(); // Limpar o buffer de entrada
            cout << "Insira o id do voo desejado: ";
            cin >> id_voo;
            cin.ignore(); // Limpar o buffer de entrada

        } 
    } while (operacao != "sair");

    return 0;
}
