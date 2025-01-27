#pragma once
#include "maze.h"
using namespace std;
struct Vector2
{
	int x, y;
	Vector2(int x, int y) : x(x), y(y) {};//C++では構造体もコンストラクタを持てる
};

class Player {
private:
	Vector2 Pos;
public:
	Player();
	Player(int x,int y);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	int move(char key, MapData& mapdata);//マップ上で移動可能か調べる
};
