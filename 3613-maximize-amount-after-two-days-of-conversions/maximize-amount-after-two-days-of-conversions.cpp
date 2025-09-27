#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {

        // Build graph for day 1
        unordered_map<string, vector<pair<string,double>>> mpp1;
        for(int i = 0; i < pairs1.size(); i++) {
            string a = pairs1[i][0];
            string b = pairs1[i][1];
            double rate = rates1[i];
            mpp1[a].push_back({b, rate});
            mpp1[b].push_back({a, 1.0 / rate});
        }

        // Build graph for day 2
        unordered_map<string, vector<pair<string,double>>> mpp2;
        for(int i = 0; i < pairs2.size(); i++) {
            string a = pairs2[i][0];
            string b = pairs2[i][1];
            double rate = rates2[i];
            mpp2[a].push_back({b, rate});
            mpp2[b].push_back({a, 1.0 / rate});
        }

        // Day 1: Dijkstra-style (maximize product)
        unordered_map<string, double> bestDay1;
        priority_queue<pair<double,string>> pq;

        pq.push({1.0, initialCurrency});
        bestDay1[initialCurrency] = 1.0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            double currRate = it.first;
            string curr = it.second;

            if(currRate < bestDay1[curr]) continue;

            for(auto &p : mpp1[curr]) {
                string nxt = p.first;
                double rate = p.second;
                double newRate = currRate * rate;
                if(newRate > bestDay1[nxt]) {
                    bestDay1[nxt] = newRate;
                    pq.push({newRate, nxt});
                }
            }
        }

        // Day 2: Start from all bestDay1 nodes
        unordered_map<string, double> bestDay2;
        priority_queue<pair<double,string>> pq2;

        for(auto &p : bestDay1) {
            pq2.push({p.second, p.first});
            bestDay2[p.first] = p.second;
        }

        while(!pq2.empty()) {
            auto it = pq2.top();
            pq2.pop();
            double currRate = it.first;
            string curr = it.second;

            if(currRate < bestDay2[curr]) continue;

            for(auto &p : mpp2[curr]) {
                string nxt = p.first;
                double rate = p.second;
                double newRate = currRate * rate;
                if(newRate > bestDay2[nxt]) {
                    bestDay2[nxt] = newRate;
                    pq2.push({newRate, nxt});
                }
            }
        }

        return bestDay2[initialCurrency];
    }
};
