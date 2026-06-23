#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end());
        string ans="";
        for(int i=0;i<dictionary.size();i++)
        {
            int idx=0;
            int index=s.find(dictionary[i][0]);
            idx=index;
            bool found=true;
            for(int j=0;j<dictionary[i].size();j++)
            {
                size_t pos=s.find(dictionary[i][j],idx);
                if(pos==string::npos)
                {
                    found=false;
                    break;
                }
                idx=pos+1;
            }
            if(found && ans.size()<dictionary[i].size())
            {
                ans=dictionary[i];
            }
        }
        return ans;
    }
};