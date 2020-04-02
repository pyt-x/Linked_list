#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
DuLinkedList InitList_DuL(DuLinkedList L) {
	DuLinkedList node = (struct DuLNode *) malloc(sizeof(struct DuLNode));
    node->data = 0;
    node->pre = NULL;
    node->next = NULL;
    return node;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList pt = NULL;
	while (*L != NULL)
	{
		pt = (*L)->next;
		free(*L);
		if (NULL != pt)
			pt->pre = NULL;
		*L = pt;
	}
}

int GetLengthDbLinkList(DuLinkedList L)  
{  
    int length = 0;  
    DuLinkedList pt = L->next;  
  
    while (pt != NULL)  
    {  
        length++;
        pt = pt->next;  
    }  
    return length;  
}  
/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
 
int IsEmptyDbLinkList(DuLinkedList L)  
{  
    DuLinkedList pt = L->next;  
    if (pt == NULL)  
        return 1;  
    else  
        return 0;  
}  
 
int InsertList_DuL(DuLinkedList L, int pos, int data) {
	DuLinkedList pt = NULL, p_new = NULL;
    if (pos > 0 && pos < GetLengthDbLinkList(L)+1)  
    {  
        p_new = (DuLinkedList)malloc(sizeof(struct DuLNode));  
        if (NULL == p_new)  
        {  
            printf("内存分配失败！\n");  
            exit(1);  
        }
        while (1)  
        {  
            pos--;  
            if (0 == pos)  
                break;  
            L = L->next;
        }
        pt = L->next;  
        p_new->data = data;  
        p_new->next = pt;  
        if (NULL != pt) 
            pt->pre = p_new;  
        p_new->pre = L;  
        L->next = p_new;
        return 1;  
    }
    else  
        return 0;  
}

DuLinkedList CreateDbLinkList(void)  
{  
    int i, length = 0,v=0;
	int data =0;  
    DuLinkedList pTail = NULL, p_new = NULL;  
    DuLinkedList pHead = (DuLinkedList)malloc(sizeof(DuLNode));  
  
    if (NULL == pHead)  
    {  
        printf("内存分配失败！\n");  
        exit(1);  
    }  
      
    pHead->data = 0;  
    pHead->pre = NULL;  
    pHead->next = NULL;  
    pTail = pHead;  
  
    printf("请输入想要创建链表的长度：");
	while(1)
	{
	   	v = scanf("%d", &length);
		if(v==1)
			break;
		else
		{
			printf("Please give a valid number");
			break;
		}	
	}
			
    for (i=1; i<length+1; i++)  
    {  
        p_new = (DuLinkedList)malloc(sizeof(DuLNode));  
  
        if (NULL == p_new)  
        {  
            printf("内存分配失败！\n");  
            exit(1);  
        }
        
  		while(1)
  		{
  			printf("请输入第%d个元素的值:", i);
  			v = scanf("%d", &data);
  			if(v==1)
  			{
  			  	p_new->data = data;  
        		p_new->next = NULL;  
        		p_new->pre = pTail;  
        		pTail->next = p_new;  
        		pTail = p_new;
  				break;	
			}
  			else
  			{	
  				printf("哼哼，老夫掐指一算你输入的不是整数是吧！\n");
				while(1)
				{
					char c = getchar();
					if(c == '\n')
						break;
				}
			}
		}
    }
    return pHead; 
}
/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 
 
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	
}

 
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLinkedList L, int pos) {
	DuLinkedList pt = NULL;
    if (pos > 0 && pos < GetLengthDbLinkList(L) + 1)  
    {  
        while (1)  
        {  
            pos--;  
            if (0 == pos)  
                break;  
            L = L->next;  
        }
        pt = L->next->next;  
        free(L->next);  
        L->next = pt;  
        if (NULL != pt)  
            pt->pre = L;
        return SUCCESS;
    }
    else  
        return ERROR; 
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L) {
	DuLinkedList pt = L->next;
	if(pt != NULL)
	{
	    while (pt != NULL)  
	    {  
	        printf("%d ", pt->data);  
	        pt = pt->next;  
	    }
	    putchar('\n');	
	}
	else
		printf("空\n");
}
