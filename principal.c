#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

struct Cliente{
    char nome[50];
    char cpf[11];
    char aniversario[11];
    char endereco[50];
    char email[80];
    char fone[17];
    char dataRegistro[15];
    char deletado;
};

struct Produto {
    int codigo[11];
    char descricao[50];
    float valor;
    char deletado; 
};

FILE *arq;              // declarar a vari�vel(*arq) como ponteiro do arquivo(FILE)

#pragma region Prot�tipos
void criptografia(void);
void montarMenu(const char* funcionalidade);
void gerenciarMenu(int opcao, const char* funcionalidade);
void menuAdministrador(void);
void menuCliente(void);
void retornarMensagem(const char* mensagem);
void gerenciarTela(int opcao);
void montarMenuPrincipal(void);
void gerenciarMenuPrincipal(int opcao);
void menuOperador(void);
void sair(void);

void cadastrarCliente(void);
void alterarCliente(void);
void consultarCliente(void);
void excluirCliente(void);

void cadastrarProduto(void);
void alterarProduto(void);
void consultarProduto(void);
void excluirProduto(void);

void cadastrarPedidos(void);
void alterarPedidos(void);
void consultarPedidos(void);
void excluirPedidos(void);

void cadastrarRelatorios(void);
void alterarRelatorios(void);
void consultarRelatorios(void);
void excluirRelatorios(void);
#pragma endregion Prot�tipos

#pragma region Fun��es Ut�is
void retornarMensagem(const char* mensagem)
{
    printf(mensagem);
    return;
}
void sair()
{
    printf("Obrigado por visitar nossa lista de cursos\n");
    system("pause");
}
void configurarTela()
{
    int opcao = 0;
    printf("1. Azul/Verde\n");
    printf("2. Roxo/Branco\n");
    printf("3. Vermelho/Amarelo\n");
    printf("4. Preto/Verde\n");
    printf("5. Voltar ao Menu Principal\n"); 
    system("pause>nul"); 
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarTela(opcao);
}
void gerenciarTela(int opcao)
{
    switch(opcao)
    {
        case 1:            
            system("color 1A");
            montarMenuPrincipal();         
            break;

        case 2:            
            system("color 5F");
            montarMenuPrincipal();             
            break;

        case 3:           
            system("color 4E"); 
            montarMenuPrincipal();            
            break;

        case 4:
            system("color 0A");            
            break;
        case 5:
            montarMenuPrincipal();
            montarMenuPrincipal();            
            break;        
        default:
            printf("Digite uma opcao valida\n");
            system("pause");
    }
}
void sobre()
{
    printf("\n\n\t\t\tPIM\n\n");
    printf("\tAn�lise e Desenvolvimento de Sistemas\n\tPIM - Projeto Integrado Multidisciplinar\n");
    printf("\tIntegrantes:\n\t\tD�bora Ishida\n\t\txxxxxxxxxxx\n\t\txxxxxxxxxxxxxx\n\t\txxxxxxxxxx");
    getch();
}
#pragma endregion Fun��es Ut�is

#pragma region Menu Administrador
void menuAdministrador()
{   
    int continuar = 0;
    
    printf("\n\tMenu de Administrador\n\n");
    printf("Informe uma op��o v�lida e aperte a tecla enter\n\n");
    printf("1. Gerenciar Cliente\n");
    printf("2. Gerenciar Produto\n");
    printf("3. Gerenciar Pedidos\n");
    printf("4. Gerenciar Relat�rios\n");
    printf("5. Criptografia\n");
    printf("6. Voltar ao Menu Principal\n");

    scanf("%i", &continuar);
    system("cls || clear");

    switch(continuar)
    {
        case 1:            
            montarMenu("Cliente");
            break;
        case 2:            
            montarMenu("Produto");         
            break;
        case 3:            
            montarMenu("Pedidos");             
            break;
        case 4:
            montarMenu("Relat�rios");        
            break;
        case 5:
            criptografia();           
        break; 
        case 6:
            montarMenuPrincipal();           
            break;        
        default:
            retornarMensagem("Digite uma opcao valida\n");
            system("pause");
    }
}
void montarMenu(const char* funcionalidade)
{
   int opcao = 0;
    printf("\n\tMenu de Administrador - %s\n\n", funcionalidade);
    printf("Informe uma op��o v�lida e aperte a tecla enter\n\n");
    printf("1. Cadastrar %s\n", funcionalidade);
    printf("2. Alterar %s\n", funcionalidade);
    printf("3. Consultar %s\n", funcionalidade);
    printf("4. Excluir %s\n", funcionalidade);
    printf("5. Voltar ao Menu Principal\n"); 
    system("pause>nul"); 
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarMenu(opcao, funcionalidade); 
}
void gerenciarMenu(int opcao, const char* funcionalidade)
{
    char funcao;
    switch(opcao)
    {
        case 1: 
            if(funcionalidade == "Cliente")
            {
                cadastrarCliente();
            }
            else if (funcionalidade == "Produto")
            {
                cadastrarProduto();
            }   
            else if (funcionalidade == "Pedidos")
            {
                cadastrarPedidos();
            } 
            else
            {
                cadastrarRelatorios();
            }                              
            break;

        case 2:            
            if(funcionalidade == "Cliente")
            {
                alterarCliente();
            }
            else if (funcionalidade == "Produto")
            {
                alterarProduto();
            }   
            else if (funcionalidade == "Pedidos")
            {
                alterarPedidos();
            } 
            else
            {
                alterarRelatorios();
            }                                 
            break;

        case 3:           
            if(funcionalidade == "Cliente")
            {
                consultarCliente();
            }
            else if (funcionalidade == "Produto")
            {
                consultarProduto();
            }   
            else if (funcionalidade == "Pedidos")
            {
                consultarPedidos();
            } 
            else
            {
                consultarRelatorios();
            }            
            break;

        case 4:
            if(funcionalidade == "Cliente")
            {
                excluirCliente();
            }
            else if (funcionalidade == "Produto")
            {
                excluirProduto();
            }   
            else if (funcionalidade == "Pedidos")
            {
                excluirPedidos();
            } 
            else
            {
                excluirRelatorios();
            }                 
            break;
        case 5:
            menuAdministrador();           
            break;        
        default:
            printf("Digite uma opcao valida\n");
            system("pause");
    }
}

#pragma region Cliente
void cadastrarCliente()
{
    time_t agora;
    struct Cliente cliente;    
    int retorno;
    arq = fopen("cliente.txt", "ab");// fopen cria arquivo de entrada
     if (arq == NULL){//caso o sistema n�o consiga criar o arquivo
        printf ("Erro!\nO arquivo da lista n�o pode ser aberto!\n");//sera mostrada esta mensagen
        getch();// espera que o usu�rio pressione uma tecla
        exit(1);//caso esse erro ocorra este comando encerra o programa
     }

    printf("Informe os dados para registro:\n");

    printf("\n\n\tE-mail:\t");
    fflush(stdin);
    gets(cliente.email);

    printf("\n\tNome:\t");
    scanf("%s", &cliente.nome);

    printf("\n\n\tCPF:\t");
    scanf("%s", &cliente.cpf);

    printf("\n\n\tData de Registro:\t");
    scanf("%s", &cliente.dataRegistro);

    printf("\n\n\tAnivers�rio:\t");
    scanf("%s", &cliente.aniversario);

    printf("\n\n\tTelefone:\t");
    scanf("%s", &cliente.fone);

    printf("\n\n\tEndere�o:\t");
    scanf("%s", &cliente.endereco);

    agora = time(NULL);
    strftime(cliente.dataRegistro, sizeof(cliente.dataRegistro), "%d.%m.%Y - %H:%M:%S", localtime( &agora ));   
    retorno = fwrite(&cliente, sizeof(struct Cliente), 1 ,arq);
    if (retorno == 1)
    {
        fclose (arq);//fecha o arquivo cliente.txt 
        retornarMensagem("\n Dados do cliente inclu�dos com sucesso!");
        system("pause>nul"); 
        system("cls || clear");       
        montarMenu("Cliente");
    }
    else
    {
        fclose (arq);//fecha o arquivo cliente.txt 
        retornarMensagem("\n Falha ao gravar dados de cliente.");
        system("pause>nul");
        system("cls || clear");        
        montarMenu("Cliente");
    }
      
}
void alterarCliente()
{
    printf("Desenvolver a fun��o alterarCliente\n");
    system("pause>nul");
    return;
}
void excluirCliente()
{
    arq = fopen("cliente.txt", "r+b");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul"); 
        system("cls || clear");       
        montarMenu("Cliente");
    }
    struct Cliente cliente;
    char nome, encontrado = 0;
    char certeza;
    printf ("\nDigite o nome do cliente que deseja EXCLUIR: \n");
    scanf ("%s", &nome);

    while (fread (&cliente, sizeof(cliente), 1, arq))
    {
        if (nome == cliente.nome)
        {
            printf("Nome: %c \n\n",cliente.nome);
            encontrado = 1;

            printf("\nTem certeza que quer excluir cliente? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                cliente.deletado = '*';        
                fseek(arq,sizeof(struct Produto)*-1, SEEK_CUR);
                fwrite(&cliente, sizeof(cliente), 1, arq);
                fseek(arq, sizeof(cliente)* 0, SEEK_END);
                printf("\nCliente excluido com Sucesso! \n");
                system("pause>nul"); 
                system("cls || clear");       
                montarMenu("Cliente");
            }
            else if (certeza == 'n')
            {
                system("cls || clear");       
                montarMenu("Cliente");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCliente nao cadastrado!!\n");
        system("pause>nul"); 
        system("cls || clear");       
        montarMenu("Cliente");
    }
    fclose(arq);
    return;
}

void consultarCliente()
{
    arq = fopen("cliente.txt", "rb");

    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul"); 
        system("cls || clear");       
        montarMenu("Cliente");
    }

    struct Cliente cliente;

    int encontrado = 0;
    char cpf[11];

    printf("\nDigite o cpf do cliente: \n");
    scanf("%s", &cpf);
    printf("CPF informado e: %s\n", &cpf);

    while (fread (&cliente, sizeof(cliente), 1, arq))
    {
        printf("Seu nome e: %s, seu CPF e: %s\n", cliente.nome, cliente.cpf);
        if (cpf == cliente.cpf)
        {
            printf("entrou no if de busca");
            printf("Cpf %s --- Nome: %s --- \n", cliente.cpf, cliente.nome);
            encontrado = 1;
            system("pause>nul");
            system("cls || clear");        
            montarMenu("Cliente");
        }
        printf("Buscando proximo cliente...\n");
    }

    if (encontrado == 0)
    {
        printf("\nCliente nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");        
        montarMenu("Cliente");
    }

    fclose(arq);
}

#pragma endregion Cliente

#pragma region Produto
void cadastrarProduto()
{
    struct Produto produtos;
    int retorno;
    arq = fopen("produtos.txt", "ab");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo");
        return;
    }
    printf("Digite o codigo do produto: \n");
    scanf("%d", &produtos.codigo);
    printf("Digite a descricao do produto: \n");
    fflush(stdin);
    gets(produtos.descricao);
    printf("Digite o valor do produto: \n");
    scanf("%f", &produtos.valor);
    retorno = fwrite (&produtos, sizeof(produtos), 1, arq);
    if (retorno == 1)
    {
        fclose (arq); 
        printf("\n Dados do produto incluídos com sucesso!");
        system("pause>nul"); 
        system("cls || clear");       
        montarMenu("Produtos");
    }
    else
    {
        fclose (arq); 
        printf("\n Falha ao gravar dados do produto.");
        system("pause>nul");
        system("cls || clear");        
        montarMenu("Produtos");
    }

}
void alterarProduto()
{
        arq = fopen("produtos.txt", "r+b");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");        
        montarMenu("Produtos");
    }

    struct Produto produtos;
    int cod, encontrado = 0;
    printf ("\nDigite o codigo que deseja alterar: \n");
    scanf ("%d", &cod);

    while (fread (&produtos, sizeof(produtos), 1, arq))
    {
        if (cod == produtos.codigo)
        {
            printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n",produtos.codigo, produtos.descricao, produtos.valor);
            encontrado = 1;

            fseek(arq,sizeof(struct Produto)*-1, SEEK_CUR);
            printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            gets(produtos.descricao);
            printf("\nDigite o novo preco....: \n");
            scanf("%f", &produtos.valor);

            fwrite(&produtos, sizeof(produtos), 1, arq);
            fseek(arq, sizeof(produtos)* 0, SEEK_END);

            printf("\n Dados do produto alterados com sucesso!");
            system("pause>nul"); 
            system("cls || clear");       
            montarMenu("Produtos");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause>nul"); 
        system("cls || clear");       
        montarMenu("Produtos");
    }
    fclose(arq);
}
void excluirProduto()
{
    arq = fopen("produtos.txt", "r+b");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul"); 
        system("cls || clear");       
        montarMenu("Produtos");
    }
    struct Produto produtos;
    int cod, encontrado = 0;
    char certeza;
    printf ("\nDigite o codigo que deseja EXCLUIR: \n");
    scanf ("%d", &cod);

    while (fread (&produtos, sizeof(produtos), 1, arq))
    {
        if (cod == produtos.codigo)
        {
            printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n",produtos.codigo, produtos.descricao, produtos.valor);
            encontrado = 1;

            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                produtos.deletado = '*';                
                fseek(arq,sizeof(struct Produto)*-1, SEEK_CUR);
                fwrite(&produtos, sizeof(produtos), 1, arq);
                fseek(arq, sizeof(produtos)* 0, SEEK_END);
                printf("\nProduto excluido com Sucesso! \n");
                system("pause>nul"); 
                system("cls || clear");       
                montarMenu("Produtos");
            }
            else if (certeza == 'n')
            {
                system("cls || clear");       
                montarMenu("Produtos");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul"); 
        system("cls || clear");       
        montarMenu("Produtos");
    }
    fclose(arq);
}
void consultarProduto()
{
    arq = fopen ("produtos.txt", "rb");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul"); 
        system("cls || clear");       
        montarMenu("Produtos");
    }
    struct Produto produtos;
    int cod, encontrado = 0;
    printf ("\nDigite o codigo que procura: \n");
    scanf ("%d", &cod);

    while (fread (&produtos, sizeof(produtos), 1, arq))
    {
        if ((cod == produtos.codigo) && (produtos.deletado != '*'))
        {
            printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n",produtos.codigo, produtos.descricao, produtos.valor);
            encontrado = 1;
            system("pause>nul");
            system("cls || clear");        
            montarMenu("Produtos");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");        
        montarMenu("Produtos");
    }
    fclose(arq);

}
#pragma endregion Produto

#pragma region Pedidos
void cadastrarPedidos()
{
    printf("Desenvolver a fun��o cadastrarPedidos\n");
    system("pause>nul");
}
void alterarPedidos()
{
    printf("Desenvolver a fun��o alterarPedidos\n");
    system("pause>nul");
}
void excluirPedidos()
{
    printf("Desenvolver a fun��o excluirPedidos\n");
    system("pause>nul");
}
void consultarPedidos()
{
    printf("Desenvolver a fun��o consultarPedidos\n");
    system("pause>nul");
}
#pragma endregion Pedidos

#pragma region Relatorios
void cadastrarRelatorios()
{
    printf("Desenvolver a fun��o cadastrarRelatorios\n");
    system("pause>nul");
    return;
}
void alterarRelatorios()
{
    printf("Desenvolver a fun��o alterarRelatorios\n");
    system("pause>nul");
    return;
}
void excluirRelatorios()
{
    printf("Desenvolver a fun��o excluirRelatorios\n");
    system("pause>nul");
    return;
}
void consultarRelatorios()
{
    printf("Desenvolver a fun��o consultarRelatorios\n");
    system("pause>nul");
    return;
}
#pragma endregion Relatorios

#pragma endregion Menu Administrador

#pragma region Menu Operador
void menuOperador()
{
    printf("Desenvolver a fun��o MenuOperador\n");
    system("pause>nul");
    return;
}
#pragma endregion Menu Operador

#pragma region Menu Princial
void montarMenuPrincipal()
{
    int opcao = 0;
    printf("\n\tMenu de Principal\n\n");
    printf("Informe uma op��o v�lida e aperte a tecla enter\n\n");
    printf("1. Menu Principal\n");
    //printf("2. Menu Operador\n");
    printf("2. Configurar Tela\n");
    printf("3. Sobre\n");
    printf("4. Sair\n"); 
    system("pause>nul"); 
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarMenuPrincipal(opcao);
}
void gerenciarMenuPrincipal(int opcao)
{
    switch(opcao)
    {
        case 1:            
            menuAdministrador();                       
            break;
        //case 2:            
        //    menuOperador();             
        //    break;
        case 2:           
            configurarTela();            
            break;
        case 3:
            sobre();            
            break;
        case 4:
            exit(1);            
            break;        
        default:
            printf("Digite uma opcao valida\n");
            system("pause");
    }
}
#pragma endregion Menu Principal

#pragma region Criptografia

#pragma endregion Criptografia
void criptografia()
{
    FILE *origem, *destino; // Declarando ponteiros para abertura de arquivos
    int opcao; // Inteiro que designa a opcao de criptografar ou descriptografar

    puts("Programa de criptografia");
    puts("Digite 1 ou 2 conforme abaixo:");
    puts("  1 - Criptografar");
    puts("  2 - Descriptografar");

    scanf("%d", &opcao);

    if (opcao == 1) // Se for para criptografia
    {

        origem = fopen("origem.txt", "r"); // Tenta abrir origem.txt para leitura
        destino = fopen("destino.txt", "w"); // Tenta abrir o arquivo destino.txt para escrita, e o cria se ele nao existir

        if(origem != NULL && destino != NULL) // Se o arquivo de origem existe e se o de destino existe ou conseguiu ser criado
        {
            char c; // Define a variavel c, para ler caractere por caractere do arquivo
            int contador = 0; // Define contador que indicara a posicao do arquivo
            int i = 0; // Variavel inteira que utilizaremos para mostrar a representacao ASCII do caractere

            // Faz enquanto o fgetc nao retornar o fim do arquivo
            while(( c = fgetc(origem)) != EOF)
            {
                contador++; // Mesma coisa que contador = contador + 1;
                //printf("%c", c); // Mostra o caractere na tela

                i = c; // i sera o codigo numerico do caractere c em ASCII;
                i = i * contador; // Multiplicando i pela posicao do caractere no arquivo;

                fprintf(destino,"%i ", i); // Escreve a representacao numerica de i e um espaco a frente no arquivo de destino
                printf("%i", i); // Mostra o caractere na tela
            }

            fclose(origem); // Fecha o arquivo de origem
            fclose(destino); // Fecha o arquivo de destino

        }
        else
        {
            puts("Erro de leitura/escrita nos arquivos...");
        }

    }
    else if(opcao == 2) // Se for descriptografia
    {
        origem = fopen("destino.txt", "r"); // Tenta abrir destino.txt para leitura
        destino = fopen("descriptografado.txt", "w"); // Tenta abrir o arquivo descriptografado.txt para escrita, e o cria se ele nao existir

        if(origem != NULL && destino != NULL) // Se o arquivo de origem existe e se o de destino existe ou conseguiu ser criado
        {
            int contador = 0; // Define contador que indicara a posicao do arquivo
            char c[100]; // Utilizaremos para armazenar cada codigo que leremos
            int i = 0; // Variavel inteira que utilizaremos para representacao numerica lida do codigo lido no arquivo

            while(fscanf(origem, "%s", c) != EOF)  // Faz enquanto o fscanf nao retornar o fim do arquivo
            {
                contador++; // Mesma coisa que contador = contador + 1;

                i = atoi(c); // Converte um char* para inteiro e atribui a i
                i /= contador; // Mesma coisa que i = i / contador;

                printf("%c", i); // Mostra o caractere na tela

                fprintf(destino,"%c", i); // Escreve a representacao numerica de i no arquivo de destino
            }

            fclose(origem); // Fecha o arquivo de origem
            fclose(destino); // Fecha o arquivo de destino
        }
    }
    else // Se a opcao for invalida
    {
        puts("Opcao invalida...");
    }
    puts("\n"); // Pula duas linhas
    system("pause"); // Pausa o sistema em ambiente windows
}
#pragma region Main
int main()
{
    setlocale(LC_ALL,"Portuguese");
    system("title PIM - Projeto Integrado Multidisciplinar");
    system("color 1F");
    montarMenuPrincipal();
}
#pragma endregion Main