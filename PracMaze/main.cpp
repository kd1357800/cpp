#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
#include "player.h"
#include <random>
#include <algorithm>
#include "battle.h"

using namespace std;
int main()
{
	Map map;//マップクラスの作成
	map.Load("stage.csv");//マップファイルの読み込みと格納
	map.SetTreasure();//宝物の配置
	Player player;//Playerクラスのインスタンスの作成
	Battle battle;//Battleクラスのインスタンスの作成
	system("cls");//コマンドプロンプトの画面消去

	random_device rnd_dev{};
	mt19937 rnd_engine(rnd_dev());
	uniform_int_distribution<int>
		rnd_x(2, map.mapdata.getMapSize(0) - 3);
	uniform_int_distribution<int>
		rnd_y(2, map.mapdata.getMapSize() - 3);
	while (true)
	{
		int px = rnd_x(rnd_engine);//X座標用の乱数生成
		int py = rnd_y(rnd_engine);//Y座標用の乱数生成
		if (map.mapdata.getMapValue(px, py) == ROAD)
		{
			player.setX(px);
			player.setY(py);
			break;
		}
	}

	while (true)
	{
		//コマンドプロンプトの表示位置を(0,0)へ設定
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
		map.DrawMap(player.getX(), player.getY());//マップの描画

		char input = _getch();
		if (player.move(input, map.mapdata) == 99)
		{
			//バトル開始
			if (battle.Initialize() == 0)
			{
				//戦闘に勝利したとき
				cout << "\033[033mお宝発見！！ゲームクリア\33[m" << endl;
				exit(0);
			}
			else
			{
				//戦闘に敗北したとき
				cout << "\033[031mゲームオーバー\33[m" << endl;
			}
		}

	}
	return 0;
}