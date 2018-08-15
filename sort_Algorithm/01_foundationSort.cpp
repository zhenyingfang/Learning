/*
 * @Author: fzy
 * @Date: 2018-08-14 16:42:42
 * @LastEditors: zhenying
 * @LastEditTime: 2018-08-14 20:11:51
 * @Description: some sort algorithm
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    /*
        *   Bubble Sort
        */
    vector<int> BubbleSort(vector<int> vec1)
    {
        if (vec1.size() < 2)
            return vec1;

        for (int i = vec1.size() - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (vec1[j] > vec1[j + 1])
                    swap(vec1, j, j + 1);
            }
        }
        return vec1;
    }

    /*
        *   Insert Sort
        */
    vector<int> InsertSort(vector<int> vec1)
    {
        if (vec1.size() < 2)
            return vec1;

        for (int i = 1; i < vec1.size(); i++)
        {
            for (int j = i - 1; j >= 0 && vec1[j] > vec1[j + 1]; j--)
            {
                swap(vec1, j, j + 1);
            }
        }
        return vec1;
    }

    /*
       *    Select Sort
       */
    vector<int> SelectSort(vector<int> vec1)
    {
        if (vec1.size() < 2)
        {
            return vec1;
        }

        for (int i = 0; i < vec1.size() - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < vec1.size(); j++)
            {
                if (vec1[j] < vec1[minIndex])
                {
                    minIndex = j;
                }
                //   minIndex = vec1[minIndex] < vec1[j] ? minIndex : j;
            }
            swap(vec1, i, minIndex);
        }
        return vec1;
    }

    /*
      *     Head Sort
      */
    vector<int> HeadSort(vector<int> vec1)
    {

        if (vec1.size() < 2)
        {
            return vec1;
        }

        for (int i = 1; i < vec1.size(); i++)
        {
            heapInsert(vec1, i);
        }

        int size = vec1.size();
        swap(vec1, 0, --size);
        while (size > 0)
        {
            heapify(vec1, 0, size);
            swap(vec1, 0, --size);
        }
        return vec1;
    }

    void heapInsert(vector<int> &vec1, int i)
    {
        while (vec1[i] > vec1[(i - 1) / 2])
        {
            swap(vec1, i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }

    void heapify(vector<int> &vec1, int i, int size)
    {
        int left = i * 2 + 1;
        while (left < size)
        {
            int largest = left + 1 < size && vec1[left + 1] > vec1[left] ? left + 1 : left;
            largest = vec1[largest] > vec1[i] ? largest : i;
            if (largest == i)
            {
                break;
            }
            swap(vec1, largest, i);
            i = largest;
            left = i * 2 + 1;
        }
    }

    /*
    *   Merge Sort
    */
   vector<int> MergeSort(vector<int> vec1)
   {
       if (vec1.size() < 2) {
           return vec1;
       }
       mergeSort(vec1, 0, vec1.size() - 1);
       return vec1;
   }

   void mergeSort(vector<int>& vec1, int l, int r)
   {
       
       if (l == r) {
           return;
       }

       int mid = l + ((r - l) / 2);
       mergeSort(vec1, l, mid);
       mergeSort(vec1, mid + 1, r);
       Merge(vec1, l, mid, r);
   }

   void Merge(vector<int>& vect1, int l, int m, int r)
   {
       vector<int> tmp_h;
       int i = l;
       int j = m + 1;
       while (i <= m && j <= r)
       {
           if (vect1[i] < vect1[j])
           {
               tmp_h.push_back(vect1[i++]);
           }
           else
           {
               tmp_h.push_back(vect1[j++]);
           }
       }
       while (i <= m)
       {
           tmp_h.push_back(vect1[i++]);
       }
       while (j <= r)
       {
           tmp_h.push_back(vect1[j++]);
       }
       for (int i = 0; i < tmp_h.size(); i++)
       {
           vect1[l + i] = tmp_h[i];
       }
   }

   /*
   *    Quick Sort
   */
  vector<int> QuickSort(vector<int> vec1)
  {
      
      if (vec1.size() < 2) {
          return vec1;
      }

      quickSort(vec1, 0, vec1.size() - 1);

      return vec1;
  }

  void quickSort(vector<int>& vec1, int l, int r)
  {
      if (l < r)
      {
        vector<int> tmp_vec =  patition(vec1, l, r);
        quickSort(vec1, l, tmp_vec[0] - 1);
        quickSort(vec1, tmp_vec[1] + 1, r);
      }
  }

  vector<int> patition(vector<int>& vec1, int l, int r)
  {
      int less = l - 1;
      int more = r;
      while (l < more)
      {
          
          if (vec1[l] < vec1[r]) {
              swap(vec1, ++less, l++);
          }
          else if(vec1[l] > vec1[r]) {
              swap(vec1, l, --more);
          }
          else {
              l++;
          }
      }
      swap(vec1, more, r);
      vector<int> vec;
      vec.push_back(less + 1);
      vec.push_back(more);
      return vec;
  }

  void swap(vector<int> &vec2, int i, int j)
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
    // vect.push_back(1);

    for (int i = 0; i < num; i++)
    {
        int tmp;
        cin >> tmp;
        vect.push_back(tmp);
    }

    Solution s;
    vector<int> res;
    res = s.QuickSort(vect);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}
