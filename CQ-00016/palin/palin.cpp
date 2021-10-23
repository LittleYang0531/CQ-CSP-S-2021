#include<cstdio>
int o,t,n,nn,m,li[500000],res[500000],f,head,last;
char out[500000];
int check(){
	int q;
	for(q=0;q<n;++q){
		if(res[q]!=res[nn-1-q]){
			return 0;
		}
	}
	return 1;
}
int find(){
	if(f>=nn){
		return check();
	}
	res[f]=li[head];//L
	++head;++f;
	if(find()){
		out[f-1]='L';--f;--head;return 1;
	}
	--f;--head;
	res[f]=li[last];//R
	++f;--last;
	if(find()){
		out[f-1]='R';--f;++last;return 1;
	}
	--f;++last;
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int i,j,p;
	scanf("%d",&t);
	for(i=0;i<t;++i){
		scanf("%d",&n);
		nn=n*2;
		last=nn-1;
		for(j=0;j<nn;++j){getchar();li[j]=getchar();}
		if(!find())printf("-1");
		else{
			for(p=0;p<=last;++p){
				printf("%c",out[p]);
			}
		}
		printf("\n");
	}
	return 0;
}
