#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w*=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;	
}
int T,n,l,r;
int R[N],p[N],a[2*N];
int num[N];
char ans[2*N],temp[2*N];
bool flag;
inline void Solve(int x,int y,int A,int B) //��¼Ŀǰ��λ�� 
{
	int cnt=1;
	while(A>=l||B<=r){ //ѡ��Ϊֹ 
		if(x<l&&y==r){ //ֻ��ѡx 
			if(a[x]==a[B]&&B<=r) B++;
			else if(a[x]==a[A]&&A>=l) A--;
			else return; //һ�������� 
			x++;
			temp[++cnt]='L';
			continue;
		}
		if(x==l&&y>r){
			if(a[y]==a[B]&&B<=r) B++;
			else if(a[y]==a[A]&&A>=l) A--;
			else return;
			y--;
			temp[++cnt]='R';
			continue;
		}
		//���������߶���ѡ
		//��ѡС��
		int tx=x,ty=y;
		if(a[x]==a[B]&&B<=r) B++,x++;
		else if(a[x]==a[A]&&A>=l) A--,x++;
		else if(a[y]==a[B]&&B<=r) B++,y--;
		else if(a[y]==a[A]&&A>=l) A--,y--;
		else return;
		if(tx!=x) temp[++cnt]='L';
		else temp[++cnt]='R';
	}
	flag=true; //ƥ��ɹ� 
}
inline void out()
{
	int x=1,y=2*n,tot=0;
	for(register int i=1;i<=n;i++){
		if(temp[i]=='L') R[++tot]=a[x],x++;
		else R[++tot]=a[y],y--;
	}
	for(register int i=n+1;i<=2*n;i++){
		if(R[tot]==a[x]) temp[i]='L',x++;
		else temp[i]='R',y--;
		tot--;
	}
	for(register int i=1;i<=2*n;i++){
		if(ans[i]<temp[i]) return;
		if(temp[i]<ans[i]) break;
	}
	for(register int i=1;i<=2*n;i++) ans[i]=temp[i];
}
inline void update()
{
	for(register int i=l;i<=r;i++) p[a[i]]=i; //��¼λ��
	flag=false;
	if(l>1) temp[1]='L',Solve(2,2*n,p[a[1]]-1,p[a[1]]+1);
	if(flag) { out(); return; }
	if(r<2*n) temp[1]='R',Solve(1,2*n-1,p[a[2*n]]-1,p[a[2*n]]+1); //������λ�ó�����һ�� 
	if(flag) { out(); return; }
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		ans[1]='Z'; //��ʼֵ 
		n=read();
		for(register int i=1;i<=2*n;i++) a[i]=read();
		//����Ҫ�ҵ�������ͬ������ 
		int cnt=0; //��¼�Ϸ����������� 
		for(register int i=1;i<=n;i++){
			if(!num[a[i]]) num[a[i]]++,cnt++;
			else num[a[i]]++,cnt--; //���Ϸ� 
		}
		l=-1,r=-1;
		for(register int i=n;i<=2*n;i++){ //ö��ĩ�� 
			if(cnt==n){ //������Ϸ� 
				l=i-n+1,r=i;
				update();
			}
			if(i==2*n) continue;
			num[a[i-n+1]]--;
			if(num[a[i-n+1]]==1) cnt++; //�Ϸ� 
			else cnt--; //���Ϸ�
			if(!num[a[i+1]]) num[a[i+1]]++,cnt++;
			else num[a[i+1]]++,cnt--;
		}
		for(register int i=1;i<=n;i++) num[i]=0;
		if(l==-1&&r==-1){ printf("-1\n"); continue; } //û������������
		if(ans[1]=='Z') printf("-1\n");
		else{
			for(register int i=1;i<=2*n;i++)
				printf("%c",ans[i]);
			printf("\n");
		}
	}
	return 0;
}
