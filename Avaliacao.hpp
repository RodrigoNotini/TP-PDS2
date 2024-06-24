#include <string>
using namespace std;
class Avaliacao {
private:
    int idUsuario;
    string comentario;
    int nota;

public:
    Avaliacao(int _idUsuario, const string& _comentario, int _nota);

    int GetId() const;
    string GetComentario() const;
    int GetNota() const;
};
