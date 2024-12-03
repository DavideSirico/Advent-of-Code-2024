#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int part1(string buffer);
unsigned long part2(string buffer);
int main() {
    fstream in;

    in.open("../long.txt", ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return -1;
    }

    int ris1 = 0;
    unsigned long ris2 = 0;
    string file;
    string buffer;
    while(getline(in, buffer)) {
        file.append(buffer);
    }
    ris1 = part1(file);
    ris2 = part2(file);
    // cout << ris1;
    cout << ris2;
    in.close();
    return 0;
}

unsigned long part2(string buffer) {
    unsigned long ris = 0;
    regex r(R"(mul\(\d*,\d*\)|do\(\)|don\'t\(\))");
    auto matches_begin = sregex_iterator(buffer.begin(), buffer.end(), r);
    auto matches_end = sregex_iterator();
    bool enabled = true;
    for (sregex_iterator it = matches_begin; it != matches_end; ++it) {
        string mul = it->str();
        if(mul == "do()") {
            enabled = true;
        } else if(mul == "don't()") {
            enabled = false;
        } else {
            // cout << "n1: " << mul.substr(mul.find_first_of('(')+1, (mul.find_first_of(',')-mul.find_first_of('(')-1)) << endl;
            // cout << "n2: " << mul.substr(mul.find_first_of(',')+1, (mul.find_first_of(')')-mul.find_first_of(',')-1)) << endl;
            string number1 = mul.substr(mul.find('(')+1, (mul.find(',')-mul.find('(')-1));
            string number2 = mul.substr(mul.find(',')+1, (mul.find(')')-mul.find(',')-1));

            int n1 = stoi(number1);
            int n2 = stoi(number2);
            if(enabled) {
                ris += n1*n2;
            }
        }
    }
    return ris;
}

int part1(string buffer) {
    int ris = 0;

    regex r(R"(mul\(\d*,\d*\))");

    auto matches_begin = sregex_iterator(buffer.begin(), buffer.end(), r);
    auto matches_end = sregex_iterator();
    for (sregex_iterator it = matches_begin; it != matches_end; ++it) {
        string mul = it->str();
        // cout << "n1: " << mul.substr(mul.find('(')+1, (mul.find_first_of(',')-mul.find_first_of('(')-1)) << endl;
        // cout << "n2: " << mul.substr(mul.find_first_of(',')+1, (mul.find_first_of(')')-mul.find_first_of(',')-1)) << endl;
        string number1 = mul.substr(mul.find_first_of('(')+1, (mul.find_first_of(',')-mul.find_first_of('(')-1));
        string number2 = mul.substr(mul.find_first_of(',')+1, (mul.find_first_of(')')-mul.find_first_of(',')-1));

        int n1 = stoi(number1);
        int n2 = stoi(number2);
        ris += n1*n2;
    }
    return ris;
}