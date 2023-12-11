#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> patt;
    int sum = 0;
    string str;
    ifstream in("input.txt");
    
    while(getline(in,str)){
        vector<int> row ;
        int number = 0;
        patt.clear();
        int neg = 0;
        for(int i = 0 ; str[i]!='\0'; i++){
            if(str[i]>=48 && str[i]<=57){
                if(str[i-1]=='-'){
                    neg = 1;
                }
                number = number*10 + (str[i]-'0');

            }

            if((str[i+1]==' '||str[i+1]=='\0')){
                if(neg==1){number=-number;neg=0;};
                row.push_back(number);
                number =0;
            }
        }

        patt.push_back(row);
        row.clear();

        int flag = 1;
        int col = 0;

        while(flag){
            
            for(int i = 0 ; i <patt[col].size()-1; i++){
                row.push_back(patt[col][i+1] - patt[col][i]);
                
            }
            

            patt.push_back(row);
            row.clear();
            col++;
            
            for(int i = 0 ; i<patt[col].size(); i ++){
                
                if(patt[col][i]!=0){
                    flag=1;
                    break;
                }
                
                flag = 0;
            }
            
        }

        for(int i = col ; col> 0 ; col--){
            patt[col-1].push_back(patt[col].back()+patt[col-1].back());
        }

        sum+=patt[0].back();

        for(int i = 0 ; i < patt.size(); i++){
            for(int j = 0 ; j < patt[i].size(); j++){
                cout<<patt[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

   cout<<sum;
    return 0;
}
