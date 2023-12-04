#include<bits/stdc++.h>
using namespace std;

int main(){

    ifstream in("input.txt");

    unordered_map<int,int> tracker;
    string str;
    vector<int> winners;
    vector<int> selected;
    long long sum = 0;

    while(getline(in,str)){
        int number = 0;
        int count = 0;
        int game_id = 0;


        for(int i = 0 ; str[i]!=':';i++){
            if((str[i]>=48 && str[i]<=57)){
                game_id = game_id*10 + (str[i]-'0');
            }
        }
        
        tracker[game_id]++;
        for(int i = 9; i < str.length();i++){

            if(count<10){
                if((str[i]>=48 && str[i]<=57)){
                number = number*10 + (str[i]-'0');
                if(str[i+1]==' '){
                    winners.push_back(number);
                    number=0;
                    count++;
                }
            }

            }else{
                if((str[i]>=48 && str[i]<=57) ){
                number = number*10 + (str[i]-'0');
                //cout<<number<<" ";
                if(str[i+1]==' ' || str[i+1]=='\0'){
                    selected.push_back(number);
                    number=0;
                    
                }
            }
            }

        }
        int matched = 0;
        for(int i = 0 ; i < selected.size(); i++){

            for(int j = 0 ; j < winners.size();j++){
                if(winners[j] == selected[i]){
                    matched++;
                }
            }
        }
        
        for(int i = 1 ; i <= matched ; i++  ){
            tracker[game_id+i] += tracker[game_id];
            ;
        }
        

       
        selected.clear();
        winners.clear();
        

    }

    for(int i = 1 ; i <= 190 ; i++){
        sum+= tracker[i];
        cout<<i<<" "<<tracker[i]<<"\n";
    }

    cout<<sum;

    
return 0;

}