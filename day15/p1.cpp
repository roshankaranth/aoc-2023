#include<bits/stdc++.h>
using namespace std;

int main(){

    string input;
    int sum =0 ;
    int i = 0 ;

    ifstream in("input.txt");
    getline(in,input);

    while(input[i]!='\0'){
       
        int number = 0;
        while(input[i]!=',' && input[i]!= '\0'){
            
            number += (int)input[i] ;
            number *= 17;
            number %= 256;
            i++;
        }
        sum+= number;
        i++;
    }

    cout<<sum;

    return 0;
}
