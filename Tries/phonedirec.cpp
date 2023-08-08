#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
        char data;
        trieNode* children[26];
        bool isTerminal;

        trieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
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
            }

            // Recursion
            insertUtil(child , word.substr(1));
        }

        void insertWord(string word) { insertUtil(root, word); }

        void printSuggestions(trieNode* curr, vector<string>& temp,string prefix){
            if(curr->isTerminal){
                temp.push_back(prefix);
            }
            // checking how many children curr node has and how many suggestions it can give
            for(char ch = 'a'; ch<= 'z'; ch++){

                trieNode* next = curr->children[ch-'a'];

                // if there is a children present then we have to run same code for their children also
                if(next != NULL){
                    prefix.push_back(ch);
                    printSuggestions(next,temp,prefix);
                    prefix.pop_back();
                }
            }
            // In every iteration, we are covering all the strings with the given prefixes
        }

        vector<vector<string>> getSuggestions(string str){

            trieNode* prev = root;
            vector<vector<string>> output;
            string prefix = "";

            for(int i = 0;i<str.length();i++){
                char lastch = str[i];

                prefix.push_back(lastch);

                trieNode* curr = prev->children[lastch - 'a'];

                if(!curr){
                    break;
                }
                else{
                    vector<string> temp;
                    printSuggestions(curr,temp,prefix);
                    output.push_back(temp);
                    prev = curr;
                }
            }

            return output;
        }

};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr) {
    trie * t = new trie();

    for(int i = 0;i<contactList.size(); i++){

        string str = contactList[i];
        t->insertWord(str);
    }


    return t->getSuggestions(queryStr);
}

int main(){

    return 0;
}