#include<bits/stdc++.h>
using namespace std;

int main(){

    map<int,vector<pair<string,int>>> mapp;
    string input;
    int sum =0 ;
    int i = 0 ;

    ifstream in("input.txt");
    getline(in,input);

    

    while(i<=input.length()){
        
        int number = 0;
        string box ;
        while(input[i]!=',' && input[i]!= '\0'){
            if(input[i]>=97 && input[i]<=122){
                box+= input[i];
                number += (int)input[i] ;
                number *= 17;
                number %= 256;
            }else if(input[i]=='='){
                
                if(mapp[number].size()==0){
                    mapp[number].push_back({box,input[i+1]-'0'});
                }else{
                    int flag = 0;
                    for(int m = 0 ; m < mapp[number].size(); m++){
                        
                        if(box==mapp[number][m].first){
                            
                            mapp[number][m].second = input[i+1]-'0';
                            flag = 1;
                            break;
                        }
                    }
                    if(flag==0){
                        mapp[number].push_back({box,input[i+1]-'0'});
                    }
                }
            }else if(input[i]=='-'){
                
                for(int i = 0 ; i < mapp[number].size(); i++){
                        if(box==mapp[number][i].first){
                            
                            mapp[number].erase(mapp[number].begin() + i);
                            
                        }
                    }
            }
           
            i++;
        }
        

        i++;
        
    }

    
    

    for(int i = 0 ; i <= 256 ; i++){
        
        for(int j = 0 ;j < mapp[i].size(); j++){
            int prod = i+1;
            
            prod = prod*(j+1)*mapp[i][j].second;
            
            sum += prod;
           
        }
    }

    cout<<sum;

    return 0;
}
