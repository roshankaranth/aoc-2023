#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("input.txt");
    string str;
    vector<string> vstr;
    //taking input from file
    while(getline(in,str)){
        vstr.push_back(str);
    }

    
    int sum=0;;

    for(int i = 0 ; i < vstr.size();i++){
        int starting= 0 ;
        int ending= 0;
        int flag = 0;
        for(int j = 0 ; j < vstr[i].size(); j ++){
            if(vstr[i][j]>=48 && vstr[i][j]<=57){
                if(flag==0){
                    starting = vstr[i][j] - '0';
                    flag=1;
                }
                ending = vstr[i][j] - '0';
            }
        }
        
        sum += starting*10 + ending;
        
    }

    cout<<sum;



    return 0;
}