#include <bits/stdc++.h>
using namespace std;

//850. Rectangle Area II
using pi = pair<int,int>;
using tup = tuple<int,int,bool>;
int mod = 1000000007;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        multiset<pi> height;
        map<int, vector<tup>> points;
        for(auto v : rectangles){
            int x1 = v[0], y1 = v[1], x2 = v[2], y2 = v[3];
            points[x1].push_back({y1, y2, true});
            points[x2].push_back({y1, y2, false});
        }

        auto getHeight = [&](){
            int currStart = -1e9, currEnd = -1e9; // -inf

            long long total = 0;
            for(auto [y1, y2] : height){
                if(currEnd < y1) {
                    total += currEnd - currStart;
                    currStart = y1;
                    currEnd = y2;
                }
                else{
                    currEnd = max(currEnd, y2);
                }
            }
            total += currEnd - currStart;
            return total;
        };

        auto isOverlap = [&](){
            int currEnd = -1e9; // -inf
            for(auto [y1, y2] : height){
                if(currEnd > y1){
                    return true; // Overlap found
                }
                else{
                    currEnd = y2;
                }
            }
            return false;
        };

        long long area = 0;
        long long h = 0;
        long long prevX = points.begin()->first;
        for(auto [key, val] : points){
            area = (area + h*(key - prevX)) % mod;
            for(auto [y1, y2, isAdd] : val){
                if(isAdd){
                    height.insert({y1, y2});
                }
                else{
                    auto it = height.find({y1, y2});
                    if(it != height.end()){
                        height.erase(it); //safe practice
                    }
                }
            }
            prevX = key;
            h = getHeight();
        }
        return area;
    }
};