#include "map.h"
#include "maze.h"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
using namespace std;

Map::Map() = default;

void Map::Load(string filename)
{
	ifstream ifs(filename);
	if (ifs.fail())
	{
		cout << "FileOpen Error" << endl;
		exit(-1);
	}

	string text;
	int j = 0;
	while (getline(ifs,text))
	{
		mapdata.resizeMap();
		istringstream iss(text);
		while (getline(iss,text,','))
		{
			mapdata.addMap(j, stoi(text));
		}
		j++;
	}
	ifs.close();
}

void Map::DrawMap(int px, int py)
{
	//py-2行目からpy+2行目までループ
	for (int y = py - 2; y <= py + 2; y++)
	{
		//px-2行目からpx+2行目までループ
		for (int x = px - 2; x <= px + 2; x++)
		{
			if (x== px && y == py)
			{
				cout << "@";
			}
			else
			{
				if (mapdata.getMapValue(x, y) == WALL)
				{
					cout << "\033[31m#\033[m";//壁
				}
				else if (mapdata.getMapValue(x, y) == ROAD)
				{
					cout << "\033[30m.\033[m";//通路
				}
				else if (mapdata.getMapValue(x, y) == TREASURE)
				{
					cout << "\033[33m$\033[m";//宝箱
				}
			}
		}
		cout << endl;
	}
}

void Map::SetTreasure()
{
	random_device rand_dev{};
	mt19937 rand_engine(rand_dev());
	uniform_int_distribution<int>
		rnd_x(2, mapdata.getMapSize(0) - 3);
	uniform_int_distribution<int>
		rnd_y(2,mapdata.getMapSize() - 3);
	while (true)
	{
		//宝物のX,Y座標を乱数で求める
		int trX = rnd_x(rand_engine);
		int trY = rnd_y(rand_engine);
		//マップデータ配列のX,Y座標が通路だったら
		if (mapdata.getMapValue(trX, trY) == ROAD)
		{
			//TREASUREに置き換える
			mapdata.setMapValue(trX, trY, TREASURE);
			break;
		}
	}
}
