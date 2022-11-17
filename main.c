#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <windows.h>
#include <locale.h> 
#include "agenda.c"
#include "contatos.c"

#define TITULO_OPCAO1 "Adicionar contato"
#define TITULO_OPCAO2 "Remover contato"
#define TITULO_OPCAO3 "Listar contatos cadastrados"
#define TITULO_OPCAO4 "Editar o contato"
#define TITULO_OPCAO5 "Buscar contato"
#define TITULO_OPCAO6 "Consultar contato em uma dada agenda"
#define TITULO_OPCAO7 "Consultar quantitativo de agendas"
#define TITULO_OPCAO8 "Sair"

#define N_OPCOES 8
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'


void LimpaBuffer(void) {
    int valorLido; 
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}

int LeOpcao(int menorValor, int maiorValor) {
    int op;
    while (1) {
        printf("\nDigite sua opção:  ");
        op = getchar();
        if (op >= menorValor && op <= maiorValor) {
            LimpaBuffer();
            break;
        }
        else {
            printf("\nOpção inválida. Tente novamente.");
            printf("\nA opção deve estar entre %c e %c. \n",
                   menorValor, maiorValor);
            LimpaBuffer();
        }
    }
    system("cls");
 
    return op;
}

void ApresentaMenu(int nItens, int menorOpcao, ...) {
    int i;
    va_list argumentos; 
    va_start(argumentos, menorOpcao);

    for(i = 0; i < nItens; ++i) {
        printf("%c-%s\n", menorOpcao++, va_arg(argumentos, char *));
    }
    va_end(argumentos);
}

int main(void) {	
    unsigned char op; // variável para amarzenar a opção digitada pelo usuario
    unsigned int saida = 0; // auxiliar para sair do programa
	setlocale(LC_ALL, "Portuguese");


	Lista lista;
	lista.inicio = NULL;
    Agendas agenda;
    int resp;
	char nome1[100];
	char nome[100];
	char email[100];
    int tel, idade;
	int op,op2;
	
	
    do {
        ApresentaMenu(N_OPCOES, OPCAO1,
                      TITULO_OPCAO1, TITULO_OPCAO2,
                      TITULO_OPCAO3, TITULO_OPCAO4, TITULO_OPCAO5,
                      TITULO_OPCAO6,TITULO_OPCAO7, TITULO_OPCAO8);
                      
        op = LeOpcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        switch(op) {
            case OPCAO1:
                ler(&agenda);
  		        inserir_inicio(&lista, agenda);
                break;

            case OPCAO2:
                printf("Digite o nome do contato que você deseja deletar:\n");	
		        scanf(" %s", nome);
		        deletar_Nome(&lista, nome);
                break;

            case OPCAO3:
                Imprimir(lista);

                break;
            
            case OPCAO4:
            	printf("Informe o nome agenda que deseja pesquisar o contato para alterar:   ");
			    scanf("%s", nome);
	  struct No* r1 = Busca_agenda(lista,nome);
		if(r1 == NULL) {
				printf("Agenda não encontrada!");
		} else
		{
			printf("Agenda encontrada com sucesso!\n");
			printf("\n=====================================================\n");
			printf("Informe qual dado você deseja alterar no contato: \n");
			printf("1 - Para editar o nome\n2 - para editar a idade\n3 - Para editar o número do telefone\n4 - Para editar o email\n5 - Para volta ao menu\n");
			printf("\n=====================================================\n");
			scanf("%d",&op2);
			
			if(op2 == 1) {	
			printf("Digite o nome do contato que deseja editar: ");
  	   	   	scanf(" %s",nome);
			printf("Informe o novo nome para alterar: ");
  		   	scanf("%s",nome1);
  		   	alterar_nome(&lista,nome,nome1);
			break;
			}
			else if(op2 == 2){
				printf("Digite o nome do contato que deseja editar: ");
  				scanf(" %s",nome);
  		   	   	printf("Informe a nova idade para alterar no contato: ");
  		   	   	scanf("%d",&idade);
  		   	   	alterar_idade(&lista,nome,idade);
  				break;
			}
			else if(op2 == 3){
				printf("Digite o nome do contato que deseja editar: ");
  		   	   	scanf(" %s",nome);
  		   	   	printf("Informe o novo número do telefone para alterar no contato: ");
  	   	   	  	scanf("%d",&tel);
  		   	   	alterar_telefone(&lista,nome,tel);	
  		   	   	break;
			}
			else if(op2 == 4){
				printf("Digite o nome do contato que deseja editar: ");
  	    		scanf(" %s",nome);
  	   	   	    printf("Informe o novo email: ");
    		    scanf("%s", email);
       	   	    alterar_Email(&lista, nome,  email);
       	   	    break;
			} 
			else if(op2 == 5){
				break;
			}
			else{
				printf("Opção inválida!");
			}
		
		}
                break;            
            
            case OPCAO5:
 	        printf("Informe o nome do contato que deseja pesquisar: ");
			scanf("%s", nome);
	  	    struct No* r = pesquisar(lista,nome);
	  	    
		if(r == NULL){
				printf("\nContato não encontrado\n");
		}
		else{
		     	printf("\nContato encontrado\n\n");
      	  	    printf("=======Exibindo os dados da pesquisa=========\n");
				printf("Nome: %s \n", r->dado.Contatos.nome);
				printf("Idade: %d \n", r->dado.Contatos.idade);
				printf("Telefone: %d \n", r->dado.Contatos.telefone);
				printf("=============================================\n");
		}			           
            	
                break;

            case OPCAO6:
  		printf("Informe o nome da agenda que deseja pesquisar: ");
        scanf("%s", nome);
	    struct No* r2 = Busca_agenda(lista,nome);
		if(r2 == NULL){
				printf("Agenda não encontrada!");
		}
		else {
		     	printf("\nAgenda encontrada\n");
      	  	    printf("=======Exibindo os dados da pesquisa=========\n");
				printf("Nome: %s \n", r2->dado.nome);
				printf("Códico de indentificação: %s \n", r2->dado.codigo_de_identificacao);
				printf("Número de contatos: %d \n", r2->dado.numero_contatos);
				printf("=============================================\n");
			printf("Informe o nome do contato que deseja pesquisar: ");
			scanf("%s", nome);
			
	    struct No* r = pesquisar(lista,nome);
	    
		if(r == NULL){
				printf("\nContato não encontrado\n");
		}
		else{
		     	printf("\nContato encontrado na dada agenda\n\n");
      	  	   printf("=======Exibindo os dados da pesquisa=========\n");
				printf("Nome: %s \n", r->dado.Contatos.nome);
				printf("Idade: %d \n", r->dado.Contatos.idade);
				printf("Telefone: %d \n", r->dado.Contatos.telefone);
				printf("=============================================\n");
		}
				
		}
                break;
			
            case OPCAO7:
                  	resp = Consultar_quantitativo(lista);
  	                printf("Quantidade de agendas: %d",resp);
	            break;
                
									            
            case OPCAO8: 
                saida = 1;
                printf("\n=============================================================\n");
                printf("Obrigada por usar nosso sistema de gerenciamento de contatos!");
                printf("\n=============================================================\n");
                
                
                printf("\n\nSistema desenvolvido por:\nIris Matias da Silva.\n\n");
                break;

            default:
                Beep(1000,500);          	
                printf("Este programa possui um bug...");
                Beep(1000,500); 
                return 1;
        }
    } while(!saida);
    return 0;
}
