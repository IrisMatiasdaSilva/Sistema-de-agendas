#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "agenda.h"


struct agendas{
    char nome[100];
    char codigo_de_identificacao[20];
    int numero_contatos;
    struct contatos Contatos;
};


struct No {
	Agendas dado;
	struct No* prox;
};

void ler(Agendas *a){
	printf("\n*******************************************\n");
	printf("\n    DIGITE AS INFORMAÇÕES DA AGENDA        \n");
	printf("\n*******************************************\n");
	
		printf("Digite o nome da agenda:\n");
		scanf(" %s", a->nome);
		printf("Digite o código de verificação da agenda:\n");
		scanf(" %s", a->codigo_de_identificacao);
		printf("Digite o número de contatos da agenda:\n");
		scanf("%d", &a->numero_contatos);	
	system("cls");	
		
	printf("\n*********************************************\n");
	printf("\n     DIGITE AS INFORMAÇÕES DO CONTATO        \n");
	printf("\n*********************************************\n\n");
	
		printf("Informe o nome:\n");
		scanf(" %s", a->Contatos.nome);
		printf("Informe a idade:\n");
		scanf("%d", &a->Contatos.idade);
		printf("Informe o número de telefone:\n");
	    scanf("%d", &a->Contatos.telefone);
		printf("Informe o email:\n");
		scanf(" %s", a->Contatos.email);  
	
	system("cls");
}

void inserir_inicio(Lista* plista, Agendas dado) {
	struct No* novo = (struct No*) malloc(sizeof(struct No));
	novo->dado = dado;
	novo->prox = plista->inicio;
	plista->inicio = novo;
}

int Consultar_quantitativo(Lista lista){
	struct No *pi;
	int cont=0;
	for(pi = lista.inicio; pi!=NULL; pi=pi->prox){
		cont++;
	}
	return cont;
}
