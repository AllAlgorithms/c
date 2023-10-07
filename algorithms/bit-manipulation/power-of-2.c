/**
 * power of 2 algorithm
 * check wether a given integer n 
 * can be in a put in a form of power of 2
 * by using a bitwise manipulation 
 * Time compexity = O(n)
 * example : n = 16 can be put in the form 2^4
 */

int power_of_two(int n){
    /* for edge cases */
    if(n <= 0) return 0;

    if ((n & (n - 1)) == 0)
    {
        return 1; // true
    }
    return 0; // false
}

/**
 ***EXPLAINATION
 * how it checks wether an integer can be put
 * in the form of power of 2 or not is
 ***any integer number which can be put 
 *  in the form of power of 2 has only 
 *  1 bit in the binary reprentation 
 *  example : n = 16 , 00010000 (8 bits represntation)
 *  so when we do AND bitwise manipulation with the
 *  previous number it will always give 0 
 *  if the integer n can be kept in the form of
 *  power of 2 ***
 *  
 * EXAMPLE :
 *      n = 16 , 00010000 (8 bits)
 *      n = n-1 = 15 , 00001111 (8 bits) previous value
 *      n & (n-1) , 00010000  
 *                & 00001111
 *                  00000000
 *      which is 0 
 *      so it can be put in the form of power of 2
 */