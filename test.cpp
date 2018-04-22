#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <streambuf>

using namespace std;

string nof = "";        // global variable - name of file

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
    
    return modified;
}

string removeNewlines(const string original){
    string lastLine = "";
    size_t last_pos = 0;
    string modified = original;
    size_t temp;
    size_t pos = modified.find('\n', 0);                        // find first newline character
    
    stringstream ss;
    while(pos != string::npos){
        lastLine = modified.substr(last_pos, pos - last_pos);   // last line of code before newline
        ss << lastLine;
        temp = lastLine.find("//");                             // scan through looking for comments
        if(temp != string::npos){                               // contains a comment - newline
            ss << "\n";
        }
        else{                                                   // does not contain a comment - no newline
            modified.replace(pos, 1, "");
        }
        last_pos = pos;                                         // update pos and last_pos
        pos = modified.find('\n', pos);
        
    }
    lastLine = modified.substr(last_pos, modified.size() - last_pos);
    
    ss << lastLine;
    
    return ss.str();
}

string openFile(){      // opens a file and returns the file as a string
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

void writeFile(string str){                 // writes file
    string formatted = "_formatted";        // formatted string
    string nof_f;
    size_t per = nof.find(".");             // file extension
    if(per != string::npos){
        nof_f = nof.substr(0, per) + formatted + nof.substr(per, nof.size() - per);
    }
    else{
        nof_f = nof + formatted;      // nameoffile_formatted       w/ no extension
    }
    
    ofstream out(nof_f.c_str());             // actual write process
    out << str;
    out.close();
}

string preserveQuotes(string str){      // only accounts for one " " in the file though
    string returnStuff = "";
    string p1 = "";
    string p2 = "";
    string p3 = "";
    string p4 = "";
    string quotation = "\"";    // quotation "
    size_t pos = str.find(quotation);
    size_t pos2 = 0; 
    size_t temp = 0;
    p1 = str.substr(0,pos);  // from start of string to first "
    p1 = removeWhiteSpace(p1);
    returnStuff += p1;
    
    if(pos != string::npos){    // found
        while(pos != string::npos){
            pos2 = str.find(quotation, pos + 1);     // find second quotation
            p2 = str.substr(pos, pos2 - pos);        // preserve between "
            returnStuff += p2;                       // add it to returnStuff
            
            temp = pos;
            pos = str.find(quotation, pos2 + 1);        // next quotation
            if(pos == string::npos){                    // check if theres no next quotation
                pos = temp;
                break;
            }
            p3 = str.substr(pos2, pos - pos2);          // between current and next quotation, 
            p3 = removeWhiteSpace(p3);                  // not in quote, so remove whitespace.
            returnStuff += p3;
        }
        p4 = str.substr(pos2, str.size() - pos);
        p4 = removeWhiteSpace(p4);
        returnStuff += p4;
    }
    else{   // no quotations
        return str;
    }
    return returnStuff;
}

string format(const string &s) {
    string str = s;
    for(unsigned p = 0; p < str.length(); p++) {
        if((str.at(p) == '*') || (str.at(p) == '+') || 
           (str.at(p) == '-') || 
           (str.at(p) == '=') || (str.at(p) == '|') ||
           (str.at(p) == '%') || (str.at(p) == '&')){       // spaces before all operators
            str.insert(p - 1, " ");
            p++;
        }
        if(str.at(p) == '>') {
            if(str.at(p + 1) == '/'){       // literally a "//" comment
                // do nothing
            }
            else if(str.at(p + 1) == '>'){  // cout>>temp;
                str.insert(p + 2, " ");
                p++;
            }
            else if(isalnum(str.at(p + 1))){    // vector<int>var;
                str.insert(p + 1, " ");
            }
            else if (str.at(p + 1) == '*'){     // array<double>*temp;
                str.insert(p + 2, " ");
            }
            else{                               // default: newline
                str.insert(p + 1,"\n");
            }
        }
        // else if(str.at(p) == '{') {
        //     if(isalpha(str.at(p + 1))) {
        //         str.insert(p + 1, " ");
        //     }
        //     else{
        //         str.insert(p + 1,"\n");
        //     }
        // }
    }
    return str;
}

string removeAllWhitespace(){
	string t = openFile();
	t = removeNewlines(t);
	t = preserveQuotes(t);
	return t;
}

int main() {
    string t = removeAllWhitespace();
    
    t = format(t);
    
    writeFile(t);
    return 0;
}


