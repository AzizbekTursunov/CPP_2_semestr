#include <iostream>
#include <string>
using namespace std;

struct Cat
{
private:
	string _name = "";
	int _age = 0;
	bool _is_set_name = false;
	bool _is_set_age = false;
	
public:
	int Health = 5;
	int foodCount = 1;
	int hit = 1;
	string GetName()
	{
		return _name;
	}
	void SetAge(int age) 
	{
		if (_is_set_age == false) {
			_age = age;
			_is_set_age = true;
		}
	}
	void SetName(string name) 
	{
		if (_is_set_name == false) {
			_name = name;
			_is_set_name = true;
		}
	}
	void Feed() { Health += foodCount; }
	void Punish() { Health -= hit; }
	int GetAge() { return _age; }
	string Color() 
	{
		if (Health <= 5) { return "Red"; }
		else if (Health > 5 && Health < 10) { return "Yellow"; }
		else if (Health >= 10) { return "Green"; }
	}

};
int main() 
{
	setlocale(LC_ALL, "");
	Cat mycat;
	string mycat_name;
	int mycat_age;
	string Feed_or_Punish;
	cout << "Задайте имю кошке!" << "\n";
	cin >> mycat_name;
	cout << "Задайте возраст кошке!" << "\n";
	cin >> mycat_age;
	mycat.SetName(mycat_name);
	mycat.SetAge(mycat_age);
	cout << "Имя кошки : " << mycat.GetName() << "\n" << "Возраст кошки : " << mycat.GetAge() << "\n";
	cout << "Если вы хотите покормит кошку введите букву : f" << "\n";
	cout << "Если вы хотите наказыват кошку введите букву : p" << "\n";
	while (mycat.Health > 0)
	{
		cin >> Feed_or_Punish;
		if (Feed_or_Punish == "f") { mycat.Feed(); }
		else if (Feed_or_Punish == "p") { mycat.Punish(); }
		cout << "Your cats color : " << mycat.Color() << "\n" << "Your cats health : " << mycat.Health << "\n";
	}
	if (mycat.Health == 0) { cout << "Ваш кот умер!"; }
}