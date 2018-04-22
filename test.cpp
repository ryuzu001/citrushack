#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <streambuf>

using namespace std;

string removeNewlines(const string);

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
    
    // modified = removeNewlines(modified);
    
    return modified;
}
string removeNewlines(const string original){
    string lastLine = "";
    size_t last_pos = 0;
    string modified = original;
    size_t temp;
    size_t pos = modified.find('\n', 0);
    
    stringstream ss;
    while(pos != string::npos){
        lastLine = modified.substr(last_pos, pos - last_pos);
        ss << lastLine;
        temp = lastLine.find("//");
        if(temp != string::npos){   // contains a comment
            // cout << "comment!";
            // exit(0);
            
            // modified.replace(pos, 0, "\n");
            ss << "\n";
        }
        else{
            modified.replace(pos, 1, "");
        }
        last_pos = pos;
        pos = modified.find('\n', pos);
        
    }
    ss << lastLine;
    
    // std::ofstream out("output.txt");
    // out << ss.str();
    // out.close();
    return ss.str();
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

string preserveQuotes(string str){      // only accounts for one " " in the file though
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

string addWhiteSpace(const string );

int main() {
    string fileStr = openFile();
    // cout << fileStr << endl;
    
    // cout << "------------------------------------------\n";
    
    // string rm = preserveQuotes(fileStr);
    
    // cout << rm << endl;
    
    // cout << "------------------------------------------\n";
    
    string rm2 = removeNewlines(fileStr);
    
    cout << rm2 << endl;
    
    return 0;
}