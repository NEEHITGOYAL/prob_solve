/*
Sample Input
------------
3
92 022
82 12
77 13
2 false numeric

Sample Output
-------------
82 12
77 13
92 022
*/
#include<bits/stdc++.h>
using namespace std;

string extractkey(string s,int key){
    char *value = strtok((char *)s.c_str()," ");
    while(key>1){
        value = strtok(NULL," ");
        key--;
    }
    return (string)value;
}

int stringtoint(string s){
    int ans=0;
    int p=1;
    for(int i = s.length()-1;i>=0;i--){
        ans += ((s[i]-'0')*p);
        p *= 10;
    }
    return ans;
}

bool numericcomp(pair<string,string> s1,pair<string,string> s2){
    string key1,key2;
    key1 = s1.second;
    key2 = s2.second;
    return stringtoint(key1)<stringtoint(key2);
}

bool lexocomp(pair<string,string> s1,pair<string,string> s2){
    string key1,key2;
    key1 = s1.second;
    key2 = s2.second;
    return key1<key2;
}

int main(){
    int n,key;
    cin>>n;
    string temp,order,rev;
    vector<string> v;
    cin.get();
    for(int i = 0;i<n;i++){
        getline(cin,temp);   // it includes spaces
        v.push_back(temp);
    }
    cin>>key>>rev>>order;

    // Extract key and form a vector of pairs
    vector<pair<string,string>> vp(v.size());
    for(int i=0;i<v.size();i++)
        vp.push_back({v[i],extractkey(v[i],key)});
    //sort according to order
    if(order == "numeric")
        sort(vp.begin(),vp.end(),numericcomp);
    else
        sort(vp.begin(),vp.end(),lexocomp);
    //reversal
    if(rev == "true")
        reverse(vp.begin(),vp.end());     
    //print all
    for(auto x:vp)
        cout<<x.first<<endl;
    return 0;   
}