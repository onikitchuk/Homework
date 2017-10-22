#include <stdio.h>


int main(void){

    int enterPin;
    int choice;
    int deposit, withdraw, sumDeposit, sumWithdraw;
    int i,j,val;

    const int SIZE = 10;
    int pinOfUsers[SIZE];
    int accountsOfUsers[SIZE];
    int userAccount = 0;
    int usAccount;
    char select;

    int* pinPtr;
    int pinUs;


    // ������ PIN - ����� �������������
        for(i = 0; i < SIZE; i++){
            pinOfUsers[i] = (2534 + 76*i);
            printf("%d ", pinOfUsers[i]);
        }

        printf("\n");
    // ������ ACCOUNTS �������������
        for(i = 0; i < SIZE; i++){
            accountsOfUsers[i] = (12000 + 900*i);
            printf("%d ", accountsOfUsers[i]);
        }
        printf("\n");

// �������� PIN - ���� �������������
        for(j = 0; j <= 3; j++){
                if(j == 2){    // ���� 2 ���� ����������� - ��������������
                    printf("\nLast try!\n");
                }
                if(j == 3){   // ���� 3 ���� ����������� - ����������� ������
                    return;
                }
            printf("\nEnter your PIN in 4 digits:\n");
                val = scanf("%d", &enterPin);
                if(val == 0){   // ���� ������������ ��� �������� ������ - ��������� ����
                    printf("\nIt`s not correct value!\n");
                    fflush(stdin);
                }
                    // �������� � ����� �� ������� PIN - ����� �������������
                    // �� ������ �������� � pinUs ���������� �������� i-�� �������� �������
                for(i = 0; i < SIZE; i++){
                    pinPtr = &pinOfUsers[i];
                    pinUs = *pinPtr;
                    // ���� ��������� PIN ������ � i-�, ���� ���������������,
                    if(enterPin == pinUs){
                        printf("\nHello, Vladimir!");
                        userAccount = accountsOfUsers[i]; // � ���������� ���������� �������� �����
                        j = 3;                      // � ����� �� ��������, ��� � ��������� PIN - ���
                        break;
                    }
                }
            }


// ���� PIN - ��� ������, ������������ ����������� ������ � ���������� ������
        for(;;){

                printf("\n--------------------------------------\n");
                printf("\nEnter the digits to choice:\n");
                printf("\n 1 - Your balance\n");
                printf("\n 2 - Refill your account\n");
                printf("\n 3 - Withdrawing money from your account\n");
                printf("\n 4 - End the work\n");
                printf("\n");
                scanf(" %d", &choice);
    // �������� �� ������ - � ������������ � �������� ����
                switch(choice){
                    case 1 :
                        printf("\n--------------------------------------\n");
                        printf("\nYour balance is - %d", userAccount);
      // ����� �������� �� ����� ���������, ������������ ����� - ���������� ������, ��� ���������
                        printf("\nContinue or exit? - y, n\n");
                        scanf("%s", &select);

                        if(select == 'y'){
                            continue;
                        }
                        if(select == 'n'){
                            return;
                        }
                    break;


                    case 2 :
                        printf("\n--------------------------------------\n");
                        printf("\nYour balance is - %d\n", userAccount);
                        printf("\nRefill - enter the amount\n");
                        scanf("%d", &deposit);
                        if(deposit){
                            sumDeposit = userAccount + deposit;
                            printf("Your balance is - %d\n", sumDeposit);
                            userAccount = sumDeposit;
                            printf("\nContinue or exit? - y, n\n");
                            scanf("%s", &select);

                            if(select == 'y'){
                                continue;
                            }
                            if(select == 'n'){
                                return;
                            }
                            break;
                        }
                    case 3 :
                        printf("\n--------------------------------------\n");
                        printf("\nYour balance is - %d\n", userAccount);
                        printf("\nWithdrawing money from your account - enter the amount\n");
                        scanf("%d", &withdraw);

                        if(withdraw){
                            sumWithdraw = userAccount - withdraw;
                            printf("Your balance is - %d\n", sumWithdraw);
                            userAccount = sumWithdraw;
                            printf("\nContinue or exit? - y, n\n");
                            scanf("%s", &select);

                            if(select == 'y'){
                                continue;
                            }
                            if(select == 'n'){
                                return;
                            }
                            break;
                        }
                    case 4 :
                        printf("\nYour balance is - %d\n", userAccount);
                    return;

                }
            }


    return 0;
    }
