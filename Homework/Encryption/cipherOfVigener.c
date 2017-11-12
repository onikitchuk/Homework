#include<stdio.h>
#include<string.h>

int main(){
    char* enteredPhrase = (char*)malloc(sizeof(char) * 100000);
    char* key = (char*)malloc(sizeof(char) * 10000);

    printf("Enter the phrase:\n");
    gets(enteredPhrase);
    printf("Enter the key:\n");
    gets(key);

    int sizeEnteredPhrase = strlen(enteredPhrase);
    int sizeKey = strlen(key);
    int i = 0;
    int j = 0;

    char firstEncrypt[sizeEnteredPhrase];
    char encryptedPhrase[sizeEnteredPhrase];
    char decryptedPhrase[sizeEnteredPhrase];

    //generating new key
    for(i = 0, j = 0; i < sizeEnteredPhrase; ++i, ++j){
        if(j == sizeKey){
            j = 0;
        }
        firstEncrypt[i] = key[j];
        if(enteredPhrase[i] == ' '){
            firstEncrypt[i] = ' ';
        }
    }
    firstEncrypt[i] = '\0';

    //encryption
    for(i = 0;  i < sizeEnteredPhrase; ++i){
        if(firstEncrypt[i] == ' '){
            encryptedPhrase[i] = ' ';
            continue;
        }
        encryptedPhrase[i] =  'A' + ((toupper(enteredPhrase[i]) + toupper(firstEncrypt[i])) % 26);
    }
    encryptedPhrase[i] = '\0';

    //decryption
    for(i = 0; i < sizeEnteredPhrase; ++i){
        if(encryptedPhrase[i] == ' '){
            decryptedPhrase[i]  = ' ';
            continue;
        }
        decryptedPhrase[i] = 'A' + (((toupper(encryptedPhrase[i]) - toupper(firstEncrypt[i])) + 26) % 26);
    }
    decryptedPhrase[i] = '\0';

            printf("Entered phrase: %s", enteredPhrase);
            printf("\nKey: %s", key);
            printf("\nFirst encrypt: %s", firstEncrypt);
            printf("\nEncrypted phrase: %s", encryptedPhrase);
            printf("\nDecrypted phrase: %s", decryptedPhrase);

        free(enteredPhrase);
        free(key);
    return 0;
}
