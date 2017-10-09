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

int main(){

    int h,m,s,t1,t2;

    sf("%d %d %d %d %d",&h,&m,&s,&t1,&t2);

    if(t1==t2) pf("Yes\n");
    else if(t1 > t2){
        if( h>=t1 || h<t2 ){
            if( (m >= t1*5 || m< t2*5)){
                if( s >= t1*5 || s<=t2*5  ) pf("Yes\n");
                else pf("No\n");
            }else if( m== t2*5){
                if( s==0 ) pf("Yes");
                else pf("No\n");
            }else pf("No\n");
        }
        else if( h==t2 ){
            if(m==0 && s==0) pf("Yes\n");
            else if(m==0 && s!=0) pf("No\n");
            else if(s==0 && m!=0) pf("No\n");
            else if( (m>=t2*5 && m< t1*5) && s>=t2*5 && s<=t1*5 ) pf("Yes");
            else pf("No\n");
        }
        else{
            if( (m>=t2*5 && m<t1*5)){
                if (s>=t2*5 && s<=t1*5 ) pf("Yes\n");
                else pf("No\n");
            }
            else pf("No\n");
        }
    }else{
        if( h>=t2 || h<t1 ){
            if( (m >= t2*5 || m< t1*5)){
                if( s >= t2*5 || s<=t1*5  ) pf("Yes\n");
                else pf("No\n");
            }else if( m== t1*5){
                if( s==0 ) pf("Yes");
                else pf("No\n");
            }else pf("No\n");
        }
        else if( h==t1 ){
            if(m==0 && s==0) pf("Yes\n");
            else if(m==0 && s!=0) pf("No\n");
            else if(s==0 && m!=0) pf("No\n");
            else if( (m>=t1*5 && m< t2*5) && s>=t1*5 && s<=t2*5 ) pf("Yes");
            else pf("No\n");
        }
        else{
            if( (m>=t1*5 && m<t2*5)){
                if (s>=t1*5 && s<=t2*5 ) pf("Yes\n");
                else pf("No\n");
            }
            else pf("No\n");
        }
    }

    //main();

    return 0;
}
