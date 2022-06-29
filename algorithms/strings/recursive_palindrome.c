#include <stdio.h>
#include <stdlib.h>
#define MAX 500

int acha_tamanho(char *string)
{
	int per = 0;
	
	while(string[per] != '\0')
	{
		per++;
	}
	return per;
}
int ehpalindromo(char *string, int index, int ini)
{
	if (index >= 0)
	{
		if (string[ini] != string[index])
			return 0;
		else
		{
			int m = index - 1;
			int n = ini + 1; 
			return (ehpalindromo(string, m, n));
		}
	}
	return 1;

}
int main()
{
	char *leitura;
	leitura = malloc(MAX*sizeof(char));
	scanf("%s",leitura);
	int tam = acha_tamanho(leitura);
	int tr = ehpalindromo(leitura,tam-1,0);
	if (tr)
		printf("PALINDROME\n");
	else
		printf("NOT PALINDROME\n");
	return 0;
}