#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
typedef int ElementType;
typedef struct LNode* List;
struct LNode{
    ElementType Data;
    List Next;
};
List CreateL(List L);
List InitL(List L);
void Ergodic(List L);
int Length(List L);
List FindKth(List L,int i);
List Find(List L,ElementType X);
void InsertL(List L,int i,ElementType X);
void DeleteL(List L,int i);
int main(int argc,char const*argv[])
{
    List PtrL=CreateL(PtrL);
    PtrL=InitL(PtrL);
    Ergodic(PtrL);
    printf("ret1=%d\n",Length(PtrL));
    printf("ret2=%d\n",FindKth(PtrL,3)->Data);
    printf("ret3=%d\n",Find(PtrL,1)->Data);
    InsertL(PtrL,1,100);
    Ergodic(PtrL);
    DeleteL(PtrL,1);
    Ergodic(PtrL);
}


//创建一个空线性表
List CreateL(List L)
{
    L=(List)malloc(sizeof(struct LNode));
    L->Next==NULL;
    L->Data=ERROR;
    return L;
}

//初始化一个空线性表
List InitL(List L)
{
    List head=NULL;
    List current=NULL;
    List prev=NULL;
    char ch='\0';
    printf("Input:");
    while(ch!='\n'){
        current=(List)malloc(sizeof(struct LNode));
        if(head==NULL){
            head=current;
        }else{
            prev->Next=current;
        }
        current->Next=NULL;
        scanf("%d",&current->Data);
        ch=getchar();
        prev=current;
    }
    L->Next=head;
    return L;
}

//遍历一个线性表
void Ergodic(List L)
{
    List current=L->Next;
    printf("Ergodic Output:\n");
    while(current!=NULL){
        printf("%d\n",current->Data);
        current=current->Next;
    }
    return ;
}

//线性表长度
int Length(List L)
{
    int cnt=0;
    List current=L->Next;
    while(current!=NULL){
        cnt++;
        current=current->Next;
    }
    return cnt;
}

//查找指定位序元素
List FindKth(List L,int i)
{
    int j=1;
    List current=L->Next;
    while(j<i&&current!=NULL){
        j++;
        current=current->Next;
    }
    if(j==i){
        return current;
    }else{
        return NULL;
    }
}

//查找指定元素第一次出现的位序
List Find(List L,ElementType X)
{
    List current=L->Next;
    while(current->Data!=X&&current!=NULL){
        current=current->Next;
    }
    if(current->Data==X){
        return current;
    }else{
        return NULL;
    }
}

//在指定位序插入指定元素
void InsertL(List L,int i,ElementType X)
{
    if(i==1){
        List s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=L->Next;
        L->Next=s;
        return ;
    }else{
        List current=Find(L,i-1);
        List s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=current->Next;
        current->Next=s;
        return ;
    }
}

//删除指定位序的元素
void DeleteL(List L,int i)
{
    if(i==1){
        List current=L->Next;
        L->Next=L->Next->Next;
        free(current);
        return ;
    }else{
        List current=FindKth(L,i-1);
        List now=current->Next;
        current->Next=current->Next->Next;
        free(now);
        return ;
    }
}
