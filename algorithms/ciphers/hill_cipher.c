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
#include <stdlib.h>

#define MOD 26 // Modulus for the English alphabet

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to find the modular multiplicative inverse of a number
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Inverse doesn't exist
}

// Function to encrypt a message using a Hill cipher
void hillCipherEncrypt(char* message, int keyMatrix[3][3], int keySize) {
    int i, j, k, msgLen;
    int block[keySize];

    // Calculate the message length
    for (msgLen = 0; message[msgLen] != '\0'; msgLen++);

    // Pad the message with 'X' to make it evenly divisible by the key size
    while (msgLen % keySize != 0) {
        message[msgLen] = 'X';
        msgLen++;
    }

    // Perform encryption for each block of characters
    for (i = 0; i < msgLen; i += keySize) {
        // Convert the block to numerical values (A=0, B=1, ..., Z=25)
        for (j = 0; j < keySize; j++) {
            block[j] = message[i + j] - 'A';
        }

        // Encrypt the block using the key matrix
        for (j = 0; j < keySize; j++) {
            message[i + j] = 'A' + (char)((block[0] * keyMatrix[j][0] + block[1] * keyMatrix[j][1] + block[2] * keyMatrix[j][2]) % MOD);
        }
    }
}

int main() {
    char message[] = "HELLOHILL"; // Message to be encrypted
    int keyMatrix[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}}; // Encryption key
    int keySize = 3; // Size of the encryption key

    // Check if the key matrix is valid (determinant should be co-prime with 26)
    int det = keyMatrix[0][0] * (keyMatrix[1][1] * keyMatrix[2][2] - keyMatrix[2][1] * keyMatrix[1][2]) -
              keyMatrix[0][1] * (keyMatrix[1][0] * keyMatrix[2][2] - keyMatrix[2][0] * keyMatrix[1][2]) +
              keyMatrix[0][2] * (keyMatrix[1][0] * keyMatrix[2][1] - keyMatrix[2][0] * keyMatrix[1][1]);
    det = (det % MOD + MOD) % MOD; // Ensure the determinant is positive

    if (gcd(det, MOD) != 1) {
        printf("The key matrix is not valid for Hill cipher encryption.\n");
        return 1;
    }

    // Encrypt the message
    hillCipherEncrypt(message, keyMatrix, keySize);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}
