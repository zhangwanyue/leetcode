//
// Created by vera on 19-4-14.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*
int main(){
    string str;
    vector<string> splitStr;
    //getline默认是使用'\n'做分割，但是第三个参数可以指定自定义的分隔符
    while(getline(cin,str,',')){
        splitStr.push_back(str);
    }
    for(int i=0; i<splitStr.size(); i++){
        cout<<splitStr[i]<<endl;
    }
    cout<<"end";
}*/


/*
vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

int main() {
    string str = "adsf+qwer+poui+fdgh";
    vector<string> v = split (str, '+');

    for (auto i : v) cout << i << endl;

    return 0;
}*/


/*
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
}*/


/*
int main(){
    //ostringstream的数据流转移：从字符串到ostringstream
    //istringstream的数据流转移：从istringstream到字符串
    //所以数据流的转移是相对于string（程序内部数据）来说的
    ostringstream ss1;
    string result1;
    ss1<<1;
    result1 = ss1.str();
    cout<<result1<<endl;
    ss1.clear();//clear成员函数继承自ios,用于清楚流的errpr状态,如果file stream的状态被职位eofbit(文件结束),则调用clear会讲错误状态重置为goodbit.但是它并不清空流!!!
    ss1.str("");//清空流
    ss1<<2<<1;
    result1 = ss1.str();
    cout<<result1<<endl;

    //stringstream其实和istringstream或者ostringstream没什么区别，只是既可以输出也可以输入
    stringstream ss2;
    ss2.str("");
    //直接使用>>处理字符串时,它会读取一个字符串,直到遇到空格,然后将后面的内容输出到下一个字符串.
    ss2<<"hello world";
    string result2, result3;
    ss2>>result2>>result3;
    cout<<result2<<" "<<result3<<endl;
    //为避免这一情况，可以使用getline()或者.str()
    result3 = ss2.str();
    cout<<result3<<endl;
    getline(ss2, result3);
    cout<<result3<<endl;
}*/


int main(){
    string str = "hello world";
    int pos1 = str.find("word");//return: the position of the first character of the first match, if no matches were found, the function returns string::npos
    cout<<pos1<<endl;
    if(pos1 == string::npos){
        cout<<"not found"<<endl;
    }

    int pos2 = str.find("worl", 2);//从下标为２的位置开始查找
    cout<<pos2<<endl;
}