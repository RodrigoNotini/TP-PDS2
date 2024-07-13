# TP-PDS2
Trabalho Prático PDS2:
Sistema de Reserva de Passagens Aéreas. 

1. Apresentação do Problema:
Nos últimos anos, o setor de aviação tem experimentado um crescimento significativo, tanto em termos de passageiros transportados quanto de novas rotas aéreas inauguradas. Esse crescimento é impulsionado pelo aumento da demanda por viagens, seja a negócios ou lazer, e pela globalização, que tem tornado o mundo cada vez mais interconectado. No entanto, com o aumento do número de passageiros e a complexidade das operações aéreas, surgem diversos desafios relacionados à gestão eficiente de reservas de passagens aéreas.

Desafios:
Disponibilidade e Preço: Os passageiros precisam encontrar passagens que sejam compatíveis com seus horários e condição financeira.
Complexidade de Escolha: Atualmente, existem muitas companhias aéreas disponíveis, o que torna difícil escolher por qual optar se o sistema de apresentação de passagens for desorganizado.
Atualizações e Cancelamentos: A necessidade de gerenciar mudanças e cancelamentos de voos, tanto pelos passageiros quanto pelas companhias aéreas, pode ser um processo complicado e suscetível a erros, resultando em insatisfação do cliente e perda de receita.
Serviço ao Cliente: A qualidade do serviço ao cliente é crucial, especialmente quando surgem problemas com reservas, atrasos ou cancelamentos. Um sistema ineficaz pode levar a uma experiência negativa para os passageiros.

2. Visão Geral da Solução:
Para enfrentar os desafios mencionados na gestão de reservas de passagens aéreas, propomos o desenvolvimento de um Sistema de Reserva de Passagens Aéreas eficiente e intuitivo. Este sistema será projetado para atender tanto às necessidades dos passageiros quanto das companhias aéreas, proporcionando uma experiência de reserva otimizada e integrada.

Descrição da modelagem:
Classe Sistema:

Classe que gerencia, armazena e modifica as informações que compõem o sistema de controle de voos, como usuários, voos e pagamentos.
Classe Pagamento:

Classe responsável por gerenciar os pagamentos e transações de usuários relacionados às passagens.
Classe Usuário:

Classe que cria, armazena e altera informações específicas de cada usuário. Nessa classe, serão introduzidos dados sobre o usuário como nome, e-mail, id (número associado ao passageiro no sistema) e senha.
Classe Voo:

Classe responsável por armazenar as informações de cada voo e características relacionadas a ele, incluindo detalhes como origem, destino, data, hora, preço e disponibilidade.
Classe SAC:

Classe que faz o papel do serviço de atendimento ao consumidor, calculando, armazenando e exibindo as notas do serviço dadas pelo usuário.
Classe Avaliação:

Essa classe processa as notas e comentários da avaliação do usuário, que serão mostradas no serviço de atendimento ao consumidor.
Modelagem baseada em cartões CRC:
Classe: Sistema
Responsabilidades:
Adicionar Usuário
Adicionar Pagamento
Adicionar Voo
Remover Usuário
Remover Pagamento
Colaborações:
Pagamento
Usuário
Voo
Classe: Pagamento
Responsabilidades:
Comprar Passagem
Preço
Reembolso
Pagador
Situação do Pagamento
Colaborações:
Sistema
Voo
Usuário
Classe: Usuário
Responsabilidades:
Nome
email
Senha
ID
Saldo
Trocar Nome
Trocar Senha
Colaborações:
Sistema
Classe: Voo
Responsabilidades:
Origem
Destino
Horário do Voo
Assentos
Preço
Colaborações:
Sistema
Classe: SAC
Responsabilidades:
Adicionar Avaliação
Mostrar Avaliação
Calcular Nota
Colaborações:
Usuário
Avaliação
Classe: Avaliação
Responsabilidades:
Nota
Comentário
Colaborações:
Usuário
3. Estrutura do Projeto:
A estrutura de diretórios do projeto de Sistema de Reserva de Passagens Aéreas deve ser organizada de maneira clara e lógica para facilitar a navegação, desenvolvimento e manutenção.

TP-PDS2/: 
  bin/: Contém os executáveis gerados após a compilação do projeto.
  src/: Contém os arquivos de implementação (.cpp) que definem a lógica das classes e funções e os cabeçalhos (.hpp).
4. Instruções de Instalação:
Abaixo estão as instruções detalhadas para instalar e configurar o Sistema de Reserva de Passagens Aéreas em um ambiente de desenvolvimento. Estas instruções cobrem as dependências e os requisitos de sistema necessários para compilar e executar o projeto.

Requisitos de Sistema:
Sistema Operacional: Linux, macOS ou Windows
Compilador C++: GCC 7.0+ ou Clang 5.0+ (para Linux/macOS), MinGW ou Visual Studio (para Windows)
Git
Visual Studio Code
Bibliotecas Adicionais: Nenhuma específica além das bibliotecas padrão do C++
Passos de Instalação:
Atualize o Sistema:

Certifique-se de que seu sistema está atualizado.
Instale o Compilador C++:

Para sistemas Linux, instale o GCC ou Clang.
Para macOS, você pode usar o Xcode Command Line Tools.
Para Windows, instale o MinGW ou use o Visual Studio com suporte a C++.
Clone o Repositório do Projeto:

Clone o repositório do projeto no Visual studio code
Clique no canto inferior esquerdo em "command pallet", depois pesquise por git:clone e utilize o link https://github.com/RodrigoNotini/TP-PDS2

Ou abra o gitbash, va para o diretorio onde deseja armazenar o projeto e utilize o comando:
git clone https://github.com/RodrigoNotini/TP-PDS2.git


Compilação:

Opção 1:

Compilação Manual:

Compile os arquivos fonte e gere o executável. Você pode usar um único comando c++ para compilar todos os arquivos.

g++ src\*.cpp -o bin\executavel

Opção 2:

tasks.json:

Para compilar o projeto utilizando o tasks.json do Visual Studio Code, você pode configurar uma tarefa de compilação. Aqui está um exemplo de como você pode configurar o tasks.json para compilar todos os arquivos .cpp na pasta src e gerar o executável na pasta bin:

Navegue até a pasta .vscode dentro da pasta do projeto.
Abra (ou crie) o arquivo tasks.json.
Aqui está um exemplo de como configurar o tasks.json:


{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Compilar Projeto",
            "type": "shell",
            "command": "g++",
            "args": [
                "src/*.cpp",
                "-o",
                "bin/executavel"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"],
            "detail": "Compilar todos os arquivos .cpp na pasta src e gerar o executável na pasta bin"
        }
    ]
}



Executar o Sistema:

Após a compilação bem-sucedida, execute o sistema.

./bin/TP-PDS2
Compilação e Execução de Testes:

Compile e teste as funcionalidades disponíveis no programa.

5. Instruções de Uso:
Exemplos de Uso:
Função: Cadastrar Usuário:
Escolha "cadastrar".
Digite o nome, email, ID, senha e saldo do novo usuário quando solicitado.
Após confirmar os dados, o usuário será cadastrado e você verá uma mensagem de confirmação.



Função: Trocar Senha
Utilização:
Escolha a opção "trocar senha".
Informe o ID do usuário.
Informe a senha atual.
Informe a nova senha desejada.
Se o usuário existir e a senha atual estiver correta, a senha será atualizada com sucesso. Caso contrário, uma mensagem informando que o usuário não foi encontrado será exibida.


Função: Trocar Nome
Utilização:
Escolha a opção "trocar nome".
Informe o ID do usuário.
Informe a senha atual.
Informe o novo nome desejado.
Se o usuário existir e a senha atual estiver correta, o nome será atualizado com sucesso. Caso contrário, uma mensagem informando que o usuário não foi encontrado ou que a senha está incorreta será exibida.


Função: Adicionar Avaliacao
Utilização:
Escolha a opção "adicionar avaliação".
Informe o ID do usuário.
Insira um comentário sobre o serviço.
Insira uma nota de 1 a 5.
A avaliação será adicionada ao serviço.


Função: Mostrar Avaliacoes
Utilização:
Escolha a opção "mostrar avaliações".
Todas as avaliações armazenadas no serviço serão exibidas.


Função: Calcular Media Notas
Utilização:
Escolha a opção "calcular média de notas".
A média das notas de todas as avaliações do serviço será calculada e exibida.


Função: Remover Usuario
Utilização:
Escolha a opção "remover usuário".
Informe o nome do usuário a ser removido.
O usuário com o nome fornecido será removido do sistema.


Função: Remover Pagamento
Utilização:
Escolha a opção "remover pagamento".
Informe o ID do pagamento a ser removido.
O pagamento com o ID fornecido será removido do sistema.


Função: mostrarVoos
Utilização:
Escolha a opção "mostrar voos".
Todos os voos disponíveis no sistema serão exibidos.


Função: Comprar Voo
Utilização:
Escolha a opção "comprar voo".
Todos os voos disponíveis serão exibidos.
Anote o ID do voo desejado.
Informe o ID do usuário.
Informe o ID do voo desejado.
Se o usuário e o voo existirem, a compra será realizada com sucesso utilizando o método de pagamento "Cartão de Crédito" e o pagamento será adicionado ao sistema. Caso contrário, mensagens informando que o usuário ou o voo não foram encontrados serão exibidas.


Essas instruções permitem que os usuários utilizem as funcionalidades disponíveis de maneira clara e objetiva, guiando-os passo a passo para cada operação.






