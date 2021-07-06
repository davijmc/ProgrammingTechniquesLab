#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]){
    int f, i, j, k, l, s, letra, ponto, l1, l2, c1, c2, aux;
    int comb = 0;
    char a;
    char m[6][12] = {{'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'c', 'c', 'c', 'c'},//matriz estatica
                     {'d', 'd', 'd', 'd', 'e', 'e', 'e', 'e', 'f', 'f', 'f', 'f'},
                     {'g', 'g', 'g', 'g', 'h', 'h', 'h', 'h', 'i', 'i', 'i', 'i'},
                     {'j', 'j', 'j', 'j', 'k', 'k', 'k', 'k', 'l', 'l', 'l', 'l'},
                     {'m', 'm', 'm', 'm', 'n', 'n', 'n', 'n', 'o', 'o', 'o', 'o'},
                     {'p', 'p', 'p', 'p', 'q', 'q', 'q', 'q', 'r', 'r', 'r', 'r'}};

    srand(time(NULL));
    for(i=0; i<72; i++){//embaralhar matriz
        l1 = rand() %6;
        l2 = rand() %6;
        c1 = rand() %12;
        c2 = rand() %12;
        aux = m[l1][c1];
        m[l1][c1] = m[l2][c2];
        m[l2][c2] = aux;
    }
    while(comb <= 2){
        printf("\n    0   1   2   3   4   5   6   7   8   9  10  11\n");//escreve matriz
        for(i = 0; i < 6; i++){
            printf("%d ", i);
            for(j = 0; j < 12; j++){
                    printf(" [%c]", m[i][j]);
            }
            printf("\n");
        }
        printf("Ligue-J%c [linha1 coluna1 linha2 coluna2]: ", 160);
        scanf("%d %d %d %d", &l1, &c1, &l2, &c2);
        if(((l1 >= 0)&&(l1 < 6)&&(c1 >= 0)&&(c1 < 12)&&
            (l2 >= 0)&&(l2 < 6)&&(c2 >= 0)&&(c2 < 12))&&
           ((l1 != l2)||(c1 != c2))&&
           ((l1 == l2)||(c1 == c2))){//verificar jogada
            if((m[l1][c1] == m[l2][c2])&&(m[l1][c1]!=' ')){//jogada valida
                m[l1][c1] = ' ';
                m[l2][c2] = ' ';
            }
            else{
                printf("\nPe%cas diferentes",135);
            }
        }
        else{
            printf("\nCordenadas inv%clidas.",160);
        }
        printf("\n    0   1   2   3   4   5   6   7   8   9  10  11\n");//escreve matriz
        for(i = 0; i < 6; i++){
            printf("%d ", i);
            for(j = 0; j < 12; j++){
                    printf(" [%c]", m[i][j]);
            }
            printf("\n");
        }
        for(k=0; k<2; k++){
            for(i=5; i >= 0; i--){
                for(j=0; j<12; j++){
                    if(i>0){
                        if(m[i][j] == ' '){
                            m[i][j] = m[i-1][j];
                            m[i-1][j] = ' ';
                        }
                    }
                }
            }
        }
        comb = 0;//verifys movimento possivel
        for(i=97; i<115; i++){
            a = i;
            for(l1=0; l1<6; l1++){
                for(c1=0; c1<12; c1++){
                    if(m[l1][c1] == a){
                        for(l2=0; l2<6; l2++){
                            for(c2=0; c2<12; c2++){
                                if(((l1 == l2)||(c1 == c2))&&
                                   ((l1 != l2)||(c1 != c2))&&
                                   ((m[l1][c1]==m[l2][c2]))&&
                                   (m[l1][c1] != ' ')){//terminar de testar a jogada
                                    comb = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(comb == 0){
            break;
        }
    }
    ponto = 0;
    for(i=0; i<6; i++){
        for(j=0; j<12; j++){
            if(m[i][j]==' '){
                ponto++;
            }
        }
    }
    ponto = ponto/2;
    if(ponto >= 36){
        printf("Parab%cns! Voc%c ganhou!\n", 130, 136);
        printf("........................................................................................................................................................................................................\n........................................................................................................................................................................................................\n........................................................................................................................................................................................................\n........................................................................................................................................................................................................\n........................................................................................................................................................................................................\n........................................................................................................................................................................................................\n........................................................................................................................................................................................................\n....................................................................................................--------............................................................................................\n...............................................................................................----:::/:::::::---.......................................................................................\n.............................................................................................---//::::::::::::::::--....................................................................................\n...........................................................................................-:+/+//--://:::::-:::::/:--..................................................................................\n.........................................................................................-::/o+/:/:/++/:::/::-:///::::--................................................................................\n........................................................................................-/oo++///++///:::::///:/://:::/:-...............................................................................\n.......................................................................................-+oo+++/:///+/+/://://::::++/:://:-..............................................................................\n.......................................................................................:oo++oo+/+ooo++////://o+++////:/++:..............................................................................\n.......................................................................................:o+/+oooooo++///////+oooo++o++//++:..............................................................................\n.......................................................................................-++++oso+/::::--..----:////++////+:-.............................................................................\n.......................................................................................-/oo+oyo/:---...````...--:/oso+/++:..............................................................................\n......................................................................................../oooss+:---............--:+yso++/-..............................................................................\n........................................................................................:ossyy+:--...```````....-:+sssso/...............................................................................\n........................................................................................-:osyo+::--.....``....-::://oos/-...............................................................................\n..........................................................................................-ss//+/+o+/:-..-:/osso+/:-:oo:................................................................................\n.........................................................................................../o/:+ooysoo/--:/+/oo+::--:++-................................................................................\n...........................................................................................-+/:-----.-:-.:-..-------//-.................................................................................\n............................................................................................:/:-.....-:..:-......--::-..................................................................................\n.............................................................................................:/:--.-:::..:::-...--:/-...................................................................................\n.............................................................................-.....---.......-+////:-/o++o+:-////+o:....................................................................................\n........................................................................-/---------::-:-/--..-ooooo+:-/+/:--:+oo+o+:....................................................................................\n......................................................................--:++oo+///:::/+:/:/o++sss/:-:++++//+++:-::++//--.....-..-........................................................................\n......................................................................-:syysssssssooosooosyhhssys+:-://////:---/+o+++://-/-----:://:+++/:--.............................................................\n......................................................................--+++oossssoooosssssyyhhysyhs/:-:-----:/oyssoo//oo:++:-:-///+oo+oo+-::-...........................................................\n..............................................................::--:--.....-.-+ssssooosoooosyyddhoohdyso++++osyyyshhysoso/:-..-:---::::/:::os-...........................................................\n............................................................---/++++++////-...-/+oo+oso+/+osyhhyo:+yydmdhhyyssooooso+/-.``.-:oyyyyyyyo+/++ss/...........................................................\n.............................................................------::/oosyso/-.`.-::/+/:--/osyo+//+/+++/:::::---...````.-+yhhysssoosso+//::/:...........................................................\n....................................................................:+syyysooo/:..``.......--:-..............-..-.`..:/oyhhyo+oyyhhhhhhyyhhh:...........................................................\n................................................................::+shddddmhsooos+/-....```..``..................:.-..-/oo+++ooo+//oyyyssoyds-...........................................................\n..............................................................:oyddddddddddmdsooso:--...``.`````...............---.....-/+++/::/oo+/+ossooo-............................................................\n.............................................................-hhhhhhyyssyyyyys///:--:--..........---.--..........--..-`.-://+++/::/+oosys+/+:...........................................................\n.............................................................:hhhyyssosso++o+/:::---:::-------.--:-...-----.......----.`--::///+o++//ossyy+::...........................................................\n............................................................../dhyssss+:---.--:///----::::-:::::::::--:--::--::------....--:://++oooooosyhy/-...........................................................\n..............................................................-ddyysss+////++oossys:--:--::-:-::://:::::::::::-:-:::/::-:-:://++oooooossyhh/-...........................................................\n.............................................................../hddhyyyyhhhho+/oo/s/--.----------:-::/:/:/:/:::/:://:-:::-:/+ooooosssyyyhdy:............................................................\n................................................................-shdddhyyyhdho:////:--------..----:::------:::-::://:-:+/:+osssssyyyyhhddy:.............................................................\n.................................................................--/syhhhhyyhs/:---------.--..----:--------:----------:::/yyhhddhyyyyso+:-..............................................................\n......................................................................------/++/s/--.......--...----.-------...-......--o+yhhddmds/:--..................................................................\n............................................................................./+oy+:---:--.---------.--.-----.-..`..-+o/+soyhhhddy:......................................................................\n............................................................................-++hs/::--------------.--.--.......:/syhy+/yhhhhhyhh/.......................................................................\n............................................................................///ys/://:-----------........---:+oyhhhh+:/yhhhhyhhh:.......................................................................\n............................................................................+++hh+:::-----------.------:-:/+ooyhhdh+++ohhhhyyyhh:.......................................................................\n...........................................................................://+yhy+::-----...--////:::://ossooshhyo++ohhhhyyyyyy-.......................................................................\n..........................................................................-///+hhhy/-...---::///////ssso+++++ooyy+//+syhhyyyyyy+........................................................................\n.........................................................................-//++ohhhy+---:///::::/ssy/oossysso/++s+///+syyyyyyyyy/........................................................................\n.........................................................................:/++/shhhhs/:::/:::/+sddyh/ooooosyysooo////+yyyyyyyyyh/........................................................................\n........................................................................-/++//yhhyyy+::::/+oshsddhd/osoooossyys+//++oyyyyyyyyyyo........................................................................\n.......................................................................-//+//ohhhyyyso+o+ososhdddyh++oooossosso/+++osyyyyyyyyyyy-.......................................................................\n......................................................................-++++oyyhhhyyyyysoooo+osdhhyh/++/osooo++/++++syyyyyyyyyyyyo.......................................................................\n......................................................................+o+/sshhhhhyyys+ossoss+sshhhh+++ooo+++++oo+ososyyyyyyyyyyyy:......................................................................\n...................................................................../y+++hhhhhhyyyo+++ossos+y+oyys:/+o++/+/oosossyssyyyyyyyyyyyys-.....................................................................\n...................................................................-:yo//yhhhhhhyyy+/+o+ossooyyyyyo+o+/////+oosyyyyyyyyyyyyyyyyyyy+.....................................................................\n.................................................................-/+/+++shhhhhhhyyo/++++ooo+:o+++o/+////////++osyyyyyyyyyyyyyyyyyyh:....................................................................\n................................................................-o++/+++shhhhhhyys+//++++++o+yssyy/:o++////++++oyyyyyyyyyyyyyyyyyyyo-...................................................................\n..............................................................-/s//oo+o+oshhhhhysoo/+++//+//sso+sy+++/+///++++++ssyyyyyyyyyyyyysso++s-..................................................................\n.............................................................-oho///++oooooshyyyso+/++///+/:ysoos/://+/::///////osssssssyyyyys++///:os-.................................................................\n............................................................-syysyyo++ooooohyhyyo/////++//:+ssso++///:://///////ossssssyysoo/++/+////os-................................................................\n.............................................................-/syyyyyso++oyhyys+/+/++/+++/:o/soossy+/+++/:/::::/osssssso/+/+/+++++///:ss-...............................................................\n..............................................................-hhhhyyyyhoohhyoo///++//++///+soooss++:+/::::::::+osssyyys:+/++o++/:///oyys-..............................................................\n.............................................................-yhyyyhhhhhhhhyyo/:++/+///++/sssooooo/o/:::::::::///ossyyyy/:++////+ossssyyyo-.............................................................\n");
    }
    else{
        printf("\nVoc%c ganhou a derrota. Boa sorte na pr%cxima!", 136, 162);
    }
    printf("Digite '0' para encerrar: ");
    scanf("%d", &f);
    return 0;
}