#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

bool way(string &tmp)
{
	int firstNum;
	for(int i = 0; i < tmp.size(); i++)
	{
		if(tmp[i] >= '0' && tmp[i] <= '9')
		{
			firstNum = i;
			break;
		}
	}
	for(int i = 0; i < firstNum; i++)
	{
		if(tmp[i] < 'A' || tmp[i] > 'Z')
			return false;
	}
	for(int i = firstNum; i < tmp.size(); i++)
	{
		if(tmp[i] < '0' || tmp[i] > '9')
			return false;
	}
	return true;
}

string stran1(string &tmp)
{
	int i = 0;
	int r = 0;
	string c = "";
	for(; i < tmp.size(); i++)
	{
		if(tmp[i] >= 'A' && tmp[i] <= 'Z')
			r = r * 26 + (tmp[i] - 'A' + 1);
		else
			c += tmp[i];
	}
	stringstream ss;
	ss << r;
	return "R" + c + "C" + ss.str();
}

string stran2(string &tmp)
{
	bool flag = true;
	string r = "";
	int t = 0;
	for(int i = 1; i < tmp.size(); i++)
	{
		if(tmp[i] != 'C' && flag)
			r += tmp[i];
		else if(tmp[i] != 'C' && !flag)
			t = t * 10 + (tmp[i] - '0');
		else
			flag = false;
	}
	string result = "";
	while (t > 26)
	{
		string p = "";
		p += (t % 26 == 0 ? 'Z' : ('A' + (t % 26) - 1));
		if(t % 26 == 0) t--;
		result = p + result;
		t = t / 26;
	}
	string p = "";
	p += (t % 26 == 0 ? 'Z' : ('A' + (t % 26) - 1));
	result = p + result;
	result += r;
	return result;
}

int main()
{
//	fstream cin("a.txt");
	int n;
	cin>>n;
	string pos;
	while (n--)
	{
		cin>>pos;
		bool flag = way(pos);
		if(flag) cout<<stran1(pos)<<endl;
		else cout<<stran2(pos)<<endl;;
	}
}