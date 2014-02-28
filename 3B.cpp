#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
/*
vector<vector<int>> dp;
vector<vector<bool>> flag;
vector<int> c;
vector<int> w;
int n, v;
int main()
{
//	fstream cin("a.txt");
	cin>>n>>v;
	dp = vector<vector<int>>(n + 1, vector<int>(v + 1, 0));
	flag = vector<vector<bool>>(n + 1, vector<bool>(v + 1, false));
	c = vector<int>(n + 1);
	w = vector<int>(n + 1);
	for(int i = 0; i < n; i++)
		cin>>w[i + 1]>>c[i + 1];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= v; j++)
		{
			if(w[i] > j)
			{
				dp[i][j] = dp[i - 1][j];
				continue;
			}
			else
			{
				if(dp[i - 1][j] > dp[i - 1][j - w[i]] + c[i])
					dp[i][j] = dp[i - 1][j];
				else
				{
					dp[i][j] = dp[i - 1][j - w[i]] + c[i];
					flag[i][j] = true;
				}
			}
		}
	}
	cout<<dp[n][v]<<endl;

	int i = n, j = v;
	vector<int> result;
	while (true)
	{
		if(j == 0) break;
		if(flag[i][j])
		{
			result.push_back(i);
			j -= w[i];
			i--;
		}
		else
			i--;
	}
	for(int i = result.size() - 1; i > 0; i--)
		cout<<result[i]<<" ";
	cout<<result[0]<<endl;
}
*/

int n, v;
struct node
{
	int i;
	int type;
	int capacity;
	double capacity_per_cubic;
	node(int i, int t, int c):i(i), type(t), capacity(c), capacity_per_cubic((c * 1.0)/(t * 1.0)){}
};
vector<node> vec[2];

bool cmp(node &n1, node &n2)
{
	return n1.capacity_per_cubic > n2.capacity_per_cubic;
}
int main()
{
//	fstream cin("a.txt");
	cin>>n>>v;
	int a, b;
	for(int i = 0; i < n; i++)
	{
		cin>>a>>b;
		node tmp(i + 1, a, b);
		if(a == 1)
			vec[0].push_back(tmp);
		else
			vec[1].push_back(tmp);
	}
	sort(vec[0].begin(), vec[0].end(), cmp);
	sort(vec[1].begin(), vec[1].end(), cmp);
	int la = 0, lb = 0;
	vector<int> result;
	int total = 0;
	while (la < vec[0].size() && lb < vec[1].size() && v >= 2)
	{
		if(vec[0][la].capacity_per_cubic > vec[1][lb].capacity_per_cubic)
		{
			if(la == vec[0].size() - 1 && v % 2 != 1)
			{
				int tmp1 = 0, tmp2 = 0;
				int tmp = v;
				for(int j = lb; j < vec[1].size(); j++)
				{
					if(tmp >= 2) tmp1 += vec[1][j].capacity;
					else break;
					tmp -= 2;
				}
				tmp2 += vec[0][la].capacity;
				tmp = v;
				tmp--;
				for(int j = lb; j < vec[1].size(); j++)
				{
					if(tmp >= 2) tmp2 += vec[1][j].capacity;
					else break;
					tmp -= 2;
				}
				if(tmp1 < tmp2)
				{
					total += vec[0][la].capacity;
					v -= vec[0][la].type;
					result.push_back(vec[0][la].i);
					la++;
				}
				else
				{
					total += vec[1][lb].capacity;
					v -= vec[1][lb].type;
					result.push_back(vec[1][lb].i);
					lb++;
					la++;
				}
			}
			else
			{
				total += vec[0][la].capacity;
				v -= vec[0][la].type;
				result.push_back(vec[0][la].i);
				la++;
			}
		}
		else
		{
			total += vec[1][lb].capacity;
			v -= vec[1][lb].type;
			result.push_back(vec[1][lb].i);
			lb++;
		}
	}
	for(int j = lb; j < vec[1].size(); j++)
	{
		if(v >= 2) 
		{
			total += vec[1][j].capacity;
			result.push_back(vec[1][j].i);
		}
		else break;
		v -= 2;
	}
	for(int j = la; j < vec[0].size(); j++)
	{
		if(v >= 1) 
		{
			total += vec[0][j].capacity;
			result.push_back(vec[0][j].i);
		}
		else break;
		v -= 1;
	}
	cout<<total<<endl;
	if(result.empty()) return 0;
	for(int i = 0; i < result.size() - 1; i++)
		cout<<result[i]<<" ";
	cout<<result[result.size() - 1]<<endl;
}