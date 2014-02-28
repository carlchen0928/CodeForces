#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int d;
int sumTime;
vector<int> interval;
vector<int> result;

int main()
{
//	fstream cin("a.txt");
	cin>>d>>sumTime;
	int a, b;
	int currentTime = 0;
	for(int i = 1; i <= d; i++)
	{
		cin>>a>>b;
		interval.push_back(b - a);
		result.push_back(a);
		currentTime += a;
	}
	int need = sumTime - currentTime;
	if(need < 0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i = 1; i <= d; i++)
	{
		if(need == 0) break;
		if(need > interval[i - 1])
		{
			need -= interval[i - 1];
			result[i - 1] += interval[i - 1];
		}
		else{
			result[i - 1] += need;
			need = 0;
		}
	}
	if(need == 0)
	{
		cout<<"YES"<<endl;
		cout<<result[0];
		for(int i = 1; i < result.size(); i++)
			cout<<" "<<result[i];
		cout<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}