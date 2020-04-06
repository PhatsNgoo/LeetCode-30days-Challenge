#include "main.h"
#include <iostream>
#include <map>
#include <string>
#include <sstream>
string sortString(string s)
{
	int temp;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			if (s[i] > s[j])
			{
				temp=s[j];
				s[j]=s[i];
				s[i]=temp;
			}
		}
	}
	return s;
}
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
	map<string,vector<string>>map;
	for(string s:strs){
		map[sortString(s)].push_back(s);
	}
	vector<vector<string>>result;
	for(auto p:map){
		result.push_back(p.second);
	}
	return result;
}
int main()
{
	vector<string> vtrString = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> result = groupAnagrams(vtrString);
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i].size() > 1)
		{
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << "/";
			}
			cout << endl;
		}
	}
	// string test="gsdfgsdfgasd";
	// string result=sortString(test);
	// cout<<result;
	// string first="converter";
	// string second="contrived";
	// if(compareTwoAnagram(first,second)){
	// 	cout<<"true";
	// }

	return 0;
}