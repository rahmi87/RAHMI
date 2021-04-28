#include<stdio.h>

int main()
{
    int angka = 10;

    if(angka < 10){
        if(angka <= 5){
            printf("Angka kurang dari atau sama 5");
        }
        else {
            printf("Angka lebih besar dari 5");
        }
    }
    else {
        printf("Angka lebih besar dari atau sama dengan 10");
    }
    return 0;
}