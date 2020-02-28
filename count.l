%{
int vow_count=0;
int conso_count=0;
%}

%%
[aeiouAEIOU] {vow_count++;}
[a-zA-Z] {conso_count++;}
. {printf("%s is invalid lexeme\n",yytext);}
%%
int main()
{
yylex();
printf("The number of vowels are :%d\n",vow_count);
printf("The number of vowels are :%d\n",conso_count);
}
int yywrap()
{
return 1;
}
