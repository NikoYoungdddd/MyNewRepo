#include<iostream>
#include<vector>
using namespace std;


int coinChange(vector<int> coin,int money )
{
	int* amount=new int [money+1];
	int i, j;
	amount[0] = 0;
	for (i = 1; i <= money; i++)
	{
		amount[i] = INT_MAX;//初始为极大值
		for (j = 0; j < coin.size(); j++)
		{
			if (i >= coin[j] && amount[i - coin[j]] != INT_MAX)//判定是否合法 关键步骤
			{
				amount[i] = min(amount[i - coin[j]] + 1, amount[i]);
			}
		}
	}
	return amount[money] == INT_MAX ? -1 : amount[money];
	
}

int main()
{
	vector<int> coins;
	int i,money;
	cout << "coins = (input z to end)";
	while (cin >> i)
	{
		coins.push_back(i);
	}
	
	cin.clear();
	cin.ignore();
	cout << "amount = ";
	cin >> money;
	cout << coinChange(coins, money) << endl;
	return 0;
}