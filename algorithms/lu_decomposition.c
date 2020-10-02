#include<stdio.h>
#include<math.h>
#define SIZE 5                  //set this to the size of the required matrix

void PrintMatrix(double A[SIZE][SIZE])
{
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			printf("%2.6lf\t",A[i][j]);
		}
		printf("\n");
	}
}
void PrintVector(double x[SIZE])
{
	for(int i=0;i<SIZE;i++)
		printf("%2.6lf\n",x[i]);
}

int MatrixEqual(const double A[SIZE][SIZE],const double B[SIZE][SIZE])
{
	int t=0;
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			if(A[i][j]!=B[i][j])
				t++;
	return t;
}

int VectorEqual(const double A[SIZE],const double B[SIZE])
{
	int t=0;
	for(int i=0;i<SIZE;i++)
			if(A[i]!=B[i])
				t++;
	return t;
}

double VectorNorm(const double A[SIZE])
{
	double sum=0.0;
	for(int i=0;i<SIZE;i++)
		sum+=A[i]*A[i];

	return sqrt(sum);
}

void SubtractVector(const double A[SIZE],const double B[SIZE],double C[SIZE])
{
	for(int i=0;i<SIZE;i++)
		C[i]=A[i]-B[i];
}

void AbsoluteMatrix(const double A[SIZE][SIZE], double B[SIZE][SIZE])
{
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			B[i][j]=fabs(A[i][j]);
}
int IsZeroMatrix(const double A[SIZE][SIZE])
{
	int t=0;
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			if(fabs(A[i][j])!=0)
				t++;
	//printf("t = %d\n",t);
	return t;
}

void MatrixMult(const double S[SIZE][SIZE], const double T[SIZE][SIZE],double C[SIZE][SIZE])
{
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			for(int k=0;k<SIZE;k++)
				C[i][j]+=S[i][k]*T[k][j];
}


void MatrixSubtraction(const double A[SIZE][SIZE],const double B[SIZE][SIZE], double C[SIZE][SIZE])
{
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			C[i][j]=A[i][j]-B[i][j];
}


void MatrixVector(const double S[SIZE][SIZE], const double X[SIZE],double Y[SIZE])
{
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
				Y[i]+=S[i][j]*X[j];
	PrintVector(Y);
}





void ForwardSubst(const double l[SIZE][SIZE],const double b[SIZE],double y[SIZE])
{
	y[0]=b[0]/l[0][0];
	for(int i=1;i<SIZE;i++)
    {   double sum=b[i];
        for(int j=0;j<i;j++)
            sum-=l[i][j]*y[j];
        y[i]=sum/l[i][i];
    }
}


void BackwardSubst(const double U[SIZE][SIZE],const double b[SIZE],double x[SIZE])
{
	x[SIZE-1]=b[SIZE-1]/U[SIZE-1][SIZE-1];
	for(int i=SIZE-2;i>=0;i--)
    {
        double sum=b[i];
        for(int j=i+1;j<SIZE;j++)
            sum-=U[i][j]*x[j];
        x[i]=sum/U[i][i];
    }
}





void LUDecomposition(const double A[SIZE][SIZE],double l[SIZE][SIZE],double u[SIZE][SIZE])
{
	for(int k=0;k<SIZE;k++)
    {      l[k][k]=1;
         double sum=0;
        for(int s=0;s<k;s++)
        {
            sum+=l[k][s]*u[s][k];
        }
        u[k][k]=(A[k][k]-sum)/l[k][k];                     //This function decomposes the A matrix into
        for(int i=k+1;i<SIZE;i++)                          //a lower triangular matrix and an Upper triangular matrix
        {   sum=0;
            for(int s=0;s<k;s++)
                sum+=l[k][s]*u[s][i];
            u[k][i]=(A[k][i]-sum)/l[k][k];
        }
        for(int i=k+1;i<SIZE;i++)
        {   sum=0;
            for(int s=0;s<k;s++)
                sum+=l[i][s]*u[s][k];
            l[i][k]=(A[i][k]-sum)/u[k][k];

        }
    }

}
void SolveLU(double L[SIZE][SIZE],double U[SIZE][SIZE],double b[SIZE],double x[SIZE])
{
	double y[SIZE]={0};
	ForwardSubst(L,b,y);                   //Here forward and backward substitution is being used to solve for x in Ax=b
	BackwardSubst(U,y,x);
}


int main()
{	double A[SIZE][SIZE]={0};			//Assign A and b values assuming the form Ax=b                     
	double b[SIZE]={0};
	PrintMatrix(A);
	double L[SIZE][SIZE]={0};
	double U[SIZE][SIZE]={0};
	LUDecomposition(A,L,U);
	double x[SIZE]={0};
	double C[SIZE][SIZE]={0};
	SolveLU(L,U,b,x);
	PrintVector(x);
	return 0;
}
