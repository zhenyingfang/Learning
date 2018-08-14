#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        vector<int> Bubble(vector<int> vec1)
        {
            for (int i = vec1.size() - 1; i > 0; i--)
            {
                for (int j = 0; j < i; j++)
                {
                    
                    if (vec1[j] > vec1[j + 1]) {
                        swap(vec1, j, j + 1);
                    }
                }
            }
            return vec1;
        }

        vector<int> InsertS(vector<int> vec)
        {
            for (int i = 1; i < vec.size() - 1; i++)
            {
                for (int j = i - 1; j >= 0 && vec[j] > vec[j + 1]; j--)
                {
                    swap(vec, j, j + 1);
                }
            }
            return vec;
        }

        vector<int> SelectS(vector<int> vec)
        {
            for (int i = 0; i < vec.size() - 1; i++)
            {
                int minInd = i;
                for (int j = i + 1; j < vec.size(); j++)
                {
                    if (vec[i] > vec[j]) {
                        minInd = j;
                    }
                }
                swap(vec, i, minInd);
            }
            return vec;
        }

        vector<int> HeapS(vector<int> vec)
        {
            
            return vec;
        }

        void swap(vector<int> & vec2, int i, int j)
        {
            int tmp = vec2[i];
            vec2[i] = vec2[j];
            vec2[j] = tmp;
        }
};

int main()
{
    cout << "输入个数：" << endl;
    int num;
    cin >> num;
    vector<int> vect;
    for (int i = 0; i < num; i++)
    {
        int tmp;
        cin >> tmp;
        vect.push_back(tmp);
    }

    Solution s;
    vector<int> res;
    res = s.SelectS(vect);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}