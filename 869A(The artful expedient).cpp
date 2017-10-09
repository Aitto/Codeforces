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

#define pi 3.141592653589793116
#define maxREAL 9999999.0
#define INF 99999999
#define maxNEG -99999999.0

#define debug cout<<"Hello here!"<<endl;
#define newl pf("\n");

using namespace std;

int x[2097152],y[2097152];

int main(){

    int n;
    sf("%d",&n);
    int xx[n],yy[n];

    for(int i=0;i<n;i++){
        sf("%d",&xx[i]);
        x[xx[i]]++;
    }
    for(int i=0;i<n;i++){
        sf("%d",&yy[i]);
        y[yy[i]]++;
    }

    int sum=0;
    int t;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            t=xx[i]^yy[j];

            if( x[t]!=0 || y[t]!=0 ){
                sum++;
            }
        }
    }

    if(sum%2) pf("Koyomi\n");
    else pf("Karen\n");

    return 0;
}
