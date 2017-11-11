#include <stdio.h>

    // encryption of a phrase with a key - keyForEncrypt
    char encryptPhrase(char* enteredPhrase, int keyForEncrypt){
        int i = 0;
             for(i = 0; i < enteredPhrase[i] != '\0'; i++){
                enteredPhrase[i] += keyForEncrypt;
             }
        printf("\nEncrypted phrase - %s\n",enteredPhrase);
        return enteredPhrase;
    }

    int main(){

        int keyForEncrypt = 0;
        int choiceOfAction = 0;

        char* enteredPhrase = (char*)malloc(sizeof(char) * 200000);
        char* encryptedPhrase = (char*)malloc(sizeof(char) * 200000);
        char* decryptedPhrase = (char*)malloc(sizeof(char) * 200000);

        printf("Enter the phrase you want to encrypt: \n");
        gets(enteredPhrase);
        printf("Enter key for encrypt: ");
        scanf("%i", &keyForEncrypt);

        encryptPhrase(enteredPhrase, keyForEncrypt);

        encryptedPhrase = enteredPhrase;

          printf("\nDo you want to decrypt phrase? - 1 / 0");
          scanf("%3i", &choiceOfAction);
              if(choiceOfAction == 0){
                return;
              }
              if(choiceOfAction == 1){
                 int i = 0;
                 for(i = 0; i < encryptedPhrase[i] != '\0'; i++){
                    encryptedPhrase[i] -= keyForEncrypt;
                 }
                decryptedPhrase = encryptedPhrase;
                printf("\nOpen phrase - %s", decryptedPhrase);
              }
        return 0;
    }
