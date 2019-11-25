#include <stdio.h>
#include "myBank.h"

int main()
{
    char type = ' ';
    printf("Transaction type?:\n");
    scanf(" %c",&type);
    
    
    while (type != 'E')
    {

     switch (type)
     {

        case 'O':
        {
            double amount;
            printf("Initial deposit?:\n");
            scanf("%lf", &amount);
            if (amount<0) printf ("balance not legal\n");
            else openAndDeposit(amount);
            break;
        }
        case 'B':
        {
            int accountNum;
            printf("Account number?:");
            scanf("%d", &accountNum);
            if (accountNum<901 || accountNum>950) printf ("account not legal\n");
            else getBalance(accountNum);
            break;
        }
        case 'D':
        {
            int accountNum;
            printf("Account number?:");
            scanf("%d", &accountNum);
            if (accountNum<901 || accountNum>950) printf ("account not legal\n");
            else 
            {
                double amount;
                printf("Amount?:");
                scanf("%lf", &amount);
                if (amount<0) printf ("balance not legal\n");
                else deposit(amount, accountNum);
            }
            break;
        }
        case 'W':
        {
            int accountNum;
            printf("Account number?:");
            scanf("%d", &accountNum);
            if (accountNum<901 || accountNum>950) printf ("account not legal\n");
            else
            {
                double amount;
                printf("Amount?:");
                scanf("%lf", &amount);
                if (amount<0) printf ("balance not legal\n");
                else withdrawal(amount, accountNum);
            }
            break;
        }
        case 'C':
        {
            int accountNum;
            printf("Account number?:");
            scanf("%d", &accountNum);
            if (accountNum<901 || accountNum>950) printf ("account not legal\n");
            else close(accountNum);
            break;
        }
        case 'I':
        {
            double interestRate;
            printf("Interest rate?:");
            scanf("%lf", &interestRate);
            interest(interestRate);
            break;
        }
        case 'P':
        {
            print();
            break;
        }

        case 'E':
        {
            closeAll();
            break;
        }
        default:
        {
            printf("your Transaction is not exist\n ");
            break;
        }
     }
    

    printf("Transaction type?:\n");
    scanf(" %c",&type);
    }  
    
return 0;
}