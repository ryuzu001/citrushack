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

string preserveQuotes(string str){      // preserves quotes, and any comment //
    string returnStuff = "";
    string p1Quote = "";
    string p1Comment = "";
    string p2 = "";
    string p3 = "";
    string p4 = "";
    string quotation = "\"";    // quotation "
    string newline = "\n";
    string comment = "//";       // comment //
    size_t commentstart = str.find(comment);
    size_t commentend = 0;
    size_t quotestart = str.find(quotation);
    size_t quoteend = 0; 
    
    if(commentstart < quotestart){      // comment before quote - comment gets priority
        p1Comment = str.substr(0, commentstart);
        p1Comment = removeWhiteSpace(p1Comment);
        returnStuff += p1Comment;
    }
    else{
        p1Quote = str.substr(0, quotestart);  // from start of string to first "
        p1Quote = removeWhiteSpace(p1Quote);
        returnStuff += p1Quote;
    }
    if(quoteend != string::npos && commentend != string::npos){    // found
        while(quoteend != string::npos || commentend != string::npos){
            if(commentstart < quotestart){          //comment comes first
                commentend = str.find(newline, commentstart + 1);        // pos2Comment is the end of the comment - newline
                p2 = str.substr(commentstart, commentend - commentstart);   // preserve comment, from // to newline
                commentstart = str.find(comment, commentend + 1);
                p3 = str.substr(commentend, quotestart - commentend); 
            }
            else{
                quoteend = str.find(quotation, quotestart + 1) + 1;          // pos2Quote pointing to the second quotation now
                p2 = str.substr(quotestart, quoteend - quotestart);           // preserve between "                                       // add it to returnStuff
                quotestart = str.find(quotation, quoteend + 1);
                p3 = str.substr(quoteend, commentstart - quoteend);
            }
            if((quotestart == string::npos) && (commentstart == string::npos)){
                break;
            }
            
            returnStuff += p2;
            
            p3 = removeWhiteSpace(p3);
            returnStuff += p3;
        }
    }
    else{   // no quotations
        cout << "hahha lol nope";
        return str;
    }
    return returnStuff;
}

string format(const string &s) {
    int numTabs = 0;
    string str = s;
    for(unsigned p = 0; p < str.length(); p++) {
        
        if(p + 1 >= str.size()){     // last } in the file
            str.erase(p - 1, 1);
            return str;
        }
        
        if(str.at(p) == '=') {
            if(str.at(p + 1) == '=') {
                str.insert(p + 2, " ");
            }
            else {
                str.insert(p, " ");
                p++;
                str.insert(p + 1, " ");
            }
        }
        
        if(str.at(p) == '*') { //not needed rn
            // if(isdigit(str.at(p + 1))) {
            //     str.insert(p + 1, " ");
            // }
            // if(str.at(p - 1) == ' ') {
            //     str.insert(p, " ");
            //     p++;
            // }
        } 
        
        // && || 
        
        if(str.at(p) == '&' && str.at(p + 1) == '&'){
            str.insert(p, " ");
            p++;
            str.insert(p + 2, " ");
        }
        
        if(str.at(p) == '|' && str.at(p + 1) == '|'){
            str.insert(p, " ");
            p++;
            str.insert(p + 2, " ");
        }
        
        
        // if(str.at(p) == '-') {
            
        // }
        if(str.at(p) == '%'){       // spaces before %
            str.insert(p, " ");
            p++;
            str.insert(p + 1, " ");
        }
        if(str.at(p) == '>') {
            
            if(str.at(p + 1) == 'i' && str.at(p + 2) == 'n' && str.at(p + 3) == 't'){       // #include<vector>intmain()...
                str.insert(p + 1, "\n");
            }
            else if(str.at(p + 1) == '/'){       // literally a "//" comment
                str.insert(p + 1, "\t");
            }
            else if(str.at(p + 1) == '>'){  // cin>>temp;
                str.insert(p, " ");
                p++;
                str.insert(p + 2, " ");
                
            }
            else if(isalpha(str.at(p + 1))){    // vector<int>temp; 
                str.insert(p + 1, " ");
            }
            else if (str.at(p + 1) == '*'){     // array<double>*temp;
                str.insert(p + 1, " ");
            }
            else if(str.at(p + 1) == '#'){                               // top headers, #include
                str.insert(p + 1, "\n");
            }
            else if(isdigit(str.at(p + 1))){         //if(argc>1){
                str.insert(p + 1, " ");
                str.insert(p, " ");
                p++;
            }
            
        }
        
        if(str.at(p) == '<'){
            if(str.at(p + 1) == '<'){       // cout << hello
                str.insert(p, " ");
                p++;
                str.insert(p + 2, " ");
            }
            else if(str.at(p - 7) == 'i' && str.at(p - 6) == 'n' &&
                    str.at(p - 5) == 'c' && str.at(p - 4) == 'l' &&
                    str.at(p - 3) == 'u' && str.at(p - 2) == 'd' &&
                    str.at(p - 1) == 'e') {
                str.insert(p, " ");
            }
        }
        
        if(str.at(p) == '}') {
            numTabs--;
            str.erase(p - 1, 1);        // get rid of the tab before the }
            p--;
            
            // this can cause an out of range error if its the last } in the file, just default to a newline
            
            
            if(str.at(p + 1) == ';') { // };
                
            }
            else if(str.at(p + 1) == 'w' && str.at(p + 2) == 'h' 
                 && str.at(p + 3) == 'i' && str.at(p + 4) == 'l'  
                 && str.at(p + 4) == 'e') { // } while(condition);
                str.insert(p + 1, " ");
            }
            else {
                str.insert(p + 1, "\n");
            }
        }
        
        if(str.at(p) == ';' && str.at(p + 1) != '\n'){
            str.insert(p + 1, "\n");
        }
        
        if(str.at(p) == 'i' && str.at(p + 1) == 'n' && str.at(p + 2) == 't'){       // int ...
            str.insert(p + 3, " ");
        }
        
        if(str.at(p) == '{'){       // {
            numTabs++;
            str.insert(p + 1, "\n");
        }
        
        // return
        if(str.at(p) == 'r' && str.at(p + 1) == 'e' && str.at(p + 2) == 't' && 
           str.at(p + 3) == 'u' && str.at(p + 4) == 'r' && str.at(p + 5) == 'n'){
            str.insert(p + 6, " ");
        }
        if(str.at(p) == '\n'){
            for(int i = 0; i < numTabs; i++){
                str.insert(p + 1, "\t");
            }
        }
        
        if(str.at(p) == ',') {
            str.insert(p + 1, " ");
        }
        
        if(str.at(p) == 'c' && str.at(p + 1) == 'h' && str.at(p + 2) == 'a' && str.at(p + 3) == 'r' && str.at(p + 4) != ' '){
            str.insert(p + 4, " ");
        }
        
        if(str.at(p) == 'd' && str.at(p + 1) == 'o' && str.at(p + 2) == 'u' && str.at(p + 3) == 'b'
        && str.at(p + 4) == 'l' && str.at(p + 5) == 'e' && str.at(p + 6) != '>'){
            str.insert(p + 6, " ");
        }
        
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


