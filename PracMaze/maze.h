#pragma once
#include <vector>
using namespace std;

enum MapObj
{
	ROAD,
	WALL,
	TREASURE
};

class MapData
{
private:
	vector<vector<int>> mapData{};
public:
	MapData();
	int getMapValue(int x, int y);//指定座標のデータを渡す
	int getMapSize(int i);//列数を取得
	int getMapSize();//行数取得
	void addMap(int j, int value);
	void resizeMap();
	void setMapValue(int x, int y, int value);

};