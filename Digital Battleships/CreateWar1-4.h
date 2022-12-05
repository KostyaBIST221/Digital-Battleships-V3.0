//
//  CreateWar1-4.h
//  Digital Battleships
//
//  Created by kostya on 01.12.2022.
//

#ifndef CreateWar1_4_h
#define CreateWar1_4_h

#include <stdio.h>

struct Info{
    int cn;
    int war;
    int sum;
};

typedef struct Info inf;

inf War4(inf b[11][11], int *data);
inf War3(inf b[11][11], int *data);
inf War2(inf b[11][11], int *data);
inf War1(inf b[11][11], int *data);

#endif /* CreateWar1_4_h */
