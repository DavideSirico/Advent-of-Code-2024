#include <iostream>
#include <fstream>
using namespace std;

int minu(int a, int b) {  
    return (a < b) ? a : b;  
} 
  
int min(int a, int b, int c) {  
    return minu(minu(a, b), c); 
} 
  
int max(int a, int b) {  
    return (a > b) ? a : b; 
}

int check_hor(string row);
int check_vert(vector<string> rows);
int check_obl(vector<string> rows);
int main() {
    fstream in;
    fstream out;

    in.open("../long.txt", ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return -1;
    }
    string buffer;
    int counter = 0;
    vector<string> stringhe;
    while(in>>buffer) {
        counter += check_hor(buffer);
        stringhe.push_back(buffer);
    }
    cout << "oriz: " << counter << endl;
    counter += check_vert(stringhe);
    cout << "vert: " << counter << endl;
    counter += check_obl(stringhe);
    cout << counter << endl;
    in.close();
    return 0;
}

int check_vert(vector<string> rows) {
    int counter = 0;

    for(int i = 0; i < rows[0].size(); i++) {
        string vert_str;
        for(int j = 0; j < rows.size(); j++) {
            vert_str += rows[j][i];
        }
        cout << vert_str << endl;
        counter += check_hor(vert_str);
    }


    return counter;
}

int check_obl(vector<string> rows) {
    int counter = 0;

    int ROW = rows[0].size();
    int COL = rows.size();
    for(int line = 1; line <= (ROW + COL - 1); line++) { 
        int start_col =  max(0, line - ROW); 
        int count = min(line, (COL - start_col), ROW); 
        string diag_str;
        for(int j = 0; j < count; j++) {
            diag_str += rows[minu(ROW, line) - j - 1][start_col + j];
        }
        // cout << diag_str << endl;
        counter += check_hor(diag_str);
    } 

    // flips the matrix horizontally
    vector<string> temp = rows;
    for(int i = 0; i < rows.size(); i++) {
        for(int j = 0; j < rows[i].size(); j++) {
            temp[i][j] = rows[i][rows[i].size() - j - 1];
        }
    }
    rows = temp;

    for(int line = 1; line <= (ROW + COL - 1); line++) { 
        int start_col =  max(0, line - ROW); 
        int count = min(line, (COL - start_col), ROW); 
        string diag_str;
        for(int j = 0; j < count; j++) {
            diag_str += rows[minu(ROW, line) - j - 1][start_col + j];
        }
        // cout << diag_str << endl;
        counter += check_hor(diag_str);
    }
    return counter;
} 

int check_hor(string row) {
   int occurrences = 0;
   string::size_type pos = 0;
   string target = "XMAS";
    while ((pos = row.find(target, pos )) != string::npos) {
        ++occurrences;
        pos += target.length();
    }
    pos = 0;
    target = "SAMX";
    while ((pos = row.find(target, pos )) != string::npos) {
        ++occurrences;
        pos += target.length();
    }

    return occurrences;
}