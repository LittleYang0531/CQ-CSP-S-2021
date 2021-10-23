#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int t=0;char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int a[1000002],n,t,ia,c1,c2,hd1,hd2,tl1,tl2,q1[1000002],q2[1000002];
char ansl[1000002],ansr[1000002];
inline void ck(int x){
	tl1=tl2=c1=c2=0,hd1=hd2=1;
	ansl[++c1]=(x==1)?'L':'R';
	ansr[++c2]='L';
	int pp=a[x],pos=0;
	for(int i=1;i<=n+n;++i)if(i!=x&&a[i]==pp)pos=i;
	for(int i=1;i<pos;++i)
		if(i!=x)
			q1[++tl1]=a[i];
	for(int i=n+n;i>pos;--i)
		if(i!=x)
			q2[++tl2]=a[i];
	while(hd1<=tl1||hd2<=tl2){
		bool c=0;
		if(hd1<=tl1){
			int x=q1[hd1];
			if(hd2<=tl2&&x==q2[tl2])ansl[++c1]='L',ansr[++c2]='R',c=1,++hd1,--tl2;
			if(hd1<tl1&&x==q1[tl1])ansl[++c1]='L',ansr[++c2]='L',c=1,++hd1,--tl1;
		}
		if(!c){
			if(hd2<=tl2){
				int x=q2[hd2];
				if(hd1<=tl1&&x==q1[tl1])ansl[++c1]='R',ansr[++c2]='L',c=1,++hd2,--tl1;
				if(hd2<tl2&&x==q2[tl2])ansl[++c1]='R',ansr[++c2]='R',c=1,++hd2,--tl2;
			}
		}
		if(!c)return;
	}
	ia=1;
	for(int i=1;i<=c1;++i)putchar(ansl[i]);
	for(int i=c2;i;--i)putchar(ansr[i]);
	puts("");
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		n=read(),ia=0;
		for(int i=1;i<=n+n;++i)a[i]=read();
		if(!ia)ck(1);
		if(!ia)ck(n+n);
		if(!ia)puts("-1");
	}
}

