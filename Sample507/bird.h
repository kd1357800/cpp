#pragma once
#include <iostream>
#include <string>
using namespace std;
class Bird
{
public:
	virtual void sing() = 0;//純粋仮想関数
	virtual void fly() = 0;//Birdには中身は何もない　　処理は子クラスでする
};