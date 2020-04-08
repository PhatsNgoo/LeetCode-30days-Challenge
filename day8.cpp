#include "main.h"
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <stddef.h>

ListNode *Solution::middleNode(ListNode *head)
{
	ListNode *node=new ListNode(0);
	int listCount=0;
	node->next=head;
	while (node->next!=NULL)
	{
		/* code */
		listCount++;
		node=node->next;
	}
	int count;
	node->next=head;
	while (count<listCount/2)
	{
		/* code */
		listCount++;
		node=node->next;
	}
	return node->next;
}
Solution solution;
int main()
{
	vector<int> input = {1, 1, 2, 2};
	cout << solution.countElements(input);
	return 0;
}