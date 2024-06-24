#include <iostream>
#include <string>
#include "Usuario.hpp"
#include"Voo.hpp"
#include"Gerenciador_sistema.hpp"
#include "Pagamento.hpp"
using namespace std;


int main() {
    string operação;
    Gerenciador_Sistema sistema;

    while (true) {
        cout << "Bem vindo ao Sistema de Reserva de Passagens Aéreas, qual operação deseja realizar?" << endl;
        cout << "Digite a operação desejada: (cadastrar, trocar senha, trocar nome) ou sair quando já tiver feito as operações necessárias" << endl;
        cin >> operação;
        

        if (operação == "cadastrar") {
            string nome, gmail;
            int id, senha, saldo;

            // Solicitar informações ao usuário
            cout << "Digite seu nome: ";
            cin >> nome;
            cout << "Digite seu email: ";
            cin >> gmail;
            cout << "Digite o ID do usuário: ";
            cin >> id;
            cout << "Digite a senha do usuário: ";
            cin >> senha;
            cout << "Digite o saldo do usuário: ";
            cin >> saldo;

            // Criar instância de Usuario
            Usuario novoUsuario(nome, gmail, id, senha, saldo);

            // Adicionar o usuário ao sistema
            sistema.adicionar_usuario(novoUsuario);

            cout << "Usuário cadastrado com sucesso!" << endl;

        } else if (operação == "trocar senha") {
            int id, senha_atual, nova_senha;

            // Solicitar informações ao usuário
            cout << "Digite o ID do usuário: ";
            cin >> id;
            cout << "Digite a senha atual: ";
            cin >> senha_atual;
            cout << "Digite a nova senha: ";
            cin >> nova_senha;

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

        } else if (operação == "trocar nome") {
            int id, senha_atual;
            string novo_nome;

            // Solicitar informações ao usuário
            cout << "Digite o ID do usuário: ";
            cin >> id;
            cout << "Digite a senha atual: ";
            cin >> senha_atual;
            cout << "Digite o novo nome: ";
            cin >> novo_nome;

            // Encontrar o usuário pelo ID
            bool usuario_encontrado = false;
            for (auto& usuario : sistema.GetUsuarios()) {
                if (usuario.GetId() == id) {
                    usuario.Trocar_Nome(novo_nome,senha_atual);
                    cout << "Nome trocado com sucesso!" << endl;
                    usuario_encontrado = true;
                    break;
                }
            }

            if (!usuario_encontrado) {
                cout << "Usuário não encontrado ou senha incorreta." << endl;
            }
        } else if (operação == "sair") {
            break;  // Finaliza o loop e sai do programa
        } else {
            cout << "Operação inválida. Tente novamente." << endl;
        }
    return 0;
    }
  
