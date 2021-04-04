#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 500

typedef struct Cadastro
{
    int categoria;
    int item;
    char titulo[MAX];
    char autor[MAX];
    char editora[MAX];
    int edicao;
    int isbn;
    int ano;
    int quantidade;
    int caixa;
}cadastro;

int i, escolhaCaixa, escolhaCategoria;
void cadastroLivros(cadastro Livro[MAX]);
void ListarTodosLivros(cadastro Livro[MAX]);
void ListarTodosRevistas(cadastro Livro[MAX]);
void ListarObrasCaixa(int escolhaCaixa, cadastro Livro[MAX]);
int contarRegistro(cadastro produto[MAX]);

int main(){
    int op, escolhaCaixa, escolhaCategoria;
    cadastro Livro[MAX];
    setlocale(LC_ALL,"Portuguese");
    i = 0;
    do
    {
        cabecario();
        printf("1-Cadastrar obras\n");
        printf("2-Listar todos os livros\n");
        printf("3-Listar todas as revistas\n");
        printf("4-Listar obras por caixa\n");
        printf("5-Sair\n");
        printf("Escolha opção:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            system("cls");
            cabecario();
            cadastroLivros(Livro);
            do
            {
            system("cls");
            cabecario();
            printf("1-Cadastrar outra obra\n");
            printf("2-Voltar\n");
            printf("Escolha opção:");
            scanf("%d", &op);
            system("cls");
            switch (op)
            {
            case 1:
                cabecario();
                cadastroLivros(Livro);
                break;
            case 2:
                break;
            default:
                system("cls");
                cabecario();
                printf("Valor indefinido");
                system("pause");
                break;
            }
            system("pause");
            system("cls");
            } while (op!=2);
            system("cls");
            break;
        case 2:
            system("cls");
            cabecario();
            ListarTodosLivros(Livro);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            cabecario();
            ListarTodosRevistas(Livro);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            cabecario();
            printf("Informe o numero da caixa:");
            scanf("%d", &escolhaCaixa);
            ListarObrasCaixa(escolhaCaixa, Livro);
            system("pause");
            system("cls");
        case 5:
			//printf("\nSaindo do sistema!!!\n");
			//system("pause");
			system("cls");
			break;
		default:
            system("cls");
			printf("Valor indefinido");
			system("pause");
			system("cls");
			break;
        }
    } while (op!=5);
    return 0;
}

void cabecario(){
    printf("-----------------------------------\n");
    printf("****Elias Rafael Ramos Ribeiro****\n");
    printf("****RA:20082176-5****\n");
    printf("****Engenharia de software****\n");
    printf("-----------------------------------\n");
}


void cadastroLivros(cadastro Livro[MAX]){
    FILE *livros;
    livros = fopen("arquivo.txt","a+");
    if (livros != NULL)
    {
        printf("1-Livros\n");
        printf("2-Revistas\n");
        fflush(stdin);
        scanf("%d", &Livro[i].categoria);
        system("cls");
        cabecario();
        printf("\nInforme os dados da obra: ");
        printf("\nTitulo.................: ");
        fflush(stdin);
        gets(Livro[i].titulo);
        printf("\nAutor:.................: ");
        fflush(stdin);
        gets(Livro[i].autor);
        printf("\nEditora................: ");
        fflush(stdin);
        gets(Livro[i].editora);
        printf("\nEdição.................: ");
        fflush(stdin);
        scanf("%d", &Livro[i].edicao);
        printf("\nISBN...................: ");
        fflush(stdin);
        scanf("%d", &Livro[i].isbn);
        printf("\nAno......................: ");
        fflush(stdin);
        scanf("%d", &Livro[i].ano);
        printf("\nQuantidade em estoque..: ");
        fflush(stdin);
        scanf("%d", &Livro[i].quantidade);
        printf("\nEm qual caixa deseja armazenar:");
        fflush(stdin);
        scanf("%d", &Livro[i].caixa);
        fwrite(&Livro[i], sizeof(cadastro), 1, livros);


        fclose(livros);
    }
    else
    {
        printf("Erro ao iniciar o arquivo!");
        system("pause");
        exit (-1);
    }
}

int contarRegistro(cadastro produto[MAX]){
	FILE * arq = fopen("arquivo.txt", "r");
	if(arq != NULL)
	{
		int contador = 0;
		while(1)
		{
			cadastro p;

			int registro = fread(&p, sizeof(cadastro), 1, arq);

			if(registro < 1)
				break;
			else
				produto[contador] = p;
			contador++;
		}
		fclose(arq);
		return contador;
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1);
	}
}

void ListarTodosLivros(cadastro Livro[MAX]){
	int quantidadeproduto = contarRegistro(Livro);
	int i;


    printf("\n>>>> Lista de obras <<<<\n");
    for(i = 0; i < quantidadeproduto; i++)
    {
        if (Livro[i].categoria == 1){
            printf("\nCategoria: Livro");
            printf("\nItem: %d \t|Titulo: %s  \t|Autor: %s \t\t\n\n|Editora: %s \t\t |Edicao: %d\n\n", i+1, Livro[i].titulo, Livro[i].autor, Livro[i].editora, Livro[i].edicao);
            printf("ISBN: %d \t|Ano: %d \t|Quantidade: %d \t|Caixa: %d\n", Livro[i].isbn, Livro[i].ano, Livro[i].quantidade, Livro[i].caixa);
            printf("-----------------------------------------------------------------------------------------------------------\n");
        }
    }

}

void ListarTodosRevistas(cadastro Livro[MAX]){
	int quantidadeproduto = contarRegistro(Livro);
	int i;


    printf("\n>>>> Lista de obras <<<<\n");
    for(i = 0; i < quantidadeproduto; i++)
    {
        if (Livro[i].categoria == 2)
        {
            printf("\nCategoria: Revista");
            printf("\nItem: %d \t|Titulo: %s  \t|Autor: %s \t\t\n\n|Editora: %s \t\t |Edicao: %d\n\n", i+1, Livro[i].titulo, Livro[i].autor, Livro[i].editora, Livro[i].edicao);
            printf("ISBN: %d \t|Ano: %d \t|Quantidade: %d \t|Caixa: %d\n", Livro[i].isbn, Livro[i].ano, Livro[i].quantidade, Livro[i].caixa);
            printf("-----------------------------------------------------------------------------------------------------------\n");
        }

    }

}

void ListarObrasCaixa(int escolhaCaixa, cadastro Livro[MAX]){
	int quantidadeproduto = contarRegistro(Livro);
	int i;

	printf("\n>>>> Lista de obras por caixa <<<< \n");
	printf("Caixa pesquisada: %d \n", escolhaCaixa);

	for(i = 0; i < quantidadeproduto; i++)
	{
		if(Livro[i].caixa == escolhaCaixa){
			if (Livro[i].categoria == 1){
                printf("\nCategoria: Livro");
                printf("\nItem: %d \t|Titulo: %s  \t|Autor: %s \t\t\n\n|Editora: %s \t\t |Edicao: %d\n\n", i+1, Livro[i].titulo, Livro[i].autor, Livro[i].editora, Livro[i].edicao);
                printf("ISBN: %d \t|Ano: %d \t|Quantidade: %d \t|Caixa: %d\n", Livro[i].isbn, Livro[i].ano, Livro[i].quantidade, Livro[i].caixa);
                printf("-----------------------------------------------------------------------------------------------------------\n");
            }
            if (Livro[i].categoria == 2)
            {
                printf("\nCategoria: Revista");
                printf("\nItem: %d \t|Titulo: %s  \t|Autor: %s \t\t\n\n|Editora: %s \t\t |Edicao: %d\n\n", i+1, Livro[i].titulo, Livro[i].autor, Livro[i].editora, Livro[i].edicao);
                printf("ISBN: %d \t|Ano: %d \t|Quantidade: %d \t|Caixa: %d\n", Livro[i].isbn, Livro[i].ano, Livro[i].quantidade, Livro[i].caixa);
                printf("-----------------------------------------------------------------------------------------------------------\n");
            }
		}
	}
}
