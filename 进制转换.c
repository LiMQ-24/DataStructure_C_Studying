  #include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 //存储空间分配增量
#define OVERFLOW -2 //定义返回状态值
#define OK 1  
#define ERROR 0
typedef int SElemType;
typedef int Status;
typedef struct{
    SElemType *top;
    SElemType *base;
    int stacksize;
}SqStack;

Status InitStack(SqStack* S){
    //定义一个空栈，成功返回OK，否则返回OVERFLOW
    S->base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S->base){
        return OVERFLOW;
    }
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
    return OK;
}

Status StackEmpty(SqStack S){
    //判断栈是否为空
    if(S.base==S.top){
        return OK;
    }else{
        return ERROR;
    }
}

Status Push(SqStack* S,SElemType e){
    //插入元素e为新的栈顶元素
    if(S->top-S->base>=S->stacksize){
        S->base=(SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S->base){
            return OVERFLOW;
        }
        S->top=S->base+S->stacksize;
        S->stacksize=S->stacksize+STACKINCREMENT;
    }
    *S->top++=e;
    return OK;
}

Status Pop(SqStack* S,SElemType* e){
    //若栈不空，则删除栈S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
    if(S->top==S->base){
        return ERROR;
    }
    *e=*--S->top;
    return OK;
}

int main(int argc,char const*argv[]){
    //对输入的任意一个非负的十进制整数，打印输出与其对应的等值的八进制数
    SqStack S;
    InitStack(&S);
    int N;
    printf("Input:");
    scanf("%d",&N);
    while(N){
        Push(&S,N%8);
        N=N/8;
    }
    int e;
    while(!StackEmpty(S)){
        Pop(&S,&e);
        printf("%d",e);
    }
return 0;
}
