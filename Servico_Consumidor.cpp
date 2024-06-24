#include "Servico_consumidor.hpp"
#include <iostream>

using namespace std;

void Servico_Consumidor::AdicionarAvaliacao(int idUsuario, const string& comentario, int nota) {
    if (nota < 1 || nota > 5) {
        cout << "Nota invalida. Deve ser entre 1 e 5." << endl;
        return;
    }
    Avaliacao novaAvaliacao(idUsuario, comentario, nota);
    avaliacoes.push_back(novaAvaliacao);
    cout << "Avaliacao adicionada com sucesso!" << endl;
}

double Servico_Consumidor::CalcularMediaNotas() const {
    if (avaliacoes.empty()) {
        return 0.0;
    }
    int soma = 0;
    for (const auto& avaliacao : avaliacoes) {
        soma += avaliacao.GetNota();
    }
    return static_cast<double>(soma) / avaliacoes.size();
}

void Servico_Consumidor::MostrarAvaliacoes() const {
    if (avaliacoes.empty()) {
        cout << "Nenhuma avaliacao encontrada." << endl;
        return;
    }
    for (const auto& avaliacao : avaliacoes) {
        cout << "ID Usuario: " << avaliacao.GetId()
             << ", Nota: " << avaliacao.GetNota()
             << ", Comentario: " << avaliacao.GetComentario() << endl;
    }
}
