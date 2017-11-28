/**
Author @Aitto_sang
CSE@Buet
*/
#include<stdio.h>
#include<iostream>
//#include<cmath>
//#include<cstdlib>
#include<algorithm>
//#include<stack>
//#include<cstring>
//#include<bits/stdc++.h>

#define lli long long int
#define pf printf
#define sf scanf
#define pi 3.141592653589793116
#define inf 1e9
#define linf 1e15
#define NULL_VALUE -999999
#define maxNEG -99999999.0
#define debug cout<<"Hello here!"<<endl;
#define readFile freopen("in.txt","r",stdin);
#define syncronize ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int nextTwoPower(int n){
    int i=1,flag=1;
    while(1){
        flag=flag<<1;
        i++;
        if(flag>=n) return 1<<i;
    }
}


int createSegmentTree(int *segmentTree,int *arr,int low,int high,int pos,int *track){
    if(low==high){
        segmentTree[pos]=arr[low];
        return 1;
    }

    int mid=(low +high)/2;

    int x=createSegmentTree(segmentTree,arr,low,mid,2*pos,track);
    createSegmentTree(segmentTree,arr,mid +1,high,2*pos +1,track);
    track[pos]=x;

    if(x & 1) segmentTree[pos]=segmentTree[2*pos] | segmentTree[2*pos +1];
    else segmentTree[pos]=segmentTree[2*pos] ^ segmentTree[2*pos +1];

    return x+1;
}

void updateSegmentTree(int *segmentTree,int low,int high,int qlow,int qhigh,int pos,int value,int *track){

    if(low>qhigh or high<qlow) return;
    if(low==high){
        segmentTree[pos]=value;
        return;
    }

    int mid=(low + high)/2;

    updateSegmentTree(segmentTree,low,mid,qlow,qhigh,2*pos,value,track), updateSegmentTree(segmentTree,mid +1, high,qlow,qhigh,2*pos +1,value,track);
    if(track[pos] & 1) segmentTree[pos]=segmentTree[2*pos] | segmentTree[2*pos +1];
    else segmentTree[pos]=segmentTree[2*pos] ^ segmentTree[2*pos +1];

}

int main(){
    syncronize

    int n,m,len,pos,val;
    cin>>n>>m;

    int *arr,*segmentTree,*track;

    n=pow(2,n);
    len=nextTwoPower(n);

    arr=new int[n +1];
    segmentTree=new int[len +1];
    track=new int[len +1];

    for(int i=1;i<=n;i++) cin>>arr[i];
    createSegmentTree(segmentTree,arr,1,n,1,track);

    for(int i=1;i<=m;i++) cin>>pos>>val, updateSegmentTree(segmentTree,1,n,pos,pos,1,val,track), cout<<segmentTree[1]<<endl;

    return 0;
}
