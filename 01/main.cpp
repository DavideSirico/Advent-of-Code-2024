#include <iostream>
#include <fstream>
using namespace std;

long part1(long long *array1, long long *array2, int lenght);
long part2(long long *array1, long long *array2, int lenght);
void sort(long long array[], int lenght);
void swap(long long &a, long long &b);
int main() {
    fstream in;

    in.open("../input.txt", ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return 0;
    }

    int lenght = 0;
    int temp1, temp2;
    while(in >> temp1 >> temp2) {
        lenght++;
    }

    in.close();
    in.open("../input.txt", ios::in);
    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return 0;
    }
    long long *array1 = new long long[lenght];
    long long *array2 = new long long[lenght];
    int c = 0;
    while(in >> temp1 >> temp2) {
        array1[c] = temp1;
        array2[c] = temp2;
        c++;
    }
    in.close();

    
    long sum = part1(array1, array2, lenght);
    cout << sum << endl;

    long similitary_score = part2(array1, array2, lenght);
    cout << similitary_score << endl;

    return 0;
}

long part2(long long *array1, long long *array2, int lenght) {
    long similitary_score = 0;
    for(int i = 0; i < lenght; i++) {
        long long current = array1[i];
        for(int j = 0; j < lenght; j++) {
            if(current == array2[j]) {
                similitary_score += current;
            }
        }
    }
    return similitary_score;
}

long part1(long long *array1, long long *array2, int lenght) {
    sort(array1, lenght);
    sort(array2, lenght);
    long sum = 0;
    for(int i = 0; i < lenght; i++) {
        long long diff = array1[i] - array2[i];
        if(diff<0) {
            diff = diff * (-1);
        }
        // cout << diff << endl;
        sum = sum+diff;
    }
    return sum;
}
void swap(long long &a, long long &b) {
    long long temp = a;
    a = b;
    b = temp;
}

void sort(long long array[], int lenght) {
    for(int i = 0; i < lenght-1; i++) {
        for(int j = i + 1; j < lenght; j++) {
            if(array[i] > array[j]) {
                swap(array[i], array[j]);
            }
        }
    }
}