#include<bits/stdc++.h>
using namespace std;

int word(string digit){

    

        if(digit=="one"){
            return 1;
        }
        if(digit=="two"){
            return 2;
        }
        if(digit=="three"){
            return 3;
        }
        if(digit=="four"){
            return 4;
        }
        if(digit=="five"){
            return 5;
        }
        if(digit=="six"){
            return 6;
        }if(digit=="seven"){
            return 7;
        }if(digit=="eight"){
            return 8;
        }if(digit=="nine"){
            return 9;
        }if(digit=="zero"){
            return 0;
        }

    return 0;

    
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

            for(int k = 3 ; k <= 5 ; k++){
                if(vstr[i].compare(j,k,"one")==0||vstr[i].compare(j,k,"two")==0||vstr[i].compare(j,k,"three")==0||vstr[i].compare(j,k,"four")==0||vstr[i].compare(j,k,"five")==0||vstr[i].compare(j,k,"six")==0||vstr[i].compare(j,k,"seven")==0||vstr[i].compare(j,k,"eight")==0||vstr[i].compare(j,k,"nine")==0||vstr[i].compare(j,k,"zero")==0){
                    if(flag==0){
                        starting = word(vstr[i].substr(j,k));
                        flag=1;
                        
                    }

                    ending = word(vstr[i].substr(j,k));
                }
            }

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