#include<vector>
#include<bits/stdc++.h>
using namespace std;


vector<int> maxInWindow(vector<int> input,int k){
    
}
int main(){
    int k,temp;
    cin>>k;
    vector<int> inp;
    for(auto x:inp){
        cin>>temp;
        inp.push_back(temp);
    }
    vector<int> res = maxInWindow(inp,k);
    for(auto x:res){
        cout<<x<<" ";
    }
}