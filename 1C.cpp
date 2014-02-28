
#include <iostream>
#include <math.h>
#include <cmath>
#include <stdio.h>
using namespace std;

#define feq(a, b) (fabs((a)-(b))<1E-2)

double fgcd(double a, double b){  
	if (feq(a, 0))  
		return b;  
	if (feq(b, 0))  
		return a;  
	return fgcd(b, fmod(a, b));  
}  

int main()
{
	double x[3], y[3], z[3], angle[3];
	for(int i = 0; i < 3; i++)
		cin>>x[i]>>y[i];
	for(int i = 0; i < 3; i++)
		z[i] = sqrt((x[i] - x[(i + 1) % 3]) * (x[i] - x[(i + 1) % 3]) + (y[i] - y[(i + 1) % 3]) * (y[i] - y[(i + 1) % 3]));
	double q = (z[0] + z[1] + z[2])/2;
	double S = sqrt(q * (q - z[0]) * (q - z[1]) * (q - z[2]));
	double r = (z[0] * z[1] * z[2])/(4 * S);

	for(int i = 0; i < 2; i++)
		angle[i] = acos(1 - z[i] * z[i]/(2 * r * r));
	angle[2] = 2 * acos(-1.0) - angle[0] - angle[1];
//	angle[0] = acos((z[1] * z[1] + z[2] * z[2] - z[0] * z[0])/(2 * z[1] * z[2]));
//	angle[1] = acos((z[0] * z[0] + z[2] * z[2] - z[1] * z[1])/(2 * z[0] * z[2]));
//	angle[2] = acos((z[1] * z[1] + z[0] * z[0] - z[2] * z[2])/(2 * z[1] * z[0]));

	double min = fgcd(angle[0], fgcd(angle[1], angle[2]));
	printf("%.6lf\n", r * r * sin(min) / 2 * (2 * acos(-1.0) / min));  
}