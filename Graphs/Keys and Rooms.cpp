/*

Platform : leetcode

Problem Statement

There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise

Testcases

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.


Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.   */


class Solution {
public:
      bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> dfs; dfs.push(0);
        unordered_set<int> seen = {0};
        while (!dfs.empty()) {
            int i = dfs.top(); dfs.pop();
            for (int j : rooms[i])
                if (seen.count(j) == 0) {   //set.count(key) is used to find if element present in the set or not if set.count(key)==0 means not present otherwise present (1) see.count always give two output 0 and 1 
                    dfs.push(j);
                    seen.insert(j);
                    if (rooms.size() == seen.size()) return true;
                }
        }
        return rooms.size() == seen.size();
    }
};