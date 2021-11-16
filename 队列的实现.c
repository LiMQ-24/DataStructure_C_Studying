#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 6
typedef int ElementType;
typedef struct QNode* Queue;
struct QNode{
    ElementType Data[MAXSIZE];
    int front;
    int rear;
};
Queue CreateQueue(Queue Q);
bool IsEmpty(Queue Q);
bool IsFull(Queue Q);
void AddQueue(Queue Q,ElementType value);
ElementType DeleteQueue(Queue Q);
int  main(int argc,char const*argv[])
{
    Queue PtrQ=CreateQueue(PtrQ);
    AddQueue(PtrQ,100);
    AddQueue(PtrQ,200);
    AddQueue(PtrQ,200);
    printf("%d\n",DeleteQueue(PtrQ));
    printf("%d\n",DeleteQueue(PtrQ));
    printf("%d\n",DeleteQueue(PtrQ));
    DeleteQueue(PtrQ);
}

/*创建一个空队列*/
Queue CreateQueue(Queue Q)
{
    Q=(Queue)malloc(sizeof(struct QNode));
    Q->front=-1;
    Q->rear=-1;
    return Q;
}

/*队列是否为空*/
bool IsEmpty(Queue Q)
{
    if(Q->front==Q->rear){
        return true;
    }else{
        return false;
    }
}

/*队列是否已满*/
bool IsFull(Queue Q)
{
    if(Q->rear==MAXSIZE-1){
        return true;
    }else{
        return false;
    }
}

/*入队操作*/
void AddQueue(Queue Q,ElementType value)
{
    if(IsFull(Q)){
        printf("队列已满!\n");
        return ;
    }else{
        Q->Data[++Q->rear]=value;
        return ;
    }
}

/*出队操作*/
ElementType DeleteQueue(Queue Q)
{
    if(IsEmpty(Q)){
        printf("队列已空!\n");
        return 0;
    }else{
        return Q->Data[++Q->front];
    }
}
