//
// Created by vera on 19-4-14.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//int main(){
//    string str;
//    vector<string> splitStr;
//    //getline默认是使用'\n'做分割，但是第三个参数可以指定自定义的分隔符
//    while(getline(cin,str,',')){
//        splitStr.push_back(str);
//    }
//    for(int i=0; i<splitStr.size(); i++){
//        cout<<splitStr[i]<<endl;
//    }
//    cout<<"end";
//}

//vector<string> split (const string &s, char delim) {
//    vector<string> result;
//    stringstream ss (s);
//    string item;
//
//    while (getline (ss, item, delim)) {
//        result.push_back (item);
//    }
//
//    return result;
//}
//
//int main() {
//    string str = "adsf+qwer+poui+fdgh";
//    vector<string> v = split (str, '+');
//
//    for (auto i : v) cout << i << endl;
//
//    return 0;
//}

// for string delimiter
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main() {
    string str = "adsf-+qwret-+nvfkbdsj-+orthdfjgh-+dfjrleih";
    string delimiter = "-+";
    vector<string> v = split (str, delimiter);

    for (auto i : v) cout << i << endl;

    return 0;
}