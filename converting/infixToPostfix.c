#include<stdio.h> 
#include<stdlib.h> 
#define max 30 
char stack[max]; 

int t=-1; 
int flag=0; 
void push(char val ) 
{ 
  if(t==max-1) 
  { 
   printf("overflow\n"); 
  } 
  else 
  { 
   t++; 
   stack[t]=val; 
    
  } 

} 
char pop() 
{ char n; 
  if(t<0) 
  { 
   printf("Underflow\n"); 
  } 
  else 
  { 
    n=stack[t]; 
    t--; 
    return n; 
  } 

} 

int precedence(char x) 
{ 
  if(x=='*' || x=='/' || x=='%') return 3; 
  if(x== '+' || x== '-')return 2; 
  if (x== '(')return 1; 
  

} 

void infixToPostfix(char infix[30],char postfix[30]) 
{ 
  int i , j=0  ; 
  char x; 
  for(i=0;infix[i]!='\0';i++) 
  { 
    if(infix[i]=='(') 
    { 
       push(infix[i]); 
    } 
    else if(isalpha(infix[i]) || isdigit(infix[i])) 
    { 
      postfix[j++]=infix[i]; 
     
    } 
    else if(infix[i]==')') 
   {  
      x=pop(); 
      while(x!='(') 
      { 
         postfix[j++]=x; 
         x=pop(); 
      } 
   
   } 
   else 
   { 
     
     while( t!=-1 && precedence(stack[t])>precedence(infix[i]) ) 
       { 
           x=pop(); 
           postfix[j++]=x; 
    
       } 
       push(infix[i]); 
         
   } 

 
  
  } 
   
   while(t!=-1  ) 
   {  
      x=pop(); 
      if(x=='('){flag=1;break;} 
      postfix[j++]=x; 
      
     
   } 
   postfix[j]='\0'; 
} 

void eval(char postfix[max]) 
{ t=-1; 
  int i , val; 
  char op1 , op2; 
  for(i=0;postfix[i]!='\0';i++) 
  { 
     if(isalpha(postfix[i])||isdigit(postfix[i])) 
     { 
       push(postfix[i]); 
     
     } 
     else 
     { 
       switch(postfix[i]) 
       { 
         case '+' : op2=pop(); 
                    op1=pop(); 
                    val = (int)(op1-48)+(int)(op2-48); 
                    push((char)(val+48)); 
                    break;     
        case '-' : op2=pop(); 
                    op1=pop(); 
                     val = (int)(op1-48)-(int)(op2-48); 
                    push((char)(val+48)); 
                    break; 
        case '*' : op2=pop(); 
                    op1=pop(); 
                     val = (int)(op1-48)*(int)(op2-48); 
                    push((char)(val+48)); 
                    break; 
        case '/' : op2=pop(); 
                    op1=pop(); 
                     val = (int)(op1-48)/(int)(op2-48); 
                    push((char)(val+48)); 
                    break; 
       case '%' : op2=pop(); 
                    op1=pop(); 
                    val = (int)(op1-48)%(int)(op2-48); 
                    push((char)(val+48)); 
                    break; 

       } 

     } 
     
  } 
  val=pop(); 
     printf("%d",(int)(val-48)); 
     printf("\n"); 
  


} 


void main() 
{ 
  
  char infix[30],postfix[30]; 
  printf("Enter infix expression: "); 
  scanf("%s",infix); 
  
  infixToPostfix(infix,postfix); 
  if(flag==1){printf("Invalid exp");} 
  else{printf("%s",postfix);} 
  printf("\n"); 
  eval(postfix); 
  //display(); 

}
