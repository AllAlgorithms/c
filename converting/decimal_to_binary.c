int decimalToBinary(int decimal) {
    int binary = 0;
    int multiplier = 1;

    while (decimal != 0) {
        binary += (decimal % 2)* multiplier;
        decimal /= 2;
        multiplier *= 10;
    }
    return binary;
}

