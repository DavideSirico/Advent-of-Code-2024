#include <iostream>
#include <fstream>
using namespace std;

int submatrix(vector<string> rows);
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
        stringhe.push_back(buffer);
    }
    counter = submatrix(stringhe);
    cout << counter << endl;
    in.close();
    return 0;
}

int submatrix(vector<string> rows) {
    int counter = 0;
    for(int i = 0; i < rows.size(); i++) {
        for(int j = 0; j < rows[0].size(); j++) {
            /*
            "M.S"
            ".A."
            "M.S"
            */       
            int found = 0;
            if(rows[i][j] == 'A') {
                if(i>0 && j>0 && rows[i-1][j-1] == 'M') {
                    found++;
                }
                if(i>0 && j<rows.size()-1 && rows[i-1][j+1] == 'S') {
                    found++;
                }
                if(j>0 && i<rows.size()-1 && rows[i+1][j-1] == 'M') {
                    found++;
                }
                if(j<rows.size()-1 && i<rows.size()-1 && rows[i+1][j+1] == 'S') {
                    found++;
                }
            }
            if(found == 4) {
                counter++;
            }
            /*
            "S.S"
            ".A."
            "M.M"
            */
            found = 0;  
            if(rows[i][j] == 'A') {
                if(i>0 && j>0 && rows[i-1][j-1] == 'S') {
                    found++;
                }
                if(i>0 && j<rows.size()-1 && rows[i-1][j+1] == 'S') {
                    found++;
                }
                if(j>0 && i<rows.size()-1 && rows[i+1][j-1] == 'M') {
                    found++;
                }
                if(j<rows.size()-1 && i<rows.size()-1 && rows[i+1][j+1] == 'M') {
                    found++;
                }
            }
            if(found == 4) {
                counter++;
            }
            /*
            "M.M"
            ".A."
            "S.S"
            */
            found = 0;  
            if(rows[i][j] == 'A') {
                if(i>0 && j>0 && rows[i-1][j-1] == 'M') {
                    found++;
                }
                if(i>0 && j<rows.size()-1 && rows[i-1][j+1] == 'M') {
                    found++;
                }
                if(j>0 && i<rows.size()-1 && rows[i+1][j-1] == 'S') {
                    found++;
                }
                if(j<rows.size()-1 && i<rows.size()-1 && rows[i+1][j+1] == 'S') {
                    found++;
                }
            }
            if(found == 4) {
                counter++;
            }
            /*
            "S.M"
            ".A."
            "S.M"
            */
            found = 0;  
            if(rows[i][j] == 'A') {
                if(i>0 && j>0 && rows[i-1][j-1] == 'S') {
                    found++;
                }
                if(i>0 && j<rows.size()-1 && rows[i-1][j+1] == 'M') {
                    found++;
                }
                if(j>0 && i<rows.size()-1 && rows[i+1][j-1] == 'S') {
                    found++;
                }
                if(j<rows.size()-1 && i<rows.size()-1 && rows[i+1][j+1] == 'M') {
                    found++;
                }
            }
            if(found == 4) {
                counter++;
            }
        }
    }
    return counter;
}