/*
 * @Author: fzy
 * @Date: 2018-08-16 10:12:22
 * @LastEditors: zhenying
 * @LastEditTime: 2018-08-16 10:14:43
 * @Description: 
 */
#include <iostream>
#include <vector> 

using namespace std;

class Solution
{
public:

    vector<int> BucketSort(vector<int> vec1)
    {
        if (vec1.size() < 2)
        {
            return vec1;
        }
        int nmax = 0x80000000;
        for (int i = 0; i < vec1.size(); i++)
        {
            nmax = max(vec1[i], nmax);
        }
        vector<int> vectmp(nmax + 1, 0);
        for (int i = 0; i < vec1.size(); i++)
        {
            vectmp[vec1[i]]++;
        }
        int i = 0;
        for (int j = 0; j < vectmp.size(); j++)
        {
            while (vectmp[j]-- > 0)
            {
                vec1[i++] = j;
            }
        }
        return vec1;
    }

    vector<int> RadixSort(vector<int> vec1)
    {
        
    }

    void swap(vector<int>& vec, int i, int j)
    {
        int tmp = vec[i];
        vec[i] = vec[j];
        vec[j] = tmp;
    }
};

int main()
{
    cout << "输入个数：" << endl;
    int num;
    cin >> num;
    vector<int> vect;
    // vect.push_back(1);

    for (int i = 0; i < num; i++)
    {
        int tmp;
        cin >> tmp;
        vect.push_back(tmp);
    }

    Solution s;
    vector<int> res;
    res = s.BucketSort(vect);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}
