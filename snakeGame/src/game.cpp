#include <ncurses.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "game_map.h"

using namespace std;

// unit: ms
int tick = 500;

int main()
{
    int num = 0;
    LoadMapFile();

    cout << "[Map Test]" << "\n\n";

    for (vector<vector<short>> m : map)
    {
        cout << "[Map " << num++ << "]" << "\n";
        for (vector<short> x : m)
        {
            for (int y : x)
            {
                cout << y << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    int e;

    do
    {
        int map_num = CreateMap(false);
        cout << "[Play Map " << map_num << "]" << "\n";
            for (vector<short> x : play_map)
            {
                for (int y : x)
                {
                    cout << y << " ";
                }
                cout << "\n";
            }
            cout << "\n";

        cin >> e;
    } while (e);

    return 0;
}
