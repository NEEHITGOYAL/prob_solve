#include<bits/stdc++.h>
using namespace std;
string find_window(string s,string p){
    //array as a freq map
    int fs[256] = {0};
    int fp[256] = {0};
    for(int i=0;i<p.length();i++){
        fp[p[i]]++;
    }

    int cnt =0;
    int start = 0;
    int start_idx = -1;
    int min_so_far = INT_MAX;
    int window_size;
    //sliding window algo
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        fs[ch]++;

        //count how many character have matched till now
        if(fp[ch]!=0 and fs[ch]<=fp[ch])
            cnt++;
        //if all chracters have matched we can start contracing
        if(cnt == p.length()){
            //start contracting from left
            while(fp[s[start]] == 0 or fs[s[start]]>fp[s[start]]){
                fs[s[start]]--;
                start++;
            }
            //note the window size
            window_size = i-start+1;
            if(window_size < min_so_far){
                min_so_far = window_size;
                start_idx = start;
            }
        }  
    }
    if(start_idx == -1)
        return "no window found";
    else
        return s.substr(start_idx,min_so_far);    
}
int main(){
    string s,p;
    cin>>s>>p;
    cout<<find_window(s,p)<<endl;
}