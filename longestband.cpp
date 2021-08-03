// given an array containing N integers find length of longest band 
// A band is a subsequence which can be reordered in such a manner aa elems appear
// consecutive (i.e. with asbsolute difference of 1 b/w them)
#include<bits/stdc++.h>
using namespace std;
int band(vector<int> arr)
{
    int cnt =0;
    int longest_band = 0;
    unordered_set<int> s;
    for( auto x:arr)
        s.insert(x);
    for(auto elem: s)
    {
        int parent = elem - 1;
        int child = elem +1;
        if(s.find(parent) == s.end())
        {
            cnt =1;
            while(1)
            {
                if(s.find(child) != s.end())
                {
                    cnt++;
                    child++;
                }
                else
                    break;
            }
        }
        longest_band = max(longest_band,cnt);
    }
    return longest_band;
}
int main()
{
    vector<int> arr = {1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<band(arr)<<endl;
}