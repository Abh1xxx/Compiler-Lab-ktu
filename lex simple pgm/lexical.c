#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
int isKeyword(char buffer[]){
char keywords[32][10] = {"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while"};
int i, flag = 0;
for(i = 0; i < 32; ++i){
if(strcmp(keywords[i], buffer) == 0){
flag = 1;
break;
}
}
return flag;
}
 
int main(){
char ch, buffer[15], operators[] = "+-*/%=",punctuator[]=";,{}[]()";//{';','(',')','{','}'}
FILE *fp;
int i,j=0,x;
fp = fopen("program.txt","r");
if(fp == NULL){
printf("error while opening the file\n");
exit(0);
}
while((ch = fgetc(fp)) != EOF){
   for(i = 0; i < 6; ++i){
   if(ch == operators[i])
      printf("%d  %c is operator\n",++x, ch);
   }
   for(i = 0; i < 8; ++i){
      if (ch==punctuator[i])
         printf("%d  %c is Punctuator\n",++x, ch);
   }
   
   
   if(isalnum(ch)){
   buffer[j++] = ch;
   }
   else if((ch == ' ' || ch == '\n') && (j != 0)){
   buffer[j] = '\0';
   j = 0;
     
   if(isKeyword(buffer) == 1)
   printf("%d  %s is keyword\n",++x, buffer);
   else
   printf("%d  %s is indentifier\n",++x, buffer);
   }
  
}
fclose(fp);
printf("Total No. of tokens ->%d",x);


}