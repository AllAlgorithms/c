//implementation of vigenere cipher alogrithm. this code can encrypt and decrypt texts using a key. 
//



#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define MAX_SIZE 1000
#define MAX_KEY_SIZE 100

void clear ()
{    
  while ( getchar() != '\n' );
}

char Alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; 
char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char* cipher(char cleartext[], char key[], char ciphertext[]){

    int count = 0;
    int keycount = 0;
    if(cleartext[0] != '\0'){
        do{
            if(cleartext[count] <= 'z' && cleartext[count]>= 'a'){
                ciphertext[count] = alphabet[((cleartext[count]-'a')+(key[keycount%strlen(key)]-'a'))%26];
                count++;
                keycount++;
            }
            else if(cleartext[count] <= 'Z' && cleartext[count]>= 'A'){
                ciphertext[count] = Alphabet[((cleartext[count]-'A')+(key[keycount%strlen(key)]-'a'))%26];
                count++;
                keycount++;
            }
            else{
                ciphertext[count] = cleartext[count];
                count++;
            }
        }while(cleartext[count] != '\0');
    }
    ciphertext[count] = '\0';
    return ciphertext;

}

char* decrypt(char ciphertext[], char key[], char cleartext[]){

    int count = 0;
    int keycount = 0;
    if(ciphertext[0] != '\0'){
        do{
            if(ciphertext[count] <= 'z' && ciphertext[count]>= 'a'){
                cleartext[count] = alphabet[((ciphertext[count]-'a')-(key[keycount%strlen(key)]-'a')+26)%26];
                count++;
                keycount++;
            }
            else if(ciphertext[count] <= 'Z' && ciphertext[count]>= 'A'){
                cleartext[count] = Alphabet[((ciphertext[count]-'A')-(key[keycount%strlen(key)]-'a')+26)%26];
                count++;
                keycount++;
            }
            else{
                cleartext[count] = ciphertext[count];
                count++;
            }
        }while(ciphertext[count] != '\0');
    }
    cleartext[count] = '\0';
    return cleartext;

}

int main(){

    char cleartext[MAX_SIZE],  key[MAX_KEY_SIZE], ciphertext[MAX_SIZE];
    
    int count;

    int choice;
    while(choice != 0){
        count = 0;
        printf("Enter 1 to encrypt a text, enter 2 to decrypt a text. Enter 0 to exit:\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the key (all lowercase):\n");
                clear();
                scanf("%99[^\n]", key);

                printf("Enter the cleartext in a single line:\n");
                clear();
                scanf("%999[^\n]", cleartext);


                strcpy(ciphertext, cipher(cleartext, key, ciphertext));

                FILE* encrypted;
                encrypted = fopen("encrypted.txt", "a");


                printf("your encrypted text is: ");
                while(ciphertext[count] != '\0'){
                    fprintf(encrypted, "%c", ciphertext[count]);
                    printf("%c", ciphertext[count]);
                    count++;
                }
                fprintf(encrypted, "\n");
                printf("\nYou can find this text in the \"encrypted.txt\" file in this folder\n");
                fclose(encrypted);
                break;
            case 2:
                printf("Enter the key (all lowercase):\n");
                clear();

                scanf("%99[^\n]", key);

                
                printf("Enter the ciphertext in a single line:\n");
                clear();
                scanf("%999[^\n]", ciphertext);


                strcpy(cleartext, decrypt(ciphertext, key, cleartext));

                FILE* decrypted;
                decrypted = fopen("decrypted.txt", "a");


                printf("your decrypted text is: ");
                while(cleartext[count] != '\0'){
                    fprintf(decrypted, "%c", cleartext[count]);
                    printf("%c", cleartext[count]);
                    count++;
                }
                fprintf(decrypted, "\n");
                printf("\nYou can find this text in the \"decryted.txt\" file in this folder\n");
                fclose(decrypted);
                break;

            case 0:
                exit(0);
            
            default:
                break;

        }
    }

    return 0;


}