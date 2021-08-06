#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char map[25][50];
int leite = 1;
int fo = 0;
int trigo = 0;
int jogadas = 0;
void imprime(){//escreve a matriz
    int i, j;
    printf("\n              1111111111222222222233333333334444444444");
    printf("\n    01234567890123456789012345678901234567890123456789\n");
    for(i=0; i<25; i++){
        printf("[%2d]",i);
        for(j=0; j<50; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("Leite= %d;  Farinha de Osso= %d;  Trigo= %d; Jogadas: %d", leite, fo, trigo, jogadas+1);
    printf("\n(f)ertilizar / (c)olher / (o)rdenar / (a)limentar / (m)over / (n)oite / (s)air / OPCAO: ");
}
void start(){
    int i, j, lin, col;
    for(i=0; i<25; i++){//start vazio
        for(j=0; j<50; j++){
            map[i][j] = ' ';
        }
    }
    for(i=0; i<3; i){//seta lama 2x3
        lin = rand() %24;
        col = rand() %49;
        if((map[lin][col-1]==' ')&&(map[lin+1][col+1]==' ')&&(map[lin][col+1]==' ')&&(map[lin+1][col-1]==' ')){
            map[lin][col-1] = '~';
            map[lin][col] = '~';
            map[lin][col+1] = '~';
            map[lin+1][col-1] = '~';
            map[lin+1][col] = '~';
            map[lin+1][col+1] = '~';
            i++;
        }
    }
    for(i=0; i<3; i){//seta lama 3x2
        lin = rand() %24;
        col = rand() %48;
        if((map[lin][col]==' ')&&(map[lin+2][col]==' ')&&(map[lin][col+1]==' ')&&(map[lin+2][col+1]==' ')){
            map[lin][col] = '~';
            map[lin+1][col] = '~';
            map[lin+2][col] = '~';
            map[lin][col+1] = '~';
            map[lin+1][col+1] = '~';
            map[lin+2][col+1] = '~';
            i++;
        }
    }
    for(i=0; i<5; i){//cria broto
        lin = rand() %24;
        col = rand() %49;
        if(map[lin][col]== ' '){
            map[lin][col] = 't';
            i++;
        }
    }
    for(i=0; i<11; i){//spawna rapoza
        lin = rand() %24;
        col = rand() %49;
        if(map[lin][col]== ' '){
            map[lin][col] = 'R';
            i++;
        }
    }
    for(i=0; i<5; i){//coloca cabra com cifre Ü
        lin = rand() %24;
        col = rand() %49;
        if(map[lin][col]== ' '){
            map[lin][col] = -102;
            i++;
        }
    }
}
void fertilizar(){
    int lin, col;
    if(fo>0){
        printf("\nFERTILIZAR [linha coluna]: ", lin, col);
        scanf("%d %d", &lin, &col);
        if((lin>=0)&&(lin<25)&&(col>=0)&&(col<50)){
            if(map[lin][col]=='t'){
                map[lin][col] = 'T';
                fo--;
                jogadas++;
            }else{
                printf("Posi%c%co sem trigo!", 135, 198);
            }
        }else{
            printf("\nPosi%c%co inv%clida!", 135, 198, 160);
        }
    }else{
        printf("Sem saldo de farinha de osso!");
    }
}
void colher(){
    int lin, col;
    printf("\nCOLHER [linha coluna]: ", lin, col);
    scanf("%d %d", &lin, &col);
    if((lin>=0)&&(lin<25)&&(col>=0)&&(col<50)){
        if(map[lin][col]=='T'){
            map[lin][col] = ' ';
            trigo++;
            jogadas++;
        }else{
            if(map[lin][col]=='t'){
                printf("\nEsse trigo ainda não cresceu!");
            }else{
                printf("\nPosi%c%co sem trigo!", 135, 198);
            }
        }
    }else{
        printf("\nPosi%c%co inv%clida!", 135, 198, 160);
    }
}
void ordenhar(){
    int lin, col;
    printf("\nCOLHER [linha coluna]: ", lin, col);
    scanf("%d %d", &lin, &col);
    if((lin>=0)&&(lin<25)&&(col>=0)&&(col<50)){
        if(map[lin][col]=='U'){
            map[lin][col] = -102;
            leite++;
            jogadas++;
        }else{
            printf("\nPosi%c%co sem cabra sem chifre!", 135, 198);
        }
    }else{
        printf("\nPosi%c%co inv%clida!", 135, 198, 160);
    }
}
void alimentar(){
    int lin, col;
    printf("\nALIMENTAR [linha coluna]: ");
    scanf("%d %d", &lin, &col);
    if((lin>=0)&&(lin<25)&&(col>=0)&&(col<50)){
        if((map[lin][col]=='u')||(map[lin][col]== -102)){
            if(map[lin][col]=='u'){
                if(leite>0){
                    map[lin][col] = -102;
                    leite--;
                    jogadas++;
                }else{
                    printf("Sem saldo de leite");
                }
            }else{
                if(trigo>0){
                    if(map[lin][col+1]== -102){
                        if(map[lin][col+2]==' '){
                            map[lin][col+2] = 'u';
                            trigo--;
                            jogadas++;
                        }
                    }
                }else{
                    printf("\nSem saldo de trigo!");
                }
            }
        }else{
            printf("\nPosi%c%co sem cabrita (u) cabra com chifre(%c)!", 135, 198, -102);
        }
    }else{
        printf("\nPosi%c%co inv%clida!", 135, 198, 160);
    }
}
void mover(){
    int lin, col, lin2, col2;
    printf("\nMOVER [linha coluna]: ");
    scanf("%d %d", &lin, &col);
    if((lin>=0)&&(lin<25)&&(col>=0)&&(col<50)){//está na matriz?
        if((map[lin][col] == 'u')||(map[lin][col] == 'U')||(map[lin][col] == -102)){//eh cabra?
            printf("\nMOVER [linha2 coluna2]: ");
            scanf("%d %d", &lin2, &col2);
            if((lin2>=0)&&(lin2<25)&&(col2>=0)&&(col2<50)){//col e lin 2 esta na matriz
                if(((lin2 == lin)||(lin2 == lin + 1)||(lin2 == lin - 1))&&
                   ((col2 == col)||(col2 == col + 1)||(col2 == col - 1))){
                    if(map[lin2][col2] == ' '){
                        map[lin2][col2] = map[lin][col];
                        map[lin][col] = ' ';
                        jogadas++;
                    }else{
                        if((map[lin2][col2] == 'R')&&(map[lin][col] == -102)){//cabra chifruda mata R e perde chifre
                            map[lin2][col2] = 'U';
                            map[lin][col] = ' ';
                            fo++;
                            jogadas++;
                        }
                    }
                }else{
                    printf("\nPosi%c%co inv%clida!", 135, 198, 160);
                }
            }else{
                printf("\nPosi%c%co inv%clida!", 135, 198, 160);
            }
        }else{
            printf("\nPosi%c%co sem cabra!", 135, 198);
        }
    }else{
        printf("\nPosi%c%co inv%clida!", 135, 198, 160);
    }
}
void noite(){
    int i, j, lin, col;
    for(i=0; i<25; i++){
        for(j=0; j<50; j++){
            if(map[i][j] == 'R'){//rapozas indo embora
                map[i][j] = ' ';
            }else{
                if((map[i][j] == ' ')&&(rand()%1250 < 1)){//brota trigo
                    map[i][j] = 't';
                }else{
                    if((map[i][j] == 'U')&&(rand()%3 < 1)){//cabra evolui
                        map[i][j] = -102;
                    }
                }
            }
        }
    }
    for(i=0; i<11; i){//volta com 11 rapozas que podem comer as cabras
        lin = rand() %24;
        col = rand() %49;
        if((map[lin][col]== ' ')||(map[lin][col]== 'u')||(map[lin][col]== 'U')||(map[lin][col]== -102)){
            map[lin][col] = 'R';
            i++;
        }
    }
    printf("\nPassou a noite!");
}
void hack(){
    leite+=100;
    fo+=100;
    trigo+=100;
}
void salvar(){
    FILE * arq;
    char nome_arq[20];
    int i, j;
    system("cls");
    printf("\nDigite o nome do arquivo (nomedoarquivo.txt): ");
    gets(nome_arq);
    arq = fopen(nome_arq, "w");
    if(arq!=NULL){
        for(i=0; i<25; i++){
            for(j=0; j<50; j++){
                fprintf(arq, "%c", map[i][j]);
            }
            fprintf(arq, "\n");
        }
        fprintf(arq, "%d\n", leite);
        fprintf(arq, "%d\n", trigo);
        fprintf(arq, "%d\n", fo);
        fprintf(arq, "%d\n", jogadas);
        fclose(arq);
    }else{
        salvar();
    }
}
void carregar(){
    FILE * arq;
    char nome_arq[20];
    int i,j;
    printf("\nDigite o nome do arquivo: ");
    gets(nome_arq);
    arq = fopen(nome_arq, "r");
    if(arq!=NULL){
        for(i=0; i<25; i++){

            for(j=0; j<50; j++){
                fscanf(arq, "%c", &map[i][j]);
            }
            fgetc(arq);
        }
        fscanf(arq, "%d\n", &leite);
        fscanf(arq, "%d\n", &trigo);
        fscanf(arq, "%d\n", &fo);
        fscanf(arq, "%d\n", &jogadas);

        fclose(arq);
    }else{
        printf("\narquivo nao encontrado!");
    }
}
int main(int argc, char *argv[]){
    int sair = 0;
    char botao;
    srand(time(NULL));
    start();
    printf("Deseja carregar um jogo salvo? [s/n]");
    botao = getch();
    printf("%c\n",botao);
    if(botao == 's'){
        carregar();
    }
    botao = ' ';
    while(sair<1){
        imprime();
        botao = getch();
        printf(" %c", botao);
        switch(botao){
            case 'f':
                fertilizar();
                break;
            case 'c':
                colher();
                break;
            case 'o':
                ordenhar();
                break;
            case 'a':
                alimentar();
                break;
            case 'm':
                mover();
                break;
            case 'n':
                //só pra teste, depois trirar
                //noite();
                break;
            case 'h':
                //hack();
                break;
            case 's':
                sair = 1;
                break;
            default:
                break;
        }
        if(jogadas >= 7){
            noite();
            jogadas = 0;
        }
    }
    printf("\nDeseja salvar o jogo? [s/n]");
    botao = getch();
    printf("%c\n", botao);
    if(botao=='s'){
        botao = ' ';
        salvar();
    }
    return 0;
}
