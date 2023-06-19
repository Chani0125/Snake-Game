#ifndef _DRAW_
#define _DRAW_

using namespace std;

void ScreenUpdate();

void SetGameWindow();
void ScreenMap(char snake_head = 'O');
void ScreenBoard();
void ScreenScoreBoard();
void ScreenMissionBoard();

void LoadingScreen();
void StartScreen();

void NewStage();
void NextStage();
void GameOver();

#endif