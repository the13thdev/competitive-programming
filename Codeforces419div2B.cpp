#include <cstdio>
#include <iostream>
#include <string>

#define lim 200000

using namespace std;

int segmentTree[524288];
int lazy[524288];
int k;

void createSegmentTree(int idx, int l, int r)
{
    //printf("..creating at idx %d from l=%d to r=%d\n",idx,l,r);
    if(l==r)
    {
        segmentTree[idx]=0;
        lazy[idx]=0;
    }
    else
    {
        int mid=l+(r-l)/2;   
        createSegmentTree(2*idx+1,l,mid);
        createSegmentTree(2*idx+2,mid+1,r);
        segmentTree[idx]=segmentTree[2*idx+1]+segmentTree[2*idx+2];
        lazy[idx]=0;
    }
}


void changeSegmentTree(int idx, int l, int r)
{
    if(lazy[idx]!=0)
    {
        segmentTree[idx] += (r-l+1)*lazy[idx];
        if(l!=r)
        {
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    
    //printf("..changing at idx=%d l=%d to r=%d val=%d\n",idx,l,r,segmentTree[idx]);
    if(l==r)
    {
        if(segmentTree[idx]>=k)
        segmentTree[idx]=1;
        else
        segmentTree[idx]=0;
    }
    else if(segmentTree[idx]!=0)
    {
        int mid=l+(r-l)/2;   
        changeSegmentTree(2*idx+1,l,mid);
        changeSegmentTree(2*idx+2,mid+1,r);
        segmentTree[idx]=segmentTree[2*idx+1]+segmentTree[2*idx+2];
    }
    //printf("..changed val at idx=%d l=%d to r=%d val=%d\n",idx,l,r,segmentTree[idx]);
}

int queryTree(int idx, int l, int r, int qL,int qR)
{
    if(r<qL || qR<l)
    {
        return 0;
    }
    else if(l>=qL && r<=qR)
    {
        return segmentTree[idx];
    }
    else
    {
        int mid=l+(r-l)/2;
        return queryTree(2*idx+1,l,mid,qL,qR)+queryTree(2*idx+2,mid+1,r,qL,qR);
    }
}

void updateRange(int idx, int l, int r, int uL,int uR)
{
    if(lazy[idx]!=0)
    {
        segmentTree[idx] += (r-l+1)*lazy[idx];
        if(l!=r)
        {
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    
    //printf("..updating idx=%d l=%d r=%d uL=%d uR=%d\n",idx,l,r,uL,uR);
        
    if(r<uL || uR<l)
    {
        //do nothing
    }
    else if(l>=uL && r<=uR)
    {
        segmentTree[idx] += (r-l+1)*1;
        if(l!=r)
        {
            lazy[2*idx+1]+=1;
            lazy[2*idx+2]+=1;
        }
    }
    else
    {
        int mid=l+(r-l)/2;
        updateRange(2*idx+1,l,mid,uL,uR);
        updateRange(2*idx+2,mid+1,r,uL,uR);
        segmentTree[idx] = segmentTree[2*idx+1]+segmentTree[2*idx+2];
    }
    //printf("updating idx=%d l=%d r=%d uL=%d uR=%d val=%d\n",idx,l,r,uL,uR,segmentTree[idx]);
}

int main() {
    int n,q,l,r,i;
    scanf("%d%d%d",&n,&k,&q);
    createSegmentTree(0,1,lim);
    //printf("%d %d %d\n",n,k,q);
    for(i=0;i<n;++i)
    {
        scanf("%d%d",&l,&r);
        updateRange(0,1,lim,l,r);
        //printf("%d %d\n",l,r);
    }
    changeSegmentTree(0,1,lim);
    
    //printf("checking idx=%d l=%d r=%d val=%d\n",0,1,200000,segmentTree[0]);
    for(i=0;i<q;++i)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",queryTree(0,1,lim,l,r));
    }
	return 0;
}