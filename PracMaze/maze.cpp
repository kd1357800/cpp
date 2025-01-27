#include "maze.h"

MapData::MapData() = default;

int MapData::getMapValue(int x, int y)
{
	return mapData[y][x];//座標の要素の値valueを返す
}

int MapData::getMapSize(int i)
{
	return mapData[i].size();//列数を返す
}

int MapData::getMapSize()
{
	return mapData.size();//行数を返す
}

void MapData::addMap(int j, int value)
{
	mapData[j].push_back(value);//行を指定してvalueを追加
}

void MapData::resizeMap()
{
	mapData.resize(mapData.size() + 1);//新しい行を追加
}

void MapData::setMapValue(int x, int y, int value)
{
	mapData[y][x] = value;//座標へvalueを格納
}
