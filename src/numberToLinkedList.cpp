/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>
int power1(int, int);

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	struct node *n = NULL, *head = NULL, *last = NULL; int number, i = 0, digits = 0,number1;
	if (N == 0)
	{
		n = (struct node *)malloc(sizeof(n));
		n->num = 0;
		n->next = NULL;
		head = n; last = n;
	}
	else
	{
		if (N > 0)
		{
			number = N;
			number1 = N;
		}
		else if (N < 0)
		{
			number = -N;
			number1 = -N;
		}
		while (number>0)
		{
			number /= 10;
			digits++;
		}
		number = number1;
		while (digits > 0)
		{
			if (i == 0){
				n = (struct node *)malloc(sizeof(n));
				n->num = (number / power1(1, digits - 1)) % 10;
				n->next = NULL;
				head = n;
				last = n;


				digits--;
			}
			else
			{
				n = (struct node *)malloc(sizeof(n));
				n->num = (number / power1(1, digits - 1)) % 10; n->next = NULL;
				last->next = n;
				last = n;

				digits--;
			}
			i++;
		}
	}
	return head;
}
int power1(int a, int digits)
{
	while (digits >0)
	{
		a = a * 10;
		digits--;
	}
	return a;
}