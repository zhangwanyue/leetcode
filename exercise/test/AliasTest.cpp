//
// Created by vera on 19-4-8.
//

#include <iostream>
#include <vector>

using namespace std;

//c++和java不同
// java的函数中的参数如果为对象（除了基本数据类型。比如自定义对象，或者List，Map等），则如果在调用的函数中修改了对象的值，调用完之后原对象的值会改变。
// 因为java是使用引用操控对象的（可以理解为List对象中存的其实是该对象的初始地址，拷贝到参数中的时候只拷贝了一个初始地址过去）（注意java中只有值传递，没有引用传递）
// 而从c++中则不同，c++拷贝对象到参数中时，会将整个对象拷贝过去。
// 所以c++如果使用值传递，那么在调用的函数中修改了对象的值之后，调用完原对象的值不会改变。
void AliasTest(vector<int> vec, int num){
    for(int item : vec){
        item++;
        cout<<item<<" ";
    }
    num++;
    cout<<endl<<num<<endl;
}

int main(){
    vector<int> vec = {0, 1, 2, 3};
    int num = 10;
    AliasTest(vec, num);
    cout<<"after call"<<endl;
    for(int item : vec){
        cout<<item<<" ";
    }
    cout<<endl<<num<<endl;
}