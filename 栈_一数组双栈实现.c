#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 6
typedef int ElementType;
typedef struct SNode* Stack;
struct SNode{
    ElementType Data[MAXSIZE];
    int Top1;
    int Top2;
};
Stack CreateStack(Stack S);
void PushStack_1(Stack S,ElementType value);
bool IsFull(Stack S);
bool IsEmpty(Stack S);
void PushStack_2(Stack S,ElementType value);
ElementType PopStack_1(Stack S);
ElementType PopStack_2(Stack S);
int main(int argc,char const*argv[])
{
    Stack PtrS=CreateStack(PtrS);
    PushStack_1(PtrS,100);
    PushStack_1(PtrS,300);
    PushStack_1(PtrS,500);
    PushStack_1(PtrS,700);
    PushStack_2(PtrS,200);
    PushStack_2(PtrS,400);
    PushStack_2(PtrS,600);
return 0;
}


/*创建一个空栈*/
Stack CreateStack(Stack S)
{
    S=(Stack)malloc(sizeof(struct SNode));
    S->Top1=-1;
    S->Top2=MAXSIZE;
}

/*栈是否已满*/
bool IsFull(Stack S)
{
    if((S->Top2)-(S->Top1)==1){
        return true;
    }else{
        return false;
    }
}

/*栈是否为空*/
bool IsEmpty(Stack S)
{
    if(S->Top1==-1&&S->Top2==MAXSIZE){
        return true;
    }else{
        return false;
    }
}

/*进栈1操作*/
void PushStack_1(Stack S,ElementType value)
{
    if(IsFull(S)){
        printf("栈已满!\n");
        return ;
    }else{
        S->Data[++S->Top1]=value;
    }
}

/*进栈2操作*/
void PushStack_2(Stack S,ElementType value)
{
    if(IsFull(S)){
        printf("栈已满!\n");
        return ;
    }else{
        S->Data[--S->Top2]=value;
    }
}

/*出栈1操作*/
ElementType PopStack_1(Stack S)
{
    if(IsEmpty(S)){
        return 0;
    }else{
        return S->Data[S->Top1--];
    }
}

/*出栈2操作*/
ElementType PopStack_2(Stack S)
{
    if(IsEmpty(S)){
        return 0;
    }else{
        return S->Data[S->Top2++];
    }
}
