
#include<stdio.h>
#include<ctype.h>
#include<string.h>
char keyword[30][30]={"int","while","break","for","do","if","float","char","switch","double","short","long","unsigned","sizeof","else","register","extern","static","auto","case","break","volatile","enum","typedef"};
char id[20], num[10];
int check_keyword(char s[])
        {
        int i;
        for(i=0;i<24;i++)
        	if(strcmp(s,keyword[i])==0)
                return 1;
        return 0;
        }
int main()
 {
    FILE *fp1,*fp2;
    char c;
    int state=0;
    int i=0,j=0;
    fp1=fopen("x.txt","r");
    fp2=fopen("y.txt","w");
    while((c=fgetc(fp1))!=EOF)
    {
        switch(state)
        {
            case 0: if(isalpha(c)||c=='_'){
                        state=1; id[i++]=c;}
                    else if(isdigit(c)){
                            state=3; num[j++]=c;}
                         else if(c=='<' || c=='>')
                                 state=5;
                              else if(c=='=' || c=='!')
                                      state=8;
                                    else if(c=='/')
                                            state=10;
                                         else if(c==' ' || c=='\t' || c=='\n')
                                                state=0;
                                              else
                                                    fprintf(fp2,"\n%c",c);
                   break;
            case 1:if(isalnum(c)){
                    state=1; id[i++]=c;
                   }
                   else{
                        id[i]='\0';
                        if(check_keyword(id))
                            fprintf(fp2," \n %s : keyword ",id);
                        else
                            fprintf(fp2,"\n %s : identifier",id);
                        state=0;
                        i=0;
                        ungetc(c,fp1);
                   }
              break;
           case 3:if(isdigit(c)){
                    num[j++]=c;
                    state=3;
                  }
                  else{
                    num[j]='\0';
                    fprintf(fp2," \n%s: number",num);
                    state=0;
                    j=0;
                    ungetc(c,fp1);
               }
               break;
          case 5:if(c=='='){
                    fprintf(fp2,"\n  relational operator ");
                    state=0;
                }
                else{
                    fprintf(fp2,"\n  relational operator ");
                    state=0;
                    ungetc(c,fp1);
                }
                break;
          case 8:if(c=='='){
                    fprintf(fp2,"\n relational operator ");
                    state=0;
                }
                else{
                    //fprintf(fp1,"=");//----
                    ungetc(c,fp1);
                    state=0;
                }
                break;
          case 10:if(c=='*')
                    state=11;
                else
                    fprintf(fp2,"\n invalid lexeme");
                break;
          case 11:if(c!='*')
                    state=11;
                else
                    state=12;
                break;
          case 12:if(c=='*')
                    state=12;
                  else if(c=='/')
                        state=0;
                       else
                        state=11;
                  break;
        //End of switch
       //end of while
int i=0,j=0,x=0,n;
 void *fp2,*add[5];
 char ch,srch,b[15],d[15],c;
 while((c=getchar())!='$')
 {
  b[i]=c;
  i++;
 }
 n=i-1;
 i=0;
 while(i<=n)
 {
  printf("%c",b[i]);
  i++;
 }
 printf("\n Symbol Table\n");
 printf("Symbol \t addr \t type");
 while(j<=n)
 {
  c=b[j];
  if(isalpha(toascii(c)))
  {

   add[x]=fp2;
   d[x]=c;
   printf("\n%c \t %d \t identifier\n",c,fp2);
   x++;
   j++;
  }
  else
  {
   ch=c;
   if(ch=='+'||ch=='-'||ch=='*'||ch=='=')
   {
    fp2=malloc(ch);
    add[x]=fp2;
    d[x]=ch;
    printf("\n %c \t %d \t operator\n",ch,fp2);
    x++;
    j++;
   }}}}

       fclose(fp1);
       fclose(fp2);
  return 0;
}}
