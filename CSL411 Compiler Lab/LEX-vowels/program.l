%{
    #include<stdio.h>
    int vowels=0;
    int consonants=0;
%}
%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {consonants++;}
[\n] {printf("\nVowels: %d\nConsonants: %d\n\n",vowels,consonants); vowels=0; consonants=0;}
%%

int yywrap(){}

void main(){
    yylex();
}