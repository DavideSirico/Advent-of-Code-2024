#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

vector< vector<char> > operation_combinations(long long int n) {
    vector< vector<char> > operations;
    long long int num_operations = n - 1;
    long long int total_combinations = std::pow(2, num_operations);

    for (long long int i = 0; i < total_combinations; i++) {
        vector<char> operation;
        for (long long int j = 0; j < num_operations; j++) {
            if (i & (1 << j)) {
                operation.push_back('*');
            } else {
                operation.push_back('+');
            }
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
                if (operation[i] == '+') {
                    res += numbers[i + 1];
                } else if (operation[i] == '*') {
                    res *= numbers[i + 1];
                }
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