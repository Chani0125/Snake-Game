#include "game_info.h"
#include "snake.h"

class Mission
{
private:
    GameInfo current;
    GameInfo goal;
public:
    Mission();
    Mission(int body_length, int num_growth, int num_poison, int num_gate, int item3, int item4);
    friend bool Snake::move(Point next_pos);
    bool isCleared();
    ~Mission();
};
