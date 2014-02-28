#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

long long n, m, a;
int main()
{
	cin>>n>>m>>a;
	long long row = ceil((double)n/(double)a);
	long long col = ceil((double)m/(double)a);
	cout<<row*col<<endl;
}