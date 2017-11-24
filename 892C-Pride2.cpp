#include<bits/stdc++.h>

using namespace std;

int arr[2005];
int n=0;

int main(){
    //ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);

    cin>>n;
    int d=0;
    for(int i=0;i<n;i++) cin>>arr[i], d=__gcd(d,arr[i]);

    if(d>1) return cout<<-1<<endl, 0;
    int ans=0;
    for(int i=0;i<n;i++) if(arr[i]!=1) ans++;

    if(ans!=n) return cout<<ans<<endl,0;

    ans=1e9;

    for(int i=0;i<n;i++){
        d=0;
        for(int j=i;j<n;j++){
            d=__gcd(d,arr[j]);
            if(d==1) {
                ans=min(ans,n-1 + j-i);
                //cout<< "hello"<<endl;
                break;
            }
        }
    }

    cout<< ans<<endl;

    return 0;
}
