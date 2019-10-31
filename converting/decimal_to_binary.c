#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverseStr(char *strToReverse) {
    int strToReverseLength = strlen(strToReverse);
    char *reversedStr = malloc(sizeof(char) * (strToReverseLength + 1));

    int i = 0;
    int j = strToReverseLength - 1;
    while (j != -1) {
        reversedStr[i] = strToReverse[j];
        i += 1;
        j -= 1;
    }
    reversedStr[i] = 0;
    return reversedStr;
}

char *decimalToBinary(int decimalValue) {
    char *res = 0;
    int position = 0;

    while (decimalValue != 0) {
        res = realloc(res, sizeof(char));
        res[position] = decimalValue % 2 == 0 ? '0' : '1';
        position += 1;
        decimalValue = decimalValue / 2;
    }
    return reverseStr(res);
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        return 0;
    }
    int argAsInt = atoi(argv[1]);
    if (argAsInt == 0) {
        return 0;
    }
    printf("%s in decimal give %s in binary", argv[1], decimalToBinary(argAsInt));
    return 0;
}
