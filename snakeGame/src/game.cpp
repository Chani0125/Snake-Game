// #include <ncurses/ncurses.h>
#include <ncurses.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "game_map.h"

using namespace std;

int main()
{
    int num = 0;
    LoadMapFile();

    cout << "[Map Test]" << "\n\n";

    for (vector<vector<int>> m : map)
    {
        cout << "[Map " << num++ << "]" << "\n";
        for (vector<int> x : m)
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
            for (vector<int> x : game_map)
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
