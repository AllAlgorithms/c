//
// Decimal to Binary
// Converts decimal to binary.
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Hiyabye
// Github: @Hiyabye
//
#include <stdio.h>

int calculate_power(int base, int power)
{
  int i, result = 1;
  for (i=0; i<power; i++)
    result *= base;
  return result;
}

void decimal_to_binary(int decimal)
{
  int i;
  int digitCount = 1;
  int temp = decimal;
  while (temp >= 2)
  {
    temp /= 2;
    digitCount++;
  }
  for (i=digitCount-1; i>=0; i--)
  {
    if (decimal >= calculate_power(2, i))
    {
      printf("1");
      decimal -= calculate_power(2, i);
    }
    else
      printf("0");
  }
}

int main()
{
  int decimal;
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);
  printf("The binary for %d is ", decimal);
  decimal_to_binary(decimal);
  printf("\n");
  return 0;
}



// I have another way of doing it using math.h library
#include <math.h>
#include <stdio.h>
long long convert(int n);
int main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("%d in decimal = %lld in binary", n, convert(n));
    return 0;
}

long long convert(int n) {
    long long bin = 0;
    int rem, i = 1, step = 1;
    while (n != 0) {
        rem = n % 2;
        printf("Step %d: %d/2, Remainder = %d, Quotient = %d\n", step++, n, rem, n / 2);
        n /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}

// here will explain the output
// 21 / 2 = 10 with 1 remainder
// 10 / 2 = 5 with 0 remainder
// 5 / 2 = 2 with 1 remainder
// 2 / 2 = 1 with 0 remainder
// 1 / 2 = 0 with 1 remainder
// so finally we get output:10101
