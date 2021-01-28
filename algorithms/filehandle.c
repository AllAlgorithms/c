//ROT-13 Cryptographic symmetric key algorithm
//Special Case of Caesar Cipher
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
/*
  @author Ridham Karia
  @Param .txt file
  @returns Cipher/Decoded Text
*/
int main()
{
    FILE *fp;
    fp=fopen("try.txt","r");
    char buf[10001],d;
    unsigned int k;
    if(fp==NULL)
      printf("Failed to Open.\n");
    else
    {
      fgets(buf,k+1,fp);
      k=ftell(fp);
      printf("Decoded/Cipher Text is:\n");
      for(int i=0;i<k;i++)
      {
        printf("%c",buf[i]+13);
      }
    }
    fclose(fp);
    return 0;
}
