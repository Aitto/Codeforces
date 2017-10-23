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
#define readFile freopen("in.txt","r",stdin);;

using namespace std;


int main()
{
    int n;
    long long int ans=0,*d;

    sf("%d",&n);

    int **cost,*dist,*visit;
    cost=new int *[n+1];
    dist=new int[n+1];
    visit=new int[n+1];
    d=new long long int[n +1];

    for(int i=0;i<=n;i++) cost[i]=new int[n+1];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            sf( "%d",&cost[i][j] );

    visit[0]=1;
    for(int i=1;i<=n;i++) {
        sf("%d",&dist[i]);
        visit[i]=1;
    }

    for(int p=n;p>=1;p--){
        int k=dist[p];
        visit[k]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                //if(visit[i]==0 and visit[j]==0)
                    {
                    if(cost[i][k]==INF or cost[k][j]==INF) continue;
                    if(cost[i][j] > cost[i][k] + cost[k][j] )
                    {
                        cost[i][j]=cost[i][k] +cost[k][j];

                    }
                }
        }

        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(visit[i]==0 and visit[j]==0) ans+=cost[i][j];
            }
        }

        d[p]=ans;
    }

    for(int i=1;i<=n;i++)
        cout<<d[i]<< " ";


    return 0;
}
