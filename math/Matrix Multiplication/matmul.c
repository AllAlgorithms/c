/* 
 * @Author: Abderrezzaq Sendjasni
 * @Email: sendjasni.abderrezzaq@gmail.com
 *
 * Matrix multiplication with execution time recording  
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAT_SIZE 50

double first_mat[MAT_SIZE][MAT_SIZE];
double second_mat[MAT_SIZE][MAT_SIZE];
double multi_result[MAT_SIZE][MAT_SIZE];

void MatrixInitialisation()
{
    srand(time(NULL));

    /*
		Initialise Matrix randomly using the rand() function
		*/

    for (int i = 0; i < MAT_SIZE; i++)
    {
        for (int j = 0; j < MAT_SIZE; j++)
        {
            first_mat[i][j] = rand() % 100;
            second_mat[i][j] = rand() % 100;
        }
    }
}
void MatrixMultiplication()
{

    int sum;

    for (int i = 0; i < MAT_SIZE; i++)
    {
        for (int j = 0; j < MAT_SIZE; j++)
        {
            sum = 0;
            for (int k = 0; k < MAT_SIZE; k++)
            {
                sum = sum + first_mat[i][k] * second_mat[k][j];
            }
            multi_result[i][j] = sum;
        }
    }
}

void DisplayMatrix()
{
    /*
		Display the multiplication result
		*/
    fprintf(stderr, "****************** Result ****************** \n");
    for (int i = 0; i < MAT_SIZE; i++)
    {
        for (int j = 0; j < MAT_SIZE; j++)
        {
            fprintf(stderr, "%f\t", multi_result[i][j]);
        }
        fprintf(stderr, "\n");
    }
}

int main(int argc, char const *argv[])
{

    MatrixInitialisation();

    struct timespec start_time;
    int begin = clock();
    clock_gettime(CLOCK_REALTIME, &start_time); /* Get cpu time before the multiplication*/

    MatrixMultiplication();

    struct timespec finish_time;
    int end = clock();
    clock_gettime(CLOCK_REALTIME, &finish_time); /* Get cpu time after the multiplication*/

    DisplayMatrix();

    fprintf(stderr, "\n *************** Mat Multiplication Stat *************** \n");
    fprintf(stderr, "Execution time : %f sec. \n", (float)((finish_time.tv_sec) - (start_time.tv_sec)));
    fprintf(stderr, "Execution time : %f nsec. \n", (float)((finish_time.tv_nsec) - (start_time.tv_nsec)));
    fprintf(stderr, "The execution clock() : %f\n ", (float)(end - begin) / (float)(CLOCKS_PER_SEC));

    return EXIT_SUCCESS;
}
