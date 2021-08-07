#include<string>
#include<iostream>
using namespace std;

string convert_to_digital_time(int minutes){
    //complete this function
    int hours = minutes/60;
    int mins = minutes%60;
    if(mins<10)
        return to_string(hours)+":0"+to_string(mins);
    return to_string(hours)+":"+to_string(mins);
}

int main(){
    int minutes;
    cin>>minutes;
    cout<<convert_to_digital_time(minutes)<<endl;
}