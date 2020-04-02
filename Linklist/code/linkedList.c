#include "linkedList.h"
#include<stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
List InitList(int x) {
	List L = (List)malloc(sizeof(struct Node));
	if(L==NULL)
	{
		printf("Fail to init\n");
		exit(1);
	}
	L->data = x;
	L->next = NULL;
	printf("Successfully initialized!\n");
	return L;
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
List SearchList(List L, ElemType e) {
	List p = L->next;
	while(p!=NULL && p->data!=e)
		p = p->next;
		
	return p;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(List L) {
	List p = L->next;
	while(p!=NULL)
	{
		List temp;
		temp = p->next;
		free(p);
		p = temp;
	}
	L->next = NULL;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(ElemType x, List L){
	List temp = (List)malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		printf("Fail to init\n");
		exit(1);
	}
	temp->data = x;
	temp->next = L->next;
	L->next = temp;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
 
List findPrevious(ElemType x,List L)
{
	List p = L;
	while( p->next!=NULL && p->next->data!=x)
		p =p->next;
	if(p->next==NULL)
		return NULL;
	else
		return p;
}

Status DeleteList(List L, ElemType e) {
	List ptr = SearchList(L,e);
	List previous;
	if(ptr==NULL)
	{
		printf("%d is not existed in List\n",e);
		return error;
	}
	previous=findPrevious(e,L);
	previous->next = ptr->next;
	free(ptr);
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
Status TraverseList(List L) {
	List p = L;
	if (L == NULL){
		printf("please init\n");
	}
	while (p != NULL) {
        printf("[%d] ", p->data);
       	p = p->next;
    }
}



/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
List ReverseList(List L) {
	List p0 = NULL;
	List p1 = L;
	List p2 = L->next;
	while (p1 != NULL) {
		p1->next = p0;
		p0 = p1;
		p1 = p2;
		if (p2 != NULL) {
			p2 = p2->next;
		}
	}
	printf("success!\n");
	return p0;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(List head) {
	    if (head == NULL) {
            return error;
        }
        List n1 = head;
        List n2 = head;
        while(n2->next != NULL && n2->next->next != NULL) {
            n1 = n1->next;
            n2 = n2->next->next;
            if (n1 == n2) {
                return success;
            }
        }
        return error;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
Node* ReverseEvenList(List phead) {
   if(phead==NULL)
    {
        return NULL ;
    }
    List odd =phead;
    List evenHead=phead->next;
    List even=evenHead;
   
    while(even!=NULL && even->next!=NULL)
    {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenHead;
    printf("success!\n");
    return phead;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
int FindMidNode(List head) {
	int i=0;
	struct Node *slow_p=head, *fast_p=head;
    while(fast_p!=0 && fast_p->next!=0){
        fast_p=fast_p->next->next;
        slow_p=slow_p->next;
        i++;
    }
    return i;
}

int input_check()
{
	int v,init;
	while(1)
	{
		printf("输入有效值：");
		v = scanf("%d",&init);
		if(v==1 && init<2000000000 && -2000000000<init)
		{
			return init;
			break;			
		}
		else
		{
			printf("给出的int数字不要超过2000000000，如果你需要录入更大的数字，联系开发者：*****"); 
			while(1)
			{
				char c = getchar();
				if(c == '\n')
					break;
			}			
		}
	}
}

