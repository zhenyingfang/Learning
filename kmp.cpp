/*
 * @Author: fzy
 * @Date: 2018-12-02 17:17:11
 * @LastEditors: Zhenying
 * @LastEditTime: 2018-12-02 17:31:39
 * @Description: kmp algorithm
 */
#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
 * KMP: 字符串匹配
 */

/** 得到模式串的netx数组 */

vector<int> getNext(string s2) {
    int len = s2.size();
    vector<int> res(len);
    res[0] = -1;
    if (len == 1)
        return res;
    res[1] = 0;
    int cnt = 0;
    for (int i = 2; i < len;) {
        if (s2[cnt] == s2[i - 1]) {
            cnt++;
            res[i] = cnt;
            i++;
        } else if (cnt > 0) {
            cnt = res[cnt];
        } else {
            res[i] = 0;
            i++;
        }
    }
    return res;
}

/** kmp */
int kmp(string s1, string s2) {
    if (s2.size() < 1 || s1.size() < s2.size())
        return -1;
    int in1 = 0;
    int in2 = 0;
    vector<int> next = getNext(s2);

    while (in1 < s1.size() && in2 < s2.size()) {
        if (s1[in1] == s2[in2]) {
            in1++;
            in2++;
        } else if (next[in2] == -1) {
            in1++;
        } else {
            in2 = next[in2];
        }
    }

    if (in2 == s2.size()) {
        return in1 - in2;
    } else {
        return -1;
    }
}