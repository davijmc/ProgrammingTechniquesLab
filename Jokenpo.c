#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    char computador, usuario, sorteio, resp, cont;
    printf("(r)ocha - (p)apel - (t)esoura - (l)agarto - (s)pook\n");
    srand(time(NULL));
    while(cont != 'n'){
        printf("Digite a letra da sua opcao: ");
        usuario = getch();
        printf("%c", usuario);
        if((usuario == 'r') || (usuario == 'p') || (usuario == 't') || (usuario == 'l') || (usuario == 's')){
            sorteio = rand() % 5;
            switch(sorteio){
            case 0 :
                computador = 'r';
                break;
            case 1 :
                computador = 'p';
                break;
            case 2 :
                computador = 't';
                break;
            case 3 :
                computador = 'l';
                break;
            case 4 :
                computador = 's';
                break;
            }
            printf("\ncomputador = %c\n", computador);
            if(computador == usuario){
                printf("empate\n");
            }
            else
            {
                if(((usuario=='t') && (computador=='p')) ||
                        ((usuario=='t') && (computador=='l')) ||
                        ((usuario=='p') && (computador=='r')) ||
                        ((usuario=='p') && (computador=='s')) ||
                        ((usuario=='r') && (computador=='l')) ||
                        ((usuario=='r') && (computador=='t')) ||
                        ((usuario=='l') && (computador=='p')) ||
                        ((usuario=='l') && (computador=='s')) ||
                        ((usuario=='s') && (computador=='r')) ||
                        ((usuario=='s') && (computador=='t')))
                {
                    printf("usuario vence");
                }
                else
                {
                    printf("computador vence");
                }
            }
        }
        else
        {
            printf("\nOpcao invalida!");
        }
        printf("\nQuer jogar novamente? (s)im - (n)ao : ");
        cont = getch();
        printf("%c\n", cont);
        if(cont == 'n')
        {
            break;
        }
    }
return 0;
}
