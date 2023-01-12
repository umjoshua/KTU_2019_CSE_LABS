%{
    #include<stdio.h>
    int noOfLines=1;
    int noOfChars=0;
    int noOfWords=0;
%}
%%
[\n] {noOfLines++;}
[a-zA-Z0-9]+ {noOfWords++; noOfChars+=yyleng;}
%%
int yywrap(){}
void main(){
    FILE *input;
    input = fopen("input.txt","r");
    yyin = input;
    yylex();
    printf("\nNo. of lines: %d\n",noOfLines);
    printf("No. of words: %d\n",noOfWords);
    printf("No. of characters: %d\n",noOfChars);
}