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

BiTree creat_bt(){ //按扩展前序建二叉树；
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


//判断二叉树是否相等的函数

bool isEqual(BiTree T1,BiTree T2)
{
    if(T1 == NULL && T2 == NULL)
        return true;//都为空，相等。
    if(!T1||!T2)    //由于上面的判断不成立，则T1，T2至少有一个不为空
        return false;//一个空，一个不空，不相等
   // if(T1->data == T2->data) //如果根节点相等
    if(T1 == NULL && T2 != NULL || T1 != NULL && T2 == NULL)
        return isEqual(T1->lchild,T2->lchild) && isEqual(T1->rchild,T2->rchild);//判断左右子树是否都相等
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
    printf("正在创建第一棵树：\n");
    BiTree b1 = creat_bt();
    printf("正在创建第二棵树：\n");
    BiTree b2 = creat_bt();
    //if(judge_similar(b1, b2))
    if(isEqual(b1,b2))
        printf("两个二叉树是相似的！\n");
    else 
        printf("两个二叉树不是相似的！\n");
        
    return 0;
}
