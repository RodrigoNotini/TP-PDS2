#include "Pagamento.hpp"
#include"Usuario.hpp"
#include"Voo.hpp"
#include"Gerenciador_sistema.hpp"
#include <iostream>
#include <random>
#include <algorithm>
using namespace std;
Pagamento::Pagamento(Gerenciador_Sistema sistema,bool _sit_pagamento,const string& _forma_pagamento,int _id_pagamento,int _preço_pagamento)
        :sit_pagamento(_sit_pagamento),forma_pagamento(_forma_pagamento),id_pagamento(_id_pagamento),preço_pagamento(_preço_pagamento){
            sistema->adicionar_pagamento(*this);
        } //construtor
int Pagamento::GetPreço_Pagamento(){
    return preço_pagamento; //retorna o preço relativo ao pagamento realizado
}
int Pagamento::GetId(){
    return id_pagamento; //retorna o id do pagamento
}
void Pagamento::Comprar_Passagem(Usuario* cliente,Voo* voo_desejado,string _forma_pagamento){
    if(voo_desejado->Checar_assentos() && voo_desejado->GetPreço()<=cliente->GetSaldo()){  
        random_device rd;    // Obter uma semente não determinística
        mt19937 gen(rd());   // Inicializar o gerador Mersenne Twister com a semente
        uniform_int_distribution<> dis(1, 1000000); // Definir a distribuição
        id_pagamento = dis(gen); // Gerar o ID aleatório
        std::cout << "Pagamento Aprovado. ID do Pagamento: " << id_pagamento << std::endl;
        sit_pagamento=true; //pagamento foi aprovado
        forma_pagamento=_forma_pagamento;//atualiza a forma de pagamento utilizada na compra
        preço_pagamento=voo_desejado->GetPreço();//atualiza o valor utilizado no pagamento, que pode ser utilizado em caso de reembolso
        cliente->PerdeSaldo(voo_desejado->GetPreço());//desconta o valor do pagamento do saldo do cliente
    }
}
string Pagamento::Reembolso(Usuario* cliente,Gerenciador_Sistema* sistema,int _id_pagamento,string _forma_pagamento){
     if (_forma_pagamento == "cartao de credito" || _forma_pagamento == "cartao de debito" || _forma_pagamento == "paypal") {
        vector<Pagamento>* pagamentos = sistema->GetPagamentos();
        // Iterar sobre o vetor de pagamentos
        for (Pagamento& pagamento : *pagamentos) {
            if (pagamento.GetId() == _id_pagamento) {
                // Realizar o reembolso
                cliente->Setsaldo(pagamento.GetPreço_Pagamento());
                cout << "Reembolso realizado para o pagamento com ID: " << _id_pagamento << " através de " << _forma_pagamento << endl;
            }
        }
        // Caso o pagamento não seja encontrado
        cout << "Pagamento com ID: " << _id_pagamento << " não encontrado." << endl;
    } else {
        cout << "Forma de pagamento inválida." << endl;
    }
}
