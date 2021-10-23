#include<bits/stdc++.h>
using namespace std;
int n,a[500001],b[500001],t,k[500001],lb=0,l=1,r;
char bz[500001],kz[500001];
bool falg;
void ks()
{
	if(falg=true)
	for(int i=1;i<=n;i++)
	{
		if(k[i]<b[i])
	    return ;
	    else if(k[i]>b[i])
	    {
	    	for(int j=1;j=n;j++)
	    	{
	    		k[j]=b[j];
	    		kz[j]=bz[j];
			}
		}
	}
	else
	{
		falg=true;
		for(int i=1;i=n;i++)
	    {
	        k[i]=b[i];
	        kz[i]=bz[i];
	    }
	}
	
}
void dfs(int j)
{
	if(j<=n/2)
	{
	    l++;
	    b[j]=a[l-1];
	    bz[j]='L';
	    dfs(j+1);
	    l--;
	    r--;
	    b[j]=a[r+1];
	    bz[j]='R';
	    dfs(j+1);
	    r++;
	} 
	else if(j==n/2+1)
	{
		int lk=l,rk=r;
	    for(int i=1;i<n/2;i++)
	    {
	        if(b[n-j+1]==a[r])
	        {
	            l++;
	            b[j]=a[l-1];
       	        bz[j]='L';
	            if(j==n)
 	            ks();
	        }
 	        else if(b[n-j+1]==a[l])
	        {
	            r--;
	            b[j]=a[r+1];
	            bz[j]='R';
	            if(j==n)
	            ks();
	        }
	        else if(b[n-j+1]!=a[r]&&b[n-j+1]!=a[l])
	        {
	        	l=lk;
	        	r=rk;
	        	return ;
			}
	    j++;
	    }
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n;
		falg=false;
		n*=2;
	    for(int i=1;i<=n;i++)
		cin>>a[i];
		r=n;
		dfs(1);
		if(falg==false)
		cout<<-1<<endl;
		else
		{
			for(int i=1;i<=n;i++)
		    cout<<kz[i];
		    cout<<endl;
		}
	}
}
