/*
 * @Author: fzy
 * @Date: 2018-08-16 10:12:22
 * @LastEditors: zhenying
 * @LastEditTime: 2018-08-16 10:14:43
 * @Description: 
 */
#include <iostream>
#include <vector> 
#include <math.h>

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
        if (vec1.size() < 2)
        {
            return vec1;
        }
        return radixSort(vec1, 0, vec1.size() - 1, maxbits(vec1));
    }

    int maxbits(vector<int> vec1)
    {
        int nmax = 0x80000000;
        for (int i = 0; i < vec1.size(); i++)
        {
            nmax = max(nmax, vec1[i]);
        }
        int res = 0;
        while (nmax != 0)
        {
            res++;
            nmax /= 10;
        }
        return res;
    }

    vector<int> radixSort(vector<int> vec1, int begin, int end, int digit)
    {
        int radix = 10;
        int i = 0, j = 0;
        vector<int> count(radix);
        vector<int> bucket(end - begin + 1);
        for (int d = 1; d <= digit; d++)
        {
            for (i = 0; i < radix; i++)
            {
                count[i] = 0;
            }
            for (i = begin; i <= end; i++)
            {
                j = getDigit(vec1[i], d);
                count[j]++;
            }
            for (i = 1; i < radix; i++)
            {
                count[i] = count[i] + count[i - 1];
            }
            for (i = end; i >= begin; i--)
            {
                j = getDigit(vec1[i], d);
                bucket[count[j] - 1] = vec1[i];
                count[j]--;
            }
            for (i = begin, j = 0; i <= end; i++, j++)
            {
                vec1[i] = bucket[j];
            }
        }
        return vec1;
    }

    int getDigit(int x, int d)
    {
        return ((x / ((int)pow(10, float(d - 1)))) % 10);
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
    res = s.RadixSort(vect);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}
