#pragma once

class Rat {
public:
	Rat();
	~Rat();
	static void showNum();//静的メンバ関数
	void squeak();
private:
	int m_id;
	//初期化できない
	static int s_count;//静的メンバ変数
};