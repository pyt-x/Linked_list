#include <stdio.h>
#include <stdlib.h>
#include "../head/duLinkedList.h"
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
        printf("��������Ч���֣�");
    }
    return '\0';
}

void pri()
{
	printf("\n***********************WELCOME TO USE***********************");
	printf("\n                |------------1 : CreateDbLinkList--------|\n");      
	printf("                |------------2 : GetLengthDbLinkList-----|\n");
	printf("                |------------3 : Insert------------------|\n");
	printf("                |------------4 : DeleteList_DuL----------|\n");
	printf("                |------------5 : DestroyList_DuL---------|\n");
	printf("                |------------6 : TraverseList_DuL--------|\n");
	printf("                |------------0 : exit--------------------|\n");
}

void land()
{
	int n;
	int flag = 0, length = 0;  
    int position = 0, value = 0;  
    DuLinkedList head;   
    head = InitList_DuL(head); 
    flag = IsEmptyDbLinkList(head);
	while(1)
	{
		pri();
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
			    	if (flag)
       			 		printf("˫������Ϊ�գ�\n");  
    				else  
    				{  
       					length = GetLengthDbLinkList(head);  
        				printf("˫�������ĳ���Ϊ��%d\n", length);
    				}
    				break;
    		case '3':
    				system("cls");
					pri();
    				printf("������Ҫ����ڵ��λ�ú�Ԫ��ֵ(�ÿո����)��");  
    				scanf("%d %d", &position, &value);  
    				flag = InsertList_DuL(head, position, value);
    				if (flag)  
    				{  
        				printf("����ڵ�ɹ���\n");  
    				    TraverseList_DuL(head);  
    				}
    				else  
        				printf("����ڵ�ʧ�ܣ������Ƿ񴴽�����\n");
					break; 
        	case '4':
        			system("cls");
					pri();
        			flag = IsEmptyDbLinkList(head);  
				    if (flag)  
				        printf("����Ϊ��!\n");  
				    else
				    {  
				        printf("������Ҫɾ���ڵ��λ�ã�");  
				        scanf("%d", &position);  
				        flag = DeleteList_DuL(head, position);  
				        if (flag)  
				        {  
				            printf("ɾ���ڵ�ɹ���\n");  
				            TraverseList_DuL(head);  
				        }     
			        	else  
			            	printf("ɾ���ڵ�ʧ�ܣ�\n");  
					} 
					break;  
			case '5':
					system("cls");
					pri();
					DestroyList_DuL(head);  
    				if (NULL == head)  
        				printf("�ѳɹ�ɾ��˫���������ͷ��ڴ���ɣ�\n");  
    				else  
        				printf("ɾ��˫������ʧ�ܣ��ͷ��ڴ�δ��ɣ�\n");
        			break; 
        	case '6':
        			system("cls");
					pri();
        			TraverseList_DuL(head);
        			break;
        	case '0':
        			system("cls");
					pri();
					printf("\n*******************ллʹ�ã�*******************\n");
					Sleep(1500);
				    exit(0);
        	default:
              		printf("�ɼ�����ʧ��"); 
			
		}
	}
}

int main() 
{
	land();
    return 0;  
}