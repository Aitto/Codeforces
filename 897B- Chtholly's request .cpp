/**
Author @Aitto_sang
CSE@Buet
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

lli pow(lli n,int digits){
    lli ans=1;
    while(digits--) ans*=n;
    return ans;
}

lli make_reverse(lli n){
    lli ans=0;
    while(n!=0){
        ans= (ans*10) + n%10;
        n=n/10;
    }
    return ans;
}


int main(){
    syncronize

    int n,p;
    lli sum=0;

    cin>>n>>p;

    for(int i=1;i<=n;i++){
        int digits=0,tp=i;
        while(tp!=0){
            digits++;
            tp=tp/10;
        }

        sum+=(i*pow(10,digits)) + make_reverse(i);
        sum=sum%p;
    }

    cout<<sum<<endl;


    return 0;
}
