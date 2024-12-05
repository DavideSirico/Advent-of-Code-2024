#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream in;

    in.open("../input.txt", ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return -1;
    }


    in.close();
    return 0;
}