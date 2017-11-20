#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

long long N,K,Q;

long long findDist(long long x, long long y){
    //printf("..dist(%lld,%lld)\n",x,y);
    long long ans,p;
    if(x==y){
        ans=0;
    }
    else if(x<y){
        p = y%K==0?(y/K-1):y/K;
        ans = 1+findDist(x,p);
    } else {
        p = x%K==0?(x/K-1):x/K;
        ans=1+findDist(p,y);
    }
    //printf("..dist(%lld,%lld)=%lld\n",x,y,ans);
    return ans;
}

int main() {
    long long x,y,i;
    scanf("%lld%lld%lld",&N,&K,&Q);
    for(i=0;i<Q;++i){
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",findDist(x-1,y-1));
    }
	return 0;
}