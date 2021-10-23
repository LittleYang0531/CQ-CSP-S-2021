#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("airport.in","r",stdin);
freopen("airport.out","w",stdout);
int n,x,y,l=0;
cin>>n>>x>>y;
int a[x][2],b[y][2],sum[n];
for(int i=1;i<=x;i++)
   {for(int j=1;j<=2;j++)
      cin>>a[i][j];
   }
for(int i=1;i<=y;i++)
   {for(int j=1;j<=2;j++)
      cin>>b[i][j];
   }	  
for(int i=0;i<=n;i++)
   sum[i]=0;
   
for(int z=0;z<=n;z++)
   {int c=z,d,azuida,bzuida,azou=0,bzou=0,acha=0,bcha=0;
   d=z-c;
   for(int i=1;i<=x;i++)
       {
	   if(c==0)
       {
	   for(int j=1;j<=i;j++)
	      {azuida=a[j][2];
		  if(a[i][1]>azuida)
             {azou++;
             
		     }
	      }
		  c=c+azou-acha;
	   acha=azou;
	   if(c>0)
	      {c--;
	      sum[z]++;
		  }
	   }
       	azou=0;
		   if(c>0)
       	 {c--;
       	 sum[z]++;
		
			}
       
	   azou=0;
	   }
	for(int i=1;i<=y;i++)
       {
	   if(d==0)
       {for(int j=1;j<=i;j++)
	      {bzuida=a[j][2];
		  if(a[j][1]>bzuida)
             {azou++;
             
		     }
	      }
		  d=d+bzou-bcha;
	   bcha=bzou;
	   bzou=0;
	   if(d>0)
	      {d--;
	      sum[z]++;
		  }
	   }
       	if(d>0)
       	 {d--;
       	 sum[z]++;
			
			}
       
	   
	   }
	}
l=sum[0];
for(int i=0;i<=n;i++)
   {
   if(sum[i]>l)
      l=sum[i];
   }
cout<<l;
return 0;
}
