/*
C code provided is an implementation of the RC4 algorithm, which is a widely used symmetric stream cipher. Here's what the code does:

Initialization: The code initializes the RC4 cipher with a secret key (key) and a plaintext message (plaintext) that you want to encrypt. It also creates arrays for storing the ciphertext and decrypted text.

Key Scheduling: The code performs key scheduling to initialize two arrays, S and T, of 256 bytes each. The key is used to create T, which is repeated to match the length of the key. The S array is initially filled with values from 0 to 255.

Key Mixing: The key and plaintext are mixed with the S array by performing a series of swaps. This process randomizes the S array based on the key and ensures that the key is well-distributed throughout the array.

Encryption: The code enters a loop to generate the keystream and use it to encrypt the plaintext. For each character in the plaintext, it generates a pseudo-random value (rnd) from the S array and XORs it with the corresponding character in the plaintext to produce the ciphertext.

Decryption: The code includes a rc4_decrypt function, which is essentially the same as the encryption process. This is because RC4 is a symmetric cipher, meaning that the same process is used for both encryption and decryption. To decrypt, you can simply call rc4_decrypt with the same key and the ciphertext.

Printing: Finally, the code prints the original message, the encrypted message (in hexadecimal format), and the decrypted message to the console.
*/

  
#include <stdio.h>
#include <string.h>

void rc4_encrypt(unsigned char *key, unsigned char *plaintext, unsigned char *ciphertext) {
    unsigned char S[256];
    unsigned char T[256];
    int keylen = strlen((char *)key);
    int plaintextlen = strlen((char *)plaintext);
    int i, j = 0, k = 0;

    for (i = 0; i < 256; i++) {
        S[i] = i;
        T[i] = key[i % keylen];
    }

    for (i = 0; i < 256; i++) {
        j = (j + S[i] + T[i]) % 256;
        // Swap S[i] and S[j]
        unsigned char temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    i = 0;
    j = 0;

    for (int m = 0; m < plaintextlen; m++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        // Swap S[i] and S[j]
        unsigned char temp = S[i];
        S[i] = S[j];
        S[j] = temp;

        int rnd = S[(S[i] + S[j]) % 256];
        ciphertext[m] = plaintext[m] ^ rnd;
    }
}

void rc4_decrypt(unsigned char *key, unsigned char *ciphertext, unsigned char *plaintext) {
    rc4_encrypt(key, ciphertext, plaintext); // RC4 decryption is the same as encryption
}

int main() {
    unsigned char key[] = "SecretKey";
    unsigned char plaintext[] = "Hello, RC4!";
    unsigned char ciphertext[12];
    unsigned char decryptedtext[12];

    rc4_encrypt(key, plaintext, ciphertext);
    rc4_decrypt(key, ciphertext, decryptedtext);

    printf("Original message: %s\n", plaintext);
    printf("Encrypted message: ");
    for (int i = 0; i < 12; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");
    printf("Decrypted message: %s\n", decryptedtext);

    return 0;
}
