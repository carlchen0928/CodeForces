#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> result;

void resc(int p1, int p2)
{
	string res = "";
	if(p1 == 0 && p2 == 0)
		return;
	if(p1 == 0)
	{
		if(p2 > 0) res += 'D';
		else res += 'U';
		result.push_back(res);
		resc(p1, p2 > 0 ? --p2 : ++p2);
		return;
	}
	if(p2 == 0)
	{
		if(p1 > 0) res += 'L';
		else res += 'R';
		result.push_back(res);
		resc(p1 > 0 ? --p1 : ++p1, p2);
		return;
	}
	if(p1 * p2 > 0)
	{
		if(p1 > 0)
			res += "LD";
		else
			res += "RU";
	}
	else
	{
		if(p1 > 0)
			res += "LU";
		else
			res += "RD";
	}
	result.push_back(res);
	resc(p1 > 0 ? --p1 : ++p1, p2 > 0 ? --p2 : ++p2);
	return;
}

int main()
{
	char a1, b1;
	int a2, b2;
	cin>>a1>>a2>>b1>>b2;
	resc(a1 - b1, a2 - b2);
	cout<<result.size()<<endl;
	for(int i = 0; i < result.size(); i++)
		cout<<result[i]<<endl;
}