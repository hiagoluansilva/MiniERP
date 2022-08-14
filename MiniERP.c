#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

/*-------------------------------------------------------------Struct Cadastros-------------------------------------------------------------*/

struct cadastro
{
    char nome[50];
    char ncm[15];
    float peso;
    float valor;
    int pre;
};

/*------------------------------------------------------------------Funções------------------------------------------------------------------*/

int IncluirProduto(struct cadastro *var, int pos)
{
    float i = 0;
    int tam = 0;
    char buffer[50];

    system("cls");

    printf("\n  Cadastro de Produto:");

    printf("\n  -> Informe o nome do produto:\n\t");

    fflush(stdin);
    fgets(buffer, 50, stdin);
    tam = strlen(buffer);

    if (tam > 0 && buffer[tam - 1] == '\n')
    {
        buffer[tam-1] = '\0';
    };

    strcpy(var[pos].nome, buffer);



    printf("\n  -> Informe o NCM do produto:\n\t");

    fflush(stdin);
    fgets(buffer, 15, stdin);
    tam = strlen(buffer);
    if (tam > 0 && buffer[tam - 1] == '\n')
    {
        buffer[tam-1] = '\0';
    };

    strcpy(var[pos].ncm, buffer);



    fflush(stdin);
    do
    {
        printf("\n  -> Informe o peso do produto (Kg):\n\t");
        scanf("%f",&i);
    }
    while(i <= 0);

    var[pos].peso = i;




    fflush(stdin);
    do
    {
        printf("\n  -> Informe o valor do produto:\n\t");
        scanf("%f",&i);
    }
    while(i <= 0);

    var[pos].valor = i;




    var[pos].pre = 1;




    system("cls");

    printf("\n  -> Cadastro realizado com sucesso!!!\n\t");

}
int ListaProdutos(struct cadastro *var)
{
    int i = 0;

    system("cls");

    printf("\n  Lista de Produtos:");
    printf("\n  (ID, Nome, NCM, Peso)");

    for(i = 0; i < 30; i++)
    {
        if(var[i].pre == 1)
        {
           printf("\n\n  -> %d\t %s\t %s\t %.2f", i, var[i].nome, var[i].ncm, var[i].peso);
        };
    };

}
int BuscaValor(struct cadastro *var)
{
    int i = 0;

    ListaProdutos(var);

    do
    {
        printf("\n\n  Consulta valores:");
        printf("\n\n  -> Informe o ID do produto para consultar seu valor:\n\t");

        fflush(stdin);
        scanf("%d", &i);
    }while(i < 0 || i >= 30);

    if(var[i].pre == 1)
    {
        printf("\n  -> O preço do item %d, %s, é R$ %.2f", i, var[i].nome, var[i].valor);
    }
    else
    {
        printf("\n  -> Solicitado valor de produto não cadastrado !!!");
    }
};

int ApagarProduto(struct cadastro *var)
{
    int i = 0;

    ListaProdutos(var);

    do
    {
        printf("\n\n  Apagar produto:");
        printf("\n  -> Informe o ID do produto que deseja apagar:\n\t");

        fflush(stdin);
        scanf("%d", &i);
    }while(i < 0 || i >= 30);

    if(var[i].pre == 0)
    {
        printf("\n  -> Produto não cadastrado !!!");
    }
    else
    {
        var[i].pre = 0;
        printf("\n  -> Produto cadastrado apagado !!!");
    };

};

void Sobre(void)
{
    system("cls");

    printf("\n  Sobre:\n");
    printf("\n  -> Trabalho final referente a cadeira Algoritmos da Universidade Feevale");
    printf("\n  -> A proposta era desenvolver um mini ERP para um comércio de eletroeletrônicos");
    printf("\n  -> Desenvolvido por Hiago Silva em 2021");
};

void PrintMenu(int menu)
{
    printf("\n  MiniERP - Loja Eletroeletrônicos\n");
    printf("\n  Selecione Uma Opção:\n\n");
    printf("   -> 1 - Incluir Produto\n");
    printf("   -> 2 - Listar Produtos\n");
    printf("   -> 3 - Consultar valor\n");
    printf("   -> 4 - Apagar Produto\n");
    printf("   -> 5 - Sobre\n");
    printf("\n   -> 0 - Sair\n\n   ");
    if(menu != 0 && menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 5)
        printf("\n  -> Opção Inválida, Digite Novamente!\n   ");

};

int PosicaoLivre(struct cadastro *prenchido)
{
    int i = 0, posLivre = 100;

    for(i = 0; i < 30; i++)
    {
        if(prenchido[i].pre == 0)
        {
            posLivre = i;
            i = 30;
        };
    };

    return posLivre;
};
/*-----------------------------------------------------------------Variáveis-----------------------------------------------------------------*/

    int menu = 0, i = 0;
    typedef struct cadastro produto;
    produto produtos[30];

/*-----------------------------------------------------------------Programa-----------------------------------------------------------------*/

int main (void){

    setlocale(LC_ALL, "Portuguese");/*UTF-8*/

    for(i=0; i < 30; i++)
    {
        produtos[i].pre = 0;
    };

    do
    {
        fflush(stdin);
        system("cls");
        PrintMenu(menu);
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:

                if(PosicaoLivre(&produtos) == 100)
                {
                    printf("\n\n  ->Memória Cheia !!!");
                }
                else
                {
                    IncluirProduto(&produtos, PosicaoLivre(&produtos));
                };

                printf("\n \n -> Pressione Enter para continuar\n\t");//Qualquer tecla inclui o botão de desligar
                getch();
            break;

            case 2:

                ListaProdutos(&produtos);
                printf("\n \n -> Pressione Enter para continuar\n\t");
                getch();

            break;

            case 3:

                BuscaValor(&produtos);
                printf("\n \n -> Pressione Enter para continuar\n\t");
                getch();

            break;

            case 4:

                ApagarProduto(&produtos);
                printf("\n \n -> Pressione Enter para continuar\n\t");
                getch();

            break;

            case 5:

                Sobre();
                printf("\n \n -> Pressione Enter para continuar\n\t");
                getch();

            break;
        };

    }while(menu!=0);


    system("cls");
    printf("\n  -> Obrigado por utilizar o MiniERP !!!\n");
    getch();


    return 0;
}
