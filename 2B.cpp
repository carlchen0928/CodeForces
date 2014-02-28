#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int n;
int matrix[1002][1002];
int dpp[2][1002][1002];
int path[2][1002][1002];
int znum[2][1002][1002];
int zeror, zeroc;
bool flag = false;
#define MIN(a, b) (((a) > (b)) ? (b) : (a))

void count_num()
{
	for(int j = 1; j <= n; j++)
	{
		for(int p = 1; p <= n; p++)
		{
			if(matrix[j][p] == 0) 
			{
				znum[0][j][p] = znum[1][j][p] = 1;
				continue;
			}
			int tmp = matrix[j][p];
			int i = 0;
			while (tmp % 2 == 0)
			{
				i++;
				tmp /= 2;
			}
			znum[0][j][p] = i;

			tmp = matrix[j][p];
			i = 0;
			while (tmp % 5 == 0)
			{
				i++;
				tmp /= 5;
			}
			znum[1][j][p] = i;
		}
	}
}

void dp(int min_num)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int tmp = znum[min_num][i][j];
/*			if(matrix[i][j] == 0) 
			{
				dpp[i][j] = 1;
				path[i][j] = 1;
			}*/
			if(i == j && i == 1)
			{
				dpp[min_num][i][j] = tmp;
				continue;
			}
			if(i == 1)
			{
				dpp[min_num][i][j] = dpp[min_num][i][j - 1] + tmp;
				path[min_num][i][j] = 1;
				continue;
			}
			if(j == 1)
			{
				dpp[min_num][i][j] = dpp[min_num][i - 1][j] + tmp;
				path[min_num][i][j] = 0;
				continue;
			}
			if(dpp[min_num][i - 1][j] >= dpp[min_num][i][j - 1])
			{
				dpp[min_num][i][j] = dpp[min_num][i][j - 1] + tmp;
				path[min_num][i][j] = 1;
			}
			else
			{
				dpp[min_num][i][j] = dpp[min_num][i - 1][j] + tmp;
				path[min_num][i][j] = 0;
			}
		}
	}
}

int main()
{
//	fstream cin("a.txt");
	cin>>n;
	for(int a = 1; a <= n; a++)
		for(int b = 1; b <= n; b++)
		{
			//scanf("%d", &matrix[a][b]);
			cin>>matrix[a][b];
			if(matrix[a][b] == 0)
			{
				zeror = a;
				zeroc = b;
				flag = true;
			}
		}
	count_num();
	dp(0);
	dp(1);
	vector<char> vf;
	int fnumber2 = dpp[0][n][n];
	int snumber5 = dpp[1][n][n];
	int i = n, j = n;
	int whi;
	if(fnumber2 < snumber5)
		whi = 0;
	else
		whi = 1;

	while (i != 1 || j != 1)
	{
		if(path[whi][i][j] == 1)
		{
			j--;
			vf.push_back('R');
		}
		else
		{
			i--;
			vf.push_back('D');
		}
	}

	if(flag && 1 < (snumber5 < fnumber2 ? snumber5 : fnumber2))
	{
		cout<<1<<endl;
		for(int p = 2; p <= zeror; p++) cout<<'D';
		for(int p = 2; p <= n; p++) cout<<'R';
		for(int p = zeror + 1; p <= n; p++) cout<<'D';
		cout<<endl;
	}
	else
	{
		if(whi) cout<<snumber5<<endl;
		else cout<<fnumber2<<endl;
		for(int p = vf.size() - 1; p >= 0; p--) cout<<vf[p];
	}
	cout<<endl;
}