#include<iostream>
#include "solutions.hpp"
#include "solutions.cpp"
#include<math.h>

using namespace std;

void chains(int a,int b,int c,int l1,int u1,int &t1,int &t2,int &x,int &y,bool &ifposs) 
{
        int x0 = 0;
        int y0 = 0;
        ifposs = true;
        solution(a,b,c,x0,y0);
        x = x0;y = y0;
        if(x == 0 & y == 0 & c!= 0)
        {
            ifposs = false;
        }
        float t1_x,t2_x;
        float t1_y,t2_y;
        if(b>0)
        {
            t1_x = ceil(float(x-u1)/float(b));
            t2_x = floor(float(x-l1)/float(b));
        }
        else
        {
            t1_x = ceil(float(x-l1)/float(b));
            t2_x = floor(float(x-u1)/float(b));
        }
        if(a>0)
        {
            t1_y = ceil(float(l1-y)/float(a));
            t2_y = floor(float(u1-y)/float(a));
        }
        else
        {
            t1_y = ceil(float(u1-y)/float(a));
            t2_y = floor(float(l1-y)/float(a));
        }
        if(t1_x <= t1_y)
        {
            t1 = t1_y;
        }
        else
        {
            t1 = t1_x;
        }
        if(t2_x <= t2_y)
        {
            t2 = t2_x;
        }
        else
        {
            t2 = t2_y;
        }

        if(t1>t2)
        {
            ifposs = false;
        }
}

