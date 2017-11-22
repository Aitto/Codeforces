#include<stdio.h>
#include<iostream>
//#include<cmath>
//#include<cstdlib>
//#include<algorithm>
//#include<stack>
#include<cstring>

#define lli long long int
#define pf printf
#define sf scanf
#define pi 3.141592653589793116
#define inf 99999999
#define maxInt 99999999
#define maxNEG -99999999.0
#define debug cout<<"Hello here!"<<endl;
#define readFile freopen("in.txt","r",stdin);

using namespace std;

long long int bigMod(long long int n,long long int p,long long int m){
    if(p==0) return 1;
    if(p%2){
        return ((n%m)*bigMod(n,p-1,m))%m;
    }else{
        long long int c=bigMod(n,p/2,m);
        return ((c%m)*(c%m))%m;
    }
}

int main(){

    lli n,m;
    short int k;

    cin>>n>>m>>k;

    if( k==-1 and (n%2!=m%2) ){
        /**
        If parity doesn't match then -1 won't be possible to make in all rows and columns;
        */
        pf("0\n");
    }else{
        lli a=bigMod(2,n-1,1000000007);
        lli b=bigMod(a,m-1,1000000007);

        cout<<b<<endl;
    }


    return 0;
}
