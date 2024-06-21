#include <string>
#include "Gerenciador_sistema.hpp"
using namespace std;




class Usuario{
    private:
    string nome;
    string gmail;
    int senha;
    int id;
    int saldo;
    public:
    Usuario(Gerenciador_Sistema sistema,const string& _nome, const string& _gmail, int _id, int _senha,int _saldo);//construtor
    string GetNome();
    int GetSaldo();
    void Setsaldo(int valor);
    void PerdeSaldo(int valor);
    void Trocar_Senha(int senha_atual, int nova_senha);
    void Trocar_Nome(string novo_nome);//nao precisa saber o nome antigo se quer mudar nome

};
