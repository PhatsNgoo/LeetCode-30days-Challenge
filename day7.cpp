#include "main.h"
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <stddef.h>

int Solution::countElements(vector<int> &array){
	map<int,int> mp;
	int count=0;
	for(int i:array){
		mp[i]=i;
	}
	for(int i=0;i<array.size();i++){
		if(mp.find(array[i]+1)->second)
		{
			count++;
		}
	}
	return count;
}
Solution solution;
int main(){
	vector<int> input={1,1,2,2};
	cout<<solution.countElements(input);
	return 0;
}