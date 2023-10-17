#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    int i, j, x, y, comida, pontos, lixo;
    char m[10][10], botao;
    srand(time(NULL));

    for (i = 0; i < 10; i++){ //prenche matriz com vazio
        for (j = 0; j < 10; j++)
        {
            m[i][j] = ' ';
        }
    }
    m[4][4] = 'o'; //seta posicao inicial
    for (j = 0; j < 60; j){
        x = rand() % 10;
        y = rand() % 10;
        if ((m[x][y] != 'o') && (m[x][y] != '-'))
        {
            m[x][y] = '-';
            j++;
        }
    }
    comida = 1;
    pontos = 0;
    while (comida > 0){ //loop pincipal
        system("cls");
        comida = 99; //reset comida
        printf("\n   0   1   2   3   4   5   6   7   8   9"); //escreve matriz
        for (i = 0; i < 10; i++){
            printf("\n%d", i);
            for (j = 0; j < 10; j++){
                printf(" [%c]", m[i][j]);
                if (m[i][j] == 'o'){ //acha o jogador
                    x = i;
                    y = j;
                }
                else{
                    if (m[i][j] == ' '){ //confere se tem comida
                        comida--;
                    }
                }
            }
        }
        if (comida <= 0){
            break;
        }
        printf("\nMova o personagem 'o' com (w, a, s, d) ");
        botao = getch();
        switch (botao){
        case 'a':
            if ((y - 1) >= 0){
                if (m[x][y - 1] == '-'){
                    pontos++;
                }
                else{
                    pontos--;
                }
                m[x][y - 1] = 'o';
                m[x][y] = ' ';
            }
            break;
        case 'd':
            if ((y + 1) <= 9){
                if (m[x][y + 1] == '-'){
                    pontos++;
                }
                else{
                    pontos--;
                }
                m[x][y + 1] = 'o';
                m[x][y] = ' ';
            }
            break;
        case 'w':
            if ((x - 1) >= 0){
                if (m[x - 1][y] == '-'){
                    pontos++;
                }
                else{
                    pontos--;
                }
            m[x - 1][y] = 'o';
            m[x][y] = ' ';
            }
            break;
        case 's':
            if ((x + 1) <= 9){
                if (m[x + 1][y] == '-'){
                    pontos++;
                }
                else{
                    pontos--;
                }
                m[x + 1][y] = 'o';
                m[x][y] = ' ';
            }
                break;
            default:
                break;
            }
    }
    printf("\nParab%cns!! Voc%c fez %d pontos!", 130, 136, pontos);
    printf("\nPressione qualquer tecla para encerrar.\n");
    lixo = getch();
    return 0;
}
