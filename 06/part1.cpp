#include <iostream>
#include <fstream>
using namespace std;


bool is_position_outside(vector<string> map, int x, int y);
int main() {
    fstream in;

    in.open("../short.txt", ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return -1;
    }
    string buffer;
    vector<string> map;
    while(in>>buffer) {
        map.push_back(buffer);
    }
    int guard_x; 
    int guard_y;
    for(int i = 0; i < map.size(); i++) {
        for(int j = 0; j < map[0].size(); j++) {
            if(map[i][j] == '^' || map[i][j] == '>' || map[i][j] == '<' || map[i][j] == 'v') {
                guard_x = i;
                guard_y = j;
            }
        }
    }
    
    int counter = 0;
    while(true) {
        // se devo andare in alto
        if(map[guard_x][guard_y] == '^') {
            // se vado fuori esco dal ciclo aumento e aumento il counter 
            if(is_position_outside(map, guard_x-1, guard_y)) {
                counter++;
                break;
            }
            // se il prossimo blocco è libero  o è gia stato visitato avanzo
            if(map[guard_x-1][guard_y] == '.' || map[guard_x-1][guard_y] == 'X') {
                // se è la prima volta che lo visito aumento il counter
                if(map[guard_x-1][guard_y] == '.') {
                    counter++;
                }
                // lo marchio come già stato visitato
                map[guard_x][guard_y] = 'X';
                // sposto la mia posizione nel prossimo blocco
                guard_x--;
                map[guard_x][guard_y] = '^';
            // altrimenti cambio direzione
            } else {
                map[guard_x][guard_y] = '>';
            }
        }
        if(map[guard_x][guard_y] == '>') {
            if(is_position_outside(map, guard_x, guard_y+1)) {
                counter++;
                break;
            }
            if(map[guard_x][guard_y+1] == '.' || map[guard_x][guard_y+1] == 'X') {
                if(map[guard_x][guard_y+1] == '.') {
                    counter++;
                }
                map[guard_x][guard_y] = 'X';
                guard_y++;
                map[guard_x][guard_y] = '>';

            } else {
                map[guard_x][guard_y] = 'v';
            }
        }
        if(map[guard_x][guard_y] == '<') {
            if(is_position_outside(map, guard_x, guard_y-1)) {
                counter++;
                break;
            }
            if(map[guard_x][guard_y-1] == '.' || map[guard_x][guard_y-1] == 'X') {
                if(map[guard_x][guard_y-1] == '.') {
                    counter++;
                }
                map[guard_x][guard_y] = 'X';
                guard_y--;
                map[guard_x][guard_y] = '<';
            } else {
                map[guard_x][guard_y] = '^';
            }
        }
        if(map[guard_x][guard_y] == 'v') {
            if(is_position_outside(map, guard_x+1, guard_y)) {
                counter++;
                break;
            }
            if(map[guard_x+1][guard_y] == '.' || map[guard_x+1][guard_y] == 'X') {
                if(map[guard_x+1][guard_y] == '.') {
                    counter++;
                }
                map[guard_x][guard_y] = 'X';
                guard_x++;
                map[guard_x][guard_y] = 'v';
            } else {
                map[guard_x][guard_y] = '<';
            }
        }
    }

    for(auto str : map) {
        cout << str << endl;
    }


    cout << counter;

    in.close();
    return 0;
}

bool is_position_outside(vector<string> map, int x, int y) {
    if(x >= map.size() || x < 0 || y >= map[0].size() || y < 0) {
        return true;
    }
    return false;
}