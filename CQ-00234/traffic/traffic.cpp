#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t;
	srand(time(NULL));
	cin>>n>>m>>t;
	while(t--)
	{
		cout<<abs(rand()%100)+1<<endl;
	}
	return 0;	
}
/*
w         w         w zzzzzz  y     y       a        k   k     c        ss     pp    |
 w       w w       w      z    y   y       a a       k  k     c c      s  s    p p   |
  w     w   w     w      z      y y       a   a      k k     c          s      p p   |
   w   w     w   w      z        y       aaaaaaa     kk      c           s     pp    |
    w w       w w      z         y      a       a    k k      c c      s s     p
     w         w      zzzzzz     y     a         a   k  k      c        s      p     .
*/
