#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#define FILENAME(n) "map" #n ".txt"

using namespace std;

vector<vector<vector<int>>> map;

int openFile()
{
    int fileNum = 0;
    ifstream file;

    file.open(FILENAME(fileNum));
    while(file.is_open())
    {
        int x = 0, y = 0;
        string map_str_line;
        vector<vector<int>> tmp_map;

        getline(file, map_str_line);
        y = map_str_line.length();

        vector<int> tmp_map_line(y, 2);

        for (int i = 0; i < y; i++)
            tmp_map_line[i] = map_str_line[i];

        while (!file.eof())
        {
            getline(file, map_str_line);

        }    

        file.open(FILENAME(++fileNum));
    }
    
}

vector& loadMap()
{

}