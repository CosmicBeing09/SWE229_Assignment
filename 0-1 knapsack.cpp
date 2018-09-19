/*
4 10
1 120
4 280
3 150
4 200
*/
#include<bits/stdc++.h>

using namespace std;

int capacity,item;
int cost[80],weight[80];

int knapSack(int i,int w)
{
    int profit1=0,profit2=0;
    if(i>item)
        return 0;


    if(w+weight[i]<=capacity)
    {
        profit1 = cost[i]+knapSack(i+1,w+weight[i]);
    }
    profit2 = knapSack(i+1,w);
    return max(profit1,profit2);
}

main()
{


    cin>>item>>capacity;
    for(int i=0; i<item; i++)
    {
        scanf("%d%d",&weight[i],&cost[i]);
    }

    int ans = knapSack(0,0);
    cout<<ans<<endl;
}
