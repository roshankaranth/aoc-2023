#include<bits/stdc++.h>
using namespace std;

int main(){

    ifstream in("input.txt");
    string str;
    

    
    int sum=0;
    for(int i = 0 ; i< str.size();i++){
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
            

            if((vstr[i][j]<48 || vstr[i][j]>57)  && number!=0){
                
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
                        if((vstr[i+k][start]<48 || vstr[i+k][start]>57) && vstr[i+k][start]!='.'){
                            cout<<number<<"\n";
                            sum += number;
                            start = 1, end=0;
                            break;
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