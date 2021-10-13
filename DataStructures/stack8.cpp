//Stock span problem
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    stack<pair<int,int>> s2;
    vector<int>right;
    for(int i=n-1;i>=0;i--)
    {
        if(s2.size()==0)
        {
            right.push_back(n);
        }
        else if(s2.size()>0 && s2.top().first<arr[i])
        right.push_back(s2.top().second);
        else if(s2.size()>0 && s2.top().first>=arr[i])
        {
            while(s2.size()>0 && s2.top().first>=arr[i])
            {
                s2.pop();
            }
            if(s2.size()==0)
            right.push_back(n);
            else
            right.push_back(s2.top().second);
        }
        s2.push({arr[i],i});
    }
    reverse(right.begin(),right.end());
    for(auto i:right)
    {
        cout<<i<<" ";
    }
    return (0);
}