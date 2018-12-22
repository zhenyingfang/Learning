#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string manacher(string input) {
        // 将输入的字符串转换为包含特殊字符的形式
        string in;
        in += "#";
        for (int i = 0; i < input.size(); ++i) {
            in += input[i];
            in += "#";
        }

        // 存储每个字符的回文半径
        vector<int> v1(in.size());
        // 遍历过程中最右的回文半径
        int R = -1;
        // 最大回文半径对应的回文中心点
        int C = -1;

        // manacher步骤：
        // 1、若当前遍历点在最右回文半径的右边，则从i点开始左右遍历，计算回文半径
        // 2、若在最右回文半径左边：
        //    2.1 若i关于C的对称点的回文半径等于R-i, 则i点在半径为R-i的基础上继续遍历，求得当前点的回文半径
        //    2.2 若i关于C的对称点的回文半径小于R-i,则i位置的回文半径等于i关于C的对称点的回文半径
        //    2.3 若i关于C的对称点的回文半径大于R-i，则i位置的回文半径等于R-i
        for (int i = 0; i < in.size(); ++i) {
            // 遍历到v[i]时先确定v[i]能遍历的最短半径
            // 即i点相对于C对称点的半径，与i到R的距离中的最小值
            v1[i] = R > i ? min(v1[2 * C - i], R - i) : 1;

            // 检查是否能继续左右扩充
            while (i + v1[i] < in.size() && i - v1[i] > -1) {
                if (in[i + v1[i]] == in[i - v1[i]]) {
                    v1[i]++;
                } else {
                    break;
                }
            }

            // 更新最右回文半径和中心点
            if (v1[i] > R) {
                R = v1[i];
                C = i;
            }
        }
        return input.substr(int((C - R + 2) / 2), (2 * R - 1) / 2);
    }
};

int main() {
    Solution s;
    string input = "babcd";
    string res = s.manacher(input);
    cout << res << endl;
}
