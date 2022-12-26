#include "CreateWar1-4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int War4(inf b[][11], int *data){
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
    return 0;
}

int War3(inf b[][11], int *data){
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
    return 0;
}

int War2(inf b[][11], int *data){
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
    return 0;
}

int War1(inf b[][11], int *data){
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
    return 0;
}
