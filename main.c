#include <stdio.h>
#include "lr.h"
#include <math.h>
#include <string.h>
#include <limits.h>

int info(){
    int x;
    printf("\n1 = rus or 2 = eng\n" );
    printf(" \nChoose the language: ");
    scanf("%d",&x);
    if(x==1){
            printf (" \nLab1 = 1 and 1  \n  Podschet ploshadi ostavsheysya figuri \n");
            printf (" \nLabdop1 = 1 and 2  \n  Podschet ploshadi ostavsheysya figuri + diametr kruga \n");
            printf (" \nLab2 = 2 \n  Vichislenie summi pervih elementov ryada \n");
            printf (" \nLabdop2 = 2 \n  Vichislenie summi pervih elementov ryada + kazhdii shag \n");
            printf (" \nLab3 = 3 \n  Schet slov nachnaushihsya s glasnoi i zakanchivaushisya na soglasnyu \n");
            printf (" \nLab4 = 4 \n  Ydalenie slov s zadvoennoi glasnoi \n");
            printf (" \nLab5 = 5 and 1 \n  Schet chet i nechet, i vivod naibolshoi \n");
            printf (" \nLabdop5 = 5 and 2 \n  Schet chet i nechet, i vivod naibolshoi + vivod avg, progress and kol-vo otricatelnih chisel\n");
            printf (" \nLab6 = 6 \n  Zamena otricatelnih na naimenshee i polozhtelnih elementov na naibolshee \n");
            printf (" \nLab7 = 7 \n  Zamena pari dvoichnih razryadov v zerkalnom poryadke \n");
    }
    if (x==2) {
            printf (" \nLab1 = 1 and 1 \n  Calculating the area of the remaining figure \n");
            printf (" \nLabdop1 = 1 and 2 \n  Calculating the area of the remaining figure + diametr of the circle \n");
            printf (" \nLab2 = 2 \n  Calculating the sum of the first elements of a series \n");0

            printf (" \nLabdop2 = 2 \n  Calculating the sum of the first elements of a series + each step \n");
            printf (" \nLab3 = 3 \n  Counting words starting with a vowel and ending with a consonant \n");
            printf (" \nLab4 = 4 \n  Removing words with a double vowel \n");
            printf (" \nLab5 = 5 and 1 \n  Counting even and odd, and drawing the greatest \n");
            printf (" \nLabdop5 = 5 and 2 \n  Counting even and odd, and output of the greatest + output of AVG, progression and number of negative numbers\n");
            printf (" \nLab6 = 6 \n  Replacing negative elements with the smallest number and positive elements with the largest number\n");
            printf (" \nLab7 = 7 \n  Replacing a pair of binary digits in mirror order \n");
    }
}


int main(){
    int n, z;
    while (1){
        printf(" \n100=info \n0=exit\n");
        printf(" \nWrite the laboratory number: ");
        scanf("%d",&n);{

        if (!(n == 0 || n == 1 || n == 2 || n == 3 || n ==4 || n == 5 || n == 6 || n == 7 || n == 100)){
                printf("\nWarning! Lab doesn't exist\n");
        }
        if(n==1){
                printf("(1)lab or (2)labdop?\n");
                scanf("%d",&z);
                if (z==1){
                        lab1();
                }
                if (z==2){
                    labdop1();
                }
        }
        if(n==2){
                printf("(1)lab or (2)labdop?\n");
                scanf("%d",&z);
                if (z==1){
                        lab2();
                }
                if (z==2){
                    labdop2();
        }
        }

        if(n==3){
                printf("(1)lab or (2)labdop?\n");
                scanf("%d",&z);
                if (z==1){
                        lab3();
                }
                if (z==2){
                    labdop3();
        }
        }
        if(n==4) {
                lab4();
        }
        if (n==5) {
                printf("(1)lab or (2)labdop?\n");
                scanf("%d",&z);
                if (z==1){
                        lab5();
                }
                if (z==2){
                    labdop5();
                }
        }
        if (n==6) {
                lab6();
        }
        if (n==7) {
                lab7();
        }
        if (n==100) {
                info();
        }
        if (n==0) {
            break;
        }
        }
    }
    printf("Exit.\n");
    return 0;
}
