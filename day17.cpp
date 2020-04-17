#include "main.h"
#include <vector>
#include <map>
using namespace std;

map<pair<int,int>,int> mp;
int count;
void eraseIsland(vector<vector<char>>& grid,int x,int y)
{
	int height=grid.size();
	int width=grid[0].size();
	if(x<0|| y<0|| x==width || y==height ||grid[y][x]=='0')
	{
		return;
	}
	grid[y][x]='0';
	eraseIsland(grid,x+1,y);
	eraseIsland(grid,x-1,y);
	eraseIsland(grid,x,y+1);
	eraseIsland(grid,x,y-1);
}
int Solution::numIslands(vector<vector<char>>& grid)
{
	int countIsland=0;
	int height=grid.size()!=0?grid.size():0;
	int width=grid[0].size()!=0?grid[0].size():0;
	for(int i=0;i<height;i++)
	{
		for (int j = 0; j < width; j++)
		{
			/* code */
			if(grid[i][j]=='1')
			{
				countIsland++;
				eraseIsland(grid,j,i);
			}
		}
		
	}
	return countIsland;
}

int main()
{

}