#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <fstream>
using namespace std;

struct node
{
	int i;
	int value;
	node(int i, int v):i(i), value(v){}
};

bool operator <(const node &n1, const node &n2){
	return n1.value < n2.value;
}

priority_queue<node> p;
string org;
string result;

int main()
{
//	fstream cin("a.txt");
	cin>>org;
	int l = 0;
	long long totalcost = 0;
	int a, b;
	for(int i = 0; i < org.size(); i++){
		if(org[i] == '(') {
			l++;
			result += '(';
		}
		else if(org[i] == ')') {
			l--;
			result += ')';
		}
		else{
			l--;
			cin>>a>>b;
			totalcost += b;
			node tmp(i, b - a);
			p.push(tmp);
			result += ')';
		}
		if(l < 0){
			if(p.empty()) break;
			node tmp = p.top();
			p.pop();
			totalcost -= tmp.value;
			result[tmp.i] = '(';
			l += 2;
		}
	}
	if(l != 0){
		cout<<-1<<endl;
		return 0;
	}
	cout<<totalcost<<endl;
	cout<<result<<endl;
}