#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
//#include <algorithm>
#include <cmath>
using namespace std;

template<typename T>
void insertRight(vector<T> &a, unsigned p, unsigned l) {
    T temp;
    while (p <= l && a.at(p) < a.at(p - 1)) {
        // Swap a.at(p) and a.at(p - 1)
        temp = a.at(p);
        a.at(p) = a.at(p - 1);
        a.at(p - 1) = temp;
        ++p;
    }
}

template<typename T>
void RInsertionSort(vector<T> &a, unsigned blockStart, unsigned blockEnd) {
    //unsigned blockEnd = blockStart + s;
    // for(int p = blockEnd - 1; p > 0; --p) {
    //     T tmp = move(a.at(p));
    //     int j;
    //     for(int j = p; j < blockEnd && tmp > a.at(j+1); ++j) {
    //         a.at(j) = move(a.at(j+1));
    //     }
    //     a.at(j) = move(tmp);
    // }
    unsigned z = 0;
   //unsigned j = 0;
   //T temp;  // Temporary variable for swap
   
   for (z = blockEnd; z > 0; --z) {
        //j = z;
        // Insert a.at(i) into sorted part
        // stopping once a.at(i) in correct position
        insertRight(a, z, blockEnd);
   }

}

template<typename T>
void SquareSort(vector<T> &v) {
    int b = static_cast<int>(sqrt(v.size()));
    int s = static_cast<int>(v.size() / b);
    vector<unsigned> left;
    
    for(unsigned x = 0, y = 0; x <= b; y += s, ++x) {
        left.push_back(y);
    }
    
    for(unsigned s = 0; s < left.size(); ++s) {
        if(s == left.size() - 1) {
            RInsertionSort(v, left.at(s), v.size() - 1);
        }
        else {
            RInsertionSort(v, left.at(s), left.at(s + 1) - 1);
        }
    }
    
    unsigned minIndex = 0;
    unsigned currentBlock = 0;
    for(unsigned t = 0; t < v.size(); ++t) {
        for(unsigned r = 0; r < left.size(); ++r) {
            if(t >= left.at(r) && t < left.at(r + 1)) {
                currentBlock = r;
            }
        }
        minIndex = t;
        for(unsigned u = currentBlock; u < left.size(); ++u) {
            if(v.at(minIndex) < v.at(left.at(u))) {
                minIndex = u;
            }
        }
        T temp = v.at(minIndex);
        v.at(minIndex) = v.at(t);
        v.at(t) = temp; 
            
        if(currentBlock < left.size() - 1) {    
            insertRight(v, minIndex, left.at(currentBlock + 1) - 1);
        }
        else {
            insertRight(v, minIndex, v.size() - 1);
        }
    }
}

class Fraction
{
    int gcd(int a, int b) {return b==0 ? a : gcd(b,a%b); }
    int n, d;
 public:
    Fraction(int n, int d = 1) : n(n/gcd(n,d)), d(d/gcd(n,d)) {}
    int num() const { return n; }
    int den() const { return d; }
    Fraction& operator*=(const Fraction& rhs) {
        int new_n = n*rhs.n / gcd(n*rhs.n, d*rhs.d);
        d = d*rhs.d / gcd(n*rhs.n, d*rhs.d);
        n = new_n;
        return *this;
    }
};

ostream& operator<<(ostream& out, const Fraction& f) {
   return out << f.num() << '/' << f.den() ;
}
bool operator==(const Fraction& lhs, const Fraction& rhs) {
    return ((lhs.num() * rhs.den()) == (rhs.num() * lhs.den()));
}
bool operator<(const Fraction& lhs, const Fraction& rhs) {
    return (lhs.num() * rhs.den() < rhs.num() * lhs.den());
}
bool operator>(const Fraction& lhs, const Fraction& rhs) {
    return (lhs.num() * rhs.den() > rhs.num() * lhs.den());
}
Fraction operator*(Fraction lhs, const Fraction& rhs) {
    return lhs *= rhs;
}

int main(int argc,char* argv[]) {
    ifstream ifs;
    ofstream ofs;
    string inputName = ""; //input file's name
    string outputName = ""; //output file's name
    
    if(argc > 1) {
        cout << "Opening file " << argv[1] << "." << endl;
        
        ifs.open(argv[1]);
        if(!ifs.is_open()) {
            cout << "Could not open file " << argv[1] << "." << endl;
            return 1;
        }
        
        outputName = argv[1];
        outputName.replace(outputName.length() - 3, 3, "out", 0, 3);
    }
    else {
        cout << "Enter name of file to use for input: ";
        cin  >> inputName;
        cout << endl;
        
        cout << "Opening file " << inputName << "." << endl;
        
        ifs.open(inputName.c_str());
        if(!ifs.is_open()) {
            cout << "Could not open file " << inputName << "." << endl;
            return 1;
        }
        
        outputName = inputName;
        outputName.replace(outputName.length() - 3, 3, "out", 0, 3);
    }
    
    ofs.open(outputName.c_str(), fstream::trunc | fstream::out);
    if(!ofs.is_open()) {
            cout << "Could not open file " << outputName << "." << endl;
            return 1; // 1 indicates error
        }
    cout << "Outputting to " << outputName << "." << endl;
    
    char type;
    int i;
    int numerator, denominator;
    vector<int> vis; //int vector to be sorted with square sort
    vector<int> vic; //int vector to be sorted with cubic sort
    vector<Fraction> vfs; //Fraction vector to be sorted with square sort
    vector<Fraction> vfc; //Fraction vector to be sorted with cubic sort
    while(ifs.good()) {
        ifs >> type;
        if(type == 'i') {
            while(ifs >> i) {
                vis.push_back(i);
            }
            vic = vis;
            //square sort
            SquareSort(vis);
            //output to terminal
            cout << "i" << endl;
            for(unsigned z = 0; z < vis.size(); ++z) {
                if(z == vis.size() - 1) {
                    cout << vis.at(z);
                }
                else {
                    cout << vis.at(z) << " ";
                }
            }
            cout << endl;
            //output to file
            ofs << "i" << endl;
            for(unsigned z = 0; z < vis.size(); ++z) {
                if(z == vis.size() - 1) {
                    ofs << vis.at(z);
                }
                else {
                    ofs << vis.at(z) << " ";
                }
            }
            cout << endl;
            //cubic sort
            
            //output to terminal
            
            //output to file
            
        }
        else {
            while(ifs >> numerator >> denominator) {
                vfs.push_back(Fraction(numerator, denominator));
            }
            vfc = vfs;
            //square sort
            //SquareSort(vfs);
            //output to terminal
            cout << "f" << endl;
            for(unsigned z = 0; z < vfs.size(); ++z) {
                if(z == vfs.size() - 1) {
                    cout << vfs.at(z);
                }
                else {
                    cout << vfs.at(z) << " ";
                }
            }
            cout << endl;
            //output to file
            ofs << "f" << endl;
            for(unsigned z = 0; z < vfs.size(); ++z) {
                if(z == vfs.size() - 1) {
                    ofs << vfs.at(z);
                }
                else {
                    ofs << vfs.at(z) << " ";
                }
            }
            ofs << endl;
            //cubic sort
            //output to terminal
            //output to file
        }
    }
    
    ifs.close();
    ofs.close();
    
    return 0;
}