// write a program to evaluate the infix expression,postfix expression
#include<stdio.h>
#include<string.h>
int top1=-1,top2=-1;  //they are storing top of operand and operator stack
char operator[100];
int operand[100];
void Process(){
    int x=operand[top1--];
    int y=operand[top1--];
    char op=operator[top2--];
    int z;
    switch(op){
        case '+' :
        z=y+x;
        break;
        case '-' :
        z=y-x;
        break;
        case '*' :
        z=x*y;
        break;
        case '/':
        z=y/x;
        break;
    }
    operand[++top1]=z;
}
int Precedence(char op){
    switch(op){
        case'+':
        case'-':
        return 1;
        case'*':
        case'/':
        return 2;
        default:
        return 0;
    }
}
int evalInfixExpression(char *str){
    int i;
    for(i=0;str[i]!='\0';i++){
        char ch=str[i];             //ascii value of digit is 48 to 57
        if(ch>=48 && ch<=57)
        operand[++top1]=ch-48;
    else if(ch=='+' ||ch=='-' ||ch=='*' ||ch=='/'){
        if(top2==-1)
        operator[++top2]=ch;
    else{
        while(top2!=-1 && Precedence(ch)<=Precedence(operand[top2])){
            Process();
        }
        operator[++top2]=ch;

    }
    }
    else if(ch=='('){
        operator[++top2]=ch;
    }
    else if(ch==')'){
        while(operator[top2]!='('){
            Process();
        }
        top2--;
    }
    }
    while(top2!=-1){
        Process();
    }
    return operand[top1--];
}
int evalPostfixExpression(char *str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>=48 && str[i]<=57)
        {
            operand[++top1]=str[i]-48;
        }
        else if(str[i]==' ')
        continue;
        else
        {
            int x = operand[top1--];
            int y = operand[top1--];
            int z;
            switch(str[i])
            {
                case '+' :
                z=y+x;
                break;
                case '-' :
                z=y-x;
                break;
                case '*' :
                z=x*y;
                break;
                case '/':
                z=y/x;
                break;
            }
            operand[++top1]=z;
        }
    }
    return operand[top1--];
}    
int evalPrefixExpression(char *str)
{
    int i;
    for(i=strlen(str)-1;i>=0;i--)
    {
        if(str[i]>=48 && str[i]<=57)
        {
            operand[++top1]=str[i]-48;
        }
        else if(str[i]==' ')
        continue;
        else
        {
            int x = operand[top1--];
            int y = operand[top1--];
            int z;
            switch(str[i])
            {
                case '+' :
                z=y+x;
                break;
                case '-' :
                z=y-x;
                break;
                case '*' :
                z=x*y;
                break;
                case '/':
                z=y/x;
                break;
            }
            operand[++top1]=z;
        }
    }
    return operand[top1--];
}    

int main(){
    char str[100];
    printf("Enter the infix expression:");
    gets(str);
    int result = evalInfixExpression(str);
    printf(" Result of the expression %s is %d\n",str,result);
    printf("Enter the post fix expression:");
    gets(str);
    result = evalPostfixExpression(str);
    printf(" Result of the expression %s is %d\n",str,result);
    printf("Enter the prefix expression:");
    gets(str);
    result = evalPrefixExpression(str);
    printf(" Result of the expression %s is %d\n",str,result);
}