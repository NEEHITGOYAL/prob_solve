#include<vector>
#include<algorithm>
#include<climits>
#include<iostream>
using namespace std;

pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0;
    int j=0;
    pair<int,int> ans ;
    int result = INT_MAX;
    while (i<a.size() && j<b.size())
    {
        if( abs(a[i] - b[j]) < result)
        {
            result = abs(a[i] - b[j]);
            ans = make_pair(a[i],b[j]);
        }
        if(a[i] < b[j])
            i++;
        else
            j++;
    }
    return ans;
}
int main()
{
    vector<int> A = {1, 3, 15, 11, 2};
    vector<int> B = {23, 127, 235, 19, 8};
    pair<int,int>result = minDifference(A,B);
    cout<<result.first<<" "<<result.second<<endl; 
}