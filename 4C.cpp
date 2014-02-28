#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int n;
map<string, int> m;

int main()
{
//	fstream cin("a.txt");
	string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(m.find(s) != m.end())
		{
			m[s]++;
			int tmp = m[s];
			stringstream ss;
			string num;
			ss << tmp;
			ss >> num;
			s += num;
			m.insert(make_pair<string, int>(s, 0));
			cout<<s<<endl;
		}
		else
		{
			m.insert(make_pair<string, int>(s, 0));
			cout<<"OK"<<endl;
		}
	}
}
