#include <string>
#include <stdexcept> // Incluindo o cabeçalho para exceções padrão como std::invalid_argument
#include "Avaliacao.hpp"

/**
 * @brief Classe que representa uma avaliação de um usuário para um sistema de reserva de passagens aéreas.
 */
Avaliacao::Avaliacao(int _idUsuario, const std::string& _comentario, int _nota)
    : idUsuario(_idUsuario), comentario(_comentario) {
    if (_nota < 0 || _nota > 5) {
        throw std::invalid_argument("Nota deve estar entre 0 e 5.");
    }
    nota = _nota;
}

/**
 * @brief Obtém o ID do usuário que fez a avaliação.
 * @return ID do usuário.
 */
int Avaliacao::GetId() const noexcept {
    return idUsuario;
}

/**
 * @brief Obtém o comentário da avaliação.
 * @return Comentário da avaliação.
 */
std::string Avaliacao::GetComentario() const {
    return comentario;
}

/**
 * @brief Obtém a nota da avaliação.
 * @return Nota da avaliação.
 */
int Avaliacao::GetNota() const noexcept {
    return nota;
}
