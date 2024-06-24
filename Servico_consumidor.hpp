#include <vector>
#include "Avaliacao.hpp"

class Servico_Consumidor {
private:
    vector<Avaliacao> avaliacoes;

public:
    void AdicionarAvaliacao(int idUsuario, const std::string& comentario, int nota);
    double CalcularMediaNotas() const;
    void MostrarAvaliacoes() const;
};
