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

lli sum;
int n,p,k;

lli pow(int a,int b){
    lli ans=1;
    while(b--) ans*=a;
    return ans;
}

bool checkPalindrome(int num){
    int n=num,number=0;

    while(num!=0){
        number=number*10 + num%10;
        num=num/10;
    }

    if(n==number) return true;
    return false;

}

void sumPalindrome(lli num,int l,int r,int digits){
    if(l<=r or num==0) return;
    cout<< "num: "<<num<<" lr: "<<l << " "<<r<<endl;

    if(l-1==r){
        for(int i=0;i<=9;i++){
            sum+=num + (i*pow(10,l-1)) + (i*pow(10,r-1));
            sum=sum%p;
            cout<<"num is: "<<num<< " summing 2: "<<num + (i*pow(10,l-1)) + (i*pow(10,r-1))<<" sum is: "<<sum<<endl;
            k++;
            if(k==n) return;
        }
    }

    if(digits>=4){
        int x=num;
        for(int i=0;i<=9;i++){
            if(k==n) return;
            //sum+= num + i*pow(10,l-1) + i*pow(10,r-1);
            num=x+ (i*pow(10,l-1)) + (i*pow(10,r-1));
            cout<<"num is: "<<num<< endl;
            sumPalindrome(num,l-1,r+1,digits-2);
        }
    }

}


int main(){
    syncronize

    k=0;
    int digits=2;
    cin>>n>>p;
    sum=0;

    while(true){
        if(k==n) break;

        for(int i=1;i<=9;i++){
            lli x=(i*pow(10,digits-1)) +i;
            cout<<"sending : "<<x<<endl;
            if(digits==2){
                sum+=x;
                sum=sum%p;
                k++;
            }else sumPalindrome(x,digits,1,digits);
            if(k==n) break;

        }
        digits+=2;
    }

    cout<<sum<<endl;


    return 0;
}
