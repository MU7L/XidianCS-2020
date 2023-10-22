#include "stdio.h"
int main(void){
    for(int red=0;red<=3;red++){
        for(int white=0;white<=4;white++){
            for(int black=0;black<=5;black++){
                if(red+white+black==8)
                    printf("%d %d %d\n",red,white,black);
            }
        }
    }
}