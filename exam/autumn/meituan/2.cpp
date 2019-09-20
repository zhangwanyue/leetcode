//
// Created by vera on 19-9-18.
//

#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;


char calculate(char c1, char operation, char c2){
    bool b1;
    bool b2;
    if(c1=='T'){
        b1 = true;
    }else if(c1=='F'){
        b1 = false;
    }else{
        return 'E';
    }
    if(c2=='T'){
        b2 = true;
    }else if(c2=='F'){
        b2 = false;
    }else{
        return 'E';
    }

    if(operation=='|'){
        if(b1|b2){
            return 'T';
        }else{
            return 'F';
        }
    }else if(operation=='&'){
        if(b1&b2){
            return 'T';
        }else{
            return 'F';
        }
    }else{
        return 'E';
    }
}


int main(){
    string str;
    while(getline(cin, str)){



        deque<char> mydeque;
        vector<char> vec = {'T', '|', 'F', '&', 'F'};

        bool flag = true;

        for(int i=0; i<vec.size(); i++){
            if(vec[i]=='&'){
                if(mydeque.empty() || vec.size()<i){
                    cout<<"error";
                    flag = false;
                    break;
                }
                char result = calculate(mydeque.back(), '&', vec[i+1]);
                mydeque.pop_back();
                if(result=='E'){
                    cout<<"error";
                    flag = false;
                    break;
                }
                mydeque.push_back(result);
                i++;
            }else{
                mydeque.push_back(vec[i]);
            }
        }

        while(flag && mydeque.size()>1){
            char c1 = mydeque.front();
            mydeque.pop_front();

            if(mydeque.empty()){
                cout<<"error";
                flag = false;
                break;
            }
            char op = mydeque.front();
            mydeque.pop_front();

            if(mydeque.empty()){
                cout<<"error";
                flag = false;
                break;
            }
            char c2 = mydeque.front();
            mydeque.pop_front();

            char result = calculate(c1, op, c2);
            if(result == 'E'){
                cout<<"error";
                flag = false;
                break;
            }
            mydeque.push_back(result);
        }

        if(flag){
            cout<<mydeque.front();
        }
    }
}
