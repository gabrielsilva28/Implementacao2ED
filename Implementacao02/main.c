#include "colecao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0

typedef struct _funcionario_{
    char nome[30];
    int idade;
    char cargo[30];
    int ID;
    float salario;
}Funcionario;

int main()
{
    int qtd_insercoes = 0, opcao;
    Colecao *colecao = NULL;

    do
    {
        printf("Selecione uma opcao:\n1 - Criar a colecao\n2 - Inserir um item na colecao\n3 - Buscar um item da colecao\n4 - Remover um item da colecao\n5 - Listar os itens da colecao\n6 - Esvaziar a colecao\n7 - Destruir a colecao\n8 - Sair do programa\n");
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n");
        switch(opcao)
        {
            case 1:
                if(colecao == NULL)
                {
                    int max_itens;
                    printf("Insira o numero total de funcionarios que a colecao tera:\n");
                    scanf("%d", &max_itens);
                    colecao = colCriar(max_itens);
                    if(colecao != NULL)
                    {
                        printf("Colecao criada com sucesso!\n");
                    }
                    else
                    {
                        printf("Erro ao criar colecao!\n");
                    }
                }
                else
                {
                    printf("A colecao ja foi criada!\n");
                }
                break;
            case 2:
                if(colecao != NULL)
                {
                    Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));
                    if(funcionario != NULL)
                    {
                        printf("Insira o nome do funcionario: \n");
                        fgets(funcionario->nome, 30, stdin);
                        printf("Insira o cargo do funcionario: \n");
                        fgets(funcionario->cargo, 30, stdin);
                        printf("Insira a idade do funcionario: \n");
                        scanf("%d", &funcionario->idade);
                        printf("Insira o ID do funcionario: \n");
                        scanf("%d", &funcionario->ID);
                        printf("Insira o salario para o funcionario:\n");
                        scanf("%f", &funcionario->salario);
                        if(colInserir(colecao, (void *)funcionario) == FALSE)
                        {
                            printf("A colecao esta cheia!\n");
                        }
                        else
                        {
                            printf("Funcionario adicionado com sucesso!\n");
                            qtd_insercoes++;
                        }
                    }
                }
                else
                {
                    printf("A colecao nao foi criada!\n");
                }
                break;
            case 3:
                if(colecao != NULL)
                {
                    Funcionario *a;
                    int opcao_interna;
                    printf("Deseja buscar o item pelo nome, ID ou salario?\n1 - Nome\n2 - ID\n3 - Salario\n");

                    scanf("%d", &opcao_interna);
                    printf("\n");
                    

                    switch(opcao_interna)
                    {
                        case 1: ;
                        	char nome[30];
                    		printf("Digite o nome:\n");
                    		fgets(nome, 30, stdin);
                    		fgets(nome, 30, stdin);
                    		a = (Funcionario *)colBuscar(colecao, (void *)&nome, cmpNome);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do funcionario:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                            else
                            {
                                printf("Funcionario nao encontrado ou lista vazia!\n");
                            }
                    		
                            break;
                            
                        case 2: ;
                            int ID;

                            printf("Digite o ID do Funcionario:\n");
                            scanf("%d", &ID);

                            a = (Funcionario *)colBuscar(colecao, (void *)&ID, cmpID);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do funcionario:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                            else
                            {
                                printf("Funcionario nao encontrado ou lista vazia!\n");
                            }
                            break;
                        case 3: ;
                        	float salario;

                            printf("Digite o salario:\n");
                            scanf("%f", &salario);

                            a = (Funcionario *)colBuscar(colecao, (void *)&salario, cmpSalario);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do funcionario:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                            else
                            {
                                printf("Funcionario nao encontrado ou lista vazia!\n");
                            }
                        	
                            break;
                    		
                        default:
                            printf("Opcao invalida!\n");
                    }
                }
                else
                {
                    printf("A colecao nao foi criada!\n");
                }
                break;
            case 4:
                if(colecao != NULL)
                {
                    Funcionario *a;
                    int opcao_interna;
                    printf("Deseja remover o item pelo nome, ID ou salario?\n1 - Nome\n2 - ID\n3 - Salario\n");

                    scanf("%d", &opcao_interna);
                    printf("\n");

                    switch(opcao_interna)
                    {
                        case 1: ;
                        	char nome[30];
                    		printf("Digite o nome:\n");
                    		fgets(nome, 30, stdin);
                    		fgets(nome, 30, stdin);
                    		a = (Funcionario *)colRetirar(colecao, (void *)&nome, cmpNome);
                            if(a != NULL)
                            {
                                qtd_insercoes--;
                                printf("\nInformacoes do funcionario removido:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                            else
                            {
                                printf("Funcionario nao encontrado ou lista vazia!\n");
                            }
                            break;
                            
                        case 2: ;
                        	int ID;

                            printf("Digite o ID:\n");
                            scanf("%d", &ID);

                            a = (Funcionario *)colRetirar(colecao, (void *)&ID, cmpID);
                            if(a != NULL)
                            {
                                qtd_insercoes--;
                                printf("\nInformacoes do funcionario removido:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                            else
                            {
                                printf("Funcionario nao encontrado ou lista vazia!\n");
                            }
                            break;
                            
                        case 3: ;
                        	float salario;

                            printf("Digite o salario:\n");
                            scanf("%f", &salario);

                            a = (Funcionario *)colRetirar(colecao, (void *)&salario, cmpSalario);
                            if(a != NULL)
                            {
                                qtd_insercoes--;
                                printf("\nInformacoes do funcionario removido:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                            else
                            {
                                printf("Funcionario nao encontrado ou lista vazia!\n");
                            }
                            break;
                            
                        default:
                            printf("Opcao invalida!\n");
                    }
                }
                else
                {
                    printf("A colecao nao foi criada!\n");
                }
                break;
            case 5:
                if(colecao != NULL)
                {
                   Funcionario *a;

                    a = (Funcionario *)colPegarPrimeiro(colecao);
                    if(a != NULL)
                    {
                        printf("\nInformacoes do funcionario:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                        for(int i = 1; i < qtd_insercoes; i++)
                        {
                            a = (Funcionario *)colPegarProximo(colecao);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do funcionario:\n\nNome: %sIdade: %d \nCargo: %sID: %d \nSalario: %.2f\n", a->nome, a->idade, a->cargo, a->ID, a->salario);
                            }
                        }
                    }
                    else
                    {
                        printf("A lista esta vazia!\n");
                    }
                }
                else
                {
                    printf("A colecao nao foi criada!\n");
                }
                break;
            case 6:
                if(colecao != NULL)
                {
                    if(colEsvaziar(colecao) == FALSE)
                    {
                        printf("A colecao ja esta vazia!\n");
                    }
                    else
                    {
                        qtd_insercoes = 0;
                        printf("Colecao esvaziada com sucesso!\n");
                    }
                }
                else
                {
                    printf("A colecao nao foi criada!\n");
                }
                break;
            case 7:
                if(colecao != NULL)
                {
                    if(colDestruir(colecao) == FALSE)
                    {
                        printf("A colecao nao esta vazia! Esvazie-a antes de destruir\n");
                    }
                    else
                    {
                        colecao = NULL;
                        printf("Colecao destruida com sucesso!\n");
                    }
                }
                else
                {
                    printf("A colecao nao foi criada!\n");
                }
                break;
            case 8:
                colEsvaziar(colecao);
                colDestruir(colecao);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        printf("\n");
    }while(opcao != 8);

    return 0;
}
