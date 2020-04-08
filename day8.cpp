#include "main.h"
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <stddef.h>

ListNode *Solution::middleNode(ListNode *head)
{
	ListNode *slow=head;
	ListNode *fast=head;
	while(fast- && fast->next){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}
Solution solution;
int main()
{
	vector<int> input = {1, 1, 2, 2};
	cout << solution.countElements(input);
	return 0;
}