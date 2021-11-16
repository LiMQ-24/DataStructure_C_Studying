#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 100
typedef int ElementType;
typedef struct SNode* Stack;
struct SNode{
    ElementType Data[MAXSIZE];
    int Top;
};

Stack CreateStack(Stack S);
bool IsFull(Stack S);
bool IsEmpty(Stack S);
void PushStack(Stack S,ElementType value);
ElementType PopStack(Stack S);
int main(int argc,char const*argv[])
{
    Stack PtrS=CreateStack(PtrS);
    PushStack(PtrS,200);
    PushStack(PtrS,1000);
    PopStack(PtrS);
    PopStack(PtrS);
    PopStack(PtrS);
return 0;
}


//初始化一个空栈
Stack CreateStack(Stack S)
{
    S=(Stack)malloc(sizeof(struct SNode));
    S->Top=-1;
    return S;
}

//判断栈是否已满
bool IsFull(Stack S)
{
    if(S->Top==MAXSIZE-1){
        return true;
    }else{
        return false;
    }
}

//判断栈是否为空
bool IsEmpty(Stack S)
{
    if(S->Top==-1){
        return true;
    }else{
        return false;
    }
}

//进栈操作
void PushStack(Stack S,ElementType value)
{
    if(IsFull(S)){
        printf("栈已满!\n");
        return ;
    }else{
        S->Data[++(S->Top)]=value;
        return ;
    }
}

//出栈操作
ElementType PopStack(Stack S)
{
    if(IsEmpty(S)){
        printf("栈已空!\n");
    }else{
        return S->Data[S->Top--];
    }
}
