/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>
long int power(int, int);
struct node {
	int digit1;
	int digit2;
	struct node *next;
};

int convert_sll_2digit_to_int(struct node *head){
	if (head == NULL)
		return NULL;
	else
	{
		int digits = 0;long int sum = 0;
		struct node *temp = head;
		while (temp != NULL)
		{
			digits+=2;
			temp = temp->next;
		}
		while (digits > 0)
		{
			sum = sum +( head->digit1*power(1, digits-1)+head->digit2*power(1,digits-2));
			digits -= 2;
			head = head->next;
		}
		return sum;
	}
}
long int power(int a, int digits)
{
	while (digits >0)
	{
		a = a * 10;
		digits--;
	}
	return a;
}