typedef struct BinNode{
    ElemType data;
    BinNode *lchild;
    BinNode *rchild;
}BinNode,*BinTree;

// 将结点插入T1
void Insert(BinTree *T,int key)
{
    if(!(*T))
    {
        (*T) = (BinTree)malloc(sizeof(BinNode));
        (*T)->data = key;
        (*T)->lchild = (*T)->rchild = NULL;
        return OK;
    }
    if(key == (*T)->data )
        return OK;
    if(key > (*T)->data )
        Insert( &((*T)->rchild), key );
    else
        Insert( &((*T)->lchild), key );
}

//将T2并入T1
void InsertBST(BinTree T1,BinTree T2)
{
    if(T2)
    {
        InsertBST(T1,T2->lchild);
        Insert(&T1,T2->data);
        InsertBST(T1,T2->rchild);
    }
}
