#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int larva=0;
int alga=1;
int sais=1;
int jogadas=1;
char tanque[25][50];
//imprime mat tanque
void imprime(){
    int i, j;
    printf("              1111111111222222222233333333334444444444\n");
    printf("    01234567890123456789012345678901234567890123456789\n");
    for(i=0; i<25; i++){
        printf("[%2d]",i);
        for(j=0; j<50; j++){
            printf("%c", tanque[i][j]);
        }
        printf("\n");
    }
}
void inicializa(){//inicializa o tanque com simbolos
    int i, j, lin, col;
    for(i=0; i<25; i++){
        for(j=0; j<50; j++){
            tanque[i][j] = ' ';
        }
    }
    //3 triangulos 1-3
    for(i=0; i<3;i++){
        lin = rand()%24;
        col = rand()%48;
        tanque[lin][col+1] = ':';
        tanque[lin+1][col] = ':';
        tanque[lin+1][col+1] = ':';
        tanque[lin+1][col+2] = ':';
    }
    //2 triangulos 1-3-5
    for(i=0; i <2; i++){
        lin = rand() %23;
        col = rand() %46;
        tanque[lin][col+2] = ':';
        tanque[lin+1][col+1] = ':';
        tanque[lin+1][col+2] = ':';
        tanque[lin+1][col+3] = ':';
        tanque[lin+2][col] = ':';
        tanque[lin+2][col+1] = ':';
        tanque[lin+2][col+2] = ':';
        tanque[lin+2][col+3] = ':';
        tanque[lin+2][col+4] = ':';
    }
    for(i=0; i<10;){//faz concha, i++ no if
        lin = rand() %(25-2)+1;
        col = rand() %(50-2)+1;
        if(tanque[lin][col] == ' '){
            tanque[lin][col] = '@';
            i++;
        }
    }
    for(i=0; i<5; i++){//faz alga, i++ normal e i-- no else
        lin = rand() %25;
        col = rand() %50;
        if(tanque[lin][col] == ' '){
            tanque[lin][col] = 'y';
        }
        else{
            i--;
        }
    }
    for(i=0; i<3;){//faz 3 peixin
        lin = rand() %25;
        col = rand() %50;
        if(tanque[lin][col] == ' '){
            tanque[lin][col] = 'x';
            i++;
        }
    }
    for(i=0; i<2;){//faz 2 peixao
        lin = rand() %25;
        col = rand() %50;
        if(tanque[lin][col] == ' '){
            tanque[lin][col] = 'X';
            i++;
        }
    }
}
void cultivar(){
    int lin, col;
    if(alga > 0){
        printf("cultivar alga [linha coluna]: ");
        scanf("%d %d",&lin, &col);
        getchar();//captura enter
        if((lin>=0)&&(lin<=24)&&(col>=0)&&(col<=49)){
            if(tanque[lin][col] == ' '){
                tanque[lin][col] = 'y';
                alga--;
                jogadas++;
            }
            else{
                printf("Posicao ocupada.");
            }
        }
        else{
            printf("cordenadas invalidas.");
        }
    }
    else{
        printf("Sem saldo de alga!\n");
    }
}
void fertilizar(){
    int lin, col;
    if(sais > 0){
        printf("fertilizar alga [linha coluna]: ");
        scanf("%d %d",&lin, &col);
        getchar();//captura enter
        if((lin>=0)&&(lin<=24)&&(col>=0)&&(col<=49)){
            if(tanque[lin][col] == 'y'){
                tanque[lin][col] = 'Y';
                sais--;
                jogadas++;
            }
            else{
                printf("Posicao ocupada.");
            }
        }
        else{
            printf("cordenadas invalidas.");
        }
    }
    else{
        printf("Sem saldo de sais!\n");
    }
}
void mover(){
    int l1, c1, l2, c2;
    printf("Cordenada de origem [linha coluna]");
    scanf("%d %d", &l1, &c1);
    getchar();  //captura o enter
    if((l1>=0)&&(l1<25)&&(c1>=0)&&(c1<25)){
        if((tanque[l1][c1] == '-')||
           (tanque[l1][c1] == 'x')||
           (tanque[l1][c1] == 'X')){
            printf("Cordenada de destino[linha coluna]");
            scanf("%d %d", &l2, &c2);
            getchar();  //captura o enter
            if((l2>=0)&&(l2<25)&&(c2>=0)&&(c2<25)){
                if((l2-l1>=-1)&&(l2-l1<=1)&&(c2-c1>=-1)&&(c2-c1<=1)){//checa vizinho
                    if(tanque[l2][c2] == ' '){//move
                        tanque[l2][c2] = tanque[l1][c1];
                        tanque[l1][c1] = ' ';
                        jogadas++;
                    }
                    if((tanque[l2][c2] == ':')||(tanque[l2][c2] == '@')){//morre
                        tanque[l1][c1] = ' ';
                        jogadas++;
                    }
                    if((tanque[l1][c1] == 'X')&&(tanque[l2][c2] == 'x')){
                        if(larva>0){
                            tanque[l1][c1] = '-';
                            larva--;
                            jogadas++;
                        }else{
                            printf("Sem saldo de larva\n");
                        }
                    }
                    if((tanque[l2][c2]=='y')||(tanque[l2][c2]=='Y')){//evolui
                        if(tanque[l1][c1]=='-'){
                            tanque[l2][c2]='x';
                            tanque[l1][c1]=' ';
                            jogadas++;
                        }
                        if(tanque[l1][c1]=='x'){
                            tanque[l2][c2]='X';
                            tanque[l1][c1]=' ';
                            jogadas++;
                        }
                        if(tanque[l1][c1]=='X'){
                            tanque[l2][c2]='x';
                            tanque[l1][c1]=' ';
                            jogadas++;
                        }
                    }
                }else{
                    printf("\nDestino invalido!");
                }
            }
            }else{
            printf("\nNao tem peixin!");
            }

    }else{
        printf("\nCordenada invalida!");
    }
}
void quebrar(){
    int lin, col;
    printf("quebrar concha [linha coluna]: ");
    scanf("%d %d",&lin, &col);
    getchar();//captura enter
    if((lin>=0)&&(lin<=24)&&(col>=0)&&(col<=49)){
        if(tanque[lin][col] == '@'){
            tanque[lin][col] = ' ';
            if(rand()%100<25){sais++;}
            if(rand()%100<25){alga++;}
            if(rand()%100<25){larva++;}
            if(rand()%100<10){sais+=2;}
            if(rand()%100<10){alga+=2;}
            if(rand()%100<5){larva+=2;}
            jogadas++;
        }
        else{
            printf("\ncordenada sem concha.");
        }
    }
    else{
        printf("\ncordenadas invalidas.");
    }
}
void pescar(){
    int lin, col;
    printf("pescar peixe[linha coluna]: ");
    scanf("%d %d",&lin, &col);
    getchar();//captura enter
    if((lin>=0)&&(lin<=24)&&(col>=0)&&(col<=49)){
        if(tanque[lin][col] == 'x'){
            tanque[lin][col] = ' ';
            sais++;
            jogadas++;
        }
        if(tanque[lin][col] == 'X'){
            tanque[lin][col] = ' ';
            sais+=2;
            larva++;
            jogadas++;
        }
    }
    else{
        printf("\ncordenadas invalidas.");
    }
}
void noite(){
    int i, j;
    for(i=0; i<25; i++){
        for(j=0; j<25; j++){
            if((tanque[i][j]=='-')&&(rand()%100<30)){
                tanque[i][j] = 'x';
            }
            if((tanque[i][j]=='y')&&(rand()%100<50)){
                tanque[i][j] = 'Y';
            }
            if((tanque[i][j]==' ')&&(rand()%1250==0)
               &&(i!=0)&&(i!=24)&&(j!=0)&&(j!=49)){
                tanque[i][j] = '@';
            }
            if(tanque[i][j]=='@'){
                    tanque[i-1][j-1] = ' ';
                    tanque[i-1][j] = ' ';
                    tanque[i-1][j+1] = ' ';
                    tanque[i][j-1] = ' ';
                    tanque[i][j+1] = ' ';
                    tanque[i+1][j-1] = ' ';
                    tanque[i+1][j] = ' ';
                    tanque[i+1][j+1] = ' ';
            }
        }
    }
}
int main( int argc, char * arv[]){
    char op = ' ';
    srand(time(NULL));
    inicializa();
    while(op != 's'){
        //func imprime
        imprime();
        printf("larva=%d alga=%d sais=%d\n", larva, alga, sais);
        printf("(c)ultivar / (f)ertilizar / (m)over / (q)uebrar / (p)escar / (n)oite / (s)air");
        printf("[Jogada %d] opcao:", jogadas);
        op = getch();
        printf("%c\n", op);
        switch(op){
            case 'c' :
                cultivar();
                break;
            case 'f' :
                fertilizar();
                break;
            case 'm' :
                mover();
                break;
            case 'q' :
                quebrar();
                break;
            case 'p' :
                pescar();
                break;
            case 'n' :
                noite();
                break;
            case 's' :
                break;
            default:
                printf("[opcao invalida]\n");
                break;
        }
        if(jogadas > 7){
            noite();
            imprime();
        }
    }
return 0;
}
