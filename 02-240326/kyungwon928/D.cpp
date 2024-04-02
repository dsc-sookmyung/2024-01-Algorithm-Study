#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ducks;

bool FindDuck(char letter, char quack, int num)
{

	if (letter == quack)
	{
		for (int i = 0; i < ducks.size(); i++)
		{
			if (ducks[i].size() % 5 == num)
			{
				ducks[i].push_back(letter);
				return false;
			}
		}
	}
	if (letter == 'q' && quack == 'q')
	{
		ducks.push_back("q");
		return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string sound;
	cin >> sound;
	bool fail;
	for (int i = 0; i < sound.size(); i++)
	{
		fail = true;
		char letter = sound[i];
		if (ducks.empty())
		{
			if (letter == 'q')
			{
				ducks.push_back("q");
				fail = false;
			}
		}
		else
		{
			fail &= FindDuck(letter, 'q', 0);
			fail &= FindDuck(letter, 'u', 1);

			fail &= FindDuck(letter, 'a', 2);

			fail &= FindDuck(letter, 'c', 3);

			fail &= FindDuck(letter, 'k', 4);
		}
		if (fail)
			break;
	}

	for (int i = 0; i < ducks.size(); i++)
	{
		if (ducks[i].length() % 5 != 0)
		{
			cout << "-1";
			return 0;
		}
	}
	if (fail)
		cout << "-1";
	else
		cout << ducks.size();

	return 0;
}