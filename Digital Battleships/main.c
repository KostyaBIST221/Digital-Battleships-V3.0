#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CreateWar1-4.h"

inf create();
void PrintAnswers(inf b[][11],int sg[11],int sv[11]);
void PrintField(inf a[][11],int sg[11],int sv[11]);
int FillingInAmounts(inf b[][11]);
int SumVer(inf b[][11], int* sv);
int SumGor(inf b[][11], int* sg);
struct tm *mytime;
int Transformation(char p);
int Uppdate_ost(inf b[][11], int ost);
int Hit(inf b[][11], int px, int py, int ost, int loc);
int Create_new_player(int h0, int m0, int h1, int m1,int loc);
void Rules();
void Games(inf b[][11], int *sg, int *sv, int loc);

void main() {
    
//------------Объявление переменных------------\\
    //1-Русский
    //2-Английский
    int loc = 2;
    
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
    
    for (int i = 1; i<11;i++){
        for (int j = 1; j<11;j++){
            inf rg = create();
            a[i][j]=rg;
        }
    }//Заполниние массива случайными числами
    FillingInAmounts(a); //Создание -1 значения суммы
    
    War4(a, data); //Корабль 4
    War3(a, data); //Корабль 3
    War2(a, data); //Корабль 2
    War1(a, data); //Корабль 1
    
    SumGor(a, sg);//Сумма горизонтали
    SumVer(a, sv);//Сумма вертикали
    
    
//------------------Меню------------------\\
    
    int n;
    int d=1;
    while (d==1) {
        if (loc==1){
            printf("Добро пожаловать в Цифровой морской бой!\n");
            printf("1-Играть\n2-Ответ\n3-Правила\n4-Смена языка\n5-Выход\n");
        }
        if (loc==2){
            printf("Welcome to Digital Sea Battle!\n");
            printf("1-Play\n2-Answer\n3-Rules\n4-Switch language\n5-Exit\n");
        }
        scanf("%i",&n);
        switch (n) {
            case 1:
                Games(a,sg,sv,loc);
                if (loc==1){
                    printf("Ответы:\n");
                }
                if (loc==2){
                    printf("Answers\n");
                }
                
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
                if (loc==1) loc=2;
                else if (loc==2) loc=1;
                break;
            case 5:
                d=0;
                break;
        }
    }
}

inf create(){
    
    inf d;
    int a = (rand() % 9) + 1;
    d.cn=a;
    d.sum=0;
    d.war=0;
    return d;
}

void PrintAnswers(inf b[][11],int sg[11],int sv[11]){
    printf("     A   B   C   D   E   F   G   H   I   J  \n");
    //printf("   ┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");
    printf(" 1 ");
    for (int i = 1; i<11;i++){
        if(b[1][i].sum==-1){
            printf("    ");
        }else if(b[1][i].sum==-2){
            printf("  x ");
        }else if(b[1][i].sum==-3){
            printf("  o ");
        }else{
            printf(" %2i ",b[1][i].sum);
        }
    }
    printf("  %i\n",sg[1]);
    for (int i=2; i<=10;i++)
    {
        //printf("   ┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
        printf("%2i ",i);
        for (int j = 1; j<11;j++){
            if(b[i][j].sum==-1){
                printf("    ");
            }else if(b[i][j].sum==-2){
                printf("  x ");
            }else if(b[i][j].sum==-3){
                printf("  o ");
            }else{
                printf(" %2i ",b[i][j].sum);
            }
        }
        printf("  %i\n",sg[i]);
        
    }
//    printf("   ┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
    printf("    ");
    for (int i=1;i<=10;i++){
        printf("%2i  ",sv[i]);
    }
    printf("\n");
}

void PrintField(inf a[][11],int sg[11],int sv[11]){
    printf("     A   B   C   D   E   F   G   H   I   J  \n");
    //printf("   ┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");
    printf(" 1 ");
    for (int i = 1; i<11;i++){
        if (a[1][i].sum==-2){
            printf(" x %i",a[1][i].cn);
        }else{
            printf(" %2i ",a[1][i].cn);
        }
    }
    printf("  %i\n",sg[1]);
    for (int i=2; i<=10;i++)
    {
        //printf("   ┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
        printf("%2i ",i);
        for (int j = 1; j<11;j++){
            if (a[i][j].sum==-2){
                printf(" x %i",a[i][j].cn);
            }else{
                printf(" %2i ",a[i][j].cn);
            }
        }
        printf("  %i\n",sg[i]);

    }
    //printf("   ┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
    printf("    ");
    for (int i=1;i<=10;i++){
        printf("%2i  ",sv[i]);
    }
    printf("\n");
}

int FillingInAmounts(inf b[][11]){
    for (int i = 1; i<11;i++){
        for (int j = 1; j<11;j++){
            b[i][j].sum=-1;
        }
    }
    return 0;
}

int SumVer(inf b[][11], int* sv){
    for(int i = 1;i<=10;i++){
        for(int j = 1;j<=10;j++){
            if (b[i][j].sum>-1){
                sv[j]+=b[i][j].sum;
            }
        }
    }
    return 1;
}

int SumGor(inf b[][11], int* sg){
    for(int i = 1;i<=10;i++){
        for(int j = 1;j<=10;j++){
            if (b[i][j].sum>-1){
                sg[i]+=b[i][j].sum;
            }
        }
    }
    return 1;
}

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

int Uppdate_ost(inf b[][11], int ost){
    for(int i = 1;i<=10;i++){
        for(int j = 1;j<=10;j++){
            if (b[i][j].sum==-2){
                ost-=1;
            }
        }
    }
    return ost;
}

int Hit(inf b[][11], int px, int py, int ost, int loc){
    if (loc==1){
        printf("Попадание\nОсталось %i клеток\n",ost-1);
    }
    if (loc==2){
        printf("Hit\nRemaining %i cells\n",ost-1);
    }
    b[px][py].sum=-2;
    return 1;
}

int Create_new_player(int h0, int m0, int h1, int m1, int loc){
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
    if (loc==1){
        printf("Время прохождения - %i:%i\n",hour,minute);
    }
    if (loc==2){
        printf("Travel time - %i:%i\n",hour,minute);
    }
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

void Games(inf b[][11], int *sg, int *sv, int loc){
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
            if (loc==1){
                printf("Поздравляю вы победили!\n");
            }
            if (loc==2){
                printf("Congratulations, you won!\n");
            }
            
            time_t t;
            t = time(NULL);
            mytime= localtime(&t);
            int h1 = mytime->tm_hour;
            int m1 = mytime->tm_min;
//            printf("%i-%i\n",h0,m0);
//            printf("%i-%i\n",h1,m1);
            Create_new_player(h0,m0,h1,m1,loc);
            ost-=20;
            break;
            //------Coming soon------\\
            Таблица лидеров
            /*printf("Введите имя\n");
            scanf("%s",Name);
            printf("%s\n",Name);
             */
        }else if (hp==0){
            if (loc==1){
                printf("Вы проиграли\n");
            }
            if (loc==2){
                printf("You lost\n");
            }
            
            break;
        }else{
            PrintField(b, sg, sv);
            if (loc==1){
                printf("Введите x,y\n");
            }
            if (loc==2){
                printf("Enter x,y\n");
            }
            
            getchar();
            scanf("%i %c",&px,&p);
            py=Transformation(p);
            if (py == -1){
                continue;
            }
            if (b[px][py].sum!=-1){
                Hit(b, px, py, ost, loc);
                ost--;
            }else if (b[px][py].sum==-2){
                if (loc==1){
                    printf("Вы уже стреляли в данную точку\n");
                }
                if (loc==2){
                    printf("You have already fired at this point\n");
                }
                
            }else{
                if (loc==1){
                    printf("Промах\n");
                }
                if (loc==2){
                    printf("Miss\n");
                }
                
                b[px][py].sum=-3;
                hp--;
                if (loc==1){
                    if (hp==3 || hp==2)printf("Осталось %i жизни\n",hp);
                    if (hp==1)printf("Осталась 1 жизнь\n");
                }
                if (hp==3 || hp==2){
                    printf("%i life left\n",hp);
                    if (hp==1)printf("1 life left\n");
                }
            }
        }
    }
}
