#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void print_records(vector< vector<int> > records);
void print_diffs(vector<int> diffs);
bool crescente(vector<int> array);
bool decrescente(vector<int> array);
int part1(vector< vector<int> > records);
int part2(vector< vector<int> > records);
int main() {
    fstream in;
    fstream out;

    in.open("../input.txt", ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return -1;
    }

    vector< vector<int> > records;
    while (in) {
        vector<int> record;
        int buffer;

        while (in >> buffer) {
            record.push_back(buffer);
            if (in.peek() == '\n' || in.peek() == EOF) {
                break;
            }
        }

        if (!record.empty()) {
            records.push_back(record);
        }
    }

    print_records(records);
    //cout << part1(records);
    cout << part2(records);

    in.close();
    return 0;
}



void print_diffs(vector<int> diffs) {
    for(int diff : diffs) {
        cout << diff << " ";
    }
    cout << endl;
}

void print_records(vector< vector<int> > records) {
    for(vector<int> record : records) {
        for(int element : record) {
            cout << element << " ";
        }
        cout << endl;
    }
    cout << endl;
} 

int part1(vector< vector<int> > records) {
    int counter = 0;
    for(vector<int> record : records) {
        if(crescente(record)  || decrescente(record)) {
            counter++;
        }

    }
    return counter;
}

int part2(vector< vector<int> > records) {
    int counter = 0;
    for(vector<int> record : records) {
        bool valid = crescente(record) || decrescente(record);
        for(int i = 0; i < record.size() && !valid; i++) {
            vector<int> temp_record = record;
            temp_record.erase(temp_record.begin()+i);
            if(crescente(temp_record) || decrescente(temp_record)) {
                valid = true;
            }
        }
        if(valid) {
            counter++;
        }
    }
    return counter;
}

bool crescente(vector<int> array) {
    for(int i = array.size()-1; i > 0; i--) {
        if(!((array[i] - array[i-1])>=1 && (array[i] - array[i-1])<=3)) {
            return false;
        }
    }
    return true;
}

bool decrescente(vector<int> array) {
    for(int i = 0; i < array.size()-1; i++) {
        if(!((array[i] - array[i+1])>=1 && (array[i] - array[i+1])<=3)) {
            return false;
        }
    }
    return true;
}