//Kuchiguse 
/*
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:
Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)

Now given a few lines spoken by the same character, can you find her Kuchiguse?
*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

map<string, int>subStrings;
void getSubStr(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		subStrings[s.substr(i)]++;
	}
}

int main()
{
	int N;
	cin >> N;
	string temps;
	getline(cin, temps);
	for (int i = 0; i < N; i++)
	{
		temps.clear();
		getline(cin, temps);
		//本来以为一定要是最后一个单词，结果是空格也可以包括的最后n个单词都算
		//string flag = " ";
		//string::size_type position;
		//position = temps.rfind(flag);
		//if (position != temps.npos)
		//{
		//	temps = temps.substr(position+1);
		//}
		getSubStr(temps);
	}
	//find count and max
	string max;
	map<string, int>::iterator iter;
	for (iter=subStrings.begin();iter!=subStrings.end();iter++)
	{
		if (iter->second == N&&iter->first.size() > max.size())
		{
			max = iter->first;
		}
	}
	if (max.empty())
		max = "nai";
	cout << max << endl;
}
