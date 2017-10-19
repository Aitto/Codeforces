#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<cstring>

#define pf printf
#define sf scanf
#define pi 3.141592653589793116
#define INF 99999
#define maxInt 99999999
#define maxNEG -99999999.0
#define debug cout<<"Hello here!"<<endl;
#define readFile freopen("in.txt","r",stdin);

using namespace std;



int main(){

    int n,k,m,x,index=-1,remind;
    bool flag=true;

    cin>>n>>k>>m;

    int *num,*track;
    num=new int[n+1];

    track=new int[m];
    for(int i=0;i<m;i++) track[i]=0;

    //for(int i=0;i<m;i++) num[i]=new int[k+1];


    for(int i=0;i<n;i++) {
        sf("%d",&x);
        num[i]=x;
        if(flag){
                remind=x%m;
                //num[remind][track[remind]]=x;
                track[remind]++;
                if(track[remind] == k){
                    flag=false;
                    index=remind;
                }
        }
    }

    if(index==-1){
        pf("No\n");
    }else{
        pf("Yes\n");
        for(int j=0,i=0;i<n;i++) {
            if(num[i]%m==index) {
                if(j==k) break;
                pf("%d ", num[i]);
                j++;
            }
        }
        cout<<endl;
    }


    return 0;

}
