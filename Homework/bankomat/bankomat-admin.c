#include <stdio.h>


int main(void){

    const int SIZE = 10;
    const int NUMBER_FOR_ALGORITM_1 = 2534;
    const int NUMBER_FOR_ALGORITM_2 = 76;
    const int NUMBER_FOR_ALGORITM_3 = 12000;
    const int NUMBER_FOR_ALGORITM_4 = 900;
    const int ADMIN_PASSWORD = 1111;

    int pinOfUsers[SIZE];
    int accountsOfUsers[SIZE];

    int enteredPin = 0;
    int choiceOfAction = 0;
    int refillAccount = 0;
    int withdraw = 0;
    int sumDeposit = 0;
    int sumWithdraw = 0;
    int i,j;

    int enteredAdminPin = 0;
    int userAccount = 0;
    int usAccount = 0;
    char select = 0;

    int* pinPtr;
    int pinOfUser = 0;
    char adminOrUser = 0;
    int adminChoiceOfAction = 0;


    // ������ PIN - ����� �������������
        for(i = 0; i < SIZE; i++){
            pinOfUsers[i] = (NUMBER_FOR_ALGORITM_1 + NUMBER_FOR_ALGORITM_2*i);
            printf("%d ", pinOfUsers[i]);
        }

        printf("\n");
    // ������ ACCOUNTS �������������
        for(i = 0; i < SIZE; i++){
            accountsOfUsers[i] = (NUMBER_FOR_ALGORITM_3 + NUMBER_FOR_ALGORITM_4*i);
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
            int enteredValue = 0;
                enteredValue = scanf("%d", &enteredPin);
                if(enteredValue == 0){   // ���� ������������ ��� �������� ������ - ��������� ����
                    printf("\nIt`s not correct value!\n");
                    fflush(stdin);
                }
                    // �������� � ����� �� ������� PIN - ����� �������������
                    // �� ������ �������� � pinOfUser ���������� �������� i-�� �������� �������
                for(i = 0; i < SIZE; i++){
                    pinPtr = &pinOfUsers[i];
                    pinOfUser = *pinPtr;
                    // ���� ��������� PIN ������ � i-�, ���� ���������������,
                    if(enteredPin == pinOfUser){
                        printf("\nHello, Vladimir!");
                        userAccount = accountsOfUsers[i]; // � ���������� ���������� �������� �����
                        j = 3;                      // � ����� �� ��������, ��� � ��������� PIN - ���
                        break;
                    }
                }
                if(enteredPin == ADMIN_PASSWORD){
                    printf("\nHello, Admin");
                    break;
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
                printf("\n 5 - Administrator\n");
                printf("\n");
                scanf(" %d", &choiceOfAction);
    // �������� �� ������ - � ������������ � �������� ����
                switch(choiceOfAction){
// ���������� �������
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

// ��������� �������
                    case 2 :
                        printf("\n--------------------------------------\n");
                        printf("\nYour balance is - %d\n", userAccount);
                        printf("\nRefill - enter the amount\n");
                        scanf("%d", &refillAccount);
                        if(refillAccount > 0){
                            sumDeposit = userAccount + refillAccount;
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
// ����� ������
                    case 3 :
                        printf("\n--------------------------------------\n");
                        printf("\nYour balance is - %d\n", userAccount);
                        printf("\nWithdrawing money from your account - enter the amount\n");
                        scanf("%d", &withdraw);

                        if(withdraw > 0){
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
 //5 - � ���� ��� �������������� � ������ ������ ������
                    case 5 :
                        for(;;){
                        printf("\nEnter PIN of Admin: \n");
                        scanf("\n%d", &enteredAdminPin);
                        if(enteredAdminPin == ADMIN_PASSWORD){
                            printf("\n-------------- Administrator ----------------------\n");
                            printf("\n1 - Balance of the previous user\n");
                            printf("\n2 - Zero the balance\n");
                            printf("\n3 - Go to the user menu\n");
                            printf("\n4 - End of work\n");
                            scanf("%d", &adminChoiceOfAction);
                        } else {
                            continue;
                        }
                        switch(adminChoiceOfAction){
                            case 1 :
                                printf("\n-------------- Administrator ----------------------\n");
                                printf("\nBalance of the previous user - %d\n", userAccount);
                                printf("\nContinue or exit? - y, n\n");
                                scanf("%s", &select);
//
                                if(select == 'y'){
                                    continue;
                                }
                                break;
                                if(select == 'n'){
                                    return;
                                }
                                break;
                            case 2 :
// ��������� �������� ������������
                                printf("\n-------------- Administrator ----------------------\n");
                                userAccount = 0;
                                printf("\nBalance of the previous user - %d\n", userAccount);
                                printf("\nContinue or exit? - y, n\n");
                                scanf("%s", &select);

                                if(select == 'y'){
                                    continue;
                                }
                                break;
                                if(select == 'n'){
                                    return;
                                }
                                break;
 // ����� � ���� ������������
                            case 3 :
                                break;
 // ����� ��������������
                            case 4 :
                                return;

                        }
                        break;
                        }
                }
            }
    return 0;
}
