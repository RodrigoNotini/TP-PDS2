#pragma once
#include <string>
#include <iostream>
#include <stdexcept> // Incluindo o cabeçalho para exceções padrão como std::invalid_argument

using namespace std;

class Avaliacao {
private:
    int idUsuario;
    string comentario;
    int nota;

public:
    // Construtor com validações
    Avaliacao(int _idUsuario, const string& _comentario, int _nota);

    // Métodos 'get'
    int GetId() const noexcept;
    string GetComentario() const;
    int GetNota() const noexcept;

    // Métodos 'set' com validações
    void SetId(int _idUsuario) {
        idUsuario = _idUsuario;
    }

    void SetComentario(const string& _comentario) {
        comentario = _comentario;
    }

    void SetNota(int _nota) {
        if (_nota < 0 || _nota > 5) {
            throw invalid_argument("Nota deve estar entre 0 e 5");
        }
        nota = _nota;
    }

    // Método para exibir os dados da avaliação
    void ExibirAvaliacao() const {
        cout << "ID do Usuário: " << idUsuario << endl;
        cout << "Comentário: " << comentario << endl;
        cout << "Nota: " << nota << endl;
    }
};
