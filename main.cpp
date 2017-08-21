#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "JSONObject.h"


static std::string txtFile = "json.txt";

using namespace std;
void readtxt()
{
    char c;
    ifstream infile;
    infile.open(txtFile);
    infile >> noskipws;
    while(!infile.eof())
    {
        infile >> c;
        cout<<c;
    }
    infile.close();
}

void readTxtByLine(string file)
{
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
    infile.close();             //关闭文件输入流
}
void tab_buff(int size, string &str){
    for (int i = 0; i < size; ++i) {
        cout<<str;
    }
}


bool arrayContains(const char* array, const char& t, const int & length){
    for (int i = 0; i < length ; ++i) {
        if ( (int) array[i] == (int)t ){
            return true;
        }
    }
    return false;
}

void format(string& str){
    str.length();
    int left=0;
    int comma_num=1;
    int right=0;
    int level = 0;
    const char bracket_left='{';
    const char bracket_right='}';
    const char comma=',';
    const char unDeal[] = {' ', '\n', '\r', 'o'};
    const int unDealLength = sizeof(unDeal) / sizeof(unDeal[0]);
    string tab="    ";
    //string tab_buff="";
    for (int i = 0; i < str.length(); ++i)
    {
        const char currentChar = str.at(i);
        switch(currentChar)
        {
            case bracket_left:
            {
                cout<<currentChar;
                cout<<endl;
                level++;
                tab_buff(level, tab);
                //tab_buff(left, tab);
                //left++;
            }break;
            case comma:
            {
                cout << currentChar;
                cout << endl;
                //comma_num=left-1;
                //tab_buff(comma_num, tab);
                tab_buff(level, tab);
            }break;
            case bracket_right:
            {
                cout << endl;
                level --;
                tab_buff(level, tab);
                //right=comma_num-1;
                //tab_buff(right, tab);
                cout << currentChar;
                //right--;
            }break;
            default:
                if (arrayContains(unDeal, currentChar, unDealLength)){
                    break;
                }
                cout << currentChar;
                break;

        }
        /*if(str.at(i)=='{'||str.at(i)==',')
        {
            cout<<str.at(i);
            cout<<endl<<tab_buff;
        }
        else if(str.at(i)=='}')
        {
            cout<<endl;
            cout<<str.at(i);
        }
        else
            cout<<str.at(i);*/
    }
}
void jsonfile(){
    string jsonStr = "{o    \r  \n      \"line1\":1,\"line2\":\"2\",\"line3\":{\"line4\":4,\"line5\": }}";
    format(jsonStr);
}


void JSONTest1();

int main() {

//    jsonfile();
//    readtxt();
    //welcome LiShiYu666
//    readTxtByLine(txtFile);
//
//    Entry<int> entry1;
//    entry1.setKey("num");
//    int a = 1;
//    entry1.setValue(&a);
//    entry1.print();


    JSONTest1();
    return 0;
    ofstream outfile;//建立ofstream对象，outfile
    outfile.open("json.txt",ios::app);//将对象与文件关联
    //以上两条语句可合并为：ofstream outfile(lsy.txt);
    if(outfile.fail()){
        cout<<"can't open it!"<<endl;
        getchar();
        return 0;
    }
//    outfile<<"书"<<endl;
    //cout<<"书"<<endl;
    outfile.close();
    getchar();
    return 0;
}
