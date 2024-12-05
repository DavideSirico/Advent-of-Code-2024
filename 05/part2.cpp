#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


void print(vector<int> p) {
    for(int i = 0; i < p.size(); i++) {
        cout << p[i]<< " ";
    }
    cout << endl;
}
int main() {
    fstream in;

    in.open("../long.txt", ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return -1;
    }

    vector< vector<int> > order_rules;
    vector< vector<int> > pages;
    string line;
    while(getline(in, line) && !line.empty()) {
        int number1 = stoi(line.substr(0,2));
        int number2 = stoi(line.substr(3,4));
        vector<int> pair;
        pair.push_back(number1);
        pair.push_back(number2);
        order_rules.push_back(pair);
        cout << number1 << "|" << number2 << endl;
    }

    while(in>>line) {
        stringstream line_stream( line );
        vector<int> row;
        string temp;
        while(getline(line_stream, temp, ',')) {
            cout << temp << endl;
            row.push_back(stoi(temp));
        }
        // cout << row[0] << "," << row[1] << endl;
        pages.push_back(row);
    } 
    int ris = 0;
    for(vector<int> page : pages) {
        bool invalid_page = false;
        for(int i = 0; i < order_rules.size(); i++) {
            vector<int> rule = order_rules[i];
            auto pos_left = find(page.begin(), page.end(), rule[0]);
            auto pos_right = find(page.begin(), page.end(), rule[1]);
            if(pos_left == page.end() || pos_right==page.end()) {
                continue;
            }
            auto index_left = pos_left - page.begin();
            auto index_right = pos_right - page.begin();
            if(index_left>index_right) {
                invalid_page = true;
                int temp = page[index_left];
                page[index_left] = page[index_right];
                page[index_right] = temp;
                i = 0;
            }
        }
        if(invalid_page) {
            print(page);
            //cout << page[page.size()/2] << " ";
            ris+=page[page.size()/2];
        }
            
    }
    cout << ris;
    in.close();
    return 0;
}