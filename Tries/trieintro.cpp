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
            int index = word[0] - 'A';
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

        void insertWord(string word){
            insertUtil(root, word);
        }

        bool searchUtil(trieNode* root, string word){
            if(word.length() == 0){
                return root->isTerminal;
            }
            int index = word[0] - 'A';
            if(root->children[index] == NULL){
                return 0;
            }
            else{
                return searchUtil(root->children[index],word.substr(1));
            }
        }

        bool search(string word){

            return searchUtil(root,word);
        }

        void removeUtil(trieNode* root, string word){
            if(word.length() == 0){
                root->isTerminal=0;
                return;
            }
            int index = word[0] - 'A';
            removeUtil(root->children[index],word.substr(1));
        }

        void remove(string word){
            removeUtil(root,word);
        }
};

int main(){

    trie *t = new trie();

    t->insertWord("CAT");
    t->insertWord("CAR");
    t->insertWord("DICK");
    t->search("CAR") ? cout<<"Word exists" : cout<<"Word doesn't exist";
    cout<<endl;
    return 0;
}