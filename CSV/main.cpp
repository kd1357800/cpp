#include <iostream>
#include <string>
#include <vector>
#include <fstream>//ファイルストリーム
#include <sstream>//文字列ストリーム
using namespace std;
class Enemy {
private:
	string m_name;
	int m_hp, m_atk, m_def;
public:
	Enemy() = default;//デフォルトコンストラクタ
	Enemy(string name, int hp, int atk, int def)
		:m_name(name), m_hp(hp), m_atk(atk), m_def(def){};
	~Enemy() = default;//デフォルトデストラクタ

	string getName() { return m_name; }
	int getHp() { return m_hp; }
	int getAtk() { return m_atk; }
	int getDef() { return m_def; }
};
int main()
{
	//ファイル読み込み用ストリームの生成
	ifstream ifs("enemy_list.csv");
	if (ifs.fail())//ファイルオープンに失敗したら
	{
		cout << "ファイルオープンエラー" << endl;
		return -1;//エラーコード-1
	}
	
	vector<Enemy*> vEne{};//Enemyクラスの配列
	vector<string> v{};   //CSVの各項目を格納する配列
	string text;
	//int j = 0;//行番号管理用
	//読み込む行がなくなるとfalseが返る
	while (getline(ifs, text))//一行読み込んでtextに格納)
	{
		//vEne.resize(j + 1);//vに1行文の領域を追加
		istringstream iss(text);//文字列ストリーム生成
		while (getline(iss, text, ','))//第3引数は区切り文字を指定できる
		{
			v.push_back(text);//追加した領域に格納
		}
		vEne.push_back(new Enemy(
			//stoi：文字列を整数値に変換
			v[0],
			stoi(v[1]),
			stoi(v[2]),
			stoi(v[3])));
		v.clear();//全要素削除
		//j++;
	}

	ifs.close();

	for (auto d : vEne)
	{
		cout << d->getName() << "\t";
		cout << d->getHp()   << "\t";
		cout << d->getAtk()  << "\t";
		cout << d->getDef()  << endl;
	}
	ofstream ofs("enemy_list.csv", ios::app);
	ofs << "Rat, 8,5,2" << endl;
	ofs.close();

	//for (auto i : vEne)//行数ループ
	//{
	//	for (auto j : i)//列数ループ
	//	{
	//		cout << j << "\t";
	//	}
	//	cout << endl;
	//}
	//for (int i = 0; i < vEne.size(); i++)//行数ループ
	//{
	//	for (int j = 0; j < vEne[i].size(); j++)//列数ループ
	//	{
	//		cout << vEne[i][j] << "\t";
	//	}
	//	cout << endl;
	//}
	//
	for (auto d : vEne)
	{
		delete d;
	}
	vEne.clear();
	return 0;
}