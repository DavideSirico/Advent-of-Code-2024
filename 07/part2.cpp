#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

vector< vector<char> > operation_combinations(long long int n) {
    vector< vector<char> > operations;
    for (long long int i = 0; i < pow(3, n-1); i++) {
        vector<char> operation;
        int temp = i;
        for (long long int j = 0; j < n-1; j++) {
            int op = temp % 3;
            if (op == 0) {
                operation.push_back('+');
            } else if (op == 1) {
                operation.push_back('*');
            } else {
                operation.push_back('|');
            }
            temp /= 3;
        }
        operations.push_back(operation);
    }

    return operations;
}


int main() {
    fstream in;

    in.open("../long.txt", ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return -1;
    }
    string buffer;
    long long int ris = 0;
    while(getline(in, buffer)) {
        bool possible = false;
        long long int result = stoll(buffer.substr(0, buffer.find(':')));
        buffer.replace(0,buffer.find(':')+2,"");
        vector<long long int> numbers;
        stringstream line_stream( buffer );
        long long int temp;
        while(line_stream>>temp) {
            numbers.push_back(temp);
        }
        vector< vector <char> > operations;
        operations = operation_combinations(numbers.size());
        /* for(auto v : operations) {
            for(auto c : v) {
                cout << c << " ";
            }
            cout << endl;
        } */
        // cout << endl;
        for(vector<char> operation : operations) {
            long long int res = numbers[0];
            for (long long int i = 0; i < operation.size(); i++) {
                if(numbers[i + 1] != -1) {
                    if (operation[i] == '+') {
                        res += numbers[i + 1];
                    } else if (operation[i] == '*') {
                        res *= numbers[i + 1];
                    } else if(operation[i] == '|') {
                        res = stoll(to_string(res)+to_string(numbers[i+1]));
                    }
                }
                // 6 8 6 15
                // 6 + 8 | 6 + 15
                // 14 | 6
            }
            if(result == res) {
                possible = true;
                break;
            }
        }
        if(possible) {
            ris+=result;
        }

    } 

    cout << ris;

    in.close();
    return 0;
}