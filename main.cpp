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

string preserveQuotes(string str){      // preserves quotes, and any comment //   (jk not the comment thing - too hard see test.cpp)
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
// string preserveQuotes(string str){      // preserves quotes, and any comment //
//     string returnStuff = "";
//     string p1 = "";
//     string p2 = "";
//     string p3 = "";
//     string p4 = "";
//     string quotation = "\"";    // quotation "
//     string newline = "\n";
//     string comment = "//";       // comment //
    
//     size_t cnl, cQ;
    
//     size_t commentSlash = str.find(comment);
//     size_t commentNewline = str.find(newline);
//     size_t openQ = str.find(quotation);
    
//     size_t closedQ = str.find(quotation, openQ + 1); 
    
//     // if(commentSlash == string::npos){
        
//     //     return nocomments(str);
//     // }
//     // if(openQ == string::npos){
//     //     return nostrings(str);
//     // }
    
//     if(commentSlash < openQ){       //comment first
//         p1 = str.substr(0, commentSlash);
//     }
//     else{                           // quote first
//         p1 = str.substr(0, openQ);
//     }
//     p1 = removeWhiteSpace(p1);
//     returnStuff += p1;
    
    
//     while(1){
//         if(commentSlash < openQ){   // comment first
//             p2 = str.substr(commentSlash, commentNewline - commentSlash);       // comment
            
//             cnl = commentNewline;
//             commentSlash = str.find(comment, commentNewline + 1);                   // update values
//             commentNewline = str.find(newline, commentNewline + 1);
//             if(openQ > commentSlash){
//                 p3 = str.substr(cnl, commentSlash - cnl);
//             }
//             else{
//                 p3 = str.substr(cnl, openQ - cnl);            // whichever one is smaller
//             }
//         }
//         else{                       // quote first
//             p2 = str.substr(openQ, closedQ - openQ);                            // quote
            
//             cQ = closedQ;
//             openQ = str.find(quotation, closedQ + 1);                               // update values
//             closedQ = str.find(quotation, openQ + 1);
//             if(commentSlash > openQ){
//                 p3 = str.substr(cQ, openQ - cQ);
//             }
//             else{
//                 p3 = p3 = str.substr(cQ, commentSlash - cQ);
//             }
//         }
//         if((commentSlash == string::npos && openQ == string::npos))
//         // if((commentSlash > 9999 || openQ > 9999))
//             break;
        
//         returnStuff += p2;
//         p3 = removeWhiteSpace(p3);
//         returnStuff += p3;
//     }
//     return returnStuff;
// }


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
                str.insert(p, " ");
                p++;
                str.insert(p + 2, " ");
            }
            else if(!(str.at(p - 1) == '=' || str.at(p - 1) == '<'
                  || str.at(p - 1) == '>' || str.at(p - 1) == '+'
                  || str.at(p - 1) == '-' || str.at(p - 1) == '*'
                  || str.at(p - 1) == '/' || str.at(p - 1) == '%'
                  || str.at(p - 1) == '!')) {
                if(str.at(p + 1) != ' ') {
                    str.insert(p, " ");
                    p++;
                    str.insert(p + 1, " ");
                }
                
            }
        }
        
        if(str.at(p) == '*') { 
            if((isdigit(str.at(p + 1)) && isalpha(str.at(p - 1))) || 
               (isdigit(str.at(p - 1)) && isalpha(str.at(p + 1))) ||
               (isdigit(str.at(p - 1)) && isdigit(str.at(p + 1))) ) { // j*1 or 1*j or 1*1
                str.insert(p + 1, " ");
                str.insert(p, " ");
                p++;
            }
            // if(!(str.at(p - 1) == ' ')') {
            //     str.insert(p, " ");
            //     p++;
            // }
        } 
        
        if(str.at(p) == '/') {
            if((isdigit(str.at(p + 1)) && isalpha(str.at(p - 1))) || // j/1
               (isdigit(str.at(p - 1)) && isalpha(str.at(p + 1))) || // 1/j
               (isdigit(str.at(p - 1)) && isdigit(str.at(p + 1))) || // 1/1
               (isalpha(str.at(p - 1)) && isalpha(str.at(p + 1))) || // j/j
               (str.at(p - 1) == ')' && isalnum(str.at(p + 1))) ||   // )/j or j/(
               (isalnum(str.at(p - 1)) && str.at(p + 1) == '(')) { 
                str.insert(p + 1, " ");
                str.insert(p, " ");
                p++;
            }
        }
        
        if(str.at(p) == '+') {
            if((isdigit(str.at(p + 1)) && isalpha(str.at(p - 1))) || // j+1
               (isdigit(str.at(p - 1)) && isalpha(str.at(p + 1))) || // 1+j
               (isdigit(str.at(p - 1)) && isdigit(str.at(p + 1))) || // 1+1
               (isalpha(str.at(p - 1)) && isalpha(str.at(p + 1))) || // j+j
               (str.at(p - 1) == ')' && isalnum(str.at(p + 1))) ||   // )+j or j+(
               (isalnum(str.at(p - 1)) && str.at(p + 1) == '(')) { 
                str.insert(p + 1, " ");
                str.insert(p, " ");
                p++;
            }
        }
        
        if(str.at(p) == '-') {
            if((isdigit(str.at(p + 1)) && isalpha(str.at(p - 1))) || // j-1
               (isdigit(str.at(p - 1)) && isalpha(str.at(p + 1))) || // 1-j
               (isdigit(str.at(p - 1)) && isdigit(str.at(p + 1))) || // 1-1
               (isalpha(str.at(p - 1)) && isalpha(str.at(p + 1))) || // j-j
               (str.at(p - 1) == ')' && isalnum(str.at(p + 1))) ||   // )-j or j-(
               (isalnum(str.at(p - 1)) && str.at(p + 1) == '(')) { 
                str.insert(p + 1, " ");
                str.insert(p, " ");
                p++;
            }
        }
        
        if(str.at(p) == '%') {
            if((isdigit(str.at(p + 1)) && isalpha(str.at(p - 1))) || // j%1
               (isdigit(str.at(p - 1)) && isalpha(str.at(p + 1))) || // 1%j
               (isdigit(str.at(p - 1)) && isdigit(str.at(p + 1))) || // 1%1
               (isalpha(str.at(p - 1)) && isalpha(str.at(p + 1))) || // j%j
               (str.at(p - 1) == ')' && isalnum(str.at(p + 1))) ||   // )%j or j%(
               (isalnum(str.at(p - 1)) && str.at(p + 1) == '(')) { 
                str.insert(p + 1, " ");
                str.insert(p, " ");
                p++;
            }
        }
        
        // if(str.at(p) == '!') {
        //     str.insert(p, " ")
        // }
        
        if(str.at(p) == '&' && str.at(p + 1) == '&'){ //&&
            str.insert(p, " ");
            p++;
            str.insert(p + 2, " ");
        }
        if(str.at(p) == '&' && str.at(p - 1) == '>') { // >& to > &a
            str.insert(p, " ");
            p++;
        }
        if(str.at(p) == '&' && isalpha(str.at(p - 1))) { // a& b -> a &x
            str.insert(p, " ");
            p++;
        }
        
        if(str.at(p) == '|' && str.at(p + 1) == '|'){ // ||
            str.insert(p, " ");
            p++;
            str.insert(p + 2, " ");
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
            else if(isalpha(str.at(p + 1)) && str.at(p - 1) == '-') {
                
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
        
        if(str.at(p) == ')') {
            if(isalpha(str.at(p + 1))) {
                str.insert(p + 1, " ");
            }
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


