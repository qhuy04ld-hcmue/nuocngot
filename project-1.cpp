#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
class SoPhuc{
    int a,b;
public:
    SoPhuc(int x=0,int y=0)         {a=x;b=y;}
    void Get(int x=0,int y=0)       {a=x;b=y;}
    friend istream& operator>>(istream& is, SoPhuc &s){
        is>>s.a>>s.b;
        return is;
    }
    friend ostream& operator<<(ostream& os, SoPhuc s){
    	if (s.b<0)  os<<s.a<<" - "<<-1*s.b<<'i'<<endl;
    	else
    	os<<s.a<<" + "<<s.b<<"*i"<<endl;
        return os;
    }
    friend SoPhuc operator+(SoPhuc a,SoPhuc b){
        SoPhuc c;
        c.a=a.a+b.a;
        c.b=a.b+b.b;
        return c;
    }
    friend bool operator>(SoPhuc a, SoPhuc b){
    	return (sqrt(a.a*a.a+a.b*a.b)>sqrt(b.a*b.a+b.b+b.b));
	}
	//u * v = (a*c - b*d, a*d + b*c)
	friend SoPhuc operator*(SoPhuc a, SoPhuc b){
		SoPhuc c;
		c.a=a.a*b.a-a.b*b.b;
		c.b=a.a*b.b+a.b*b.a;
		return c;
	}
};
int main(){
    SoPhuc a[100],b; int i,n,s=0;
    ifstream in("D:\\input.txt");
    ofstream on("D:\\output.txt");
    in>>n;
    for (i=0;i<n;i++)
        in>>a[i];
    b=a[0];
    for (i=1;i<n;i++)
    	if (a[i]>b) b=a[i];
    on<<b;
    b=0;
    for (i=0;i<n;i++)
    	b=b+a[i];
    on<<b;
    b=1;
    for (i=0;i<n;i++)
    	b=b*a[i];
    on<<b;
    return 0;
}
