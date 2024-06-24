#include "Avaliacao.hpp"
using namespace std;
Avaliacao::Avaliacao(int _idUsuario, const std::string& _comentario, int _nota)
    : idUsuario(_idUsuario), comentario(_comentario), nota(_nota) {}

int Avaliacao::GetId() const {
    return idUsuario;
}

string Avaliacao::GetComentario() const {
    return comentario;
}

int Avaliacao::GetNota() const {
    return nota;
}
