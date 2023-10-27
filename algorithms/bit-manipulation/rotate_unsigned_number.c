/*
Bit-Manipulation: Rotate right and rotate left.

For:
The All ▲lgorithms Project
Note: Only applicable for positive integers
1. rotate_right(num, times): rotate num(passed as decimal) "times" times towards right and return
eg.: rotate_right(12, 1) --> 6
2. rotate_left(num, times): rotate num(passed as decimal) "times" times towards left and return
eg.: rotate_left(12, 2) --> 3
Additional functions: 
3. unsigned dec_to_bin(num): return decimal form of binary format number
eg.: dec_to_bin(12) --> 1100
4. unsigned bin_to_dec(bin): return binary form of decimal format number
eg.: bin_to_dec(1100) --> 12

By AnshumanAryan24 https://github.com/AnshumanAryan24
*/

#include <stdio.h>
#include <malloc.h>

int length_of_num(unsigned);
int bin_length_of_num(unsigned);
int power(unsigned, unsigned);
unsigned* num_as_bin_array(unsigned);
unsigned array_as_bin(unsigned[], int);
unsigned dec_to_bin(unsigned);
unsigned bin_to_dec(unsigned);
unsigned rotate_right(unsigned, unsigned);
unsigned rotate_left(unsigned, unsigned);

int length_of_num(unsigned num)
{
    /*
    Returns minimum number of digits in decimal representation of number (passed in decimal format).
    Returns 0 for 0.
    */
    unsigned temp;
    int len = 0;
    // Determining length of binary number
    // for (temp = num; temp != 0;temp = temp>>1)
    // {
    //     len++;
    // }
    for (temp = num; temp != 0; len++, temp /= 10)
        ;
    return len;   
}
int bin_length_of_num(unsigned num)
{
    /*
    Returns minimum number of digits in binary representation of number (passed in decimal format).
    Returns 0 for 0.
    */
    unsigned temp;
    int len = 0;
    // Determining length of binary number
    // for (temp = num; temp != 0;temp = temp>>1)
    // {
    //     len++;
    // }
    for (temp = num; temp != 0; len++, temp >>= 1)
        ;
    return len;
}
int power(unsigned num, unsigned exponent)
{
    int res = 1;
    if (exponent == 0)
        return 1;
    // while (exponent--)
    //     res *= num;
    for ( ; exponent--; )
        res *= num;
    return res;
}
unsigned* num_as_bin_array(unsigned num)
{
    int len = bin_length_of_num(num);
    unsigned* arr = (unsigned*)malloc(sizeof(unsigned)*len);
    for (int i=0; i<len; i++)
        arr[i] = (num>>(len-i-1))&1;
    return arr;
}
unsigned array_as_bin(unsigned arr[], int len)
{
    unsigned bin = 0;
    if (len == 1)
        return arr[0];
    else if (len < 1)
        return 0;
    // else
    for (int i=0; i<len; i++)
        bin += arr[i]*power(10, len - i - 1);
    return bin;
}
unsigned dec_to_bin(unsigned num)
{
    int bin = 0;  // resulting binary number
    int pv;  // place-value holder
    // while (num)
    // {
    //     bin += power(10, pv++)*(num&1);
    //     num /= 2;
    // }
    for (pv = 0; num != 0; pv++)
    {
        bin += power(10, pv)*(num&1);  // Bitwise AND for faster modulo with 2
        num /= 2;
    }
    return bin;
}
unsigned bin_to_dec(unsigned bin)
{
    int num = 0;
    int pv = 0;  // place-value holder

    // for (num = 0, pv = 0; bin != 0; bin /= 10, pv++)
    //     num += power(2, pv)*(bin&1);  // num = 2^pv * bin[pv]

    // Multiplying by 2^k is same as left shift by k
    // Shift is usually faster than multiplication
    // num += (bin&1)<<pv, for unsigned bin
    for (; bin != 0; bin /= 10, pv++)
        num += (bin&1)<<pv;  // num = 2^pv * bin[pv]    

    return num;
}

unsigned rotate_right(unsigned num, unsigned times)
{
    int len = bin_length_of_num(num);
    unsigned bin = dec_to_bin(num);
    unsigned temp;
    for (; times--; )
    {
        temp = bin%10;  // LSB of current binary bin
        // bin ~ temp + bin[0:len-1-1]
        bin /= 10;
        bin += temp*power(10, len);
    }
    return bin_to_dec(bin);
}
unsigned rotate_left(unsigned num, unsigned times)
{
    unsigned* arr = num_as_bin_array(num);
    int len = bin_length_of_num(num);
    unsigned temp;
    for (; times--; )
    {
        temp = arr[0];  // MSB of binary
        // Shift array elements left
        for (int i=0; i<len-1; i++)
            arr[i] = arr[i+1];
        arr[len-1] = temp;  // MSB shifted to LSB position
    }
    return bin_to_dec(array_as_bin(arr, len));
}


int main()
{
    printf("rotate_left((unsigned)12, 2): %d\n", rotate_left((unsigned)12, 2));
    printf("rotate_right(12, 1): %u\n", rotate_right(12, 1)); // type conversion optional
    printf("dec_to_bin(12): %u\n", dec_to_bin(12));
    printf("bin_to_dec(12): %u\n", bin_to_dec(1100));
    return 0;
}