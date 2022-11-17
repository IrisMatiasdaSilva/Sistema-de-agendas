
typedef struct agenda Agenda;

typedef struct no No;

void Imprimir(Lista lista);

void deletar_Nome(Lista *plista, char *nome);

void alterar_nome(Lista *lista,char *nome, char nome1[]);

void alterar_idade(Lista *lista, char *nome, int idade);

void alterar_telefone(Lista *lista, char *nome, int telefone);

void alterar_Email(Lista *lista, char *nome, char email[]);
