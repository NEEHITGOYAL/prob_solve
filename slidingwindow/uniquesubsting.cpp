#include<bits/stdc++.h>
using namespace std;

string uniquesubstring(string s){
    unordered_map<char,int> m;
    int i,j;i=j=0;
    int window_len,max_len,start_window;
    window_len = max_len = start_window =0;
    while(j<s.length()){
        char ch = s[j];
        //if elem is present
        if(m.count(ch)){
            i=m[ch]+1;
            window_len = j-i;
        }
        m[ch] = j;
        window_len++;
        j++;
        if(window_len>max_len){
            start_window = i;
            max_len = window_len;
        }
    }
    return s.substr(start_window,max_len);
}
int main(){
    string s;
    getline(cin,s);
    cout<<uniquesubstring(s)<<endl;
}