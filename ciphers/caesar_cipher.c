#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* caesarCipher(int, char*, char);

int main () {
  char text[] = "Hello World! ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *encryptedText;
  char *decryptedText;

  encryptedText = caesarCipher(1, text, 'e');
  decryptedText = caesarCipher(1, encryptedText, 'd');

  printf("Plain text: %s\n", text);
  printf("Encrypted text with key 1: %s\n", encryptedText);
  printf("Decrypted text: %s\n", decryptedText);

  free(encryptedText);

  return 0;
}

char* caesarCipher(int key, char *text, char opt) {
  char alphabet[26];
  int offset = 65;
  int textSize = strlen(text);
  int i = 0;
  char *outputText = malloc(textSize+1);
  char oldCharacter;
  char newCharacter;
  char upperChar;

  if (!outputText)
    exit(1);

  // if decrypting text
  if (opt == 'd')
    key = -key;

  // create alphabet
  for (i = 0; i < 26; i++) {
    alphabet[i] = offset + i;
  }

  // caesar cipher
  for (i = 0; i < textSize; i++) {
    if (isalpha(text[i])) {
      // convert text to uppercase
      upperChar = toupper(text[i]);
      // gets index of the old character in alphabet array
      oldCharacter = upperChar - offset;
      // finds shifted index 
      newCharacter = (oldCharacter + key) % 26;
      if (newCharacter < 0)
        newCharacter += 26;
      // add character to output text
      outputText[i] = alphabet[newCharacter];
    } else {
      // if character isn't in the alphabet, add it
      outputText[i] = text[i];
    }
  }
  outputText[textSize] = '\0';

  return outputText;
}
