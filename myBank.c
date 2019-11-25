#include <stdio.h>
#include "myBank.h"
#define ROWS 2
#define COLUMNS 50

     double Account[ROWS][COLUMNS];

 void openAndDeposit (double amount){
     int j=0;
     while (Account[0][j]==1 && j<=50){
         j++;
     }
      if (j==50 && Account[0][j]==1){
          printf("there is no more space\n");
      }
      else {
          Account[0][j]=1;
          Account[1][j]=amount;
      }
      printf("account Num: %d\n",j+901);
 }
 
 void getBalance (int accountNum){
     if (Account[0][accountNum-901]==1){
         double balance=Account[1][accountNum-901];
         printf("your balance is: %0.2f\n",balance);
     }
     else printf("this account is close\n");
 }
 
 void deposit (double money, int accountNum){
     if (Account[0][accountNum-901]==1){
         Account[1][accountNum-901]+= money;
         double balance=Account[1][accountNum-901];
         printf("your balance is: %0.2f\n",balance);
     }
     else printf("the account is close\n");
 }
 
 void withdrawal(double money, int accountNum){
     if (Account[0][accountNum-901]==1){
         if (money<= Account[1][accountNum-901]){
             Account[1][accountNum-901]-=money;
             double balance=Account[1][accountNum-901];
             printf("your balance is: %0.2f\n",balance);
         }
         else printf("there is'nt enough money to do your ask\n");
     }
     else printf("the account is close\n");
 }
 
 void close(int accountNum){
     if (Account[0][accountNum-901]==1){
         Account[0][accountNum-901]=0;
     }
     else printf("this account is already close\n");
 }
 
 void interest(double percent){
     double percentNew = (percent/100)+1;
     int j;
     for (j=0; j<=50; j++){
         if (Account[0][j]==1){
             Account[1][j]*=percentNew;
         }
     }
 }
 
 void print(){
     int j;
     for (j=0; j<=50; j++){
         if (Account[0][j]==1){
             double balance=Account[1][j];
             printf("account num: %d the balance: %0.2f\n",j+901,balance);
         }
     }
     if (Account[0][0]==0) print ("there is not open accounts");
 }
 
 void closeAll(){
     int j;
     for (j=0; j<=50; j++){
         Account[0][j]=0;
         Account[1][j]=0;
     }
 }