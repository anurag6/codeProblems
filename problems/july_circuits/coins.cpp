#include<iostream>
#include<string>
using namespace std;

int alpha[26];
int distinct=0;
string sequence;
int K;

int findCombos()
{
	int left=0,right=0,count=0;
	alpha[sequence[0]-'a']++;
	distinct++;
	while(left<sequence.size() && right<sequence.size())
	{
		//cout<<"left:("<<left<<","<<sequence[left]<<") right:("<<right<<","<<sequence[right]<<")"<<endl;
		if(distinct<K)
		{
			//cout<<"Distinct < k"<<endl;
			right++;
			if(right >= sequence.size())
			{
				//cout<<"Right exceeded string size"<<endl;
				break;
			}			
			if(alpha[sequence[right]-'a'] == 0)
			{
				//cout<<"Found a distinct letter:"<<sequence[right]<<" Updating distinct count."<<endl;
				distinct++;
			}
			alpha[sequence[right]-'a']++;
		}
		else if(distinct == K)
		{
			//cout<<"Found a min size distinct entity equal to k"<<endl;
			count++;

			//calculating other sequences with same size
			for (int i = right+1; i < sequence.size(); ++i)
			{
				if(alpha[sequence[i]-'a'] == 0)			//found new alphabet
				{
					//cout<<"Found a distinct letter:"<<sequence[i]<<" at i:"<<i<<" while seeking additionals."<<endl;
					//cout<<"Breaking. No more additional sequences with same start and size."<<endl;
					break;
				}		
				else
				{
					count++;
				}		
			}
			//cout<<"Moving left"<<endl;
			left++;
			if(left >= sequence.size())
			{
				//cout<<"Left exceeded right. Breaking"<<endl;
				break;
			}
			if(alpha[sequence[left-1]-'a'] == 1)
			{
				//cout<<"Removing a single letter:"<<sequence[left-1]<<endl;
				distinct--;
			}
			alpha[sequence[left-1]-'a']--;
			if(left>right)
			{
				right++;
				if(right >= sequence.size())
				{
					//cout<<"Right exceeded string size"<<endl;
					break;
				}			
				if(alpha[sequence[right]-'a'] == 0)
				{
					//cout<<"Found a distinct letter:"<<sequence[right]<<" Updating distinct count."<<endl;
					distinct++;
				}
				alpha[sequence[right]-'a']++;

			}
		}
		else
		{
			//cout<<"Distinct letters should never be more than k"<<endl;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	cin>>K;
	cin>>sequence;
	cout<<findCombos()<<endl;
	return 0;
}