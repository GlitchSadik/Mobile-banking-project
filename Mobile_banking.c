// Id 221-35-915,Final Project on Mobile Banking by Md Imdadul Islam.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct user
{
    char phone[50];
    char password[50];
    float balance;
};
int main()
{
    struct user usr, usr1;
    FILE *fp;
    char filename[50], phone[50], pword[50];
    int opt, choice;
    char cont = 'y';
    float amount;

    printf("\nChoose a Login method\n");
    printf("\n1. Register an account");
    printf("\n2. Login to an existing account\n");

    printf("\nYour choice:\t");
    scanf("%d", &opt);

    if (opt == 1)
    {
        system("cls");
        printf("Enter your phone number:\t");
        scanf("%s", usr.phone);
        printf("Enter your new password:\t");
        scanf("%s", usr.password);
        usr.balance = 0.00;
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(struct user), 1, fp);
        if (fwrite != 0)
        {
            printf("\n\nAccount succesfully registered");
        }
        else
        {
            Beep(700, 700);
            printf("\n\nSomething went wrong,please try again");
        }
        fclose(fp);
    }
    else if (opt == 2)
    {
        system("cls");
        printf("\nPhone number:\t");
        scanf("%s", phone);
        printf("Password:\t");
        scanf("%s", pword);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "r");
        if (fp == NULL)
        {
            Beep(700, 700);
            printf("\nAccount number not registered");
        }
        else
        {
            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
            if (!strcmp(pword, usr.password))
            {
                printf("\n\t\tWelcome %s", usr.phone);
                while (cont == 'y')
                {
                    system("cls");
                    printf("Services");
                    printf("\n1. Balance Inquiry");
                    printf("\n2. Cash In");
                    printf("\n3. Cash Withdrawal");
                    printf("\n4. Merchant Payment");
                    printf("\n5. Send Money");
                    printf("\n6. Change Password");
                    printf("\n\nYour choice:\t");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        printf("\nYour current balance is Bdt/=%.2f", usr.balance);
                        break;
                    case 2:
                        printf("\nEnter the amount:\t");
                        scanf("%f", &amount);
                        usr.balance += amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if (fwrite != NULL)
                            printf("\nSuccesfully cashed in Bdt/=%.2f and your current balance is Bdt/=%.2f", amount, usr.balance);
                        fclose(fp);
                        break;
                    case 3:
                        printf("\nEnter the amount:\t");
                        scanf("%f", &amount);
                        fread(&usr1, sizeof(struct user), 1, fp);

                        fclose(fp);
                        if (amount > usr.balance)
                        {
                            Beep(700, 700);
                            printf("\nInsufficient Balance");
                        }
                        else
                        {
                            usr.balance -= amount;
                            fp = fopen(filename, "w");
                            fwrite(&usr, sizeof(struct user), 1, fp);
                            if (fwrite != NULL)
                                printf("\nYou have withdrawn Bdt/=%.2f and your current balance is Bdt/=%.2f", amount, usr.balance);
                            fclose(fp);
                        }
                        break;
                    case 4:
                        printf("\nPlease enter the merchant phone number to transfer the balance:\t");
                        scanf("%s", phone);
                        printf("\nPlease enter the amount to transfer:\t");
                        scanf("%f", &amount);
                        strcpy(filename, phone);
                        fp = fopen(strcat(filename, ".dat"), "r");
                        if (fp == NULL)
                        {
                            Beep(700, 700);
                            printf("\nAccount number not registered");
                        }
                        else
                        {
                            fread(&usr1, sizeof(struct user), 1, fp);

                            fclose(fp);
                            if (amount > usr.balance)
                            {
                                Beep(700, 700);
                                printf("\nInsufficient balance");
                            }
                            else
                            {
                                fp = fopen(filename, "w");
                                usr1.balance += amount;
                                fwrite(&usr1, sizeof(struct user), 1, fp);

                                fclose(fp);
                                if (fwrite != NULL)
                                {
                                    printf("\nYou have succesfully paid Bdt/=%.2f to %s and your current balance is Bdt/=%.2f", amount, phone, usr.balance);
                                    strcpy(filename, usr.phone);
                                    fp = fopen(strcat(filename, ".dat"), "w");
                                    usr.balance -= amount;
                                    fwrite(&usr, sizeof(struct user), 1, fp);
                                    fclose(fp);
                                }
                            }
                            break;
                        case 5:
                            printf("\nPlease enter the phone number to transfer the balance:\t");
                            scanf("%s", phone);
                            printf("\nPlease enter the amount to transfer:\t");
                            scanf("%f", &amount);
                            strcpy(filename, phone);
                            fp = fopen(strcat(filename, ".dat"), "r");
                            if (fp == NULL)
                            {
                                Beep(700, 700);
                                printf("\nAccount number not registered");
                            }
                            else
                            {
                                fread(&usr1, sizeof(struct user), 1, fp);

                                fclose(fp);
                                if (amount > usr.balance)
                                {
                                    Beep(700, 700);
                                    printf("\nInsufficient balance");
                                }
                                else
                                {
                                    fp = fopen(filename, "w");
                                    usr1.balance += amount;
                                    fwrite(&usr1, sizeof(struct user), 1, fp);

                                    fclose(fp);
                                    if (fwrite != NULL)
                                    {
                                        printf("\nYou have succesfully transfered Bdt/=%.2f to %s and your current balance is Bdt/=%.2f", amount, phone, usr.balance);
                                        strcpy(filename, usr.phone);
                                        fp = fopen(strcat(filename, ".dat"), "w");
                                        usr.balance -= amount;
                                        fwrite(&usr, sizeof(struct user), 1, fp);
                                        fclose(fp);
                                    }
                                }
                                break;
                            case 6:
                                printf("\nPlease enter your new password:\t");
                                scanf("%s", pword);
                                fp = fopen(filename, "w");
                                strcpy(usr.password, pword);
                                fwrite(&usr, sizeof(struct user), 1, fp);
                                if (fwrite != NULL)
                                    printf("\nPassword succesfully changed");
                            }
                            break;
                        default:
                            Beep(700, 700);
                            printf("\nInvalid option");
                        }
                    }
                    printf("\nDo you want to continue? [y/n]\t");
                    scanf("%s", &cont);
                }
            }
            else
            {
                Beep(700, 700);
                printf("\nInvalid password");
            }
        }
    }
    else
    {
        Beep(700, 700);
        printf("\nInvalid option");
    }

    return 0;
}