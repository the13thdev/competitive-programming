#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int K;

map<pair<int,int>, vector<pair<int,int> > > map2d;
map<pair<int,int>, vector<pair<int,int> > >::iterator itr2d;
map<pair<int,int>, bool > visited2d;
map<pair<int, pair<int,int> >, vector<pair<int,pair<int,int> > > > map3d;
map<pair<int, pair<int,int> >, vector<pair<int,pair<int,int> > > >::iterator itr3d;
map<pair<int, pair<int,int> >, bool > visited3d;

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

pair<int,int> get2dPair(int x, int y)
{
    return make_pair(x,y);
}

pair <int, pair<int,int> > get3dPair(int x, int y, int z)
{
    return make_pair(x, make_pair(y,z));    
}

bool dfscheck3d(int x, int y, int z, int px, int py, int pz)
{
    int a,b,c,i;
    visited3d[get3dPair(x,y,z)]=true;
    //printf("..just visited (%d,%d,%d)\n",x,y,z);
    for(i=0;i<(map3d[get3dPair(x,y,z)]).size();++i)
    {
        a=(map3d[get3dPair(x,y,z)])[i].first; b=((map3d[get3dPair(x,y,z)])[i].second).first; c=((map3d[get3dPair(x,y,z)])[i].second).second;
        if(a!=px || b!=py || c!=pz)
        {
            if(visited3d[get3dPair(a,b,c)])
            {
                //printf("..found already visited node (%d,%d,%d), returning false\n",a,b,c);
                return false;
            }
            else
            {
                //printf("..going on to (%d,%d,%d)\n",a,b,c);
                if(!dfscheck3d(a,b,c,x,y,z))
                return false;
            }
        }
    }
    //printf("..all done, returning true for starting node (%d,%d,%d)\n",x,y,z);
    return true;
}

bool dfscheck2d(int x, int y, int px, int py)
{
    int a,b,i;
    visited2d[get2dPair(x,y)]=true;
    //printf("..just visited (%d,%d)\n",x,y);
    for(i=0;i<(map2d[get2dPair(x,y)]).size();++i)
    {
        a=(map2d[get2dPair(x,y)])[i].first; b=(map2d[get2dPair(x,y)])[i].second;
        if(a!=px || b!=py)
        {
            if(visited2d[get2dPair(a,b)])
            {
                //printf("..found already visited node (%d,%d), returning false\n",a,b);
                return false;
            }
            else
            {
                //printf("..going on to (%d,%d)\n",a,b);
                if(!dfscheck2d(a,b,x,y))
                return false;
            }
        }
    }
    //printf("..all done, returning true for starting node (%d,%d)\n",x,y);
    return true;
}


int main() {
    int x1,y1,z1,x2,y2,z2,i;
    K=scanInt();
    //printf("%d\n",K);
    for(i=0;i<K;++i)
    {
        x1=scanInt(); y1=scanInt(); z1=scanInt();
        x2=scanInt(); y2=scanInt(); z2=scanInt();
        map3d[get3dPair(x1,y1,z1)].push_back(get3dPair(x2,y2,z2));
        map3d[get3dPair(x2,y2,z2)].push_back(get3dPair(x1,y1,z1));
        if(x1!=x2 || y1!=y2)
        {
        if(map2d.find(get2dPair(x1,y1))==map2d.end() ||  find(map2d[get2dPair(x1,y1)].begin(),map2d[get2dPair(x1,y1)].end(), get2dPair(x2,y2))== map2d[get2dPair(x1,y1)].end())
        {
            map2d[get2dPair(x1,y1)].push_back(get2dPair(x2,y2));
        }
        if(map2d.find(get2dPair(x2,y2))==map2d.end() ||  find(map2d[get2dPair(x2,y2)].begin(),map2d[get2dPair(x2,y2)].end(), get2dPair(x1,y1))== map2d[get2dPair(x2,y2)].end())
        {
            map2d[get2dPair(x2,y2)].push_back(get2dPair(x1,y1));
        }
        }
        visited3d[get3dPair(x1,y1,z1)]=false;
        visited3d[get3dPair(x2,y2,z2)]=false;
        visited2d[get2dPair(x1,y1)]=false;
        visited2d[get2dPair(x2,y2)]=false;
        //printf("%d %d %d %d %d %d\n",x1,y1,z1,x2,y2,z2);
    }
    /*
    //printf("..printing 3d map:\n");
    for(itr3d = map3d.begin(); itr3d!=map3d.end(); ++itr3d)
    {
        //printf(" (%d,%d,%d): ", (itr3d->first).first, ((itr3d->first).second).first, ((itr3d->first).second).second );
        for(i=0;i<(itr3d->second).size();++i)
        {
            //printf("(%d,%d,%d) ", (itr3d->second)[i].first, ((itr3d->second)[i].second).first, ((itr3d->second)[i].second).second);
        }
        //printf("\n");
    }
    //printf("..printing 2d map:\n");
    for(itr2d = map2d.begin(); itr2d!=map2d.end(); ++itr2d)
    {
        //printf(" (%d,%d): ", (itr2d->first).first, (itr2d->first).second );
        for(i=0;i<(itr2d->second).size();++i)
        {
            //printf("(%d,%d) ", (itr2d->second)[i].first, (itr2d->second)[i].second);
        }
        //printf("\n");
    }*/
    bool has3dchain=false, has2dchain=false;
    //checking for 3d chain (cycle)
    for(itr3d = map3d.begin(); itr3d!=map3d.end(); ++itr3d)
    {
        x1=(itr3d->first).first; y1=((itr3d->first).second).first, z1=((itr3d->first).second).second;
        if(!visited3d[get3dPair(x1,y1,z1)])
        {
            //printf("..(%d,%d,%d) not visited\n", x1,y1,z1);
            if(!dfscheck3d(x1,y1,z1,-1,-1,-1))
            {
                has3dchain=true;
                break;
            }
        }
    }   
    //checking for 2d chain (cycle)
    for(itr2d = map2d.begin(); itr2d!=map2d.end(); ++itr2d)
    {
        x1=(itr2d->first).first; y1=(itr2d->first).second;
        if(!visited2d[get2dPair(x1,y1)])
        {
            //printf("..(%d,%d) not visited\n", x1,y1);
            if(!dfscheck2d(x1,y1,-1,-1))
            {
                has2dchain=true;
                break;
            }
        }
    }    
    if(has3dchain)
    printf("True closed chains\n");
    else
    printf("No true closed chains\n");
    if(has2dchain)
    printf("Floor closed chains\n");
    else
    printf("No floor closed chains\n");
    return 0;
}