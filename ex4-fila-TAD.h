typedef struct no * fila;

struct pacientes
{
    char nome[20];
    int idade;
    float peso;
    int altura;
    char doenca;
    int gravidade;   // 1 menos grave; 5 mais grave
};

fila cria_fila();
int fila_vazia(fila A);
int remove_ordenada(fila* A, struct pacientes *elem);
int insere_final(fila *A, struct pacientes elem);
int apaga_fila(fila *A);
int get_elem_pos(fila A, int pos, struct pacientes *elem);
int esvazia_fila(fila *A);
