#include<bits/stdc++.h>
using namespace std;

int word(string digit){

    switch(digit){

        case "zero":return 0;
        case "one":return 1;
        case "two":return 2;
        case "three":return 3;
        case "four":return 4;
        case "five":return 5;
        case "six":return 6;
        case "seven":return 7;
        case "eight":return 8;
        case "nine":return 9;
    }
}

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
        string digit;
        for(int j = 0 ; j < vstr[i].size(); j ++){

            ///INCOMPLETE!

            //Getting number;
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