#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

const int MIN_INT = -0xfffffff;

struct node
{
	int nows;
	int step;
	node(int s, int n):nows(n), step(s){}
};

map<string, vector<node>> m;
int main()
{
//	fstream cin("a.txt");
	int n;
	cin>>n;
	int i = 0;
	string name;
	int score;
	while (n--)
	{
		cin>>name>>score;
		if(m.find(name) == m.end())
		{
			vector<node> tmp;
			tmp.push_back(node(i, score));
			m.insert(make_pair(name, tmp));
		}
		else
		{
			int nows = m[name].back().nows;
			m[name].push_back(node(i, nows + score));
		}
		i++;
	}

	int max_score = MIN_INT;
	int final_step = 9999;
	string winner;
	map<string, vector<node>>::iterator it;
	for(it = m.begin(); it != m.end(); it++)
	{
		int tmp = (*it).second.back().nows;
		string peo = (*it).first;
		if(tmp > max_score)
		{
			max_score = tmp;
			winner = peo;
			for(int i = 0; i < (*it).second.size(); i++)
				if((*it).second[i].nows >= tmp) 
				{
					final_step = (*it).second[i].step;
					break;
				}
		}
		else if(tmp == max_score)
		{
			int tmp_step = 0;
			for(int i = 0; i < (*it).second.size(); i++)
				if((*it).second[i].nows >= tmp) 
				{
					tmp_step = (*it).second[i].step;
					break;
				}
			if(tmp_step < final_step) 
			{
				final_step = tmp_step;
				winner = peo;
			}
		}
	}
	cout<<winner<<endl;
}