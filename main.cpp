#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <streambuf>

using namespace std;

string removeWhiteSpace(const string original) {
    string modified = original; //copy original string
    size_t pos = 0; //position of white space
    pos = modified.find(' ', pos); //find first position of white space, if any
    
    while(pos != string::npos) { 
        modified.replace(pos, 1, ""); //get rid of white space
        if(pos > 0) {
            pos--;
        }
        pos = modified.find(' ', pos);
    }
    
    pos = modified.find('\n', 0); //find first position of white space, if any
    while(pos != string::npos) { 
        modified.replace(pos, 1, ""); //get rid of white space
        if(pos > 1) {
            pos -= 2;
        }
        pos = modified.find('\n', pos);
    }
    return modified;
}

string openFile(){      // opens a file and returns the file as a string

    string nof = "";
    stringstream buffer;
    cout << "Enter the name of a file\n";
    getline(cin, nof);
    
    ifstream t(nof.c_str());
    
    if(t.is_open()){
        buffer << t.rdbuf();
        t.close();
    
        return buffer.str();
    }
    else{               // file failed to open
        cout << "Could not open " << nof << endl;
        exit(EXIT_FAILURE);
    }
}

string preserveQuotes(string str){
    string returnStuff;
    string quotation = "\"";    // quotation "
    size_t pos = str.find(quotation);
    if(pos != string::npos){    // found
        size_t pos2 = str.find(quotation, pos + 1);
        if(pos2 != string::npos){
            string part1, part2, part3;
            part1 = str.substr(0, pos);                 // from start of string to first "
            part1 = removeWhiteSpace(part1);
            part2 = str.substr(pos, pos2 - pos);        // preserve between "
            part3 = str.substr(pos2, str.size() - 1);
            part3 = removeWhiteSpace(part3);        // 2nd " to end
            returnStuff = part1 + part2 + part3;
        }
        else{
            cout << "only one quotation, error";
        }
    }
    else{   // no quotations
        return str;
    }
    return returnStuff;
}

int main() {
    string fileStr = openFile();
    cout << fileStr << endl;
    
    cout << "------------------------------------------\n";
    
    string rm = preserveQuotes(fileStr);
    
    cout << rm << endl;
    
    cout << "------------------------------------------\n";
    
    return 0;
}