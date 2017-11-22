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

int main(){

    int n,Q[101],A[101],q=0,a=0,ans=0;

    for(int i=0;i<=100;i++){
        Q[i]=-1;
        A[i]=-1;
    }
    string arr;
    cin>>arr;
    n=arr.length();

    for(int i=0;i<n;i++){
        //cin>>arr[i];
        if(arr[i]=='Q'){
            Q[q]=i;
            q++;
        }else if(arr[i]=='A'){
            A[a]=i;
            a++;
        }
    }
    
    if(q==0 or a==0){
        pf("0\n");
        return 0;
    }else{
        for(int i=0;i<a;i++){
            int index=A[i],m1=0,m2=0,j=0;
            while(Q[j]<index) {
                m1++;
                j++;
            }
            while(j<n){
                m2++;
                j++;
                if(Q[j]==-1) break;
            }
            ans+=m1*m2;
        }
    }

    cout<<ans<<endl;

    return 0;
}
