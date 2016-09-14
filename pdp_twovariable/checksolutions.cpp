#include<iostream>
#include "solutions.hpp"
#include "solutions.cpp"

using namespace std;

int main()
{
    int a,b,c,x0,y0;
    x0 = 0;
    y0 = 0;
    cin>>a>>b>>c;
    solution(a,b,c,x0,y0);
    cout<<x0<<" "<<y0;
}
