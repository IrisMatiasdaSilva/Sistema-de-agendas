#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "contatos.h"


struct contatos{
    char nome[100];
    int idade;
    int telefone;
    char email[100];
};

struct lista {
	struct No* inicio;
};

void Imprimir(Lista lista) {
	struct No * pi;
		printf("___________________________________________________________________________________________________\n");
	for(pi = lista.inicio; pi != NULL  ; pi = pi->prox) {
        printf("Nome da Agenda: %s \t", pi->dado.nome);
		printf("Códico de verificação da agenda: %s \t", pi->dado.codigo_de_identificacao);
		printf("Número de contato da agenda: %d \n", pi->dado.numero_contatos);
		printf("\nNome: %s \t", pi->dado.Contatos.nome);
		printf("Idade: %d \t", pi->dado.Contatos.idade);
		printf("Número de telefone: %d \t", pi->dado.Contatos.telefone);
		printf("Email: %s \n", pi->dado.Contatos.email);
    	printf("\n___________________________________________________________________________________________________\n");

	}
}

struct No * pesquisar (Lista lista, char *nome ) { ///aqui usa o metodo de busca com o telefone
    struct No* pi;
    for(pi = lista.inicio; pi != NULL && strcmp(pi->dado.Contatos.nome,nome); pi = pi->prox);
    return pi;
}
struct No * Busca_agenda (Lista lista, char *nome ) { //aqui usa o metodo de busca com o telefone 
    struct No* pi;
    for(pi = lista.inicio; pi != NULL && strcmp(pi->dado.nome,nome); pi = pi->prox);
    return pi;
}

void deletar_Nome(Lista *plista, char *nome) {
	if(plista->inicio == NULL) {  //Quanda a agenda está vazia
		printf("\n");
		printf("A lista está vazia. \n");
		printf("\n");
	}
	else if(  !strcmp(plista->inicio->dado.Contatos.nome, nome) ) { 
		struct No* pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
	}
	else if(plista->inicio->prox == NULL){ 
		if(  strcmp(plista->inicio->dado.Contatos.nome,nome) ) {
			printf("\n");
			printf("O contato não pode ser removido.\n"); 
			printf("\n");
		}
	}
	else {
		struct No* pa;
		struct No* pi;
		for(pi = plista->inicio; pi != NULL &&  !strcmp(pi->dado.Contatos.nome,nome)  ; pi = pi->prox){
			pa = pi;
		}
			if(pi == NULL) {
			printf("\nO contato não pode ser removido.\n\n");
		}
		else {
			pa->prox = pi->prox;
			free(pi);
		}
	}
}

void alterar_nome(Lista *lista,char *nome, char nome1[]) { //alterar o nome
   struct No *pi = pesquisar(*lista,nome);
    if(pi == NULL){
       printf("O contato não pode ser alterado!\n");
    }
   else{
       strcpy(pi->dado.Contatos.nome, nome1);
       
   }
}
void alterar_idade(Lista *lista, char *nome, int idade) { //alterar a idade	
  struct  No *pi = pesquisar(*lista,nome);
   if(pi == NULL){
        printf("O contato não pode ser alterado!\n");
    }
  else{
      pi->dado.Contatos.idade = idade;

       
   }
}
void alterar_telefone(Lista *lista, char *nome, int telefone) { //alterar o telefone
   struct No *pi = pesquisar(*lista,nome);
    if(pi == NULL){
        printf("O contato não pode ser alterado!\n");
    }
    else{
      pi->dado.Contatos.telefone = telefone;
      
    }
}

void alterar_Email(Lista *lista, char *nome, char email[]) { //alterar email
  struct No *pi = pesquisar(*lista,nome);
    if(pi == NULL){
       printf("O contato não pode ser alterado!\n");
    }
  else{  
        strcpy(pi->dado.Contatos.email, email);     
   }
}
