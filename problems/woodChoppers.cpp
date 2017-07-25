/*
Little Susie listens to fairy tales before bed every day. Today's fairy tale was about wood cutters and the little girl immediately started imagining the choppers cutting wood. She imagined the situation that is described below.

There are n trees located along the road at points with coordinates x1, x2, ..., xn. Each tree has its height hi. Woodcutters can cut down a tree and fell it to the left or to the right. After that it occupies one of the segments [xi - hi, xi] or [xi;xi + hi]. The tree that is not cut down occupies a single point with coordinate xi. Woodcutters can fell a tree if the segment to be occupied by the fallen tree doesn't contain any occupied point. The woodcutters want to process as many trees as possible, so Susie wonders, what is the maximum number of trees to fell.
Input

The first line contains integer n (1 ≤ n ≤ 105) — the number of trees.

Next n lines contain pairs of integers xi, hi (1 ≤ xi, hi ≤ 109) — the coordinate and the height of the і-th tree.

The pairs are given in the order of ascending xi. No two trees are located at the point with the same coordinate.
Output

Print a single number — the maximum number of trees that you can cut down by the given rules.
Examples
Input

5
1 2
2 1
5 10
10 9
19 1

Output

3

Input

5
1 2
2 1
5 10
10 9
20 1

Output

4

Note

In the first sample you can fell the trees like that:

    fell the 1-st tree to the left — now it occupies segment [ - 1;1]
    fell the 2-nd tree to the right — now it occupies segment [2;3]
    leave the 3-rd tree — it occupies point 5
    leave the 4-th tree — it occupies point 10
    fell the 5-th tree to the right — now it occupies segment [19;20] 

In the second sample you can also fell 4-th tree to the right, after that it will occupy segment [10;19].
*/

/* Reasoning: Best solution for i, where i<n. Left(i), Right(i), Stay(i).The current solution depends
on solution of previous two points.
*/ 
#include<iostream>
#include<vector>

using namespace std;

vector<long long> _left;
std::vector<long long> _right;
std::vector<long long> _stay;

std::vector<long long> _position;
std::vector<long long> _height;
std::vector<long long> _solution;

long long size=0;

long long compare(long long a, long long b, long long c)
{
	if(a>b)
	{
		if(a>c)
		{
			return a;
		}
		else
		{
			return c;
		}
	}
	else
	{
		if (b>c)
		{
			return b;
		}
		else
			return c;
	}
}

long long compare(long long a, long long b)
{
	if (a>b)
	{
		return a;		
	}
	else
		return b;
}

void solve(long long i)
{
	//long long l,r,st;
	if(i==1)
	{
		_left[i] = 1;
		_right[i] = 1;
		_stay[i] = 0;
		_solution[i] = 1;
	//	cout<<"i:"<<i<<" left:"<<_left[i]<<" right:"<<_right[i]<<" stay:"<<_stay[i]<<" solution:"<<_solution[i]<<endl;
		return;
	}

	if(_height[i]+_height[i-1]<_position[i]-_position[i-1])
	{
		_left[i] = _right[i-1] + 1;		
	}
	else if(_height[i] < _position[i]-_position[i-1])
	{
		_left[i] = compare(_left[i-1],_stay[i-1])+1;
	}
	else
		_left[i]=0;

	if(_height[i-1] < _position[i]-_position[i-1])
	{
		_stay[i] = _solution[i-1];
		_right[i] = _solution[i-1] + 1;
	}
	else
	{
		_stay[i] = compare(_left[i-1],_stay[i-1]);
		_right[i] = compare(_left[i-1],_stay[i-1])+1;
	}
	long long sol = compare(_left[i],_right[i],_stay[i]);
	//cout<<"i:"<<i<<" left:"<<_left[i]<<" right:"<<_right[i]<<" stay:"<<_stay[i]<<" solution:"<<sol<<endl;
	_solution[i]=sol;
}

int main(int argc, char const *argv[])
{
	cin>>size;
	_left.resize(size+1);
	_right.resize(size+1);
	_stay.resize(size+1);
	_position.resize(size+1);
	_height.resize(size+1);
	_solution.resize(size+1);

	_left[0]=_right[0]=_stay[0]=_position[0]=_height[0]=0;
	//cout<<"starting input"<<endl;
	for(long long i=1;i<=size;i++)
	{
		cin>>_position[i]>>_height[i];
		solve(i);	
	}

	cout<<_solution[size];

	return 0;
}