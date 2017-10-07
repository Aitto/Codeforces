#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>

#define pf printf
#define sf scanf
const int sz=100002;

#define pi 3.141592653589793116
#define maxREAL 9999999.0
#define INF 99999999
#define maxNEG -99999999.0

#define debug cout<<"Hello here!"<<endl;
#define newl pf("\n");

using namespace std;

long long dp[sz];
map<long long,long long> track;


int main(){

    long long t,c;

    cin>>t;

    for(int i=0;i<t;i++){
        cin>>c;
        track[c]++;
    }

    memset(dp,-1,sizeof(dp));

    dp[0]=0;
    dp[1]=track[1];

    for(int i=2;i<100001;i++){
        dp[i]=max( dp[i-1], dp[i-2] + i*track[i] );
    }

    cout<<dp[100000]<<endl;

    return 0;
}
