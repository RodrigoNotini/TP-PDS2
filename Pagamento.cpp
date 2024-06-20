#include "Pagamento.hpp"
#include"Usuario.hpp"
#include"Voo.hpp"
#include <iostream>
#include <random>
using namespace std;
Pagamento::Pagamento(bool _sit_pagamento,const string& _forma_pagamento,int _id_pagamento)
        :sit_pagamento(_sit_pagamento),forma_pagamento(_forma_pagamento),id_pagamento(_id_pagamento){}
int Pagamento::GetId(){
    return id_pagamento;
}
void Pagamento::Comprar_Passagem(Usuario* cliente,Voo* voo_desejado,string _forma_pagamento){
    if(voo_desejado->Checar_assentos() && voo_desejado->GetPreço()<=cliente->GetSaldo()){  
        random_device rd;    // Obter uma semente não determinística
        mt19937 gen(rd());   // Inicializar o gerador Mersenne Twister com a semente
        uniform_int_distribution<> dis(1, 1000000); // Definir a distribuição
        id_pagamento = dis(gen); // Gerar o ID aleatório
        std::cout << "Pagamento Aprovado. ID do Pagamento: " << id_pagamento << std::endl;
        sit_pagamento=true;
        forma_pagamento=_forma_pagamento;
    }
}
void Pagamento::Reembolso(Usuario* cliente,int _id_pagamento,string _forma_pagamento){
    if(_forma_pagamento=="cartao de credito"||"cartao de debito"||"paypal"){
         
}
}
