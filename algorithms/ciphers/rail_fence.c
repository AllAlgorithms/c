#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

// function to encrypt a message 
char* encryptRailFence(char* text, int key){
    // create the matrix to cipher plain text
    // key = rows , length(text) = columns
    char rail[key][strlen(text)];
    int i=0,j=0,k=0;
    // to find the direction
    int dir_down = 0;
    int row = 0, col = 0;
    char* result = (char *)malloc(sizeof(char)* strlen(text));
    // filling the rail matrix to distinguish filled
    // spaces from blank ones
    for (i=0; i < key; i++)
        for (j = 0; j < strlen(text); j++)
            rail[i][j] = '\n';
            
    for (i=0; i < strlen(text); i++) {
        // check the direction of flow
        // reverse the direction if we've just
        // filled the top or bottom rail
        if (row == 0 || row == key-1)
            dir_down = !dir_down;
        // fill the corresponding alphabet
        rail[row][col++] = text[i];
        // find the next row using direction flag
        dir_down?row++ : row--; 
    }
    //now we can construct the cipher using the rail matrix
    for (i=0; i < key; i++)
        for (j=0; j < strlen(text); j++)
            if (rail[i][j]!='\n') {
                result[k] = rail[i][j];
                k++;
            }
     return result; 
}

// This function receives cipher-text and key 
// and returns the original text after decryption 
char* decryptRailFence(char* cipher, int key) {
    // create the matrix to cipher plain text 
    // key = rows , length(text) = columns 
    char rail[key][strlen(cipher)];
    int i=0,j=0,k=0;
    // to find the direction
    int dir_down = 0;
    int row = 0, col = 0;
    int index = 0; 
    char* result = (char *)malloc(sizeof(char)* strlen(cipher)); 
    
    // filling the rail matrix to distinguish filled 
    // spaces from blank ones 
    for (i=0; i < key; i++)
        for (j=0; j < strlen(cipher); j++)
            rail[i][j] = '\n';
    
    // mark the places with '*' 
    for (i=0; i < strlen(cipher); i++) { 
        // check the direction of flow 
        if (row == 0) 
            dir_down = 1; 
        if (row == key-1) 
            dir_down = 0; 
        // place the marker 
        rail[row][col++] = '*';
        // find the next row using direction flag 
        dir_down?row++ : row--; 
    } 
    // now we can construct the fill the rail matrix 
    for (i=0; i<key; i++) 
        for (j=0; j<strlen(cipher); j++) 
            if (rail[i][j] == '*' && index<strlen(cipher)) 
                rail[i][j] = cipher[index++];
    
    // now read the matrix in zig-zag manner to construct 
    // the resultant text 
    row = 0, col = 0; 
    for (i=0; i< strlen(cipher); i++) {
        // check the direction of flow 
        if (row == 0) 
            dir_down = 1; 
        if (row == key-1)
            dir_down = 0; 
        // place the marker
        if (rail[row][col] != '*') {
            result[k] = rail[row][col++];
            k++;
        }
        // find the next row using direction flag 
        dir_down?row++: row--; 
    } 
    return result; 
}

//driver program to check the above functions 
int main() { 
    char plain_text[50];
    char* cipher_text = NULL;
    int key;
    printf("Enter the plain text : ");
    fgets(plain_text,50,stdin);
    printf("Enter the key : ");
    scanf("%d",&key);
    cipher_text = encryptRailFence(plain_text,key);
    printf("Cipher text : %s\n",cipher_text);
    //Now decryption of the same cipher-text 
    printf("Decryption of the same cipher text : %s\n",decryptRailFence(cipher_text,key)); 
    return 0; 
} 
