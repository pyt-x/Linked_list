#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>


char check()
{
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i)
            ;
        if(i == 1){
            if('0'<=flag && flag<='9'){
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
	printf("\n***********************WELCOME TO USE***********************");
	printf("\n                |-------1 : IsLoopList-----|\n");      
	printf("                |-------2 : insert---------|\n");
	printf("                |-------3 : SearchList-----|\n");
	printf("                |-------4 : DeleteList-----|\n");
	printf("                |-------5 : DestroyList----|\n");
	printf("                |-------6 : TraverseList---|\n");
	printf("                |-------7 : FindMidNode----|\n");
	printf("                |-------8 : ReverseList----|\n");
	printf("                |-------9 : ReverseEvenList|\n");
	printf("                |-------0 : exit-----------|\n");
}

void land()
{
	int n=1,x,v,i,init,v_insert;
	List res,list;
	pri();
	while(1)
	{
		printf("please give a (int)number to init\n");
		v = scanf("%d",&init);
		if(v==1)
		{
			list = InitList(init);
			break;			
		}

		else
		{
			while(1)
			{
				char c = getchar();
				if(c == '\n')
					break;
			}			
		}
	}

	while(1)
	{
		printf("Please give the number to continue:\n");
		switch(n = check())
		{	case '9':
					system("cls");
					pri();
					ReverseEvenList(list);
					break;
			case '1':
					system("cls");
					pri();	
					IsLoopList(list) == 0 ? printf("no\n") : printf("yes\n");
					break;
					
			case '2':
					system("cls");
					pri();
					x = input_check();
					InsertList(x,list);
					break;
			case '3':
					system("cls");
					pri();
					printf("find element：");
					x = input_check();
					res = SearchList(list,x);
					if(res !=NULL)
						printf("Here you wanna get:%d\n",res->data);
					else
						printf("查无此数");
					break;
					
			case '4':
					system("cls");
					pri();
					printf("Input the element what you wnana delete");
					x = input_check();
					DeleteList(list,x);
					break;
			case '5':
					system("cls");
					pri();
					DestroyList(list);
					break;
			case '6':
					system("cls");
					pri();
					TraverseList(list);
					break;
			case '7':
					system("cls");
					pri();
				    i=FindMidNode(list);
				    printf("第%d个\n",i);
				    break;
			case '8':
					system("cls");
					pri();
					list = ReverseList(list);
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
