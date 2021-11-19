#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 6
#define ERROR -1  //不合法
typedef int ElementType;   //暂定所存储元素为int型
typedef struct LNode* List;
struct LNode{
    ElementType Data[MAXSIZE];
    int Last;
};
List CreateList(List L);    //创建一个空线性表
List InitList(List L);      //初始化一个空线性表
void Ergodic(List L);       //遍历一个线性表
bool IsEmpty(List L);       //线性表是否为空（无实际意义）
bool IsFull(List L);        //线性表是否已满 (无实际意义）
void InsertL(List L,int i,ElementType value);     //在指定位序插入元素
void DeleteL(List L,int i);                       //删除指定位序的元素
ElementType FindKth(List L,int i);                //查找指定位序的元素
int Find(List L,ElementType X);                   //查找指定元素第一次出现的位置
int main(int argc,char const*argv[])              
{
    List PtrL=CreateList(PtrL);
    PtrL=InitList(PtrL);
    Ergodic(PtrL);
    InsertL(PtrL,1,100);
    Ergodic(PtrL);
    DeleteL(PtrL,3);
    Ergodic(PtrL);
    printf("ret1=%d\n",FindKth(PtrL,5));
    printf("ret2=%d\n",Find(PtrL,2));
}


//创建一个空线性表
List CreateList(List L)
{
    L=(List)malloc(sizeof(struct LNode));
    L->Last=-1;
    return L;
};

//初始化一个线性表
List InitList(List L)
{
    int i=0;
    while(i<MAXSIZE-3){
        L->Data[i]=i;
        i++;
        L->Last++;
    }
}

//遍历一个线性表
void Ergodic(List L)
{
    int i=0;
    while(i<=L->Last){
        printf("%d\n",L->Data[i]);
        i++;
    }
    printf("#\n");
    return ;
}

//线性表是否为空
bool IsEmpty(List L)
{
    if(L->Last==-1){
        return true;
    }else{
        return false;
    }
}

//线性表是否已满
bool IsFull(List L)
{
    if(L->Last==MAXSIZE-1){
        return true;
    }else{
        return false;
    }
}

//线性表元素指定位序插入
void InsertL(List L,int i,ElementType value)
{
    if(IsFull(L)){
        return ;
    }else{
        int j;
        for(j=L->Last;j>=i-1;j--){
            L->Data[j+1]=L->Data[j];
        }
        L->Data[i-1]=value;
        L->Last++;
        return ;
    }
}

//线性表元素指定位序删除
void DeleteL(List L,int i)
{
    if(IsEmpty(L)){
        return ;
    }else{
        int j;
        for(j=i-1;j<L->Last;j++){
            L->Data[j]=L->Data[j+1];
        }
        L->Last--;
        return ;
    }
}

//查找指定位序元素
ElementType FindKth(List L,int i)
{
    int j=0;
    while(j<i-1&&j<L->Last){
        j++;
    }
    if(j==i-1){
        return L->Data[j];
    }else{
        return ERROR;
    }
}

//查找指定元素第一次出现的位置
int Find(List L,ElementType X)
{
    int j=0;
    while(j<=L->Last&&L->Data[j]!=X){
        j++;
    }
    if(L->Data[j]==X){
        return j+1;
    }else{
        return ERROR;
    }
}
