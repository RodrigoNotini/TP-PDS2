#include <iostream>
#include <string>
#include <limits>
#include "Usuario.hpp"
#include "Voo.hpp"
#include "Gerenciador_sistema.hpp"
#include "Pagamento.hpp"
#include "Servico_consumidor.hpp"

using namespace std;

void cadastrarUsuario(Gerenciador_Sistema& sistema) {
    string nome, gmail;
    int id, senha, saldo;

    cout << "Digite seu nome: ";
    getline(cin, nome);
    cout << "Digite seu email: ";
    getline(cin, gmail);
    cout << "Digite o ID do usuário (apenas numeros): ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite a senha (em números) do usuário: ";
    cin >> senha;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite o saldo do usuário: ";
    cin >> saldo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Usuario novoUsuario(nome, gmail, id, senha, saldo);
    sistema.adicionar_usuario(novoUsuario);
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
    for (auto &usuario : sistema.GetUsuarios()) {
        if (usuario.GetId() == id) {
            usuario.Trocar_Senha(senha_atual, nova_senha);
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
    for (auto &usuario : sistema.GetUsuarios()) {
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
}

void adicionarAvaliacao(Servico_Consumidor& servico) {
    int idUsuario, nota;
    string comentario;

    cout << "Digite o ID do usuário: ";
    cin >> idUsuario;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite o comentário: ";
    getline(cin, comentario);
    cout << "Digite a nota (1 a 5): ";
    cin >> nota;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    servico.AdicionarAvaliacao(idUsuario, comentario, nota);
}

void mostrarAvaliacoes(const Servico_Consumidor& servico) {
    servico.MostrarAvaliacoes();
}

void calcularMediaNotas(const Servico_Consumidor& servico) {
    double media = servico.CalcularMediaNotas();
    cout << "A média das notas é: " << media << endl;
}

void removerUsuario(Gerenciador_Sistema& sistema) {
    string nome_remov;
    cout << "Digite o nome do usuário a ser removido: ";
    getline(cin, nome_remov);

    sistema.remover_usuario(nome_remov);
}

void removerPagamento(Gerenciador_Sistema& sistema) {
    int id;
    cout << "Digite o ID do pagamento a ser removido: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    sistema.remover_pagamento(id);
}

void mostrarVoos(const Gerenciador_Sistema& sistema) {
    cout << "Segue os voos disponíveis:" << endl;
    const auto& voos = sistema.getVoos();
    for (const auto& voo : voos) {
        voo.ExibirVoo();
        cout << endl; // Adiciona uma linha em branco entre os voos
    }
}

void comprarVoo(Gerenciador_Sistema& sistema) {
    cout << "Guarde o id do voo que você tem interesse" << endl;
    mostrarVoos(sistema);

    cout << "Insira seu Id de usuário: ";
    int id_usuario, id_voo;
    cin >> id_usuario;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Insira o id do voo desejado: ";
    cin >> id_voo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Encontrar o usuário pelo ID
    Usuario* usuario = nullptr;
    for (auto& u : sistema.GetUsuarios()) {
        if (u.GetId() == id_usuario) {
            usuario = &u;
            break;
        }
    }

    if (!usuario) {
        cout << "Usuário não encontrado." << endl;
        return;
    }

    // Encontrar o voo pelo ID
    Voo* voo = nullptr;
    for (auto& v : const_cast<vector<Voo>&>(sistema.getVoos())) {
        if (v.GetIdVoo() == id_voo) {
            voo = &v;
            break;
        }
    }

    if (!voo) {
        cout << "Voo não encontrado." << endl;
        return;
    }

    // Realizar pagamento e atualizar sistema
    Pagamento pagamento(false, "", 0, 0); // Inicialização padrão
    pagamento.Comprar_Passagem(usuario, voo, "Cartão de Crédito");
    sistema.adicionar_pagamento(pagamento);
}


int main() {
    string operacao;
    Gerenciador_Sistema sistema;
    sistema.criarVoosDeTeste();
    Servico_Consumidor servicoConsumidor;

    while (true) {
        cout << "Bem vindo ao Sistema de Reserva de Passagens Aéreas, qual operação deseja realizar?" << endl;
        cout << "Digite a operação desejada: (cadastrar, trocar senha, trocar nome, mostrar horarios, comprar, adicionar avaliacao, mostrar voos, mostrar avaliacoes, calcular media, remover usuario, remover pagamento) ou sair quando já tiver feito as operações necessárias" << endl;
        getline(cin, operacao);

        if (operacao == "cadastrar") {
            cadastrarUsuario(sistema);
        } else if (operacao == "trocar senha") {
            trocarSenha(sistema);
        } else if (operacao == "trocar nome") {
            trocarNome(sistema);
        } else if (operacao == "mostrar horarios") {
            cout << "Segue os horários dos voos disponíveis:" << endl;
            sistema.MostrarHorarios();
        } else if (operacao == "comprar") {
            comprarVoo(sistema);
        } else if (operacao == "adicionar avaliacao") {
            adicionarAvaliacao(servicoConsumidor);
        } else if (operacao == "mostrar avaliacoes") {
            mostrarAvaliacoes(servicoConsumidor);
        } else if (operacao == "calcular media") {
            calcularMediaNotas(servicoConsumidor);
        } else if (operacao == "remover usuario") {
            removerUsuario(sistema);
        } else if (operacao == "remover pagamento") {
            removerPagamento(sistema);
        } else if (operacao == "mostrar voos") {
            mostrarVoos(sistema);
        } else if (operacao == "sair") {
            break;
        } else {
            cout << "Operação inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
