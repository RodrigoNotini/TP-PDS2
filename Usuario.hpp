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
    Usuario(const string& _nome, const string& _gmail, int _id, int _senha,int _saldo);//construtor
    string GetNome();
    int GetSaldo();
    void Trocar_Senha(int senha_atual, int nova_senha);
    void Trocar_Nome(string novo_nome);//nao precisa saber o nome antigo se quer mudar nome

};
