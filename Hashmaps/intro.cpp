#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<string,int> m;
    
    // INSERTION
    // 1
    pair<string,int> p = make_pair("ayush",3);
    m.insert(p);

    // 2
    pair<string,int> pair2("kaul",84);
    m.insert(pair2);

    // 3
    m["wow"] = 45;

    // SEARCHING
    
    // 1
    cout<<m.at("kaul")<<endl;

    // 2
    cout<<m["ayush"]<<endl;    

    // Error: If the key is not present in the map
    // m.at(): It just shows that there is no key present in the map
    // cout<<m.at("hehe")<<endl;

    // m["hehe"]: Creates the hehe key with value initialized as 0
    cout<<m["hehe"]<<endl;

    // Size
    cout<<m.size()<<endl;

    // to check if the key is present or not
    // Gives 0 if absent
    m.count("kaul");

    // erase
    m.erase("kaul");

    // traversing
    
    // 1
    for(auto i:m){
        cout<<"m["<<i.first<<"] = "<<i.second<<endl;
    }

    // 2: Using iterator
    unordered_map<string,int> :: iterator it = m.begin();

    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}