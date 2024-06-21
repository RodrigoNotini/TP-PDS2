# TP-PDS2
Trabalho Prático PDS2:
Sistema de Reserva de Passagens Aéreas

1-Apresentação do Problema
Nos últimos anos, o setor de aviação tem experimentado um crescimento significativo, tanto em termos de passageiros transportados quanto de novas rotas aéreas inauguradas. Esse crescimento é impulsionado pelo aumento da demanda por viagens, seja a negócios ou lazer, e pela globalização, que tem tornado o mundo cada vez mais interconectado. No entanto, com o aumento do número de passageiros e a complexidade das operações aéreas, surgem diversos desafios relacionados à gestão eficiente de reservas de passagens aéreas.

1-Disponibilidade e Preço: Os passageiros precisam encontrar passagens que sejam compatíveis com seus horários e condição financeira.

2-Complexidade de Escolha: Atualmente, existem muitas companhias aéreas disponíveis, o que torna difícil escolher por qual optar se o sistema de apresentação de passagens for desorganizado.
3-Atualizações e Cancelamentos:A necessidade de gerenciar mudanças e cancelamentos de voos, tanto pelos passageiros quanto pelas companhias aéreas, pode ser um processo complicado e suscetível a erros, resultando em insatisfação do cliente e perda de receita.
4-Serviço ao Cliente: A qualidade do serviço ao cliente é crucial, especialmente quando surgem problemas com reservas, atrasos ou cancelamentos. Um sistema ineficaz pode levar a uma experiência negativa para os passageiros.


2-Visão Geral da Solução
Para enfrentar os desafios mencionados na gestão de reservas de passagens aéreas, propomos o desenvolvimento de um Sistema de Reserva de Passagens Aéreas eficiente e intuitivo. Este sistema será projetado para atender tanto às necessidades dos passageiros quanto das companhias aéreas, proporcionando uma experiência de reserva otimizada e integrada. Abaixo, destacamos a estrutura geral do programa e seu funcionamento básico.
1-Classe Usuário: Nessa classe, serão introduzidos dados sobre o usuário como nome, e-mail, id(número associado ao passageiro no sistema) e senha.
2-Classe Voo:Representa um voo, incluindo detalhes como origem, destino, data, hora, preço e disponibilidade.
3-Classe Reserva: Gerencia as reservas feitas pelos usuários, incluindo dados do voo e status da reserva.
4-Classe Pagamento:Lida com os detalhes de pagamento para as reservas.
5-Classe Serviço_Consumidor : Gerencia as interações de suporte ao cliente.
6-Classe Gerenciador_Sistema: Centraliza a gestão de voos, reservas, pagamentos e suporte ao cliente.



3-Estrutura Do Projeto:A estrutura de diretórios do projeto de Sistema de Reserva de Passagens Aéreas deve ser organizada de maneira clara e lógica para facilitar a navegação, desenvolvimento e manutenção.
SistemaDeReservasAéreas/: 
bin/: Contém os executáveis gerados após a compilação do projeto.
include/: Contém os arquivos de cabeçalho (.h) que definem as interfaces das classes e funções.
src/: Contém os arquivos de implementação (.cpp) que definem a lógica das classes e funções.




4-Instruções de Instalação
Abaixo estão as instruções detalhadas para instalar e configurar o Sistema de Reserva de Passagens Aéreas em um ambiente de desenvolvimento. Estas instruções cobrem as dependências e os requisitos de sistema necessários para compilar e executar o projeto.

Requisitos de Sistema
Sistema Operacional: Linux, macOS ou Windows
Compilador C++: GCC 7.0+ ou Clang 5.0+ (para Linux/macOS), MinGW ou Visual Studio (para Windows)
Bibliotecas Adicionais: Nenhuma específica além das bibliotecas padrão do C++
Passos de Instalação
1-Atualize o Sistema:
Certifique-se de que seu sistema está atualizado.
2-Instale o Compilador C++:
Para sistemas Linux, instale o GCC ou Clang.
Para macOS, você pode usar o Xcode Command Line Tools.
Para Windows, instale o MinGW ou use o Visual Studio com suporte a C++.
3-Clone o Repositório do Projeto:
Clone o repositório do projeto para o seu ambiente local.
git clone https://github.com/seu-usuario/AirlineReservationSystem.git
cd AirlineReservationSystem
4-Compilação Manual:
Compile os arquivos fonte e gere o executável. Você pode usar um único comando g++ para compilar todos os arquivos.
g++ -I include/ src/*.cpp -o bin/airline_reservation_system
5-Executar o Sistema:
Após a compilação bem-sucedida, execute o sistema.
./bin/airline_reservation_system
6-Compilação e Execução de Testes:
Compile e execute os testes individualmente ou todos de uma vez. Aqui está um exemplo de como compilar e executar um teste.
g++ -I include/ tests/UserTest.cpp src/User.cpp -o bin/UserTest
./bin/UserTest



5-Instruções de uso:
