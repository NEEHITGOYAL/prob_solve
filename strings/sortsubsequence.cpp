#include<bits/stdc++.h>
using namespace std;

void subsequence(string s,string o,vector<string> &v){
    //base case
    if(s.size() == 0){
        v.push_back(o);
        return;
    }
    //rec case
    char temp = s[0];
    string reduced = s.substr(1);

    //includes
    subsequence(reduced,o+temp,v);
    //not include
    subsequence(reduced,o,v);
}

bool compare(string s1,string s2){
    if(s1.length() == s2.length())
        return s1< s2;
    return s1.length()<s2.length();    
}

int main(){
    string s;
    cin>>s;
    vector<string> v;
    string output = "";
    subsequence(s,output,v);
    sort(v.begin(),v.end(),compare);
    for(auto x:v)
        cout<<x<<",";
    cout<<endl;
    return 0;
}