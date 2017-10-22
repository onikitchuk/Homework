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


    // Массив PIN - кодов пользователей
        for(i = 0; i < SIZE; i++){
            pinOfUsers[i] = (2534 + 76*i);
            printf("%d ", pinOfUsers[i]);
        }

        printf("\n");
    // Массив ACCOUNTS пользователей
        for(i = 0; i < SIZE; i++){
            accountsOfUsers[i] = (12000 + 900*i);
            printf("%d ", accountsOfUsers[i]);
        }
        printf("\n");

// Введение PIN - кода пользователем
        for(j = 0; j <= 3; j++){
                if(j == 2){    // Если 2 раза неправильно - предупреждение
                    printf("\nLast try!\n");
                }
                if(j == 3){   // Если 3 раза неправильно - заканчиваем работу
                    return;
                }
            printf("\nEnter your PIN in 4 digits:\n");
                val = scanf("%d", &enterPin);
                if(val == 0){   // Если некорректный тип вводимых данных - повторить ввод
                    printf("\nIt`s not correct value!\n");
                    fflush(stdin);
                }
                    // Проходим в цикле по массиву PIN - кодов пользователей
                    // На каждой итерации в pinUs записываем значение i-го элемента массива
                for(i = 0; i < SIZE; i++){
                    pinPtr = &pinOfUsers[i];
                    pinUs = *pinPtr;
                    // Если введенный PIN совпал с i-м, цикл останавливается,
                    if(enterPin == pinUs){
                        printf("\nHello, Vladimir!");
                        userAccount = accountsOfUsers[i]; // В переменную записываем значение счета
                        j = 3;                      // с таким же индексом, что и совпавший PIN - код
                        break;
                    }
                }
            }


    // Если PIN - код верный, пользователю открывается доступ к управлению счЁтом
        for(;;){

                printf("\n--------------------------------------\n");
                printf("\nEnter the digits to choice:\n");
                printf("\n 1 - Your balance\n");
                printf("\n 2 - Refill your account\n");
                printf("\n 3 - Withdrawing money from your account\n");
                printf("\n 4 - End the work\n");
                printf("\n");
                scanf(" %d", &choice);
    // Операции со счетом - в соответствии с пунктами меню
                switch(choice){
                    case 1 :
                        printf("\n--------------------------------------\n");
                        printf("\nYour balance is - %d", userAccount);
      // Кокда операция по счету заверщена, предлагается выбор - продолжить работу, или завершить
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
