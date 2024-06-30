#include "Pagamento.hpp"
#include"Usuario.hpp"
#include"Voo.hpp"
#include"Gerenciador_sistema.hpp"
#include <iostream>
#include <random>
#include <algorithm>
using namespace std;
Pagamento::Pagamento(bool _sit_pagamento,const string& _forma_pagamento,int _id_pagamento,int _preco_pagamento)
        :sit_pagamento(_sit_pagamento),forma_pagamento(_forma_pagamento),id_pagamento(_id_pagamento),preco_pagamento(_preco_pagamento){
        } 
int Pagamento::GetPreco_Pagamento(){
    return preco_pagamento; //retorna o preço relativo ao pagamento realizado
}
int Pagamento::GetId(){
    return id_pagamento; //retorna o id do pagamento
}
//função que realiza um pagamento para comprar uma passagem e atualiza algumas variáveis quando isso acontece
void Pagamento::Comprar_Passagem(Usuario* cliente,Voo* voo_desejado,string _forma_pagamento){
    if(voo_desejado->Checar_assentos() && voo_desejado->GetPreco()<=cliente->GetSaldo()){  
        random_device rd;    // Obter uma semente não determinística
        mt19937 gen(rd());   // Inicializar o gerador Mersenne Twister com a semente
        uniform_int_distribution<> dis(1, 1000000); // Definir a distribuição
        id_pagamento = dis(gen); // Gerar o ID aleatório
        cout << "Pagamento Aprovado. ID do Pagamento: " << id_pagamento << std::endl;
        sit_pagamento=true; //pagamento foi aprovado
        forma_pagamento=_forma_pagamento;//atualiza a forma de pagamento utilizada na compra
        preco_pagamento=voo_desejado->GetPreco();//atualiza o valor utilizado no pagamento, que pode ser utilizado em caso de reembolso
        cliente->PerdeSaldo(voo_desejado->GetPreco());//desconta o valor do pagamento do saldo do cliente
    }
}

