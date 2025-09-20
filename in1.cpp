#include <iostream>
#include <string>
#include<sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solve(string s){
    stringstream in(s);

    int n;
    in >> n;

    vector<int> a(n);

    for(int &x : a){
        in >> x;
    }

    stringstream out;



    for(int x:a){
        out << x << " ";
    }

    return out.str();
}

void solve(){
    string input_line;
    getline(cin, input_line);
}

inline void ltrim(std::string &s){
    s.erase(s.begin(),std::find_if(s.begin(),s.end(),[](unsigned char ch){
        return !std::isspace(ch);
    }));
}

inline void rtrim(std::string &s){
    s.erase(std::find_if(s.rbegin(),s.rend(),[](unsigned char ch){
        return !std::isspace(ch);
    }).base(),s.end());
}

int main(){
    // string input_data = "4 1 6";
    // string result = solve(input_data);
    // cout << result << endl;

    //cin.ignore()
    // string a;
    // getline(cin, a);

    // cout << a;

    // string b;
    // b = "scott>=tiger>=mushroom 1";

    // string delimiter = ">=";
    // size_t pos = 0;

    // while((pos=b.find(delimiter))!= std::string::npos){
    //     string token = b.substr(0,pos);
    //     cout << token << endl;
    //     b.erase(0,pos+delimiter.length());

    // }
    // cout << b << endl;

    



    return 0;
}