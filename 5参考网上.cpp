#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int status;

typedef char elemtype;

typedef struct BiTNode {
    elemtype data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree creat_bt(){ //����չǰ�򽨶�������
    BiTree t;   elemtype x;
    scanf(" %c",&x);
    if (x=='#') t=NULL;
    else 
    { t=(BiTree)malloc(sizeof(BiTNode));
        t->data=x;
        t->lchild=creat_bt();
        t->rchild=creat_bt();
    }
    return t;
}


//�ж϶������Ƿ���ȵĺ���

bool isEqual(BiTree T1,BiTree T2)
{
    if(T1 == NULL && T2 == NULL)
        return true;//��Ϊ�գ���ȡ�
    if(!T1||!T2)    //����������жϲ���������T1��T2������һ����Ϊ��
        return false;//һ���գ�һ�����գ������
   // if(T1->data == T2->data) //������ڵ����
    if(T1 == NULL && T2 != NULL || T1 != NULL && T2 == NULL)
        return isEqual(T1->lchild,T2->lchild) && isEqual(T1->rchild,T2->rchild);//�ж����������Ƿ����
    else 
        return false;
}
/*status judge_similar(BiTree b1, BiTree b2)
{
    if(b1 == NULL && b2 == NULL)
        return true;
    else if(b1 == NULL && b2 != NULL || b1 != NULL && b2 == NULL)
    //if(!b1|| !b2)
        return false;
    else
    {
        if(judge_similar(b1->lchild, b2->lchild) && judge_similar(b1->rchild, b2->rchild))
            return true;
        else 
            return false;
    }
}*/

int main()
{
    printf("���ڴ�����һ������\n");
    BiTree b1 = creat_bt();
    printf("���ڴ����ڶ�������\n");
    BiTree b2 = creat_bt();
    //if(judge_similar(b1, b2))
    if(isEqual(b1,b2))
        printf("���������������Ƶģ�\n");
    else 
        printf("�����������������Ƶģ�\n");
        
    return 0;
}
