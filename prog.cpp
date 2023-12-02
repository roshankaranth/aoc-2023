#include<bits/stdc++.h>
using namespace std;

int main(){

    string str;
    ifstream in("input.txt");
    int sum;

    for(int k = 0 ; k < 100 ; k++){
    getline(in,str);
    
    int game_id=0;
    for(int i = 5; str[i]!=':';i++){
        game_id = game_id*10 + (str[i]-'0');
        cout<<game_id<<" ";
    }
    cout<<str<<"\n";
    
    int possible = 1;
    for(int i = 7 ; str[i]!= '\0';){
        int number = 0;
        int red = 0;
        int blue = 0 ;
        int green = 0;
        while(str[i]!=';' && str[i+1]!='\0'){
            
            if(str[i]>=48 && str[i]<=57){
                number = number*10 + (str[i] - '0');

            
        }else if(str[i]==' '){
            if(str[i+1]=='r'){
                red = number;
                number = 0;
            }else if(str[i+1]=='g'){
                green = number;
                number = 0;
            }else if(str[i+1]=='b'){
                blue = number;
                number = 0;
            }
        }
        i++;
        }
        //cout<<game_id<<" "<<red<<" "<<blue<<" "<<green<<"\n";
        if(red>12 || green > 13 || blue > 14){
            possible = 0;
            break;
        }
        i++;
    }
    if(possible){
        sum += game_id;
       
    }

}
    cout<<sum;
    return 0;
}

//12 red cubes, 13 green cubes, and 14 blue cubes