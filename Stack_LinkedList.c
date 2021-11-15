/*
stack CreateStack(Stack S)   创建一个空栈
bool IsEmpty(Stack S)    栈是否为空
void PushStack(Stack S,int value)   进栈操作
ElementType PopStack(Stack S)   出栈操作
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"5_main.c"
typedef int ElementType;
typedef struct SNode* Stack;
/*
typedef int ElementType;
typedef struct SNode* Stack;
struct SNode{
    ElementType Data;
    Stack Next;
};
*/
Stack CreateStack(Stack S);
void PushStack(Stack S,ElementType value);
bool IsEmpty(Stack S);
ElementType PopStack(Stack S);
int main(int argc,char const*argv[])
{
    Stack PtrS=CreateStack(PtrS);
    PushStack(PtrS,100);
    PushStack(PtrS,200);
    printf("%d\n",PtrS->Next->Data);
    printf("ret1=%d\n",PopStack(PtrS));
    printf("ret2=%d\n",PopStack(PtrS));
    printf("ret3=%d\n",PopStack(PtrS));
return 0;
}
