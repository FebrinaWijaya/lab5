#include"Hugeint.h"
#include<iomanip>
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
Hugeint::Hugeint(int x)
{
	num.push_back(x);
}
Hugeint::Hugeint(string str)
{
	int multiplies=str.length()/9;
	int remainder=str.length()%9;
	int pos=0;
	char rem[remainder];
	if(remainder>0)
	{
		for(int i=0;i<remainder;i++)
		{
			rem[i]=str[pos];
			pos++;
		}
		num.push_back(atoi(rem));
	}
	char part[9];
	for(int i=0;i<multiplies;i++)
	{
		for(int j=0;j<9;j++)
		{
			part[j]=str[pos];
			pos++;
		}
		num.push_back(atoi(part));
	}
}

ostream &operator<<(ostream &out,const Hugeint &huge_int)
{
	out<<huge_int.num.at(0);
	for(int i=1;i<huge_int.num.size();i++)
	{
		for(int j=8;j>=0;j--)
		{
			int divider=1;
			for(int k=1;k<=j;k++) divider*=10;
			if(huge_int.num.at(i)/divider<1) cout<<0;
			else break;
		}	
		out<<huge_int.num.at(i);
	}
	return out;
}
istream &operator>>(istream &in,Hugeint &huge_int)
{
	huge_int.num.clear();
	string input;
	in>>input;
	int multiplies=input.length()/9;
	int remainder=input.length()%9;
	int pos=0;
	char rem[remainder];
	if(remainder>0)
	{
		for(int i=0;i<remainder;i++)
		{
			rem[i]=input[pos];
			pos++;
		}
		huge_int.num.push_back(atoi(rem));
	}
	char part[9];
	for(int i=0;i<multiplies;i++)
	{
		for(int j=0;j<9;j++)
		{
			part[j]=input[pos];
			pos++;
		}
		huge_int.num.push_back(atoi(part));
	}
}
Hugeint& Hugeint::operator=(const Hugeint& huge_int)
{
	num.clear();
	num=huge_int.num;
}
Hugeint Hugeint::operator+(Hugeint huge_int)
{
	if(num.at(0)<0&&huge_int.num.at(0)>0)//negative num plus positive num
	{
		num.at(0)*=(-1);
		Hugeint minus=huge_int-(*this);
		num.at(0)*=(-1);
		return minus;
	}
	if(num.at(0)>0&&huge_int.num.at(0)<0)//positive num plus negative num
	{
		huge_int.num.at(0)*=(-1);
		Hugeint minus=(*this)-huge_int;
		return minus;
	}
	int pos1=num.size()-1;
	int pos2=huge_int.num.size()-1;
	Hugeint temp;
	if(pos1>=pos2)
	{
		temp=*this;
		while(pos1>=0&&pos2>=0)
		{
			temp.num.at(pos1)+=huge_int.num.at(pos2--);
			if(temp.num.at(pos1)>=1000000000&&pos1!=0)
			{
				temp.num.at(pos1)-=1000000000;
				temp.num.at(--pos1)++;
			}
		}
	}
	else
	{
		temp=huge_int;
		while(pos1>=0&&pos2>=0)
		{
			temp.num.at(pos2)+=num.at(pos1--);
			if(temp.num.at(pos2)>=1000000000&&pos2!=0)
			{
				temp.num.at(pos2)-=1000000000;
				temp.num.at(--pos2)++;
			}
		}
	}
	if(temp.num.at(0)>=1000000000)
	{
		temp.num.at(0)-=1000000000;
		temp.num.push_back(temp.num.at(temp.num.size()-1));
		for(int i=temp.num.size()-2;i>0;i--)
		{
			temp.num.at(i)=temp.num.at(i-1);
		}
		temp.num.at(0)=1;
	}
	return temp;
}

Hugeint Hugeint::operator-(Hugeint huge_int)
{
	if(num.at(0)<0&&huge_int.num.at(0)>0)//negative num minus positive num
	{
		num.at(0)*=(-1);
		Hugeint add=*this+huge_int;
		add.num.at(0)*=(-1);
		num.at(0)*=(-1);
		return add;
	}
	if(num.at(0)<0&&huge_int.num.at(0)<0)//negative num minus negative num
	{
		num.at(0)*=(-1);
		huge_int.num.at(0)*=(-1);
		Hugeint minus=huge_int-(*this);
		num.at(0)*=(-1);
		return minus;
	}
	if(num.at(0)>0&&huge_int.num.at(0)<0)//positive num minus negative num
	{
		huge_int.num.at(0)*=(-1);
		Hugeint add=*this+huge_int;
		return add;
	}
	int pos1=num.size()-1;
	int pos2=huge_int.num.size()-1;
	Hugeint temp;
	bool this_is_bigger=false;
	if(pos1>pos2) this_is_bigger=true;
	if(pos1==pos2)
	{
		for(int i=0;i<num.size();i++)
			if(num.at(i)>huge_int.num.at(i)) this_is_bigger=true;
	}
	if(this_is_bigger)
	{
		temp=*this;
		while(pos1>=0&&pos2>=0)
		{
			if(temp.num.at(pos1)<huge_int.num.at(pos2))
			{
				temp.num.at(pos1)+=1000000000;
				temp.num.at(pos1-1)--;
			}
			temp.num.at(pos1)-=huge_int.num.at(pos2);
			--pos2;
			--pos1;
		}
	}
	else
	{
		temp=huge_int;
		while(pos1>=0&&pos2>=0)
		{
			if(temp.num.at(pos2)<num.at(pos1))
			{
				temp.num.at(pos2)+=1000000000;
				temp.num.at(pos2-1)--;
			}
			temp.num.at(pos2)-=num.at(pos1);
			--pos2;
			--pos1;
		}
		temp.num.at(0)*=(-1);
	}
	return temp;
}
