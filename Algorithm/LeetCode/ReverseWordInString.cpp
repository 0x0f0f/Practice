#include<iostream>
#include<string>
#include<stack>

using namespace std;

/*注意空格的处理, 各种情况*/

bool WhiteString(string& s){
    int sz = s.size();
    int i = 0;
    while(i < sz){
        if(s[i++] !=' ') {
            return 0;
        }
    }
    return 1;
}

void removeExtraSpace(string& s) {
    int start = 0,end = 0;
    int size = s.size();
    while(end < size ) {
        if(s[end] == ' '){
            end++;
        }
    }
}

int lenOfString(string& s) {
    int i = 0;
    while(s.c_str()[i] != '\0'){
        i++;
    }
    return i;
}

void ReverseWord(string& s) {
    int begin =0,end;
    int size = s.size() ;

    while(s[begin] == ' ') {
        begin++;
    }
    end = begin;
    while(begin < size  && end < size ) {
        while(s[end] != ' ' && s[end] != '\0') {
            end++;
        }
        int curr = 0;
        curr = end - 1;
        while(begin < curr ) {
            swap(s[begin], s[curr]);
            begin++;
            curr--;
        }

        while(s[end] == ' ') {
            end++;
        }
        begin = end;
    }
}

void ReverseString(string& s){
    int begin = 0, end = s.size() -1;

    if(WhiteString(s)){
        s = "";
        return;
    }
    while(begin < end){
        swap(s[begin], s[end]);
        begin++;
        end--;
    }
}

void ReverseWordByStack(string& s) {
    string rs;
    for (int i = s.length()-1; i >= 0; )
    {
        while (i >= 0 && s[i] == ' ') i--;
        if (i < 0) break;
        if (!rs.empty())
            rs.push_back(' ');
        string t;
        while (i >= 0 && s[i] != ' ')
            t.push_back(s[i--]);
        reverse(t.begin(), t.end());
        rs.append(t);
    }
    s = rs;
}

int main() {
    string s("hello world beijing nice");

    ReverseWord(s);
    ReverseString(s);
    cout<<s<<endl;

    string sa("a");
    ReverseWord(sa);
    ReverseString(sa);
    cout<<sa<<endl;

}

