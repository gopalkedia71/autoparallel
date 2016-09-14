#include<iostream>
#include<vector>
#include "chains.hpp"
#include "solutions.hpp"
#include "chains.cpp"

using namespace std;

int main()
{
    int a[2],b[2],c[2],l1[2],u1[2];
    int t1[2],t2[2],x[2],y[2];
    bool ifposs[2];
    int n[2],count[2];
    vector<int> u[2],v[2];
    vector<vector<int> > output[2];
    vector<int> index1[2];
    vector<int> index2[2];
    for(int i = 0;i<2;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>l1[i]>>u1[i];
        ifposs[i] = true;
        t1[i] = 0;t2[i] = 0;
        x[i] = 0;y[i] = 0;
        count[i] = 0;
    }
    for(int i = 0;i<2;i++)
    {
        if(ifsol(a[i],b[i],c[i]))
        {
            chains(a[i],b[i],c[i],l1[i],u1[i],t1[i],t2[i],x[i],y[i],ifposs[i]);
            if(ifposs[i])
            {
                cout<<"The solution for the case: "<<i+1<<" is:"<<"\n";
                if(t1[i]>t2[i])
                {
                    int temp;
                    temp = t2[i];
                    t2[i] = t1[i];
                    t1[i] = temp;
                }
                n[i] = t2[i]-t1[i]+1;
                for(int j = 0;j<n[i];j++)
                {
                    u[i].push_back(x[i]-b[i]*(j+t1[i]));
                    v[i].push_back(y[i]+a[i]*(j+t1[i]));
                    cout<<u[i][j]<<" "<<v[i][j]<<"\n";
                }
                for(int j = 0;j<n[i];j++)
                {
                    for(int k = 0;k<n[i];k++)
                    {
                        if(v[i][k] == u[i][j] && j!=k)
                        {
                            index2[i].push_back(k);
                            index1[i].push_back(j);
                        }
                    }                                        
                }
                cout<<"the chain"<<"\n";
                bool repeat[index2[i].size()];
                for(int j = 0; j<index2[i].size();j++)
                {
                    repeat[j] = true;
                }
                for(int j = 0; j<index2[i].size();j++)
                {
                    for(int k = 0; k<index2[i].size();k++)
                    {
                        if(index2[i][j] == index1[i][k])
                        {
                            if(index1[i][j] == index2[i][k])
                            {
                                repeat[k] = false;
                            }
                            else
                            {
                                if(repeat[j] == true)
                                    repeat[j] = false;
                            }
                        }
                    }
                    if(repeat[j])
                    {
                        vector<int> temp;
                        int l = index2[i][j];
                        int m = index1[i][j];
                        temp.push_back(u[i][l]);
                        temp.push_back(v[i][l]);
                        bool repeats = true;
                        while(v[i][l] == u[i][m])
                        {
                            for(int h = 0; h<temp.size();h++)
                            {
                                if(v[i][m] == temp[h])
                                    repeats = false;
                            }
                            if(!repeats)
                                break;
                            temp.push_back(v[i][m]);
                            int tmp;
                            tmp = l;
                            l = m;
                            bool check = false;
                            for(int o = 0; o<index2[i].size();o++)
                            {
                                if(m == index2[i][o])
                                {
                                    check = true;
                                    m = index1[i][o];
                                    break; 
                                }
                            }
                            if(!check)
                            {
                                break;
                            }
                        }
                        output[i].push_back(temp);
                    }
                }
                for(int j = 0 ;j< n[i]; j++)
                {
                    bool check2 = true;
                    for(int k = 0; k<index2[i].size();k++)
                    {
                        if(j == index2[i][k])
                        {
                            check2 = false;
                            break;
                        }
                        if(j == index1[i][k])
                        {
                            check2 = false;
                            break;
                        }
                    }
                    if(check2)
                    {
                        if(u[i][j] != v[i][j])
                        {
                            vector<int> temp;
                            temp.push_back(u[i][j]);
                            temp.push_back(v[i][j]);
                            output[i].push_back(temp);
                        }
                        else
                        {
                            vector<int> temp;
                            temp.push_back(u[i][j]);
                            output[i].push_back(temp);
                        }
                    }
                
                }
                for(int j = 0; j<output[i].size();j++)
                {
                    for(int k = 0; k<output[i][j].size();k++)
                    {
                        cout<<output[i][j][k]<<" ";
                    }
                    cout<<"\n";
                }
                
            }
                        else
            {
                cerr<<"No possible solution in the given range for the case "<<i+1<<"\n";
            }

        }
        else
        {
            cerr<<"No solution exists for the case "<<i+1<<"\n";
        }
    }
    cout<<"the intersection"<<"\n";
    int num = 0;
    for(int i = 0; i<output[0].size();i++)
    {
        for(int j = 0; j<output[0][i].size();j++)
        {
            for(int k = 0; k<output[1].size(); k++)
            {
                for(int l = 0; l<output[1][k].size();l++)
                {
                    if(output[0][i][j] == output[1][k][l] && output[0][i][j+1] == output[1][k][l+1] && j!= output[0][i].size()-1 && l!= output[1][k].size()-1)
                    {
                        cout<<output[0][i][j]<<" "<<output[0][i][j+1];
                        num++;
                        int m = j+1;
                        int n = l+1;
                        while(output[0][i][m] == output[1][k][n] && output[0][i][m+1] == output[1][k][n+1] && m!= output[0][i].size()-1 && n!= output[1][k].size()-1)
                        {
                            cout<<" "<<output[0][i][m+1];
                            m++;
                            n++;
                        }
                        cout<<"\n";
                        j = m;
                        break;
                    }
                    if(output[0][i][j] == output[1][k][l] && output[0][i][j+1] == output[1][k][l-1] && j!= output[0][i].size()-1 && l!= 0) 
                    {
                        cout<<output[0][i][j]<<" "<<output[0][i][j+1];
                        num++;
                        int m = j+1;
                        int n = l-1;
                        while(output[0][i][m] == output[1][k][n] && output[0][i][m+1] == output[1][k][n-1] && m!= output[0][i].size()-1 && n!= 0)
                        {
                            cout<<" "<<output[0][i][m+1];
                            m++;
                            n--;
                        }
                        cout<<"\n";
                        j = m;
                    }
                }
            }
        }
    }
    cerr<<"The number of intersection is "<<num<<"\n";


}
