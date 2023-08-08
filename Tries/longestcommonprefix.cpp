#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
        char data;
        trieNode* children[26];
        bool isTerminal;
        int childCount;

        trieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            childCount = 0;
            isTerminal = 0;
        }


};

class trie{

    public:
        trieNode* root;

        trie(){
            root = new trieNode('\0');
        }

        void insertUtil(trieNode* root,string word){
            // base case: whole word has been inserted in the trie
            if(word.length() == 0){
                root->isTerminal = 1;
                return ;
            }

            // Assumption, word will be in the caps
            int index = word[0] - 'a';
            trieNode* child;

            if(root->children[index] != NULL){
                // if present
                child = root->children[index];
            }
            else{
                // if absent
                child = new trieNode(word[0]);
                root->children[index] = child;
                root->childCount++;
            }

            // Recursion
            insertUtil(child , word.substr(1));
        }

        void insertWord(string word) { insertUtil(root, word); }

        void lcp(string str, string& ans){
            for(int i=0;i<str.length();i++){
                char ch = str[i];

                if(root->childCount == 1){
                    ans.push_back(ch);
                    int index = ch - 'a';
                    root = root->children[index];
                }
                else{
                    break;
                }
                if(root ->isTerminal){

                    break;
                }


            }
        }
};

string longestCommonPrefix(vector<string> &arr, int n) {
    trie* root = new trie(); 
    for(auto i: arr){
        root->insertWord(i);
    }
    string str = arr[0];
    string ans = "";
    root->lcp(str,ans);
    return ans;
}

int main(){

    return 0;
}