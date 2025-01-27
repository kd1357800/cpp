#include "maze.h"
#include "player.h"
#include <iostream>
using namespace std;

Player::Player() : Pos(0, 0) {};
Player::Player(int x, int y) : Pos(x, y) {}

void Player::setX(int x)
{
	Pos.x = x;
}
void Player::setY(int y)
{
	Pos.y = y;
}
int Player::getX()
{
	return Pos.x;
}
int Player::getY()
{
	return Pos.y;
}
int Player::move(char key, MapData& mapdata)
{
	int newPosX = Pos.x;
	int newPosY = Pos.y;

	switch (key)
	{
	case 'w':
		newPosY--;
		break;
	case 'a':
		newPosX--;
		break;
	case 's':
		newPosY++;
		break;
	case 'd':
		newPosX++;
		break;
	case '@'://強制終了用
		exit(0);
	}

	//予測位置が壁でないかどうかのチェック
	if (mapdata.getMapValue(newPosX,newPosY) != WALL)
	{
		Pos.x = newPosX;//移送可能ならプレイヤーの位置を更新
		Pos.y = newPosY;

		//プレイヤーの位置が宝箱と重なるとき
		if (mapdata.getMapValue(newPosX, newPosY) == TREASURE)
		{
			return 99;
			//cout << "\033[033mお宝発見！！ゲームクリア\33[m" << endl;
			//exit(0);
		}
	}
	return 0;
}
;