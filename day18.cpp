#include "main.h"
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

//First solution run but it exceeds the time limit
// int result;
// int width;
// int height;
// int travel(vector<vector<int>> &grid, int x, int y)
// {
// 	int res = 0;
// 	if (x == width - 1 && y == height - 1)
// 		return grid[y][x];
// 	if (x >= width || y >= height)
// 	{
// 		return INT_MAX;
// 	}

// 	int right = travel(grid, x + 1, y);
// 	int down = travel(grid, x, y + 1);
// 	res = std::min(right, down) + grid[y][x];
// 	result = std::min(right, down);
// 	return res;
// }
// int minPathSum(vector<vector<int>> &grid)
// {
// 	height = grid.size() != 0 ? grid.size() : 0;
// 	width = height ? grid[0].size() : 0;
// 	if (!height)
// 		return 0;
// 	return travel(grid, 0, 0);
// }

//Better solution with memoi run faster than 5.65%

// int width;
// int height;
// map<pair<int, int>, int> mp;
// int travel(vector<vector<int>> &grid, int x, int y)
// {
// 	int res = 0;
// 	if (mp[make_pair(y, x)])
// 		return mp[make_pair(y, x)];
// 	if (x == width - 1 && y == height - 1)
// 		return grid[y][x];
// 	if (x >= width || y >= height)
// 	{
// 		return INT_MAX;
// 	}
// 	res = std::min(travel(grid, x + 1, y), travel(grid, x, y + 1)) + grid[y][x];
// 	mp[make_pair(y, x)] = res;
// 	return res;
// }
// int minPathSum(vector<vector<int>> &grid)
// {
// 	height = grid.size() != 0 ? grid.size() : 0;
// 	width = height ? grid[0].size() : 0;
// 	if (!height)
// 		return 0;
// 	return travel(grid, 0, 0);
// }

//Better solution without recursion faster than 84.87% read from discussion

int Solution::minPathSum(vector<vector<int>> &grid)
{
	for (int c = 1; c < grid[0].size(); ++c)
		grid[0][c] += grid[0][c - 1];
	for (int r = 1; r < grid.size(); ++r)
		grid[r][0] += grid[r - 1][0];
	for (int r = 1; r < grid.size(); ++r)
		for (int c = 1; c < grid[0].size(); ++c)
			grid[r][c] += min(grid[r - 1][c], grid[r][c - 1]);
	return grid.back().back();
}
int main()
{
	return 0;
}