#include<bits/stdc++.h>
using namespace std;

int main(){

    ifstream in("input.txt");
    string str;
    vector<string> vstr;

    for(int i = 0 ; getline(in,str); i++){
        vstr.push_back(str);
    }

    long long sum=0;
    vector<pair<int,pair<int,int>>> data;
    for(int i = 0 ; i< vstr.size();i++){
        int number = 0;
        int flag = 0;
        
        for(int j = 0 ; j < vstr[i].size();j++){
            int start,end;
            if(vstr[i][j]>=48 && vstr[i][j]<=57){
                number = number*10 + (vstr[i][j]-'0');
                if(flag==0){
                    start = j-1;
                    flag=1;
                }
                end = j+1;
               
                
            }
            
            if((vstr[i][j]<48 || vstr[i][j]>57 || vstr[i][j+1] == '\0')  && number!=0){
                
                if(start==-1){
                    start = 0;
                }

                if(end==vstr[i].size()){
                    end = vstr[i].size()-1;
                }
                while(start<=end){
                    for(int k = -1 ; k <=1 ; k++){
                        if((i==0 && k==-1) || (i==vstr.size()-1 && k==1)){
                            continue;
                        }
                        //cout<<vstr[i+k][start];
                        if(vstr[i+k][start] == '*' && vstr[i+k][start]!='.'){
                            for(int l = 0 ; l < data.size();l++){
                                if(data[l].second.first == i+k && data[l].second.second == start){
                                    sum+= number*data[l].first;
                                    
                                    //cout<<sum;
                                }
                            }
                            data.push_back({number,{i+k,start}});

                            
                        }
                        
                    }
                    start++;
                }
                start=0;
                number = 0;
                end = 0;
                flag =0;
                
            }
        }
    }

    cout<<sum;
    return 0;
}