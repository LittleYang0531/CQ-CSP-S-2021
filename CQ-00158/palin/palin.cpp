#include<iostream>
#include<cstdio>
using namespace std;
int t, n, a[100000], b[100000], k, h, l, sum;
char s[1000000];
void find(int);
int main()
{
	freopen("palin.in","r",stdin); freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		h=1; l=2*n; k=1; sum=0;
		for(int j=1;j<=2*n;j++)
		{
			cin>>a[j];
		}
		find(1);
		if(k==0)
		{
			cout<<"-1"<<endl;
		}
		for(int j=1;j<=2*n;j++)
		{
			a[j]=0; b[j]=0;
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
void find(int x)
{
		if(x<=2*n)
	    {
		    for(int i=1;i<=2;i++)
	        {
		        if(i==1)
		        {
		     	   s[x]='L';
		     	   b[x]=a[h];
		     	   h++;
			    }
			    if(i==2)
			    {
			 	  s[x]='R';
			      b[x]=a[l];
			 	  l--;
			    }
			    if(x==2*n)
			    {
			    	for(int j=1;j<=n*2;j++)
			    	{
			 		    if(b[j]==b[2*n+1-j]&&sum==0)
			 	    	{
			 		    	k=1;
					    }
					    else
					    {
						    k=0;
						    break;
					    }
					    
				    }
				
				    if(k==1)
				    {
				    	sum=1;
					    for(int j=1;j<=2*n;j++)
					    {
						    cout<<s[j];
					    }
					    cout<<endl;
				    }
			    }
			    else
			    {
			 	    find(x+1);
			    }
				return;
		    }
		}
}
