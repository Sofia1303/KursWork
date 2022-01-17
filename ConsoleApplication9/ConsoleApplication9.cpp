#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
struct elements
{
	char data[20] = "";
	elements* next = NULL;
};
struct list
{
	int lenght = 0, position = 0;
	elements* pointer = NULL, * first = NULL;
	~list()
	{
		elements* ptr = 0, * PrevPtr = 0;
		ptr = first;
		while (ptr)
		{
			PrevPtr = ptr;
			ptr = ptr->next;
			free(PrevPtr);
		}
	}
	void get(int i)
	{
		int count = 0;
		elements* ptr = first;
		while (count != i && ptr)
		{
			ptr = ptr->next;
			count++;
		}
		if (count == i && ptr)
			printf("Deleted element is %s\n", ptr->data);
		else
		{
			printf("End of the list\n");
			exit(1);
		}
	}
	void change(int i)
	{
		int count = 0;
		char c[20];
		printf("Enter the data\n");
		scanf("%s", c);
		elements* ptr = first;
		while (count != i && ptr)
		{
			ptr = ptr->next;
			count++;
		}
		if (count == i && ptr)
			strcpy(ptr->data, c);
		else
		{
			printf("End of the list\n");
			exit(1);
		}
	}
	void deldata()
	{
		elements* ptr = pointer->next, * prevptr = pointer;
		prevptr->next = ptr->next;
		free(ptr);
		lenght--;
	}
	void printsentence()
	{
		elements* ptr = 0;
		/*if (!first)
		{
			printf("Tne set is empty\n");
			return;
		}*/
		ptr = first;
		while (ptr)
		{
			printf("%s ", ptr->data);
			if (ptr == pointer)
				printf("[<-] ");
			ptr = ptr->next;
		}
		printf("\n");
	}
	void pushright()
	{
		char a[20];
		scanf("%s", a);
		elements* ptr = pointer;
		if (!ptr)
		{
			ptr = (elements*)malloc(sizeof(elements));
			if (!ptr)
			{
				printf("Error\n");
				exit(1);
			}
			pointer = first = ptr;
			lenght = 1;
			position = 0;
			strcpy(ptr->data, a);
			ptr->next = 0;
			return;
		}
		elements* p = ptr->next;
		ptr->next = 0;
		ptr->next = (elements*)malloc(sizeof(elements));
		if (!ptr->next)
		{
			printf("Error\n");
			exit(1);
		}
		ptr = ptr->next;
		strcpy(ptr->data, a);
		ptr->next = p;
		lenght++;
	}
	int empty()
	{
		if (lenght == 0)
			return 0;
	}
	void firstpointer()
	{
		pointer = first;
		position = 0;
	}
	int getposition()
	{
		return position;
	}
	int getlenght()
	{
		return lenght;
	}
	void next()
	{
		if (!pointer->next)
			printf("None\n");
		else
		{
			pointer = pointer->next;
			position++;
		}
	}
	void printnext()
	{
		elements* ptr = pointer;
		ptr = ptr->next;
		int i = position + 1;
		while (ptr && i < lenght)
		{
			printf("%s ", ptr->data);
			ptr = ptr->next;
			i++;
		}
		printf("\n");
	}
	void addstr()
	{
		elements* ptr = 0;
		ptr = (elements*)malloc(sizeof(elements));
		if (!ptr)
		{
			printf("Error\n");
			exit(1);
		}
		pointer = first = ptr;
		position = lenght = 0;
		char a;
		while ((a = getchar()) != '\n')
		{
			int i = 0;
			char A[20];
			while (a != ' ' && a != '\n' && i<19)
			{
				A[i] = a;
				a = getchar();
				i++;
			}
			A[i] = '\0';
			strcpy(ptr->data, A);
			lenght++;
			if (a != '\n')
			{
				ptr->next = (elements*)malloc(sizeof(elements));
				if (!ptr->next)
				{
					printf("Error\n");
					exit(1);
				}
				ptr = ptr->next;
			}
		}
		ptr->next = NULL;
		//printsentence();
	}
};
int compare(list* ptr, list* n)
{
	elements* a = 0;
	elements* b = 0;
	a = ptr->first;
	b = n->first;
	while (a && b && !strcmp(a->data, b->data))
	{
		a = a->next;
		b = b->next;
	}
	if (!a && !b)
		return 1;
	else
		return 0;
}
int sentencemenu()
{
	int a;
	printf("1. Start\n2. Make the list empty\n3. Check the list is empty or not\n4. Pointer to the beginning\n5. Pointer at the end or not\n");
	printf("6. Forward pointer\n7. Show data after the pointer\n8. Delete data after the pointer\n9. Get data after the pointer\n");
	printf("10. Change data after the pointer\n11. Add data after the pointer\n12. Print\n13. End of the work with the list\n14. Return to the set\n");
	scanf("%d", &a);
	return (a);
}
list* sentence()
{
	list* str = 0;
start:
	int a = sentencemenu();
	while (a != 1)
	{
		if (a == 14)
		{
			if (str->first==NULL)
				return 0;
			return str;
		}
		printf("Error, you must get started first\n");
		scanf("%d", &a);
	}
	while (a)
	{
		switch (a)
		{
		case 1:
			str = (list*)malloc(sizeof(list));
			if (!str)
			{
				printf("Error\n");
				exit(1);
			}
			*str = list();
			break;
		case 2:
			str->~list();
			*str = list();
			printf("The list is cleared\n");
			break;
		case 3:
			if (!str->empty())
				printf("The list is empty\n");
			else
				printf("The list is not empty\n");
			break;
		case 4:
			if (!str->empty())
			{
				printf("The list is empty\n");
				break;
			}
			str->firstpointer();
			str->printsentence();
			break;
		case 5:
			if (!str->empty())
			{
				printf("The list is empty\n");
				break;
			}
			if (str->getposition() == str->getlenght() - 1)
				printf("The pointer is in the end of the list\n");
			else
				printf("The pointer is not in the end of the list\n");
			str->printsentence();
			break;
		case 6:
			if (!str->empty())
			{
				printf("The list is empty\n");
				break;
			}
			str->next();
			str->printsentence();
			break;
		case 7:
			if (!str->empty())
			{
				printf("The list is empty\n");
				break;
			}
			if (str->getposition() == str->getlenght() - 1)
			{
				printf("The end ot the list\n");
				break;
			}
			str->printnext();
			str->printsentence();
			break;
		case 8:
			if (!str->empty())
			{
				printf("The list is empty\n");
				break;
			}
			if (str->getposition() == str->getlenght() - 1)
			{
				printf("The end ot the list\n");
				break;
			}
			str->deldata();
			printf("The element is deleted\n");
			str->printsentence();
			break;
		case 9:
			if (!str->empty())
			{
				printf("The list is empty\n");
				break;
			}
			if (str->getposition() == str->getlenght() - 1)
			{
				printf("The end ot the list\n");
				break;
			}
			str->get(str->getposition() + 1);
			str->deldata();
			str->printsentence();
			break;
		case 10:
			if (!str->empty())
			{
				printf("The list is empty\n");
				break;
			}
			if (str->getposition() == str->getlenght() - 1)
			{
				printf("The end ot the list\n");
				break;
			}
			str->change(str->getposition() + 1);
			str->printsentence();
			break;
		case 11:
			printf("Enter the data\n");
			str->pushright();
			str->printsentence();
			break;
		case 12:
			str->printsentence();
			break;
		case 13:
			goto start;
		case 14:
			printf("You must end work with the list\n");
			break;
		default:
			printf("Error\n");
			break;
		}
		printf("\n");
		a = sentencemenu();
	}
}
struct node
{
	list* sentence = NULL;
	int load = 0;
	node* prev = NULL;
	node* next = NULL;
	void addload(int l)
	{
		if (!l)
			return;
		if (load)
		{
			printf("The element has already loaded\n");
			return;
		}
		load = l;
	}
};
struct set
{
	node* first = NULL;
	node* last = NULL;
	node* getsentence(list* i)
	{
		node* fptr = first;
		node* lptr = last;
		while (fptr && !compare(fptr->sentence, i) && lptr && !compare(lptr->sentence, i))
		{
			fptr = fptr->next;
			lptr = lptr->prev;
		}
		if (!fptr || !lptr)
			return 0;
		if (compare(fptr->sentence, i) && fptr)
			return fptr;
		if (compare(lptr->sentence, i) && lptr)
			return lptr;
	}
	~set()
	{
		node* ptr = first, * prevptr;
		while (ptr)
		{
			prevptr = ptr;
			if (ptr)
				ptr = ptr->next;
			prevptr->load = 0;
			prevptr->sentence->~list();
			free(prevptr);
		}
	}
	void delsentence(list* n)
	{
		node* fptr = 0, * prev = 0, * lptr = 0, * foll = 0, *p = 0;
		fptr = first;
		lptr = last;
		if (!fptr)
		{
			printf("The set is empty\n");
			return;
		}
		while (fptr->next && !compare(fptr->sentence, n) && lptr->prev && !compare(lptr->sentence, n))
		{
			prev = fptr;
			fptr = fptr->next;
			foll = lptr;
			lptr = lptr->prev;
		}
		if (!compare(fptr->sentence, n) && !compare(lptr->sentence, n))
		{
			printf("There is no such element\n");
			return;
		}
		if (compare(fptr->sentence, n))
		{
			if (prev)
			{
				prev->next = fptr->next;
				p = fptr->next;
				p->prev = fptr->prev;
			}
			else
			{
				first = fptr->next;
				p = fptr->next;
				if (!p)
					goto del;
				p->prev = 0;
			}
		del:
			fptr->sentence->~list();
			free(fptr);
			return;
		}
		if (compare(lptr->sentence, n))
		{
			if (foll)
			{
				foll->prev = lptr->prev;
				p = lptr->prev;
				p->next = lptr->next;
			}
			else
			{
				last = lptr->prev;
				p = lptr->prev;
				p->next = 0;
			}
			lptr->sentence->~list();
			free(lptr);
		}
	}
	void add()
	{
		list* a = sentence();
		if (!a)
			return;
		node* fptr = first, * lptr = last, * ptr;
		if (!fptr)
		{
			first = last = (node*)malloc(sizeof(node));
			first->sentence = a;
			first->next = 0;
			first->prev = 0;
			first->load = 0;
			return;
		}
		do
		{
			if (compare(fptr->sentence, a) || compare(lptr->sentence, a))
			{
				printf("This element already exists\n");
				return;
			}
			if (fptr->next)
				fptr = fptr->next;
			if (lptr->prev)
				lptr = lptr->prev;
		} while (fptr->next && lptr->prev);
		fptr->next = (node*)malloc(sizeof(node));
		if (!fptr->next)
		{
			printf("Error\n");
			exit(1);
		}
		ptr = fptr->next;
		ptr->sentence = a;
		ptr->next = 0;
		ptr->prev = fptr;
		ptr->load = 0;
		last = ptr;
	}
	void printset()
	{
		node* ptr = 0;
		ptr = first;
		while (ptr)
		{
			//printf("%s", ptr->sentence);
			ptr->sentence->printsentence();
			if (ptr->load)
				printf(" - %d\n", ptr->load);
			else
				printf("\n");
			ptr = ptr->next;
		}
	}
	long getlenght()
	{
		int lenght = 0;
		node* ptr = first;
		while (ptr)
		{
			ptr = ptr->next;
			lenght++;
		}
		return lenght;
	}
	int setempty()
	{
		if (getlenght() == 0)
			return 0;
		return 1;
	}
};
int setmenu()
{
	int a;
	printf("1. Start\n2. Make the set empty\n3. Check the set is empty or not\n4. Delete an element\n5. Get an element from the set\n");
	printf("6. Add element n to the set\n7. To load an element\n8. Print\n9. End of the work with the set\n10. End of the program\n");
	scanf("%d", &a);
	return (a);
}
void setcommand()
{
start:
	list* b = 0;
	b = (list*)malloc(sizeof(list));
	if (!b)
	{
		printf("Error\n");
		exit(1);
	}
	int l;
	node* save;
	save = (node*)malloc(sizeof(node));
	set* str = 0;
	int a = setmenu();
	while (a != 1)
	{
		if (a == 10)
			exit(1);
		printf("Error, you must get started first\n");
		scanf("%d", &a);
	}
	while (a)
	{
		switch (a)
		{
		case 1:
			str = (set*)malloc(sizeof(set));
			if (!str)
			{
				printf("Error\n");
				exit(1);
			}
			*str = set();
			break;
		case 2:
			str->~set();
			*str = set();
			printf("The set is cleared\n");
			break;
		case 3:
			if (!str->setempty())
				printf("The set is empty\n");
			else
				printf("The set is not empty\n");
			break;
		case 4:
			if (!str->setempty())
			{
				printf("The set is empty\n");
				break;
			}
			printf("What element you want to delete?\n");
			getchar();
			b->addstr();
			str->delsentence(b);
			str->printset();
			b->~list();
			*b = list();
			break;
		case 5:
			if (!str->setempty())
			{
				printf("The set is empty\n");
				break;
			}
			printf("Enter the element\n");
			getchar();
			b->addstr();
			save = str->getsentence(b);
			if (!save)
			{
				printf("There is no such an element\n");
				str->printset();
				break;
			}
			printf("Tne deleted element is\n");
			save->sentence->printsentence();
			if (save->load)
				printf(" - %d\n\n", save->load);
			else
				printf("\n\n");
			str->delsentence(save->sentence);
			str->printset();
			b->~list();
			*b = list();
			break;
		case 6:
			printf("\n");
			str->add();
			break;
		case 7:
			if (!str->setempty())
			{
				printf("The set is empty\n");
				break;
			}
			printf("What element you want to load?\n");
			getchar();
			b->addstr();
			save = str->getsentence(b);
			if (save)
			{
				printf("What load do you want to add?\n");
				scanf("%d", &l);
				save->addload(l);
			}
			else
				printf("There is no such element\n");
			str->printset();
			b->~list();
			*b = list();
			break;
		case 8:
			if (!str->setempty())
			{
				printf("The set is empty\n");
				break;
			}
			str->printset();
			break;
		case 9:
			str->~set();
			free(str);
			str = 0;
			goto start;
		case 10:
			printf("You must end work with the set\n");
			break;
		default:
			printf("Error\n");
			break;
		}
		printf("\n");
		a = setmenu();
	}
}
void main()
{
	setcommand();
}