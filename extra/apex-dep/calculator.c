#include <string.h>
#include <stdio.h>
#include "calculator.h"
void calculator(){
   int first_number = 0;
   int second_number = 0;
   int final_calculation = 0;
   char op[16];
   printf("----------------------\n");
   printf("   Talon Calculator\n");
   printf("----------------------\n");
   printf("Enter Operator > ");
   if (scanf("%s",op) != 1){
       printf("Invalid Input\n");
       return;
   }
   printf("Operator %s Selected\n",op);
   if (strcmp(op,"+") == 0){
    printf("Enter First Number \n > ");
    if (scanf("%d",&first_number) != 1){
        printf("Invalid Number\n");
        return;
    }
    printf("Enter Second \n > ");
    if (scanf("%d",&second_number) != 1){
        printf("Invalid Number\n");
        return;
    }
    final_calculation = first_number + second_number;
    printf("%d + %d = %d\n",first_number,second_number,final_calculation);
   }
   else if (strcmp(op,"-") == 0){
    printf("Enter First Number \n > ");
    if (scanf("%d",&first_number) != 1){
        printf("Invalid Number\n");
        return;
    }
    printf("Enter Second \n > ");
    if (scanf("%d",&second_number) != 1){
        printf("Invalid Number\n");
        return;
    }
    final_calculation = first_number - second_number;
    printf("%d - %d = %d\n",first_number,second_number,final_calculation);
   }
   else if (strcmp(op,"/") == 0){
    printf("Enter First Number \n > ");
    if (scanf("%d",&first_number) != 1){
        printf("Invalid Number\n");
        return;
    }
    printf("Enter Second \n > ");
    if (scanf("%d",&second_number) != 1){
        printf("Invalid Number\n");
        return;
    }
    if (second_number == 0){
        printf("Can't Divide By Zero\n");
    }
    else{
        final_calculation = first_number / second_number;
        printf("%d / %d = %d\n",first_number,second_number,final_calculation);
    }
   }
   else if (strcmp(op,"*") == 0){
    printf("Enter First Number \n > ");
    if (scanf("%d",&first_number) != 1){
        printf("Invalid Number\n");
        return;
    }
    printf("Enter Second \n > ");
    if (scanf("%d",&second_number) != 1){
        printf("Invalid Number\n");
        return;
    }
    final_calculation = first_number * second_number;
    printf("%d * %d = %d\n",first_number,second_number,final_calculation);
   }
   else{
       printf("Operator Not Found\n");
   }
   int c;
   while ((c = getchar()) != '\n' && c != EOF);

}
