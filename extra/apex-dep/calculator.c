#include <string.h>
#include <stdio.h>
int main(){
   int first_number;
   int second_number;
   int final_calculation;
   char operator[3];
   printf("----------------------\n");
   printf("   Talon Calculator\n");
   printf("----------------------\n");
   printf("Enter Operator > ");
   scanf("%s",operator);
   printf("Operator %s Selected\n",operator);
   if (strcmp(operator,"+") == 0){
    printf("Enter First Number \n > ");
    scanf("%d",&first_number);
    printf("Enter Second \n > ");
    scanf("%d",&second_number);
    final_calculation = first_number + second_number;
    printf("%d + %d = %d\n",first_number,second_number,final_calculation);
   }
   else if (strcmp(operator,"-") == 0){
    printf("Enter First Number \n > ");
    scanf("%d",&first_number);
    printf("Enter Second \n > ");
    scanf("%d",&second_number);
    final_calculation = first_number - second_number;
    printf("%d - %d = %d\n",first_number,second_number,final_calculation);
   }
   else if (strcmp(operator,"/") == 0){
    printf("Enter First Number \n > ");
    scanf("%d",&first_number);
    printf("Enter Second \n > ");
    scanf("%d",&second_number);
    final_calculation = first_number / second_number;
    printf("%d / %d = %d\n",first_number,second_number,final_calculation);
   }
   else if (strcmp(operator,"*") == 0){
    printf("Enter First Number \n > ");
    scanf("%d",&first_number);
    printf("Enter Second \n > ");
    scanf("%d",&second_number);
    final_calculation = first_number * second_number;
    printf("%d * %d = %d\n",first_number,second_number,final_calculation);
   }
   else{
       printf("Operator Not Found\n");
   }

}
