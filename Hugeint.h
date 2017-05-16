#ifndef HUGEINT_H
#define HUGEINT_H
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
class Hugeint
{
	friend ostream &operator<<(ostream&,const Hugeint&);
	friend istream &operator>>(istream&,Hugeint&);
public:
	Hugeint(int x=0);
	Hugeint(string);
	Hugeint& operator=(const Hugeint&);
	Hugeint operator+(Hugeint);
	Hugeint operator-(Hugeint);
private:
	vector<int> num;
};
#endif
