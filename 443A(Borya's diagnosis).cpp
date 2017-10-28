#include<bits/stdc++.h>

using namespace std;

int s[1005], d[1005];

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++) cin>>s[i]>>d[i];

    int ans=0;
    for(int i=0;i<n;i++){

            if(s[i] >ans) ans=s[i] ;
            else{
                int j=0;

                while(s[i]  + j*d[i] <= ans){
                    j++;
                    //if(j==n) break;
                }
                ans=s[i] + j*d[i];
            }
    }

    cout<<ans;

    return 0;
}
