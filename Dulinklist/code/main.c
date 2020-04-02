#include <stdio.h>
#include <stdlib.h>
#include "duLinkedList.h"
#include <windows.h>

char check()
{
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i)
            ;
        if(i == 1){
            if('0'<=flag && flag<='6'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        printf("请输入有效数字：");
    }
    return '\0';
}

void pri()
{
	printf("\n           ||------------1 : CreateDbLinkList--------||\n");      
	printf("           ||------------2 : GetLengthDbLinkList-----||\n");
	printf("           ||------------3 : Insert------------------||\n");
	printf("           ||------------4 : DeleteList_DuL----------||\n");
	printf("           ||------------5 : DestroyList_DuL---------||\n");
	printf("           ||------------6 : TraverseList_DuL--------||\n");
	printf("           ||------------0 : exit--------------------||\n");
}

void land()
{
	int n;
	int flag = 0, length = 0;  
    int position = 0, value = 0;  
    DuLinkedList head;   
    head = InitList_DuL(head); 
    flag = IsEmptyDbLinkList(head);
    printf("\n***********************WELCOME TO USE***************************");
    pri();
    printf("(太菜只能放弃溢出检测，百度后可能要检测寄存器,学习不能好高骛远是吧(菜))\n");
	while(1)
	{
		printf("Please give the number to continue:\n");
		switch(n = check())
		{	
			case '1':
					system("cls");
					pri();
					head = CreateDbLinkList();
					break;
			case '2':
					system("cls");
					pri();
					if(head == NULL)
						printf("Please Create!\n");
					else
					{
						flag = IsEmptyDbLinkList(head);
				    	if (flag)
	       			 		printf("双向链表为空！\n");  
	    				else  
	    				{  
	       					length = GetLengthDbLinkList(head);  
	        				printf("双向链表的长度为：%d\n", length);
	    				}						
					}
    				break;
    		case '3':
    				system("cls");
					pri();
					if(head == NULL)
						printf("Please Create!\n");
					else
					{
						printf("请输入要插入节点的位置和元素值(用空格隔开)：");
						position = input_check();
						value = input_check();  
    					flag = InsertList_DuL(head, position, value);
    					if (flag)  
    					{  
        					printf("插入节点成功！\n");  
    				    	TraverseList_DuL(head);  
    					}
    					else  
        					printf("插入节点失败！请检查是否创建链表\n"); 	
					}
					break;
        	case '4':
        			system("cls");
					pri();
					if(head == NULL)
						printf("Please Create!\n");
					else
					{
	        			flag = IsEmptyDbLinkList(head);
					    if (flag)  
					        printf("链表为空!\n");  
					    else
					    {  
					        printf("请输入要删除节点的位置："); 
							position = input_check();  
					        flag = DeleteList_DuL(head, position);  
					        if (flag)  
					        {  
					            printf("删除节点成功！\n");  
					            TraverseList_DuL(head);  
					        }     
				        	else  
				            	printf("删除节点失败！\n");  
						}					
					} 
					break;  
			case '5':
					system("cls");
					pri();
					DestroyList_DuL(&head);  
    				if (head == NULL)  
        				printf("已成功删除双向链表，释放内存完成！\n");  
    				else  
        				printf("删除双向链表失败，释放内存未完成！\n");
        			break; 
        	case '6':
        			system("cls");
					pri();
					if(head == NULL)
						printf("Please Create!\n");
					else
        				TraverseList_DuL(head);
        			break;
        	case '0':
        			system("cls");
					pri();
					printf("\n*******************谢谢使用！*******************\n");
					Sleep(1500);
				    exit(0);
        	default:
              		printf("采集参数失败"); 
			
		}
	}
}

int main() 
{
	land();
    return 0;  
}
