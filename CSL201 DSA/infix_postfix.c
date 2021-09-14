#include <stdio.h>
#include <ctype.h>
#define MAX 50            
int top=-1;
char stack[MAX];
void push(char el){                       
    stack[++top]=el;
}
char pop(){                      
    return(stack[top--]);
}
 
int precedencee(char sym){                
    
	if(sym == '^')
		return(3);
	else if(sym == '*' || sym == '/')
		return(2);
	else if(sym == '+' || sym == '-')
		return(1);
	else
		return(0);
}
int evaluate(char *postfix){
    char ch;
    int i = 0, op1, op2;
    while((ch = postfix[i++]) != 0) {
     if(isdigit(ch)) 
         push(ch-'0'); 
     else { 
        op2 = pop();
        op1 = pop();
        switch(ch){
          case '+' : push(op1+op2); 
                    break;
          case '-' : push(op1-op2); 	
                    break;
          case '*' : push(op1*op2);
                    break;
          case '/' : push(op1/op2);
                    break;
        }
    }
 }
 return stack[top];
}

void main(){                        
    char infix[50],postfix[50],c,el;
    int i=0,j=0;
    printf("Enter infix expression : ");
    scanf("%s",infix);
    push('$');
    while( (c=infix[i++]) != '\0'){
        if( c == '(') 
        push(c);
        else
            if(isalnum(c))
            postfix[j++]=c;
            else
                if( c == ')'){
                    while( stack[top] != '(')
                        postfix[j++]=pop();
                    el=pop(); 
                }
                else{     
                    while( precedencee(stack[top]) >= precedencee(c) )
                        postfix[j++]=pop();
                    push(c);
                }
    }
    while( stack[top] != '$')     
        postfix[j++]=pop();
    postfix[j]='\0';          
    printf("\nPostfix Expression =  %s\n",postfix);
    printf("\nResult : %d\n", evaluate(postfix));
}
