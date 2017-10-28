#include <bits/stdc++.h>

using namespace std;

int num[1000],m[1000];

int main() {
  int n;
  long long int k;
  cin>>n>>k;

  for(int i=0;i<n;i++){
    cin>>num[i];
    if(i==0) m[0]=num[0];
    else m[i]=m[i-1]=max(m[i-1],num[i]);

  }

  if(k>=n){
    cout<<m[n-1]<<endl;
    return 0;
  }

  int ans=n-1;

  for(int i=0;i<n;i++){
    if(i +k -1>=n) break;
 
    if(m[i]==m[i +k -1]) {
        ans=i;
        break;
    }
  }

  cout<< m[ans];


  return 0;
}
