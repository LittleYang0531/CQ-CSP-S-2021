#include<bits/stdc++.h>
using namespace std;
map<int,char>mp;
int sol[25];
int n;
bool yj=0;
void dfs(string str1,string str2)
{
	//cout<<str1<<' '<<str2<<endl;
	//system("pause");
	if(yj) return;
	if(str1.size()==0)
	{
		for(int i=0;i<n;i++)
		{
			if(str2[i]!=str2[2*n-i-1])
			{
				//cout<<i<<' '<<str2[i]<<' '<<str2[2*n-i]<<endl;
				return;
			}
		}
		//cout<<str2<<endl;
		yj=1;
		return;
	}
	//cout<<str2.size()<<endl;
	//system("pause");
	sol[str2.size()+1]=0;
	string str3=str1;
	str2+=str3[0];
	//cout<<str2.size()<<endl;
	//system("pause");
	str3.erase(0,1);
	dfs(str3,str2);
	if(yj) return;
	str2.erase(str2.size()-1,1);
	//cout<<str2.size()<<endl;
	//system("pause");
	sol[str2.size()+1]=1;
	str2+=str1[str1.size()-1];
	str1.erase(str1.size()-1,1);
	dfs(str1,str2);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		yj=0;
		mp.clear();
		char c='0';
		string str1="";
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			int x;
			cin>>x;
			if(!mp.count(x))
			{
				mp[x]=c;
				c++;
			}
			str1+=mp[x];
		}
		dfs(str1,"");
		if(yj==0) printf("-1\n");
		else
		{
			for(int i=1;i<=2*n;i++)
			{
				if(sol[i]) cout<<"R";
				else cout<<"L";
			}
			cout<<endl;
		}
	}
	return 0;
}
