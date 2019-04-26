#include<bits/stdc++.h>
using namespace std;

vector<pair<double, double>> g;

double len(pair<double, double> a, pair<double, double> b){
    return (a.first - b.first) * (a.first - b.first) 
        + (a.second - b.second) * (a.second - b.second);
}

double cross(pair<double, double> p, pair<double, double> a, pair<double, double> b){
    return (a.first - p.first) * (b.second - p.second)
        - (a.second - p.second) * (b.first - p.first);
}

bool compare(pair<double, double> a, pair<double, double> b){
    double c = cross(g[0], a, b);
    return (c > 0) || (c == 0 && len(g[0], a) < len(g[0], b));
}

int main(){
    vector<pair<double, double>> ch;
    int n, count = 0;
    double x, y;
    while(cin >> n){
        count++;
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            g.push_back(make_pair(x, y));
        }

        sort(g.begin(), g.end());
        sort(g.begin() + 1, g.end(), compare);

        g.push_back(g[0]);


        for(int i = 0; i < g.size(); i++){
            while(ch.size() >= 2 && cross(ch[ch.size() - 2], ch[ch.size() - 1], g[i]) <= 0){
                ch.pop_back();
            }
            ch.push_back(g[i]);
        }

        double length = 0;
        for(int i = 0;i < ch.size() - 1; i++){
            length += sqrt(len(ch[i], ch[i+1]));
        }

        if(count != 1) cout << "\n";
        cout << "Region #" << count << ":\n";
        
        for(int j = 0; j < ch.size(); j++){
            if(j != 0) cout << "-";
            cout << fixed << setprecision(1) << 
                "(" << ch[ch.size() - j - 1].first << "," << ch[ch.size() - j - 1].second << ")";  
        }
        cout << "\n";
        cout << fixed << setprecision(2) << "Perimeter length = " << length << "\n";

        ch.clear();g.clear();
    }
}