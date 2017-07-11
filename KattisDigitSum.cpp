#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long s[16];

long long calc(long long a, long long b)
{
    long long i,sum=0,num;
    for(i=a;i<=b;++i)
    {
        num=i;
        while(num>0)
        {
            sum+=num%10;
            num/=10;
        }
    }
    return sum;
}

long long getDigSum(long long num)
{
    long long sum=0;
    while(num>0)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}

long long getIncrement(long long a, long long b)
{
    long long incr=1000000000000000;
    while(incr>0)
    {
        if((a%incr==0) && ((a+incr)<=b))
        {
            return incr;
        }
        incr/=10;
    }
    //case when a==b
    return 0;
}

long long calc2(long long a, long long b)
{
    //printf("..calc2 called for a=%lld b=%lld\n",a,b);
    long long sum=0,incr,base_sum;
    int incr_sum_idx;
    sum+=getDigSum(a);
    incr=getIncrement(a,b);
    while(incr!=0)
    {
        if(incr==1)
        {
            sum+=getDigSum(a+1);
            a+=incr;
            //printf(".. case 1: a=%lld b=%lld incr=%lld incr_sum_idx=%d sum=%lld\n",a,b,incr, incr_sum_idx,sum);
        }
        else
        {
            incr_sum_idx=(int)log10(incr);
            base_sum=getDigSum(a);
            sum+=base_sum*(incr-1)+(s[incr_sum_idx]-1);
            a+=(incr-1);
            //printf(".. case 2: a=%lld b=%lld incr=%lld incr_sum_idx=%d sum=%lld\n",a,b,incr, incr_sum_idx,sum);
        }
        incr=getIncrement(a,b);
    }
    return sum;
}

int main() {
    int T,i;
    long long a,b,temp;
    s[0]=1;
    for(i=1;i<16;++i)
    {
        temp=pow(10,i);
        s[i]=calc2(1,temp-1)+1;
        //printf("..1 to %lld, sum = %lld\n",temp,s[i]);
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&a,&b);
        //printf("calc=%lld\n",calc(a,b));
        printf("%lld\n",calc2(a,b));
    }
	return 0;
}