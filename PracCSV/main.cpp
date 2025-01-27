#include <iostream>//cout,string,endl
#include <fstream>//ifstream
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>//setw
using namespace std;
class Weapon
{
public:
	Weapon() = default;
	Weapon(string name, int atk, int price, int weight)
		: m_name(name), m_atk(atk), m_price(price), m_weight(weight) {};
	~Weapon() = default;

	string GetName() { return m_name; }
	int GetAtk() { return m_atk; }
	int GetPrice() { return m_price; }
	int GetWeight() { return m_weight; }

private:
	string m_name;
	int m_atk;
	int m_price;
	int m_weight;
};

int main() 
{
	ifstream ifs("wepon_list.csv");
	if (ifs.fail())
	{
		cout << "error" << endl;
		return -1;
	}
	vector<Weapon*>vWpn{};
	vector<string>v{};//一時的にCSVの各項目を格納する配列
	string text;

	getline(ifs,text);//1行読み捨て

	while (getline(ifs,text))
	{
		istringstream iss(text);
		while (getline(iss,text,','))
		{
			v.push_back(text);//分割した項目を配列へ追加
		}
		//CSVから分割した項目をWeaponクラスのコンストラクタの引数として
		//インスタンスを生成し、そのインスタンスのアドレスをvWpnへ格納
		vWpn.push_back(new Weapon(v[0], stoi(v[1]), stoi(v[2]), stoi(v[3])));
		v.clear();//配列の要素を削除
	}
	ifs.close();

	for (int i = 0; i < vWpn.size(); i++)
	{
		cout << i << ':' << left << setw(20) << vWpn[i]->GetName();
		
		if (vWpn[i]->GetPrice() >= 0)
		{
			cout << right << setw(8) << vWpn[i]->GetPrice() << 'G';
		}
		else
		{
			cout << right << setw(9) << "-非売品-";
		}
		cout << endl;
	}
	cout << endl;

	int num;
	cout << "どの武器を購入しますか？＞";
	cin >> num;//キーボードから入力
	if (num >= 0 && num < vWpn.size())
	{
		if (vWpn[num]->GetPrice() >= 0)
		{
			cout << vWpn[num]->GetName() << "を購入した" << endl;
			cout << "攻撃力が" << vWpn[num]->GetAtk() << "アップした" << endl;
			cout << "重量が" << vWpn[num]->GetWeight() << "増えた" << endl;
		}
		else
		{
			cout << vWpn[num]->GetName() << "は非売品です" << endl;
		}
	}
	else
	{
		cout << "リスト内の武器を選択してください" << endl;
	}

	return 0;
}