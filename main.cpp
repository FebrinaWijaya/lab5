#include<iostream>
#include "Hugeint.h"
using namespace std;
int main()
{
	Hugeint x;
	Hugeint y(28825252);
	Hugeint z("314159265358979323846");
	Hugeint result;
	cout<<"Input a huge integer : ";
	cin>>x;
	result=x+y;
	cout<<x<<" + "<<y<<" = "<<result<<endl;
	result=z-x;
	cout<<z<<" - "<<x<<" = "<<result<<endl;
	return 0;
}
