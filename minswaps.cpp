//minimum swaps needed to sort the array
#include<bits/stdc++.h>
using namespace std;
int minswaps(vector<int> arr)
{
    int result=0;
    int n = arr.size();
    pair<int,int> ap[n];
    for (int i = 0; i < n; i++){
        ap[i].first = arr[i];
        ap[i].second = i;
    }
    sort(ap,ap+n);
    vector<bool> visited(n,false);
    for(int i =0;i<n;i++)
    {
        int old_position = ap[i].second;
        if(visited[i] == true or old_position == i)
            continue;
        int node = i;
        int cycle=0;
        while (visited[node]==false)
        {
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle++;
        }
        result += cycle -1;
    }
    return result;
}
int main()
{
    vector<int> arr = {10,11,5,4,3,2,1};
    cout<<minswaps(arr)<<endl;
}