#include <stdio.h>
#include <ctype.h>
#include "ex4-fila-TAD.h"

int main()
{
    struct pacientes X;
    struct pacientes view;
    int op = 0;
    int opconsult = 0;
    int guard = 0;
    fila A;

    printf("-=-=-=-=-CONTROLE DE PACIENTES-=-=-=-=-=-\n");
    printf("[0] Criar fila\n");
    printf("[1] Inserir paciente\n");
    printf("[2] Remover paciente\n");
    printf("[3] Consultar paciente\n");
    printf("[4] Esvaziar fila\n");
    printf("[5] Apagar fila\n");
    printf("[6] Encerrar programa\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    do
    {
        printf("Digite um comando: ");
        scanf("%d", &op);

        if(op==0)
        {
            if(guard==0)
            {
                A = cria_fila();
                guard++;
                printf("FILA CRIADA COM SUCESSO\n");
            }
            else
            {
                printf("FILA JÁ CRIADA\n");
            }
        }

        else if(op==1)
        {
            if(guard==1)
            {
                printf("Digite o NOME do paciente: ");
                scanf("%s", X.nome);

                printf("Digite a IDADE do paciente: ");
                scanf("%d", &X.idade);

                printf("Digite o PESO do paciente: ");
                scanf("%f", &X.peso);

                printf("Digite a ALTURA do paciente (em cm): ");
                scanf("%d", &X.altura);

                do
                {
                    printf("Digite a DOENCA do paciente (C,N,S,R): ");
                    scanf(" %c", &X.doenca);
                }while(X.doenca!='C'&&X.doenca!='N'&&X.doenca!='S'&&X.doenca!='R');

                do
                {
                    printf("Digite a GRAVIDADE da doenca (1 a 5): ");
                    scanf("%d", &X.gravidade);
                }while(X.gravidade<=0 || X.gravidade>5);

                if(insere_final(&A, X)==0)
                {
                    printf("ERRO AO INSERIR PACIENTE\n");
                }
                else
                {
                    printf("PACIENTE CADASTRADO\n");
                }
            }
            else
            {
                printf("CRIE UMA FILA\n");
            }
        }

        else if(op==2)
        {
            if(guard==1)
            {
                if(remove_ordenada(&A, &view)==1)
                {
                    printf("\nDADOS DO PACIENTE REMOVIDO:\n");
                    printf("%s\n", view.nome);
                    printf("%d anos\n", view.idade);
                    printf("%.2f kg\n", view.peso);
                    printf("%d cm\n", view.altura);
                    printf("Doenca: %c\n", view.doenca);
                    printf("Gravidade: %d\n", view.gravidade);
                }
                else
                {
                    printf("ERRO AO REMOVER PACIENTE\n");
                }
            }
            else
            {
                printf("CRIE UMA FILA\n");
            }
        }

        else if(op==3)
        {
            if(guard==1)
            {
                printf("Digite o número da fila que deseja consultar: ");
                scanf("%d", &opconsult);
                if(get_elem_pos(A, opconsult, &view)==1)
                {
                    printf("\nDADOS DO PACIENTE:\n");
                    printf("%s\n", view.nome);
                    printf("%d anos\n", view.idade);
                    printf("%.2f kg\n", view.peso);
                    printf("%d cm\n", view.altura);
                    printf("Doenca: %c\n", view.doenca);
                    printf("Gravidade: %d\n", view.gravidade);
                }
                else
                {
                    printf("ERRO AO OBTER DADOS DO PACIENTE, POSIÇÃO INEXISTENTE\n");
                }
            }
            else
            {
                printf("CRIE UMA FILA\n");
            }
        }

        else if(op==4)
        {
            if(guard==1)
            {
                if(esvazia_fila(&A)==1)
                {
                    printf("FILA ESVAZIADA\n");
                }
                else
                {
                    printf("ERRO AO ESVAZIAR FILA\n");
                }
            }
            else
            {
                printf("CRIE UMA FILA\n");
            }
        }

        else if(op==5)
        {
            if(guard==1)
            {
                if(apaga_fila(&A)==1)
                {
                    printf("FILA APAGADA\n");
                    guard--;
                }
                else
                {
                    printf("ERRO AO APAGAR FILA\n");
                }
            }
            else
            {
                printf("CRIE UMA FILA\n");
            }
        }

        else if(op==6)
        {
            break;
        }

        else
        {
            printf("DIGITE UM COMANDO VÁLIDO!\n");
        }
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    }while(op!=6);

    printf("\nPROGRAMA ENCERRADO, VOLTE SEMPRE!\n");
}
