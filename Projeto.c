#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h>
#include <windows.h>

typedef struct contatos{
    char nome[100];
    int idade;
    int telefone;
    char email[100];
}Contatos;

typedef struct agendas{
    char nome[100];
    char codigo_de_identificacao[20];
    int numero_contatos;
    struct contatos Contatos;
}Agendas;

struct No {
	Agendas dado;
	struct No* prox;
};

typedef struct {
	struct No* inicio;
} Lista;


//Função para ler agenda e contatos
void ler(Agendas *a){
	
		 
	printf("\n*******************************************");
	printf("\n    DIGITE AS INFORMAÇÕES DA AGENDA        \n");
	printf("*******************************************\n");
	
		printf("Digite o nome da agenda:\n");
		scanf(" %s", a->nome);
		printf("Digite o código de verificação da agenda:\n");
		scanf(" %s", a->codigo_de_identificacao);
		printf("Digite o número de contatos da agenda:\n");
		scanf("%d", &a->numero_contatos);	
	system("cls");	
		
	printf("\n*********************************************");
	printf("\n     DIGITE AS INFORMAÇÕES DO CONTATO        \n");
	printf("*********************************************\n\n");
	
		printf("Informe o nome:\n");
		scanf(" %s", a->Contatos.nome);
		printf("Informe a idade:\n");
		scanf("%d", &a->Contatos.idade);
		printf("Informe o número de telefone:\n");
	    scanf("%d", &a->Contatos.telefone);
		printf("Informe o email:\n");
		scanf(" %s", a->Contatos.email);  
	
	system("cls");
	
	FILE *arquivo_agenda;
    arquivo_agenda =fopen("ListaContatos.txt", "a");
    
   if(arquivo_agenda == NULL){
		printf("ERRO AO ABRIR ARQUIVO!");
	}
//	else {
//		printf("Salvo com sucesso!");
//	}
	fprintf(arquivo_agenda, "Nome da agenda: %s\tCódigo de verificação da agenda: %s\tNúmero de contatos da agenda: %d\n\nNome: %s\tIdade: %d\tTelefone: %d\tEmail: %s\n", a->nome, a->codigo_de_identificacao, a->numero_contatos,  a->Contatos.nome, a->Contatos.idade, a->Contatos.telefone,  a->Contatos.email );
	fclose(arquivo_agenda);
		
}

// inserindo numa lista encadeada no inicio
void inserir_inicio(Lista* plista, Agendas dado) {
	struct No* novo = (struct No*) malloc(sizeof(struct No));
	novo->dado = dado;
	novo->prox = plista->inicio;
	plista->inicio = novo;
}

// imprindo todos os contato da lista
void Imprimir(Lista lista) {
	struct No * pi;
	for(pi = lista.inicio; pi != NULL  ; pi = pi->prox) {
        printf("___________________________________________________________________________________________________\n");
        printf("Nome da Agenda: %s \t", pi->dado.nome);
		printf("Códico de verificação da agenda: %s \t", pi->dado.codigo_de_identificacao);
		printf("Número de contato da agenda: %d \n", pi->dado.numero_contatos);
		printf("\nNome: %s \t", pi->dado.Contatos.nome);
		printf("Idade: %d \t", pi->dado.Contatos.idade);
		printf("Número de telefone: %d \t", pi->dado.Contatos.telefone);
		printf("Email: %s \n", pi->dado.Contatos.email);
    	printf("\n___________________________________________________________________________________________________\n");

	}
	system("pause");
	system("cls");
	
}



struct No * pesquisar (Lista lista, char *nome ) { 
    struct No* pi;
    for(pi = lista.inicio; pi != NULL && strcmp(pi->dado.Contatos.nome,nome); pi = pi->prox);
    return pi;
}
struct No * Busca_agenda (Lista lista, char *nome ) { 
    struct No* pi;
    for(pi = lista.inicio; pi != NULL && strcmp(pi->dado.nome,nome); pi = pi->prox);
    return pi;
}

//Função remover contatos
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
    system("pause");
	system("cls");
 
}

//Função para alterar na lista, ou seja, editar o contato
void alterar_nome(Lista *lista,char *nome, char nome1[]) { //alterar o nome
   struct No *pi = pesquisar(*lista,nome);
    if(pi == NULL){
       printf("O contato não pode ser alterado!\n");
    }
   else{
       strcpy(pi->dado.Contatos.nome, nome1);
       
   }
   	system("pause");
	system("cls");
}
void alterar_idade(Lista *lista, char *nome, int idade) { //alterar a idade	
  struct  No *pi = pesquisar(*lista,nome);
   if(pi == NULL){
        printf("O contato não pode ser alterado!\n");
    }
  else{
      pi->dado.Contatos.idade = idade;

       
   }
   	system("pause");
	system("cls");
}
void alterar_telefone(Lista *lista, char *nome, int telefone) { //alterar o telefone
   struct No *pi = pesquisar(*lista,nome);
    if(pi == NULL){
        printf("O contato não pode ser alterado!\n");
    }
    else{
      pi->dado.Contatos.telefone = telefone;
      
    }
 	system("pause");
	system("cls");
}

void alterar_Email(Lista *lista, char *nome, char email[]) { //alterar email
  struct No *pi = pesquisar(*lista,nome);
    if(pi == NULL){
       printf("O contato não pode ser alterado!\n");
    }
  else{  
        strcpy(pi->dado.Contatos.email, email);     
   }
   	system("pause");
	system("cls");
}

//Função para consultar quantitativo de agendas
int Consultar_quantitativo(Lista lista){
	struct No *pi;
	int cont=0;
	for(pi = lista.inicio; pi!=NULL; pi=pi->prox){
		cont++;
	}
	return cont;
	
    system("pause");
	system("cls");
}

void menu(){
    printf("\n|*********************************************|");
    printf("\n|                   MENU                      |\n");
	printf("|*********************************************|");
	printf("\n|---------------------------------------------|\n");
    printf("|1. Adicionar contato                         |");
	printf("\n|---------------------------------------------|\n");
 	printf("|2. Remover contato                           |");
	printf("\n|---------------------------------------------|\n");
    printf("|3. Listar contatos cadastrados               |");
	printf("\n|---------------------------------------------|\n");
    printf("|4. Editar o contato                          |");
	printf("\n|---------------------------------------------|\n");
    printf("|5. Buscar contato                            |");
	printf("\n|---------------------------------------------|\n");
    printf("|6. Consultar contato em uma dada agenda      |");
	printf("\n|---------------------------------------------|\n");
    printf("|7. Consultar quantitativo de agendas         |");
	printf("\n|---------------------------------------------|\n");
    printf("|8. Sair                                      |");
	printf("\n|---------------------------------------------|\n");
}

int main(){
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

  menu();
  printf("\nESCOLHA UMA OPÇÃO:  ");
  scanf("%d", &op);
  system("cls");
  
  
  switch(op) {
  case 1:
  		ler(&agenda);
  		inserir_inicio(&lista, agenda);
		break;

  case 2:
		printf("Digite o nome do contato que você deseja deletar:\n");	
		scanf(" %s", nome);
		deletar_Nome(&lista, nome);
  		break;
  	

  case 3:
  		Imprimir(lista);
  		break;
  	
  	case 4:	
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

  case 5:
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
  
  case 6:
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
  
  case 7: 
  	resp = Consultar_quantitativo(lista);
  	printf("Quantidade de agendas: %d",resp);
	break;

  case 8:
  	printf("Saindo...\n");
	printf("\n=============================================================\n");
	printf("Obrigada por usar o meu sistema de gerenciamento de contatos!");
	printf("\n=============================================================\n");
                          
	printf("\n\nSistema desenvolvido por:\nÍris Matias da Silva.\n\n");
  	break;

  default:
  	Beep(1000,500); 
    printf("Este programa possui um bug.\nTente novamente.\n\n");
    Beep(1000,500); 
 	  system("pause");
	  system("cls");
    break;
  }

  }   
  while(op != 8);  

	return 0;

}
