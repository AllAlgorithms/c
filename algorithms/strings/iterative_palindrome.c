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
char *inversor(char *string, int tam)
{
	char *aux;
	aux = malloc(MAX*sizeof(char));

	int inc = 0;
    int copy = 0;
	int i;
	for (i = tam-1; i >= 0 ; i--)
	    copy = tam-1;
        inc = 0;
	for (int i = tam-1; i >= 0 ; i--)
	{
		aux[inc] = string[i];
		inc++;
	}
	return aux;
}
int comparador(char *s1, char *s2, int max)
{
	int contador = 0;
	while(contador < max)
	{
		if (s1[contador] != s2[contador])
			return 0;
		contador++;
	}
	return 1;
}
int main()
{
	char *reader;
	reader = malloc(MAX*sizeof(char));
	char *inverso;
	inverso = malloc(MAX*sizeof(char));
	scanf("%s",reader);
	int tam = acha_tamanho(reader);
	inverso = inversor(reader,tam);
	if (comparador(reader,inverso, tam))
		printf("PALINDROME\n");
	else
		printf("NOT PALINDROME\n");
	free(reader);
	free(inverso);
	return 0;
}
