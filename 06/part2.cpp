#include <iostream>
#include <fstream>
using namespace std;


bool is_position_outside(vector<string> map, int x, int y);
int main() {
    fstream in;

    in.open("../long.txt", ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return -1;
    }
    string buffer;
    vector<string> map;
    while(in>>buffer) {
        map.push_back(buffer);
    }
    int start_guard_x; 
    int start_guard_y;
    for(int i = 0; i < map.size(); i++) {
        for(int j = 0; j < map[0].size(); j++) {
            if(map[i][j] == '^' || map[i][j] == '>' || map[i][j] == '<' || map[i][j] == 'v') {
                start_guard_x = i;
                start_guard_y = j;
            }
        }
    }
    
    int counter = 0;
    for(int i = 0; i < map.size(); i++) {

        for(int j = 0; j < map[0].size(); j++) {
            vector<string> temp = map;
            if(temp[i][j] == '.') {
                temp[i][j] = '0';
                int guard_x = start_guard_x;
                int guard_y = start_guard_y;
                int direction = (int)temp[guard_x][guard_y];
                bool loop = false;
                int passi = 10000;
                while(true) {
                    if(passi == 0) {
                        loop = true;
                        break;
                    }
                    // se devo andare in alto
                    if(temp[guard_x][guard_y] == '^') {
                        // se vado fuori esco dal ciclo aumento e aumento il counter 
                        if(is_position_outside(temp, guard_x-1, guard_y)) {
                            break;
                        }
                        // se il prossimo blocco è libero  o è gia stato visitato avanzo
                        if(temp[guard_x-1][guard_y] == '.' || temp[guard_x-1][guard_y] == 'X') {
                            // lo marchio come già stato visitato
                            temp[guard_x][guard_y] = 'X';
                            // sposto la mia posizione nel prossimo blocco
                            guard_x--;
                            temp[guard_x][guard_y] = '^';
                            passi--;
                        // altrimenti cambio direzione
                        } else {
                            temp[guard_x][guard_y] = '>';
                        }
                    }
                    if(temp[guard_x][guard_y] == '>') {
                        if(is_position_outside(temp, guard_x, guard_y+1)) {
                            break;
                        }
                        if(temp[guard_x][guard_y+1] == '.' || temp[guard_x][guard_y+1] == 'X') {
                            temp[guard_x][guard_y] = 'X';
                            guard_y++;
                            temp[guard_x][guard_y] = '>';
                            passi--;
                        } else {
                            temp[guard_x][guard_y] = 'v';
                        }
                    }
                    if(temp[guard_x][guard_y] == '<') {
                        if(is_position_outside(temp, guard_x, guard_y-1)) {
                            break;
                        }
                        if(temp[guard_x][guard_y-1] == '.' || temp[guard_x][guard_y-1] == 'X') {
                            temp[guard_x][guard_y] = 'X';
                            guard_y--;
                            temp[guard_x][guard_y] = '<';
                            passi--;
                        } else {
                            temp[guard_x][guard_y] = '^';
                        }
                    }
                    if(temp[guard_x][guard_y] == 'v') {
                        if(is_position_outside(temp, guard_x+1, guard_y)) {
                            break;
                        }
                        if(temp[guard_x+1][guard_y] == '.' || temp[guard_x+1][guard_y] == 'X') {
                            temp[guard_x][guard_y] = 'X';
                            guard_x++;
                            temp[guard_x][guard_y] = 'v';
                            passi--;
                        } else {
                            temp[guard_x][guard_y] = '<';
                        }
                    }
                    /* for(auto str : temp) {
                        cout << str << endl;
                    }
                    cout << counter;
                    cout << endl << endl; */
                    if((int)temp[guard_x][guard_y] == direction && guard_x == start_guard_x && guard_y == start_guard_y) {
                        loop = true;
                        break;
                    }
                }
                if(loop) {
                    cout << counter << endl; 
                    counter++;
                }
            }
                
            // provo a mettere un nuovo blocco nella posizione i,j
            // creo una matrice temp per evitare di modificare quella originale
            // se passo per lo stesso percorso per 2 volte di fila esco e aggiungo al counter
            // se esco dalla mappa non aumento il counter
            // mi devo salvare un array con le posizioni delle celle che visito e confrontarlo ogni volta
            // l'array inzia vuoto e si riempe fino a quando ????

        }
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