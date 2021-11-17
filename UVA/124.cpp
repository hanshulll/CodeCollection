#include<bits/stdc++.h>

using namespace std;
 
char c, d;
string line;
stringstream ss;
vector<char> elements;
vector<vector<char> > adj;
map<char, bool> vis;
 
bool valid(int e) {
    for(int i = 0; i < adj[elements[e]].size(); i++)
        if(vis[adj[elements[e]][i]])
            return false;
    return true;
}
 
void generate(string comb) {
    if(comb.length() == elements.size())
        cout << comb << endl;
    for(int i = 0; i < elements.size(); i++) {
        if(!vis[elements[i]]) {
            vis[elements[i]] = true;
            if(valid(i))
                generate(comb + elements[i]);
            vis[elements[i]] = false;
        }
    }
}
 
int main() {
    for(int T = 0;; T++) {
        if(!getline(cin, line)) break;
        if(T > 0) cout << endl;
 
        elements.clear();
        adj.clear();
        adj.resize(256);
        ss.clear();
        ss.str(line);
 
        while(ss >> c)
            elements.push_back(c);
        sort(elements.begin(), elements.end());
        getline(cin, line);
        ss.clear();
        ss.str(line);
        while(ss >> c >> d)
            adj[c].push_back(d);
 
        generate("");
    }
}
