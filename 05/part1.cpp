#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

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
        bool valid_page = true;
        for(vector<int> rule : order_rules) {
            auto pos_left = find(page.begin(), page.end(), rule[0]);
            auto pos_right = find(page.begin(), page.end(), rule[1]);
            if(pos_left == page.end() || pos_right==page.end()) {
                continue;
            }
            auto index_left = pos_left - page.begin();
            auto index_right = pos_right - page.begin();
            if(!(index_left<index_right)) {
                valid_page = false;
                break;
            }
        }
        if(valid_page) {
            cout << (page.size()) << endl;
            ris+=page[page.size()/2];
        }
            
    }
    cout << ris;
    in.close();
    return 0;
}