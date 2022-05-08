#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int Levenshtein_dis( string s1, string s2, int InsertCost, int DeleteCost, int ReplaceCost)
{

    int M = s1.length() - 1;
    int N = s2.length() - 1;
    int Main_Array[100][100];// Here D[100][100] because s1.length() < 100, s2.length() < 100;
    Main_Array[0][0] = 0;
    for (int j = 1; j <= N; j++)
    {
        Main_Array[0][j] = j * InsertCost;
    }


    for (int i = 1; i <= M; i++)
    {
        Main_Array[i][0] = i * DeleteCost;
        for (int j = 1; j <= N; j++)
        {
            if (s1[i - 1] != s2[j - 1])
            {
                Main_Array[i][j] = min(min(
                    Main_Array[i - 1][j] + DeleteCost,
                    Main_Array[i][j - 1] + InsertCost),
                    Main_Array[i - 1][j - 1] + ReplaceCost);
            }
            else
            {
                Main_Array[i][j] = Main_Array[i - 1][j - 1];
            }
        }
    }
    return Main_Array[M][N];
}

int main()
{
    cout << Levenshtein_dis("symmetric", "asymmetrical", 1, 1, 1) << "\n";

    const string a = "First string for find distance Levenshtein's";
    const string b = "Second string";
    cout << Levenshtein_dis(a, b, 1, 1, 1);
    return 0;
}