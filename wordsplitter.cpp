#include <iostream>
#include <vector>
#include <sstream>
using namespace std; 

vector<string> split(const string& s)
{
    stringstream ss(s);
    vector<string> words;
    for (string w; ss>>w; ) words.push_back(w);
    return words;
}
int main(){
    string sentence = "Marry had a little lamb"; 
    vector<string> words = split(sentence);
    for(auto& var : words){
        cout << var << endl ; 
    }
}