#include<bits/stdc++.h>
using namespace std;

int main(){

    ifstream in("input.txt");
    string dir;
    string str;
    unordered_map<string,pair <string,string>>  mapp;
    
    getline(in,dir);

    while(getline(in,str)){
        string node = "";
        string element = "";
        int flag = 0;
        
        for(int i = 0 ; str[i]!='\0'; i++){
            
            if(str[i]>=65 && str[i]<=90){
                
                if(flag==0){

                    node+=str[i];
                    if(str[i+1]==' '){
                    mapp[node];
                    flag=1;
                    
                    }
                }else if(flag==1){
                    
                    element+= str[i];
                    ;
                    if(str[i+1] == ',' ){
                        mapp[node].first = element;
                        element = "";
                    }else if(str[i+1] == ')'){
                        mapp[node].second = element;
                        element = "";
                    }
                }

            }
        }
        //taking input


    }

    int steps = 0;
    string next = "AAA";
    int i = 0;
    while(next!="ZZZ"){
        if(dir[i]=='\0'){
            i = 0;
        }
        if(dir[i]=='L'){
            next = mapp[next].first;
            steps++;
        }else{
            next = mapp[next].second;
            steps++;
        }
        i++;
    }

    cout<<steps;
    return 0;
}