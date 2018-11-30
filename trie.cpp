/*
 * @Author: fzy
 * @Date: 2018-11-30 21:01:15
 * @LastEditors: Zhenying
 * @LastEditTime: 2018-11-30 21:20:50
 * @Description: trie
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
 * 前缀树：是一种树形结构，是一种哈希树的变种。典型应用为用于统计和排序大量的字符串。
 * 所以经常被搜索引擎系统用于文本词频统计。
 * 优点：最大限度地减少无畏的字符串比较。
 * 核心思想：空间换时间。
 * 
 * 前缀树的三个性质：
 *  1、根节点不包含字符，除根节点为每一个节点都只包含一个字符。
 *  2、从根节点到某一个节点，路径上经过的字符连接起来，为该节点对应的字符串。
 *  3、每个节点的所有子节点包含的字符都不相同。
 * 
 */

/*
 * 树结构：
 *  其中count表示以当前单词结尾的单词数量。
 *  prefix表示以该处节点之前的字符串为前缀的单词数量。
 */

class TrieNode {
public:
  int prefix;
  int count;
  TrieNode *nextNode[26] = {NULL};
  TrieNode() {
      prefix = 0;
      count = 0;
  }
};

/*
 * 字典树的插入、单词word的数量、以单词word开头的单词数量。
 */

class Trie {
private:
  TrieNode *root;
  TrieNode *head;
public:
    Trie() {
        root = new TrieNode();
        head = root;
    }

    // 字典树的插入
    void insert(string word) {
        root = head;
        int size = word.size();
        for (int i = 0; i < size; ++i) {
            if (root->nextNode[word[i] - 'a'] == NULL)
                root->nextNode[word[i] - 'a'] = new TrieNode();
            root = root->nextNode[word[i] - 'a'];
            root->prefix++;
        }
        root->count++;
    }
    
    /** 查询是否存在word字符串 */
    bool search(string word) {
        root = head;
        int size = word.size();
        for (int i = 0; i < size; ++i) {
            if (root->nextNode[word[i] - 'a'] == NULL)
                return false;
            root = root->nextNode[word[i] - 'a'];
        }
        if (root->count > 0) {
            return true;
        } else {
            return false;
        }
    }
    
    /** 查询是否存在以prefix开头的字符串 */
    bool startsWith(string prefix) {
        root = head;
        int size = prefix.size();
        for (int i = 0; i < size; ++i) {
            if (root->nextNode[prefix[i] - 'a'] == NULL)
                return false;
            root = root->nextNode[prefix[i] - 'a'];
        }
        if (root->prefix > 0) {
            return true;
        } else {
            return false;
        }
    }

}
