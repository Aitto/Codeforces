#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>

#define pf printf
#define sf scanf
#define pi acos(-1.0)

#define matched 10009919


using namespace std;

int match(string str,char pass[]){

    //cout <<0 <<": "<<pass[0]<<" 1: "<<pass[1]<<endl;
    if(str[0]==pass[0] && str[1]==pass[1]) return matched;
    if(str[0]==pass[1] && str[1]==pass[0]) return matched;
    if(str[0]==pass[1]) return 1;
    if(str[1]==pass[0]) return 2;
    else return -1;
}

int main(){

    int t,c=0,x;

    bool flag=false;

    string password;

    cin>>password>>t;
    char tmp[3];


    for(int i=0;i<t;i++){
        cin>>tmp;
        x=match(password,tmp);
        //cout<< "x: "<<x<<endl;
        if(x!=-1 && c==0 ) c+=x;
        else if( (c==1 && x==2) || (c==2 && x==1) ) c+=x;
        if(x==matched || c==3) flag=true;
    }

    if(flag) pf("YES\n");
    else pf("NO\n");


    return 0;

}
