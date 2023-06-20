#ifndef _GAME_INFO_
#define _GAME_INFO_

struct GameInfo
{
    short body_len, max_body_len, n_growth, n_poison, n_gate;

    GameInfo(short body_len=3, short max_body_len=3, short n_growth=0, short n_poison=0, short n_gate=0)
    : body_len(body_len), max_body_len(max_body_len), n_growth(n_growth), n_poison(n_poison), n_gate(n_gate) {}

    friend bool operator==(const GameInfo &g1, const GameInfo &g2)
    {
        return (g1.body_len == g2.body_len) && (g1.max_body_len == g2.max_body_len) && (g1.n_growth == g2.n_growth) && (g1.n_poison == g2.n_poison) && (g1.n_gate == g2.n_gate);
    }
};


#endif