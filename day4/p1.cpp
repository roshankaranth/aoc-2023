#include<bits/stdc++.h>
using namespace std;

int main(){

    ifstream in("input.txt");

    string str;
    vector<int> winners;
    vector<int> selected;
    int sum = 0;

    while(getline(in,str)){
        int number = 0;
        int count = 0;
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
        int points = 0;
        for(int i = 0 ; i < selected.size(); i++){

            for(int j = 0 ; j < winners.size();j++){
                if(winners[j] == selected[i]){
                    if(points != 0){
                        points=points*2;
                    }else{
                        points = 1;
                    }
                }
            }
        }

        sum+=points;

       
        selected.clear();
        winners.clear();
        

    }

    cout<<sum;

    
return 0;

}