#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

struct Produto {
int codigo;
char descricao[50];
float valor;
char deletado; 
};


struct Cliente {
char nome[50];
int cpf[11];
int aniversario[11];
char endereco[50];
char email[80];
int fone[17];
};
FILE *arq;

void montarMenu(const char* funcionalidade);
void gerenciarMenu(int opcao, const char* funcionalidade);
void montarMenuPrincipal(void);
void gerenciarMenuPrincipal(int opcao);

void cadastrarProduto(void);
void alterarProduto(void);
void consultarProduto(void);
void excluirProduto(void);

void cadastrarCliente(void);
void alterarCliente(void);
void consultarCliente(void);
void excluirCliente(void);

void cadastrarPedidos(void);
void alterarPedidos(void);
void consultarPedidos(void);
void excluirPedidos(void);

void cadastrarRelatorios(void);
void alterarRelatorios(void);
void consultarRelatorios(void);
void excluirRelatorios(void);void menuAdministrador(void);


void menuAdministrador()
{   
    int continuar = 0;
    
    printf("\n\tMenu de Administrador\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Gerenciar Cliente\n");
    printf("2. Gerenciar Produtos\n");
    printf("3. Gerenciar Pedidos\n");
    printf("4. Gerenciar Relatórios\n");
    printf("5. Criptografia\n");
    printf("6. Gerenciar Usuário\n");
    printf("7. Voltar ao Menu Principal\n");

    scanf("%i", &continuar);
    system("cls || clear");

    switch(continuar)
    {
        case 1:            
            montarMenu("Cliente");
            break;
        case 2:            
            montarMenu("Produtos");         
            break;
        case 3:            
            montarMenu("Pedidos");             
            break;
        case 4:
            montarMenu("Relatórios");        
            break;
        case 5:
            montarMenu("Relatórios");           
        break;
        case 6:
            montarMenu("Usuário");           
            break; 
        case 7:
            montarMenuPrincipal();           
            break;        
        default:
            printf("Digite uma opcao valida\n");
            system("pause");
    }
}
void montarMenu(const char* funcionalidade)
{
   int opcao = 0;
    printf("\n\tMenu de Administrador - %s\n\n", funcionalidade);
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
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
            cadastrarProduto();                                   
            break;
        case 2:            
            alterarProduto();                                             
            break;
        case 3:           
            consultarProduto();                        
            break;
        case 4:
            excluirProduto();                             
            break;
        case 5:
            menuAdministrador();           
            break;        
        default:
            printf("Digite uma opcao valida\n");
            system("pause");
    }
}

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
void montarMenuPrincipal()
{
    int opcao = 0;
    printf("\n\tMenu de Principal\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Menu Principal\n");  
    printf("2. Sair\n");   
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
        case 2:
            exit(1);            
            break;        
        default:
            printf("Digite uma opcao valida\n");
            system("pause");
    }
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    system("title PIM - Projeto Integrado Multidisciplinar");
    system("color 1F");
    montarMenuPrincipal();
}