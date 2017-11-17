#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<stack>
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

    readFile

    int x=0,y=0,n,c,ans=0,counter=0;
    char ch;

    cin>>n;
    c=n;

    while(n--){
        cin>>ch;

        switch(ch){
        case 'U':
            y++;
            counter++;
            break;
        case 'D':
            y--;
            counter++;
            break;
        case 'L':
            x--;
            counter++;
            break;
        case 'R':
            x++;
            counter++;
        }


    }
    ans=c-abs(x)-abs(y);
    cout<<ans<<endl;

}

/**
88
LLUUULRDRRURDDLURRLRDRLLRULRUUDDLLLLRRDDURDURRLDURRLDRRRUULDDLRRRDDRRLUULLURDURUDDDDDLDR

*/
