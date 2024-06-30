
#ifndef USUARIO_HPP
#define USUARIO_HPP
#include <string>
using namespace std;
class Usuario{
private:
    string nome;
    string gmail;
    int senha;
    int id;
    int saldo;

public:
    Usuario(const string& _nome, const string& _gmail, int _id, int _senha, int _saldo); // construtor
    string GetNome();
    string MostrarSaldo();
    int GetSenha();
    int GetId();
    int GetSaldo();
    void Setsaldo(int valor);
    void PerdeSaldo(int valor);
    void Trocar_Senha(int senha_atual, int nova_senha); // precisa saber a senha antiga
    void Trocar_Nome(std::string novo_nome, int senha); // não precisa saber o nome antigo se quer mudar nome
};

#endif 
