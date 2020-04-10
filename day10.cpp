#include <iostream>
#include <vector>
using namespace std;

class MinStack
{
public:
	/** initialize your data structure here. */
	vector<int> data;
    vector<int> min;
	int rear;
	int size;
    int currentMin=INT_MAX;
	MinStack()
	{
		this->rear=-1;
	}

	void push(int x)
	{
        if(min.size()==0)
        {
            currentMin=INT_MAX;
        }
		this->data.push_back(x);
		rear++;
        if(currentMin>=x)
        {
            min.push_back(x);
            currentMin=x;
        }
        
	}

	void pop()
	{
        if(data.back()==currentMin)
        {        
            min.pop_back();
            if(min.size()!=0)
                currentMin=min.back();
        }
		this->data.erase(data.begin()+data.size()-1);
		rear--;
	}

	int top()
	{
		return data.back();
	}

	int getMin()
	{
		return currentMin;
	}
	void show()
	{
		cout << endl;
		for (int i = 0; i <= rear; i++)
		{
			cout << data[i] << "/";
		}
	}
};

int main()
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	minStack.pop();
	minStack.show();
	int top=minStack.top();
	int min=minStack.getMin();
	cout<<min<<endl;
	cout<<top<<endl;
	return 0;
}