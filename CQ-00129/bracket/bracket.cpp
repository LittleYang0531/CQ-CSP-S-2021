#include<bits/stdc++.h>
using namespace std;
int n,K;
string str1;
bool be[505][505];//*
char s[15]; 
int check(int l,int r)
{
	int sum=0;
	bool out=0;
	if(r-l<1||str1[l]=='*'||str1[l]==')'||str1[r]=='*'||str1[r]=='(') return 0;
	s[l]='(',s[r]=')';
	for(int i=l+1;i<=r-1;i++)//l+1~i,i+1~j,j+1~k,k+1~r-1
	{
		for(int j=i+1;j<=r-1;j++)
		{
			/*for(int k=j+1;k<=r-1;k++)
			{
				if(i-l-1<=K&&be[l+1][i-1]&&k-j-1<=K&&be[j+1][k-1])
				{
					sum+=check(i,j)*check(k,r-1);
					if(out&&check(i,j)*check(k,r-1)) printf("1%d %d %d %d  ",i,j,k,check(i,j)*check(k,r-1));
				}
				if(j-i-1<=K&&be[i+1][j-1]&&r-k-1<K&&r-k-1>0&&be[k+1][r-1])
				{
					sum+=check(l+1,i)*check(j,k);
					if(out&&check(l+1,i)*check(j,k)) printf("2%d %d %d %d  ",i,j,k,check(l+1,i)*check(j,k));
				}
			}*/
			if(j-i-1<=K&&be[i+1][j-1])
			{
				sum+=check(l,i)*check(j,r);
				if(out&&check(l,i)*check(j,r)) printf("6%d %d %d  ",i,j,check(l,i)*check(j,r));
				for(int k=i+1;k<=j-1;k++) s[k]='*';
			}
		}
		if(i-l-1<=K&&be[l+1][i-1])
		{
			if(out&&check(i,r-1)) printf("3%d %d  ",i,check(i,r-1));
			sum+=check(i,r-1);
			for(int k=l+1;k<=i-1;k++) s[k]='*';
		}
		if(r-i-1<=K&&be[i+1][r-1]&&i!=r-1)
		{
			if(out&&check(l+1,i)) printf("4%d %d  ",i,check(l+1,i));
			sum+=check(l+1,i);
			for(int k=i+1;k<=r-1;k++) s[k]='*';
		}
	}
	if(r-l==1) sum++;
	else if(r-l-1<=K&&be[l+1][r-1])
	{
		sum++;
		//for(int k=l+1;k<=r-1;k++) s[k]='*';
	}
	if(out) cout<<s<<endl;
	//cout<<l<<' '<<r<<' '<<sum<<"   ";
	return sum;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>K;
	cin>>str1;
	for(int i=0;i<str1.size();i++)
	{
		for(int j=0;j<str1.size();j++)
		{
			if(i>j) be[i][j]=1;
			else if(i==j) be[i][j]=(str1[i]=='*'||str1[i]=='?');
			else
			{
				be[i][j]=be[i][j-1]&(str1[j]=='*'||str1[j]=='?');
			}
		}
	}
	cout<<check(0,str1.size()-1);
	return 0;
}
