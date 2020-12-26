#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(){
    unordered_map<string, int> ourMap;
    pair<string, int> p("abc", 1);
    ourMap.insert(p); // one way of inserting
    ourMap.insert({"kdljsklj", 78});

    ourMap["efg"] = 2; // another way of inserting into map

    // search for a key

    cout << ourMap["abc"] << endl;
    cout << ourMap["efg"] << endl;

    // another way of searching for a key

    cout << ourMap.at("abc") << endl;

    // what happens if we ask for non existing key
    cout << ourMap["blah"] << endl;

    unordered_map<string, int>::iterator i;
    for(i = ourMap.begin(); i != ourMap.end(); i++){
        cout << i->first << ":" << i->second << "\n";
    }
}