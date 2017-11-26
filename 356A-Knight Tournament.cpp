/**
Author @Aitto_sang
CSE@Buet
******Segment Tree*******
*/
#include<stdio.h>
#include<iostream>
//#include<cmath>
//#include<cstdlib>
//#include<algorithm>
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
    int i=0,flag=1;

    while(1){
        flag=flag<<1;
        i++;
        if(flag>=n) return 1<<i;
    }
}

//Making segment Tree
void makeSegmentTree(int *segmentTree,int low,int high,int qlow,int qhigh,int pos,int value){
    if(segmentTree[pos]) return;
    if(high<qlow or low>qhigh) return;

    if( low==high) {
        if(!segmentTree[pos] and value!=low)
            segmentTree[pos]=value; //Assigning winner
        return;
    }

    int mid=(low +high)/2;
    makeSegmentTree(segmentTree,low,mid,qlow,qhigh,2*pos,value), makeSegmentTree(segmentTree,mid +1,high,qlow,qhigh,2*pos +1, value);
    segmentTree[pos]= segmentTree[2*pos] and segmentTree[2*pos +1];
}

//Printing segment Tree
void printSegmentTree(int *segMentTree,int low,int high,int pos){

    //for(int i=low;i<=high;i++) cout<<i<< " "<< segMentTree[i]<<endl;
    if(low == high){
        cout<< segMentTree[pos]<< " " ;
        return;
    }

    int mid=(low + high)/2;
    printSegmentTree(segMentTree,low,mid,2*pos), printSegmentTree(segMentTree,mid+1,high,2*pos +1);
}

int main(){
    syncronize

    int n,m,low,high,winner;

    cin>>n>>m;

    int *segmentTree;
    int len=2*nextTwoPower(n);

    //arr=new int[n +1];
    segmentTree=new int[len +1];

    //for(int i=0;i<n;i++) arr[i]=0;
    for(int i=0;i<=len;i++) segmentTree[i]=0;

    for(int i=0;i<m;i++){
        cin>>low>>high>>winner;
        makeSegmentTree(segmentTree,1,n,low,high,1,winner);
    }

    printSegmentTree(segmentTree,1,n,1);



    return 0;
}
