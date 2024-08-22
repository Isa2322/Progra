#include<stdio.h>

int ingresar_mayor_int(int x)
 {
     int num;

     do{
        fflush(stdin);
        scanf("%d",&num);
        if(num<=x)
            printf("\nError el numero ingresado no es mayor que %d \n",x);
       } while(num<=x);

       return (num);
 }
