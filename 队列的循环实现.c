#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 6
#define ERROR 0
typedef int ElementType;
typedef struct QNode* Queue;
struct QNode{
    int Data[MAXSIZE];
    int Front;
    int Rear;
};
Queue CreateQueue(Queue Q);
bool IsEmpty(Queue Q);
bool IsFull(Queue Q);
void AddQ(Queue Q,ElementType value);
ElementType DeleteQ(Queue Q);
int main(int argc,char const*argv[])
{
    Queue PtrQ=CreateQueue(PtrQ);
    AddQ(PtrQ,100);
    AddQ(PtrQ,200);
    AddQ(PtrQ,300);
    AddQ(PtrQ,400);
    AddQ(PtrQ,500);
    AddQ(PtrQ,600);
    AddQ(PtrQ,700);
    DeleteQ(PtrQ);
    AddQ(PtrQ,800);
    printf("ret1=%d\n",DeleteQ(PtrQ));
}

//创建一个空链表
Queue CreateQueue(Queue Q)
{
    Q=(Queue)malloc(sizeof(struct QNode));
    Q->Front=-1;
    Q->Rear=-1;
    return Q;
}

//判断队列是否为空
bool IsEmpty(Queue Q)
{
    if(Q->Front==Q->Rear){
        return true;
    }else{
        return false;
    }
}

//判断队列是否已满
bool IsFull(Queue Q)
{
    if((Q->Rear+1)%MAXSIZE==Q->Front){
        return true;
    }else{
        return false;
    }
}

//入队操作
void AddQ(Queue Q,ElementType value)
{
    if(IsFull(Q)){
        printf("队列已满!\n");
        return ;
    }else{
        Q->Data[(++Q->Rear)%MAXSIZE]=value;
        return ;
    }
}

//出队操作
ElementType DeleteQ(Queue Q)
{
    if(IsEmpty(Q)){
        return ERROR;
    }else{
        return Q->Data[(++Q->Front)%MAXSIZE];
    }
}
