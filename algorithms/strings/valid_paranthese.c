/*Given a string of '{' and '}' parentheses characters, we have to check whether parentheses are in correct order or not using stack*/

/* Valid Expressions
{}{}{}{{}}, {{{{}}}{}}, {{{{}}}} */

/* Invalid Parenthesis Expressions 
{{{}{}{{{, }}{{}{{}, {{{{{{{{ */


#include <stdio.h>
#include <string.h>
 
#define SIZE 100
#define TRUE 1
#define FALSE 0 
 
// Structure defining Stack data structure
struct Stack {
    int top;
    int array[SIZE];
} st;
 
/*
Initializes the top index to -1
*/
void initialize() {
 st.top = -1;
}
 
/*
 Checks if Stack is Full or not 
*/
int isFull() {   
    if(st.top >= SIZE-1)
        return TRUE;
    else
        return FALSE;
}
 
/*
 Checks if Stack is Empty or not
*/
int isEmpty() {
 if(st.top == -1)
     return TRUE;
 else
     return FALSE;
}
 
/*
 Adds an element to stack and then increment top index 
*/
void push(int num) {
    if (isFull())
        printf("Stack is Full...\n");
    else {
        st.array[st.top + 1] = num;
        st.top++;
    }
}
 
/*
 Removes top element from stack and decrement top index
*/
int pop() {
    if (isEmpty())
        printf("Stack is Empty...\n");
    else {
     st.top = st.top - 1;
        return st.array[st.top+1];
    }
}
 
int main() {
    char inputString[100], c;
    int i, length;
    initialize();
    printf("Enter a string of paranthesis\n");
    gets(inputString);
    length = strlen(inputString);
    /*
    # for '{' : we push '{' in stack 
    # for '}' : we pop a character from stack. For every '}' there must be one '{' earlier.  
                This will ensure that
                ** There are equal number of '{' and '}' characters in string.
                ** For every '{' there is a '}' in input string later.   
             
    */
    for(i = 0; i < length; i++){
        if(inputString[i] == '{')
            push(inputString[i]);
        else if(inputString[i] == '}')
            pop();
        else {
            printf("Error : Invalid Character !! \n");
            return 0;
        }
    }
     
    if(isEmpty())
        printf("Valid Paranthesis Expression\n");
    else
        printf("InValid Paranthesis Expression\n");
         
    return 0;
