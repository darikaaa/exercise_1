#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    struct Name {
        string name;
        string family;
    };

    string source_path = "C:\\programming\\text2.txt";

    ifstream file;
    file.open(source_path);
    if (!file.is_open()) {
        cout << "File does not exist" << endl;
        return 0;
    }
    vector<Name> result;
    string line;
    while (getline(file,line)) {
        int char_pos = line.find("|");
        Name temp;
        temp.family = line.substr(0,char_pos);
        temp.name = line.substr(char_pos+1);
        result.push_back(temp);
    }
    file.close();

    ofstream file2;
    string result_file_path = "C:\\programming\\result_file.txt";
    file2.open(result_file_path);
    if (!file2.is_open()) {
        cout << "File does not exists" << endl;
        return 0;
    }

    for (auto name: result) {
        file2 << name.family << endl;
    }
    file2.close();









}

