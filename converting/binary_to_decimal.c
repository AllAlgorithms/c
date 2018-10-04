// Author: Murilo Ferreira

int binaryToDecimal(int binary) {
    int decimal = 0;
    int multiplier = 1;
    while (binary != 0) {
        decimal += (binary % 10)* multiplier;
        binary /= 10;
        multiplier *= 2;
    }
    return decimal;
}

