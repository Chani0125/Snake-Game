#include "map.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#define FILENAME(n) "map" + to_string(n) + ".txt"

using namespace std;

// vector<vector<vector<int>>> map = vector<vector<vector<int>>>(5, vector<vector<int>>(5, vector<int>(5, 5)));
vector<vector<vector<int>>> map;

int loadMapFile()
{
    int fileNum = 0;
    ifstream file;

    file.open("map0.txt");
    cout << "map0.txt" << " is opening" << "\n";
    if (file.fail())
        cout << "map0.txt" << " is not opened" << "\n\n";

    // file.open(FILENAME(fileNum));
    // cout << FILENAME(fileNum) << " is opening" << "\n";
    // if (file.fail())
    //     cout << FILENAME(fileNum) << " is not opened" << "\n\n";
    
    while(file.is_open())
    {
        if (file.eof())
        {
            fileNum++;
            continue;
        }

        cout << FILENAME(fileNum) << " is successfully opened" << "\n\n";

        int x = 0, y = 0;
        string map_str_line;
        vector<vector<int>> tmp_map;

        getline(file, map_str_line);
        y = map_str_line.length();

        cout << "str: " << map_str_line << "\n";

        vector<int> tmp_map_line(y, 2);

        for (int i = 0; i < y; i++)
            tmp_map_line[i] = map_str_line[i];
        tmp_map.push_back(tmp_map_line); x++;



        while (!file.eof())
        {
            getline(file, map_str_line);
            for (int i = 0; i < y; i++)
                tmp_map_line[i] = map_str_line[i];
            tmp_map.push_back(tmp_map_line); x++;
        }

        map.push_back(tmp_map);

        file.close();
        file.open(FILENAME(++fileNum));
    }

    return fileNum;
}
