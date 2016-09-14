#include<iostream>
#include "chains.cpp"
#include "chains.hpp"

using namespace std;

int main()
{
    int a,b,c,x0,y0;
    x0 = 0;
    y0 = 0;
    cin>>a>>b>>c;
    int l1,u1,t1,t2;
    cin>>l1>>u1;
    t1 = 0;
    t2 = 0;
    bool ifexists = true;
    chains(a,b,c,l1,u1,t1,t2,x0,y0,ifexists);
    int n;
    if(ifexists)
    {
        if(t1>t2)
        {
            int temp;
            temp = t1;
            t1 = t2;
            t2 = temp;
        }
        n = t2-t1+1;
        for(int i=0; i<n; i++)
        {
            cout<<x0-b*(i+t1)<<" ";
            cout<<y0+a*(i+t1)<<"\n";
        }
    }
    else
    {
        cout<<"No solution";
    

    }
}
