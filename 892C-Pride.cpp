#include<stdio.h>
#include<iostream>

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

int gcd(int x,int y){
    if(x==0) return y;
    if(y==0) return x;
    if(x<y){
        return gcd(y%x,x);
    }else return gcd(x%y,y);
}

//lcm= (a*b)/gcd(a,b);

int main(){

    int n,flag=0,distance=0,mini=inf,nonone=0,gi;
    int *arr,*g; 
    cin>>n; //Input size
    arr=new int[n];
    g=new int[n];
  
    //Input array
    for(int i=0;i<n;i++){
        cin>>arr[i];
        g[i]=-1;
        if(arr[i]!=1) nonone++;
    }
    
  //If 1 exist in array then print n- no_of_ones = nonone;
    if(nonone!=n){
        cout<<nonone<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            gi=gcd(arr[i],arr[j]);
            if(gi==1){
                flag=1;
                if(j-i < mini) mini=j-i;
                if(mini==1) break;
            }

            //arr[j]=gcd(arr[i],arr[j]);
        }
    }
    g[n-1]=arr[n-1];
    
  //If gcd 1 is possible
    if( flag ){
        cout<<n-1+mini<<endl;
    }else{
      
      //Else trying to make gcd by gcd... second try
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                if(g[i]==-1) {
                    g[i]=gcd(arr[i],arr[j]);
                    j++;
                }
                if(gcd(g[i],arr[j])==1){
                    flag=1;
                    if(j-i < mini) mini=j-i;
                    if(mini==1) break;
                }
            }
        }
        if( flag ){
        cout<<n-1+mini<<endl;
        }
      //not possible
        else cout<<-1<<endl;
    }

    return 0;
}
