#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

const int inf = 0x7fffffff;
int n, w, h;
struct node
{
	int w;
	int h;
	int i;
	node(int w, int h, int i): w(w), h(h), i(i){}
};
vector<node> v;
vector<int> pre;
vector<int> dp;
bool cmp(const node &n1, const node &n2)
{
	if(n1.w < n2.w) return true;
	else if(n1.w > n2.w) return false;
	else if(n1.h < n2.h) return true;
	else return false;
}

int main()
{
//	fstream cin("a.txt");
	cin>>n>>w>>h;
	pre = vector<int>(n, -1);
	dp = vector<int>(n, -1);
	int a, b;
	for(int i = 0; i < n; i++)
	{
		cin>>a>>b;
		node tmp(a, b, i);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);

	int maxindex = -1;
	int max = 0;
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i].h <= h || v[i].w <= w)
			continue;
		else dp[i] = 1;
		for(int j = 0; j < i; j++)
		{
			if(v[i].h > v[j].h && v[i].w > v[j].w && dp[i] < dp[j] + 1 && dp[j] != -1)
			{
				dp[i] = dp[j] + 1;
				pre[i] = j;
			}
		}
		if(max < dp[i])
		{
			max = dp[i];
			maxindex = i;
		}
	}

	if(maxindex == -1) cout<<0<<endl;
	else
	{
		vector<int> tmp;
		cout<<max<<endl;
		int cou = maxindex;
		while (pre[cou] != -1)
		{
			tmp.push_back(v[cou].i + 1);
			cou = pre[cou];
		}
		tmp.push_back(v[cou].i + 1);

		cout<<tmp[tmp.size() - 1];
		for(int i = tmp.size() - 2; i != -1; i--)
			cout<<" "<<tmp[i];
		cout<<endl;
	}
	return 0;
}