#include "gerenciador_sistema.hpp"
void Gerenciador_Sistema::remover_usuario(string nome_remov){
    auto it = Usuarios.begin();
        while (it != Usuarios.end()) {
            if (it->GetNome() == nome_remov) {
                it = Usuarios.erase(it);  // Remove o usuário do vetor
                cout << "Usuario '" << nome_remov << "' removido com sucesso." << endl;
                return;  // Retorna após remover o usuário
            } else {
                ++it;
            }
        }
        // Se chegou aqui, significa que o usuário não foi encontrado
        cout << "Usuario '" << nome_remov << "' nao encontrado." << endl;
    }
