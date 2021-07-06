#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main(int argc, char * argv[]){
    int i, j, l1, c1, l2, c2, aux;
    char jogador='o';
    char adversario='x';
    char vencedor=' ';
    bool fimJogo = false;
    bool possivel = false;
    char tab[10][10] = {
    {'o','o','o','o','o','o','o','o','o','o'},
    {'o','o','o','o','o','o','o','o','o','o'},
    {'o','o','o','o','o','o','o','o','o','o'},
    {'o','o','o','o','o','o','o','o','o','o'},
    {'o','o','o','o','o','o','o','o','o','o'},
    {'x','x','x','x','x','x','x','x','x','x'},
    {'x','x','x','x','x','x','x','x','x','x'},
    {'x','x','x','x','x','x','x','x','x','x'},
    {'x','x','x','x','x','x','x','x','x','x'},
    {'x','x','x','x','x','x','x','x','x','x'}};//comecomat
    srand(time(NULL));
    for(i=0;i<70;i++){//embaralhar
        l1 = rand() % 10;
        c1 = rand() % 10;
        l2 = rand() % 10;
        c2 = rand() % 10;
        aux=tab[l2][c2];
        tab[l2][c2]=tab[l1][c1];
        tab[l1][c1]=aux;
    }
    while (fimJogo==false){
        //imprimir na tela
        printf("   0  1  2  3  4  5  6  7  8  9\n");
        for(i=0; i<10; i++){
            printf("%d ", i);
            for(j=0; j<10; j++){
                printf("[%c]", tab[i][j]);
            }
            printf("\n");
        }
        printf("[%c] captura [%c] (linha1 coluna1 linha2 coluna2): ", jogador, adversario);
        scanf("%d %d %d %d", &l1, &c1, &l2, &c2);
        if( (l1>=0)&&(l1<=9)&&(c1>=0)&&(c1<=9)&&(l2>=0)&&(l2<=9)&&(c2>=0)&&(c2<=9) ){  //olhalimite
            if( (abs(l2-l1)<=1)&&(abs(c2-c1)<=1) ){  //olha vizinho, serve pro campo minado
                if( (tab[l1][c1] == jogador)&&(tab[l2][c2] == adversario) ){  //olha jogador e adversario
                    tab[l2][c2] = jogador;//troca destino por jogador e origem por vazio
                    tab[l1][c1] = ' ';
                    if(jogador=='o'){//inverte o jogadors
                        jogador = 'x';
                        adversario = 'o';
                    }else{
                        jogador = 'o';
                        adversario = 'x';
                    }
                    possivel = false;
                    for(i=0;i<10;i++){//teste de captura, possivel = true;
                        for(j=0;j<10;j++){
                            if((tab[i][j]==jogador)&&(
                               ((i-1>=0)&&(j-1>=0)&&(tab[i-1][j-1]==adversario))||
                               ((i-1>=0)&&(tab[i-1][j]==adversario))||
                               ((i-1>=0)&&(j+1<=9)&&(tab[i-1][j+1]==adversario))||

                               ((j-1>=0)&&(tab[i][j-1]==adversario))||
                               ((j+1<=9)&&(tab[i][j+1]==adversario))||

                               ((i-1>=0)&&(j-1>=0)&&(tab[i+1][j-1]==adversario))||
                               ((i-1>=0)&&(tab[i+1][j]==adversario))||
                               ((i-1>=0)&&(j+1<=9)&&(tab[i+1][j+1]==adversario))
                                )){
                                possivel=true;
                            }
                        }
                    }

                    if(possivel==false){
                        fimJogo=true;
                        vencedor=adversario;
                    }
                }
                else{
                    printf("coordenadas devem ter [%c] e [%c]\n", jogador, adversario);
                }
            }
            else{
                printf("destino deve estar ha uma posicao\n");
            }
        }
        else{
            printf("coordenadas invalidas\n");
        }
    }
    printf("   0  1  2  3  4  5  6  7  8  9\n");
        for(i=0; i<10; i++){
            printf("%d ", i);
            for(j=0; j<10; j++){
                printf("[%c]", tab[i][j]);
            }
            printf("\n");
        }
    printf("Jogador = %c\n", jogador);
    printf("vencedor eh [%c]\n", vencedor);
    return 0;
}
