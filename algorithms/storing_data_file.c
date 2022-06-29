#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

FILE *contact;
//void search();
void welcome();
int press();
void add();
struct contact//this is the data that we will take 
{
    char name[20];
    char number[10];
};
void main()
{
    int a;
    welcome();
    printf("\n");
    while(1)//this is that our program runs continuosly till we don't close it
    {
      a=press();//to take input from the user about the feature that the user want to use
      if(a==1)
      {
        add();
      }
      else if(a==0)
      {
          exit(0);//it will exit the program
      }
      else
      {
          printf("please enter the valid number");
      }
    }
}

void welcome()//welcome guard this will capitalize the first letters of the name and say welcome to the user
{
    int a=0;
    char welcome[15];
    printf("What's your name: ");
    fgets(welcome,15,stdin);
    if(welcome[0]>='a' && welcome[0]<='z')
    {
        welcome[0]=toupper(welcome[0]);
    }
    for(int i=0;i<15;i++)
    {
       if(welcome[i]== ' ')
       {
           if(welcome[i+1]>='a' && welcome[i+1]<='z')
            {
                   welcome[i+1]=toupper(welcome[i+1]);
            }
       }
    }
    printf("Welcome %s",welcome);
}

int press()// this will take the input from the user about the feature that the user want to user and will return to main
{
    int a;//declaration for storing the value of input key
    printf("Choose out from the following:\n\nPress 1 to Add a contact\nPress 0 for exit\nWhich one will you prefer:");//these are the options
    scanf("%d",&a);//it will scan the button pressed
    return a;//it will return the number to main and according to that action will be taken
}

void add()//to add a contact
{
    struct contact add;//declaration of structure as add
    printf("NAME: ");//will tell to type the name in terminal
    scanf("%s",&add.name);//it will scan the name from the user
    printf("CONTACT NO.: ");//will tell to type the number in terminal
    scanf("%s",&add.number);//it will scan the number from the user
    contact=fopen("contact.txt","a");//it opens file in append mode
    fprintf(contact,"NAME: %s , ",add.name);//it will print the scanned name into the text file named as contact.txt
    fprintf(contact,"NUMBER: %s\n",add.number);//it will print the scanned number into the text file named as contact.txt
    fclose(contact);//it will close the file at last    
}
