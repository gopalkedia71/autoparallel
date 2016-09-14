#include<iostream>
#include<vector>
#include "chains.hpp"
#include "two.cpp"
#include "two.hpp"
#include "chains.cpp"

using namespace std;

int main()
{
    int a[2],b[2],c[2],l[2],u[2],d;
    vector<vector<int> > lpairs;
    vector<vector<int> > rpairs;
    vector<vector<int> > index;
    vector<int> tmp;
    for(int i=0; i<2; i++)
    {
        cin>>a[i]>>b[i]>>l[i]>>u[i];
    }
    cin>>d;
    int low[2],upp[2];
    for(int i=0; i<2; i++)
    {
        if(a[i]>0 && b[i]>0)
        {
            low[i] = a[i]*l[i] + b[i]*l[i];
            upp[i] = a[i]*u[i] + b[i]*u[i];
        }
        else if(a[i]>0 && b[i]<0)
        {
            low[i] = a[i]*l[i] + b[i]*u[i];
            upp[i] = a[i]*u[i] + b[i]*l[i];
        }
        else if(a[i]<0 && b[i]<0)
        {
            low[i] = a[i]*u[i] + b[i]*l[i];
            upp[i] = a[i]*l[i] + b[i]*u[i];
        
        }
        else
        {
            low[i] = a[i]*u[i] + b[i]*u[i];
            upp[i] = a[i]*l[i] + b[i]*l[i];
        }
    }
    int c_low,c_upp;
    bool c_exists;
    two(low[0],low[1],upp[0],upp[1],d,c_low,c_upp,c_exists);
    //cout<<c_low<<" "<<c_upp<<"\n";

    int tl[2],tu[2],x[2],y[2];
    int tdiff[2];
    if(c_exists)
    {
        for(int c_now=c_low; c_now<=c_upp; c_now++)
        {
            c[0] = c_now;
            c[1] = d-c_now;
            bool ifposs[2];
            for(int i = 0; i<2; i++)
            {
                ifposs[i]=true;
                tl[i]=0;tu[i]=0;
                x[i]=0;y[i]=0;
                if(ifsol(a[i],b[i],c[i]))
                {
                    chains(a[i],b[i],c[i],l[i],u[i],tl[i],tu[i],x[i],y[i],ifposs[i]);
                    if(ifposs[i])
                    {
                        tdiff[i]=tu[i]-tl[i]+1;
                    }
                    else
                    {
                        tdiff[i] = 0;
                    }
                }
            }
            for(int i=0; i<tdiff[0]; i++)
            {
                for(int j=0; j<tdiff[1]; j++)
                {
                    tmp.clear();
                    tmp.push_back(x[0]-b[0]*(i+tl[0]));
                    tmp.push_back(x[1]-b[1]*(j+tl[1]));
                    lpairs.push_back(tmp);
                    tmp.clear();
                    tmp.push_back(y[0]+a[0]*(i+tl[0]));
                    tmp.push_back(y[1]+a[1]*(j+tl[1]));
                    rpairs.push_back(tmp);
               }
            }
        }
        cout<<lpairs.size()<<"\n";
        for(int i=0; i<lpairs.size(); i++)
        {
            for(int j=0; j<lpairs[i].size(); j++)
            {
                cout<<lpairs[i][j]<<" ";
            }
            for(int k=0; k<lpairs[i].size(); k++)
            {
                cout<<rpairs[i][k]<<" ";
            }
            cout<<"\n";
        }
    }
    for(int i = 0; i < lpairs.size(); i++)
    {
        for(int j = 0; j< lpairs.size(); j++)
        {
            if((((lpairs[i][0] == lpairs[j][0]) && (lpairs[i][1] == lpairs[j][1])) || ((lpairs[i][0] == rpairs[j][0]) && (lpairs[i][1] == rpairs[j][1])) || ((rpairs[i][0] == rpairs[j][0]) && (rpairs[i][1] == rpairs[j][1]))) && i!=j)
            {
                bool if_i_present = true;
                bool if_j_present = true;
                int i_present = -1;
                int j_present = -1;
                for(int k = 0; k<index.size() ; k++)
                {
                    for(int l = 0; l<index[k].size(); l++)
                    {
                        if(i == index[k][l])
                        {
                            i_present = k;
                            if_i_present = false;
                        }
                        if(j == index[k][l])
                        {
                            j_present = k;
                            if_j_present = false;
                        }
                    }
                }
                if( if_i_present && if_j_present)
                {
                    tmp.clear();
                    tmp.push_back(i);
                    tmp.push_back(j);
                    index.push_back(tmp);
                }
                else if(if_i_present)
                {
                    index[j_present].push_back(i);
                }
                else if(if_j_present)
                {
                    index[i_present].push_back(j);
                }

            }
        }
    }

    for(int i = 0; i<index.size() ; i++)
    {
        for(int j = 0; j<index[i].size(); j++)
        {
            cout<<index[i][j]<<" ";
        }
        cout<<"\n";
    }

    
}
