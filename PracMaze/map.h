#pragma once
#include "maze.h"
#include <iostream>

class Map 
{
public:
	MapData mapdata;
	Map();
	void Load(string filename);//CSVƒtƒ@ƒCƒ‹‚Ì“Ç‚İ‚İ
	void DrawMap(int px,int py);
	void SetTreasure();//•ó•¨‚ÌêŠ‚ğ—”‚ÅŒˆ’è
};