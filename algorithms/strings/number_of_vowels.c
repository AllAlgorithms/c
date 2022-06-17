#include<stdio.h>

int main(){

  char word[25];
  int no_of_a = 0, no_of_e = 0, no_of_i = 0, no_of_o = 0, no_of_u = 0,total=0;
  printf("Enter the word: ");
  gets(word);

  char* wordat = &word[0];
  int i;
  for(i = 0; *(wordat + i) != '\0'; i++){

    if(*(wordat+i)=='a' || *(wordat+i)=='A'){
      no_of_a++;
    }
    else if(*(wordat+i)=='e' || *(wordat+i)=='E' ){
      no_of_e++;
    }
    else if(*(wordat+i)=='i' || *(wordat+i)=='I'){
      no_of_i++;
    }
    else if(*(wordat+i)=='o' || *(wordat+i)=='O'){
      no_of_o++;
    }
    else if(*(wordat+i)=='u' || *(wordat+i)=='U'){
      no_of_u++;
    }
    else{
      continue;
    }

  }

  printf("Number of 'a': %d\n", no_of_a);
  printf("Number of 'e': %d\n", no_of_e);
  printf("Number of 'i': %d\n", no_of_i);
  printf("Number of 'o': %d\n", no_of_o);
  printf("Number of 'u': %d\n", no_of_u);
  total= no_of_a + no_of_e + no_of_i + no_of_o + no_of_u
  printf("Total number of vowels: %d\n",total);


  return 0;
}
