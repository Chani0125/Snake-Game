#ifndef _GAME_INFO_
#define _GAME_INFO_

struct GameInfo
{
    int body_length, num_growth, num_poison, num_gate, item3, item4;

    GameInfo(int body_length=3, int num_growth=0, int num_poison=0, int num_gate=0, int item3=0, int item4=0): 
    body_length(body_length), num_growth(num_growth), num_poison(num_poison), num_gate(num_gate), item3(item3), item4(item4){}

    friend bool operator==(const GameInfo &g1, const GameInfo &g2){
        return (g1.body_length == g2.body_length) && (g1.num_growth == g2.num_growth) && (g1.num_poison == g2.num_poison) && (g1.num_gate == g2.num_gate) && (g1.item3 == g2.item3) && (g1.item4 == g2.item4);
    }
};


#endif