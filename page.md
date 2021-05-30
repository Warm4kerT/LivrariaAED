@page workflow Page − Manual de Utilização

# Como utilizar a Livraria.

O nosso projeto foi desenvolvido para ser compilado através de um MakeFile, portanto, inicialmente vamos escrever na nossa linha de comandos "make", para prepararmos todos os ficheiros executáveis.

Seguidamente, vamos executar o nosso ficheiro principal, ou seja, a nossa "livraria.h" utilizando o seguinte comando: "./livraria"

Resumindo, Comandos Iniciais:

1. "make"
2. "./livraria"

Após ambos os passos, o nosso programa dará início, e aparecerá ao utlizador um pequeno Menu Inicial: 

\n
\image html Menu.png
\n

Para utilizar este e os demais Menus presentes no projeto, o utilizador apenas tem de digitar na linha de comandos, o número referente à operação que deseja efetuar, seja entrar num Sub-Menu, Criar um cliente, ou utlizar uma das operações presentes.

Seguidamente, fica um exemplo de como criar um cliente e guardar na nossa Base de Dados. (Exemplifica apenas como criar um Cliente, as outras operações do Projeto são utilizadas praticamente da mesma forma, portanto iremos apenas demonstrar esta).

Antes de entrarmos no nosso SubMenu Clientes, temos de entrar no SubMenu Ficheiros para inicializarmos os nossos ficheiros que servem como Base de Dados:
1. Entramos no SubMenu escrevendo na linha de comandos o número "1".
2. Após isso selecionamos a opção Abrir e selecionamos Abrir Clientes:
    1. Ao selecionar, escrevemos o nome do ficheiro, que neste caso é "clientes.txt".
    2. Após estar devidamente aberto podemos sair do SubMenu Ficheiros e seguir para o próximo Passo.

\n

 Após o passo anterior estar completo, selecionamos do Menu-Principal o Sub-Menu "3", relativo a clientes.

1. Ao ser selecionado "3", aparecerá o seguinte Sub-Menu: \image html Clientes.png
2. Para adicionar um Cliente, temos de selecionar a opção "1" do nosso SubMenu Clientes. 
3. Seguidamente será pedido passo a passo, os diferentes dados necessários para registar um Cliente. \n\n
        Exemplo de um Cliente aleatório criado: \image html AddCliente.png

\n

Após estar adicionado o Cliente á lista de Clientes aberta no início através do ficheiro, temos de guardar esta nova lista atualizada, para também atualizar o nosso ficheiro de Base de Dados de Clientes.
1. Para isso, temos então de voltar ao nosso Menu.
2. Selecionar a opção Ficheiros.
3. Selecionar no SubMenu Ficheiros a opção Guardar.
4. Selecionar Clientes em Guardar.

Após estes 4 passos, o nosso novo Cliente e respetiva informação estará devidamente armazenado no nosso ficheiro "clientes.txt".

Assim termina o nosso exemplo de utilização do projeto.


