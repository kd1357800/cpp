#include <map>
#include <vector>
#include <iostream>
using namespace std;

typedef struct {      //\‘¢‘ÌEnemy
	string name;
	int hp, atk, def;
}Enemy;

int main()
{
	vector<Enemy> vEne = { 
		{"Slime",10,5,8},
		{"Wolf",20,30,1},
		{"Spider",30,15,5} };

	vector<string, Enemy> mapEne;
	for (int i = 0; i < vEne.size(); i++)
	{
		mapEne.emplace(vEne[i].name, vEne[i]);

	}
	//for (auto e : vEne)
	//{
	//	mapEne.emplace(e.name, e);
	//	mapEne[e.name] = { e.name,e.hp,e.atk,e.def };
	//}
	string input;
	cout << "Enemy–¼‚ğ“ü—Í";
	cin >> input;
	if (mapEne.count(input))
	{
		count << "Name:" << mapEne[input].name << endl
			<< "HP:" << mapEne[input].hp << endl
			<< "Atk:" << mapEne[input].atk << endl
			<< "Def:" << mapEne[input].def << endl;
	}


	return 0;
}