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
    return modified;
}

int main() {
    string test = " test 1 dksfkj nnkb ";
    string modified = removeWhiteSpace(test);
    cout << "Original string: " << test << endl;
    cout << "String with white space removed: " << modified << endl;
    
    return 0;
}