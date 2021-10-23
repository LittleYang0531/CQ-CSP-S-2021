#include<bits/stdc++.h>
using namespace std;
int n,mc,ma;
struct chn{//国内航班信息
    int start,end; 
}ch[100005];
struct abr{//国外航班信息 
	int start,end;
}ab[100005];
struct arv{
	int til,id;
	friend bool operator<(arv x,arv y){
		return x.til>y.til;
	}
};
struct ok{
	int til,id;
	friend bool operator<(ok x,ok y){
		return x.id>y.id;
	}
};
priority_queue<arv>q;
int cn[100005],an[100005];
bool cmpc(chn x,chn y){
	return x.start<y.start;
}
bool cmpa(abr x,abr y){
	return x.start<y.start;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&mc,&ma);
	for(int i=1;i<=mc;i++)
	    scanf("%d%d",&ch[i].start,&ch[i].end);
	for(int i=1;i<=ma;i++)
	    scanf("%d%d",&ab[i].start,&ab[i].end);
	sort(ch+1,ch+mc+1,cmpc);
	sort(ab+1,ab+ma+1,cmpa);
	
	int cln=0,aln=0;
	for(int i=1;i<=mc;i++){//计算国内航班拥有廊桥数及对应近机位航班数 
		if(i==1){
			cln++;
			cn[cln]++;
			arv t;
			t.til=ch[1].end;
			t.id=1;
			q.push(t);
			continue;
		}
	    if(ch[i].start<q.top().til){//需要使用新廊桥 
			cln++;//廊桥数目计数 
	    	cn[cln]++;
	    	arv t;
			t.til=ch[i].end;
			t.id=cln;
			q.push(t);
		}
		else{
			priority_queue<ok>qq;
			while(!q.empty()){
				arv x=q.top();
				if(x.til>ch[i].start)break;
				q.pop();
				ok xx;
				xx.id=x.id;
				xx.til=x.til;
				qq.push(xx); 
			}
			int u=qq.top().id;
			qq.pop();
			while(!qq.empty()){
				ok xx;
				xx=qq.top();
				qq.pop();
				arv x;
				x.id=xx.id;
				x.til=xx.til;
				q.push(x);
			}
			cn[u]++;
			arv t;
			t.til=ch[i].end;
			t.id=u;
			q.push(t);
		}
	}
	
	while(!q.empty())q.pop();
	for(int i=1;i<=ma;i++){//计算国际航班拥有廊桥数及对应近机位航班数 
		if(i==1){
			aln++;
			an[aln]++;
			arv t;
			t.til=ab[1].end;
			t.id=1;
			q.push(t);
			continue;
		}
	    if(ab[i].start<q.top().til){//需要使用新廊桥 
			aln++;//廊桥数目计数 
	    	an[aln]++;
	    	arv t;
			t.til=ab[i].end;
			t.id=aln;
			q.push(t);
		}
		else{
			priority_queue<ok>qq;
			while(!q.empty()){
				arv x=q.top();
				if(x.til>ab[i].start)break;
				q.pop();
				ok xx;
				xx.id=x.id;
				xx.til=x.til;
				qq.push(xx); 
			}
			int u=qq.top().id;
			qq.pop();
			while(!qq.empty()){
				ok xx;
				xx=qq.top();
				qq.pop();
				arv x;
				x.id=xx.id;
				x.til=xx.til;
				q.push(x);
			}
			an[u]++;
			arv t;
			t.til=ab[i].end;
			t.id=u;
			q.push(t);
		}
	}
	
	for(int i=1;i<=n;i++){
		cn[i]+=cn[i-1];
		an[i]+=an[i-1];
	}
	
	int maxn=0;
	for(int i=0;i<=n;i++){//枚举国内廊桥数量
	    maxn=max(maxn,cn[i]+an[n-i]);
    }
	printf("%d",maxn);
	return 0;
}
