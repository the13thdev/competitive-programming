#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int scanInt()
{
    int n=0, ch = getchar_unlocked();
    while(ch<'0' || ch>'9')
    ch=getchar_unlocked();
    while(ch>='0' && ch<='9')
    {
        n= (n<<3) + (n<<1) + ch - '0';
        ch=getchar_unlocked();
    }
    return n;
}

int main() {
    int N,x,y,i;
    long long ans=0;
    N=scanInt();
    map<int,vector<pair<int,int> > > map_x;
    map<int,int> map_y_count;
    while(N--)
    {
        x=scanInt(); y=scanInt();
        //printf("%d %d\n",x,y);
        //printf("..adding in map_x x=%d y=%d\n");
        map_x[x].push_back(make_pair(x,y));
        map_y_count[y]+=1;
    }
    //solving
    /*printf("..printing map_x\n");
    for(map<int,vector<pair<int,int> > >::iterator itr=map_x.begin();itr!=map_x.end();++itr)
    {
        printf("..x=%d, map[x].size=%d\n",itr->first,(itr->second).size());
    }
    printf("..printing map_y_count\n");
    for(map<int,int>::iterator itr= map_y_count.begin();itr!=map_y_count.end();++itr)
    {
        printf("..y=%d, count=%d\n",itr->first,itr->second);
    }*/
    for(map<int,vector<pair<int,int> > >::iterator itr=map_x.begin();itr!=map_x.end();++itr)
    {
        //printf("..checking x=%d, map[x].size=%d\n",itr->first,(itr->second).size());
        for(i=0;i<(itr->second).size();++i)
        {
            //printf("..for x=%d y=%d, adding %d*%d\n",(itr->second)[i].first,(itr->second)[i].second,(itr->second).size()-1,(map_y_count[(itr->second)[i].second]-1));
            ans+=((itr->second).size()-1)*1ll*(map_y_count[(itr->second)[i].second]-1);
            //printf("..ans=%lld\n",ans);
        }
    }
    printf("%lld",ans);
    return 0;
}