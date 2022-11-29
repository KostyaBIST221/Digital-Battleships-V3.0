#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Info{
    int cn;
    int war;
    int sum;
};

typedef struct Info inf;

inf create(){
    
    inf d;
    int a = (rand() % 9) + 1;
    d.cn=a;
    d.sum=0;
    d.war=0;
    return d;
}

void PrintAnswers(inf b[11][11],int sg[11],int sv[11]){
    printf("     A   B   C   D   E   F   G   H   I   J  \n");
    printf("   ┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");
    printf(" 1 ");
    for (int i = 1; i<11;i++){
        if(b[1][i].sum==-1){
            printf("┃   ");
        }else if(b[1][i].sum==-2){
            printf("┃ x ");
        }else if(b[1][i].sum==-3){
            printf("┃ o ");
        }else{
            printf("┃%2i ",b[1][i].sum);
        }
    }
    printf("┃ %i\n",sg[1]);
    for (int i=2; i<=10;i++)
    {
        printf("   ┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
        printf("%2i ",i);
        for (int j = 1; j<11;j++){
            if(b[i][j].sum==-1){
                printf("┃   ");
            }else if(b[i][j].sum==-2){
                printf("┃ x ");
            }else if(b[i][j].sum==-3){
                printf("┃ o ");
            }else{
                printf("┃%2i ",b[i][j].sum);
            }
        }
        printf("┃ %i\n",sg[i]);
        
    }
    printf("   ┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
    printf("    ");
    for (int i=1;i<=10;i++){
        printf("%2i  ",sv[i]);
    }
    printf("\n");
}

void PrintField(inf a[11][11],int sg[11],int sv[11]){
    printf("     A   B   C   D   E   F   G   H   I   J  \n");
    printf("   ┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");
    printf(" 1 ");
    for (int i = 1; i<11;i++){
        if (a[1][i].sum==-2){
            printf("┃x %i",a[1][i].cn);
        }else{
            printf("┃%2i ",a[1][i].cn);
        }
    }
    printf("┃ %i\n",sg[1]);
    for (int i=2; i<=10;i++)
    {
        printf("   ┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
        printf("%2i ",i);
        for (int j = 1; j<11;j++){
            if (a[i][j].sum==-2){
                printf("┃x %i",a[i][j].cn);
            }else{
                printf("┃%2i ",a[i][j].cn);
            }
        }
        printf("┃ %i\n",sg[i]);

    }
    printf("   ┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
    printf("    ");
    for (int i=1;i<=10;i++){
        printf("%2i  ",sv[i]);
    }
    printf("\n");
}

inf CreatWarRandom(inf a[11][11]){
    for (int i = 1; i<11;i++){
        for (int j = 1; j<11;j++){
            inf rg = create();
            a[i][j]=rg;
        }
    }
    return a[11][11];
}

inf FillingInAmounts(inf b[11][11]){
    for (int i = 1; i<11;i++){
        for (int j = 1; j<11;j++){
            b[i][j].sum=-1;
        }
    }
    return b[11][11];
}

inf War4(inf b[11][11], int *data){
    int x = (rand() % 9) + 1;
    int y = (rand() % 9) + 1;
    int rotation = (rand() % 2) + 1;
    
    while (data[4]==1) {
        if (x>=7 && y>=7){
            x=6;
            y=6;
        }
        if (rotation == 1 && x+4<=10){
            for (int j=-1;j<=1;j++){
                for (int i =-1;i<5;i++){
                    b[x+i][y+j].war=2;
                }
            }
            b[x][y].war=1;
            b[x][y].sum=b[x][y].cn;
            b[x+1][y].war=1;
            b[x+1][y].sum=b[x+1][y].cn;
            b[x+2][y].war=1;
            b[x+2][y].sum=b[x+2][y].cn;
            b[x+3][y].war=1;
            b[x+3][y].sum=b[x+3][y].cn;
            
            data[4]=0;
        }else if (rotation == 2 && y+4<=10){
            for (int j=-1;j<5;j++ ){
                for (int i =-1;i<=1;i++){
                    b[x+i][y+j].war=2;
                }
            }
            b[x][y].war=1;
            b[x][y].sum=b[x][y].cn;
            b[x][y+1].war=1;
            b[x][y+1].sum=b[x][y+1].cn;
            b[x][y+2].war=1;
            b[x][y+2].sum=b[x][y+2].cn;
            b[x][y+3].war=1;
            b[x][y+3].sum=b[x][y+3].cn;
            data[4]=0;
        }else{
            if (rotation==2){
                rotation=1;
                
            }else{
                rotation+=1;
            }
        }
    }
    return b[11][11];
}

inf War3(inf b[11][11], int *data){
    int cnt=1;
    while (data[3]>0 && cnt<1000) {
        int x1 = (rand() % 9) + 1;
        int y1 = (rand() % 9) + 1;
        int rotation1 = (rand() % 2) + 1;
        int tf = 1;
        for (int i = -1; i<=1; i++) {
            for (int j = -1; j<=1; j++) {
                if ((x1+i>0 && y1+j>0) && (x1+i<10 && y1+j<10)){
                    if ((b[x1+i][y1+j].war) == 1 || (b[x1+i][y1+j].war) == 2){
                        tf=0;
                        break;
                    }
                }
            }
        }
        if (rotation1==1)
        {
            for (int i = -1; i<=1; i++) {
                for (int j = -1; j<=1; j++) {
                    if ((x1+2+i>0 && y1+j>0) && (x1+2+i<10 && y1+j<10)){
                        if ((b[x1+2+i][y1+j].war) == 1 || (b[x1+2+i][y1+j].war) == 2){
                            tf=0;
                            break;
                        }
                    }
                    if (!(x1+2>0 && y1>0 && x1+2<10 && y1<10)){
                        tf=0;
                        break;
                    }
                }
            }
            for (int i = -1; i<=1; i++) {
                for (int j = -1; j<=1; j++) {
                    if ((x1+1+i>0 && y1+j>0) && (x1+1+i<10 && y1+j<10)){
                        if ((b[x1+1+i][y1+j].war) == 1 || (b[x1+1+i][y1+j].war) == 2){
                            tf=0;
                            break;
                        }
                    }
                }
            }
        }
        if (rotation1==2)
        {
            for (int i = -1; i<=1; i++) {
                for (int j = -1; j<=1; j++) {
                    if ((x1+i>0 && y1+2+j>0) && (x1+i<10 && y1+j+2<10)){
                        if ((b[x1+i][y1+2+j].war) == 1 || (b[x1+i][y1+2+j].war) == 2){
                            tf=0;
                            break;
                        }
                    }
                    if (!(x1>0 && y1+2>0 && x1<10 && y1+2<10)){
                        tf=0;
                        break;
                    }
                }
            }
            for (int i = -1; i<=1; i++) {
                for (int j = -1; j<=1; j++) {
                    if ((x1+i>0 && y1+1+j>0) && (x1+i<10 && y1+1+j<10)){
                        if ((b[x1+i][y1+1+j].war) == 1 || (b[x1+i][y1+1+j].war) == 2){
                            tf=0;
                            break;
                        }
                    }
                }
            }
        }
        if (tf == 1){
            if (rotation1==1)
            {
                for (int j=-1;j<=1;j++){
                    for (int i =-1;i<=3;i++){
                        b[x1+i][y1+j].war=2;
                    }
                }
                b[x1][y1].war=1;
                b[x1][y1].sum=b[x1][y1].cn;
                b[x1+1][y1].war=1;
                b[x1+1][y1].sum=b[x1+1][y1].cn;
                b[x1+2][y1].war=1;
                b[x1+2][y1].sum=b[x1+2][y1].cn;
                data[3]-=1;
            }
            if (rotation1==2)
            {
                for (int j=-1;j<=1;j++){
                    for (int i =-1;i<=3;i++){
                        b[x1+j][y1+i].war=2;
                    }
                }
                b[x1][y1].war=1;
                b[x1][y1].sum=b[x1][y1].cn;
                b[x1][y1+1].war=1;
                b[x1][y1+1].sum=b[x1][y1+1].cn;
                b[x1][y1+2].war=1;
                b[x1][y1+2].sum=b[x1][y1+2].cn;
                data[3]-=1;
            }
        }
        cnt+=1;
    }
    return b[11][11];
}

inf War2(inf b[11][11], int *data){
    int cnt=0;
    while (data[2]>0 && cnt<5000000) {
        int x1 = (rand() % 9) + 1;
        int y1 = (rand() % 9) + 1;
        int rotation1 = (rand() % 2) + 1;
        int tf = 1;
        for (int i = -1; i<=1; i++) {
            for (int j = -1; j<=1; j++) {
                if ((x1+i>0 && y1+j>0) && (x1+i<10 && y1+j<10)){
                    if ((b[x1+i][y1+j].war) == 1 || (b[x1+i][y1+j].war) == 2){
                        tf=0;
                        break;
                    }
                }
            }
        }
        if (rotation1==1)
        {
            for (int i = -1; i<=1; i++) {
                for (int j = -1; j<=1; j++) {
                    if ((x1+1+i>0 && y1+j>0) && (x1+1+i<10 && y1+j<10)){
                        if ((b[x1+1+i][y1+j].war) == 1 || (b[x1+1+i][y1+j].war) == 2){
                            tf=0;
                            break;
                        }
                    }
                    if (!(x1+1>0 && y1>0 && x1+1<10 && y1<10)){
                        tf=0;
                        break;
                    }
                }
            }
        }
        if (rotation1==2)
        {
            for (int i = -1; i<=1; i++) {
                for (int j = -1; j<=1; j++) {
                    if ((x1+i>0 && y1+1+j>0) && (x1+i<10 && y1+1+j<10)){
                        if ((b[x1+i][y1+1+j].war) == 1 || (b[x1+i][y1+1+j].war) == 2){
                            tf=0;
                            break;
                        }
                    }
                    if (!(x1>0 && y1+1>0 && x1<10 && y1+1<10)){
                        tf=0;
                        break;
                    }
                }
            }
        }
        if (tf == 1){
            if (rotation1==1)
            {
                for (int j=-1;j<=1;j++){
                    for (int i =-1;i<=2;i++){
                        b[x1+i][y1+j].war=2;
                    }
                }
                b[x1][y1].war=1;
                b[x1][y1].sum=b[x1][y1].cn;
                b[x1+1][y1].war=1;
                b[x1+1][y1].sum=b[x1+1][y1].cn;
                data[2]-=1;
            }
            if (rotation1==2)
            {
                for (int j=-1;j<=1;j++){
                    for (int i =-1;i<=2;i++){
                        b[x1+j][y1+i].war=2;
                    }
                }
                b[x1][y1].war=1;
                b[x1][y1].sum=b[x1][y1].cn;
                b[x1][y1+1].war=1;
                b[x1][y1+1].sum=b[x1][y1+1].cn;
                data[2]-=1;
            }
        }
        cnt+=1;
    }
    if (data[2]>0){
        for (int x1=1;x1<=10;x1++){
            for(int y1=1;y1<=10;y1++){
                for(int rotation1=1;rotation1<=2;rotation1++){
                    if (((b[x1][y1].war!=1 && b[x1][y1].war!=2)&&(b[x1+1][y1].war!=1 && b[x1+1][y1].war!=2))){
                        for (int j=-1;j<=1;j++){
                            for (int i =-1;i<=2;i++){
                                b[x1+i][y1+j].war=2;
                            }
                        }
                        for (int j=-1;j<=1;j++){
                            for (int i =-1;i<=2;i++){
                                b[x1+i][y1+j].war=2;
                            }
                        }
                        b[x1][y1].war=1;
                        b[x1][y1].sum=b[x1][y1].cn;
                        b[x1+1][y1].war=1;
                        b[x1+1][y1].sum=b[x1+1][y1].cn;
                        data[2]-=1;
                    }else if ((b[x1][y1].war!=1 && b[x1][y1].war!=2)&&(b[x1][y1+1].war!=1 && b[x1][y1+1].war!=2)){
                        for (int j=-1;j<=1;j++){
                            for (int i =-1;i<=2;i++){
                                b[x1+j][y1+i].war=2;
                            }
                            
                        }
                        for (int j=-1;j<=1;j++){
                            for (int i =-1;i<=2;i++){
                                b[x1+j][y1+i].war=2;
                            }
                        }
                        b[x1][y1].war=1;
                        b[x1][y1].sum=b[x1][y1].cn;
                        b[x1][y1+1].war=1;
                        b[x1][y1+1].sum=b[x1][y1+1].cn;
                        data[2]-=1;
                    }
                }
                if (data[2]<=0)break;
            }
            if (data[2]<=0)break;
        }
    }
    return b[11][11];
}

inf War1(inf b[11][11], int *data){
    int cnt=0;
    while (data[1]>0 && cnt<10000) {
        int x1 = (rand() % 9) + 1;
        int y1 = (rand() % 9) + 1;
        int tf = 1;
        if ((b[x1][y1].war) == 1 || (b[x1][y1].war) == 2){
            tf=0;
        }
        if (tf == 1){
            for (int j=-1;j<=1;j++){
                for (int i =-1;i<=1;i++){
                    b[x1+i][y1+j].war=2;
                }
            }
            b[x1][y1].war=1;
            b[x1][y1].sum=b[x1][y1].cn;
            data[1]-=1;
        }
        cnt+=1;
    }
    if(data[1]>0){
        for (int x1=1;x1<=10;x1++){
            for(int y1=1;y1<=10;y1++){
                if (b[x1][y1].war!=1 && b[x1][y1].war!=2){
                    for (int j=-1;j<=1;j++){
                        for (int i =-1;i<=1;i++){
                            b[x1+i][y1+j].war=2;
                        }
                    }
                    b[x1][y1].war=1;
                    b[x1][y1].sum=b[x1][y1].cn;
                    data[1]-=1;
                }
                if (data[1]<=0)break;
            }
            if (data[1]<=0)break;
        }
    }
    return b[11][11];
}

int SumVer(inf b[11][11], int* sv){
    for(int i = 1;i<=10;i++){
        for(int j = 1;j<=10;j++){
            if (b[i][j].sum>-1){
                sv[j]+=b[i][j].sum;
            }
        }
    }
    return 1;
}

int SumGor(inf b[11][11], int* sg){
    for(int i = 1;i<=10;i++){
        for(int j = 1;j<=10;j++){
            if (b[i][j].sum>-1){
                sg[i]+=b[i][j].sum;
            }
        }
    }
    return 1;
}

struct tm *mytime;

int Transformation(char p){
    int py;
    switch (p) {
        case 'A':
        case 'a':
            py=1;
            break;
        case 'B':
        case 'b':
            py=2;
            break;
        case 'C':
        case 'c':
            py=3;
            break;
        case 'D':
        case 'd':
            py=4;
            break;
        case 'E':
        case 'e':
            py=5;
            break;
        case 'F':
        case 'f':
            py=6;
            break;
        case 'G':
        case 'g':
            py=7;
            break;
        case 'H':
        case 'h':
            py=8;
            break;
        case 'I':
        case 'i':
            py=9;
            break;
        case 'J':
        case 'j':
            py=10;
            break;
        default:
            return -1;
            break;
    }
    return py;
}

int Uppdate_ost(inf b[11][11], int ost){
    for(int i = 1;i<=10;i++){
        for(int j = 1;j<=10;j++){
            if (b[i][j].sum==-2){
                ost-=1;
            }
        }
    }
    return ost;
}

inf Hit(inf b[11][11], int px, int py, int ost){
    printf("Попадание\nОсталось %i клеток\n",ost-1);
    b[px][py].sum=-2;
    return b[11][11];
}

void print_hp(int hp){
    if (hp==3 || hp==2)printf("Осталось %i жизни\n",hp);
    if (hp==1)printf("Осталась 1 жизнь\n");
}

int Create_new_player(int h0, int m0, int h1, int m1){
    int hour, minute;
    
    if (m1>=m0){
        hour = h1-h0;
        minute = m1-m0;
    }else{
        hour = h1-h0-1;
        minute = 60-m0+m1;
        if (hour<0){
            hour +=24;
        }
    }
    
    printf("Время прохождения - %i:%i\n",hour,minute);
    
    printf("Введите имя\n");
    char Name[50];
    scanf("%s", &Name);
    if (Name=='0'){
        return 1;
    }
    FILE *fp;
    fp = fopen("/Users/kostya/c Lab/Digital Battleships/Digital Battleships/top.txt", "a");
    fprintf(fp ,"\n%s-%i:%i",Name , hour, minute);
    fclose(fp);
    return 0;
}

void Rules(){
    printf("Правила игры в цифровой морской бой:\n");
    printf("Перед игроками есть поле 10x10. Задача игрока попасть по всем кораблям, при этом у игрока всего 3 жизни.\n");
    printf("Числовые значения за пределами сетки (справа, снизу) означают суммы чисел только в тех клетках, которые содержат фрагменты кораблей, в соответствующих рядах и столбцах.\n");
    printf("Корабли, спрятанные среди чисел, не могут соприкасаться друг с другом даже углами.\n");
    printf("Игрок должен написать координаты точки (4а), (7 G), (1 a).\n");
    printf("В ответ он получит резулитат выстрела(Попадание, Промах).\n");
    printf("После того как вы победите вам будет предложено написать имя для сохраниния результатов, если вы не хотите сохранять результат напишите 0.\n");
    printf("\n");
}

void Games(inf b[11][11], int *sg, int *sv){
    int ost=20;
    int hp=3;
    time_t t;
    t = time(NULL);
    mytime= localtime(&t);
    int h0 = mytime->tm_hour;
    int m0 = mytime->tm_min;
    int px,py;
    char p;
    while (hp>=0 && ost>=0) {
        //ost=Uppdate_ost(b, ost); //Обновление остатка
        if (ost==0){
            printf("Поздравляю вы победили!\n");
            time_t t;
            t = time(NULL);
            mytime= localtime(&t);
            int h1 = mytime->tm_hour;
            int m1 = mytime->tm_min;
//            printf("%i-%i\n",h0,m0);
//            printf("%i-%i\n",h1,m1);
            Create_new_player(h0,m0,h1,m1);
            break;
            //------Coming soon------\\
            Таблица лидеров
            /*printf("Введите имя\n");
            scanf("%s",Name);
            printf("%s\n",Name);
             */
        }else if (hp==0){
            printf("Вы проиграли\n");
            break;
        }else{
            PrintField(b, sg, sv);
            printf("Введите x,y\n");
            getchar();
            scanf("%i %c",&px,&p);
            py=Transformation(p);
            if (py == -1){
                continue;
            }
            if (b[px][py].sum!=-1){
                Hit(b, px, py, ost);
                ost--;
            }else if (b[px][py].sum==-2){
                printf("Вы уже стреляли в данную точку\n");
            }else{
                printf("Промах\n");
                b[px][py].sum=-3;
                hp--;
                print_hp(hp);
            }
        }
    }
}

void main() {
    
//------------Объявление переменных------------\\
    
    inf a[11][11];
    int sg[11] = {0,0,0,0,0,0,0,0,0,0,0};
    int sv[11] = {0,0,0,0,0,0,0,0,0,0,0};
    int data[5] = {0,4,3,2,1};
    
    int stime;
    long ltime;
    ltime = time(NULL);
    stime = (unsigned) ltime/2;
    srand(stime);
    
//------------Заполнение кораблей------------\\
    
    a[11][11] = CreatWarRandom(a); //Заполниние массива случайными числами
    a[11][11] = FillingInAmounts(a); //Создание -1 значения суммы
    
    a[11][11]=War4(a, data); //Корабль 4
    a[11][11]=War3(a, data); //Корабль 3
    a[11][11]=War2(a, data); //Корабль 2
    a[11][11]=War1(a, data); //Корабль 1
    
    SumGor(a, sg);//Сумма горизонтали
    SumVer(a, sv);//Сумма вертикали
    
    
//------------------Меню------------------\\
    
    int n;
    int d=1;
    while (d==1) {
        printf("Добро пожаловать в Цифровой морской бой!\n");
        printf("1-Играть\n2-Ответ\n3-Правила\n4-Выход\n");
        scanf("%i",&n);
        switch (n) {
            case 1:
                Games(a,sg,sv);
                printf("Ответы:\n");
                PrintAnswers(a,sg,sv);
                break;
            case 2:
                PrintAnswers(a,sg,sv);
                break;
            case 3:
                Rules();
//                printf("Тут должны быть правила\n");
                break;
            case 4:
                d=0;
                break;
        }
    }
}
