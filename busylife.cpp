#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}

int countActivites(vector<pair<int,int> > activities){
    //Complete this method
    int k,count,n;
    count=1;
    n = activities.size();
    sort(activities.begin(),activities.end(),compare);
    k=0;
    for(int i=1;i<n;i++)
    {
        if(activities[k].second<=activities[i].first)
        {
            count++;
            k=i;
        }
    }
    return count;
}
int main()
{
    vector<pair<int,int>> test = {{10,20},{12,15},{20,30}};
    cout<<countActivites(test)<<endl;
}