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

	
	
    do {
        ApresentaMenu(N_OPCOES, OPCAO1,
                      TITULO_OPCAO1, TITULO_OPCAO2,
                      TITULO_OPCAO3, TITULO_OPCAO4, TITULO_OPCAO5,
                      TITULO_OPCAO6,TITULO_OPCAO7, TITULO_OPCAO8);
                      
        op = LeOpcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        switch(op) {
            case OPCAO1:
 	  			Beep(1000,500);
                break;

            case OPCAO2:
            	Beep(1000,500); 
                break;

            case OPCAO3:
                Beep(1000,500);
                break;
            
            case OPCAO4:
            	Beep(1000,500); 
                break;            
            
            case OPCAO5:
            	Beep(1000,500); 
                break;

            case OPCAO6:
            	Beep(1000,500); 	
                break;
			
            case OPCAO7:
                Beep(1000,500);
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


