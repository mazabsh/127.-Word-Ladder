#include<iostream> 
#include<vector> 
#include<queue> 
#include<unordered_set> 

using namespace std; 

class Solution{
public: 
      int ladderLength(string beginWord, string endWord, vector<string> wordList){
          unordereded_set<string> dict(wordList.begin(), wordList.end()); 
          if(dict.find(endWord)==dict.end()) return 0; 
          int ans=1; 
          queue<string> q; 
          q.push(beginWord); 
          while(!q.empty()){
                int size = q.size(); 
                for(int i=0; i<size; ++i){
                    string word = q.front(); 
                    q.pop(); 
                    if(word==endWord) return ans; 
                    for(int j=0; j<word.size(); ++j){
                         char original = word[j]; 
                          for(char c ='a'; c<='z'; ++c){
                              word[j]=c; 
                              if(dict.find(word)!=dict.end()){
                                   q.push(word); 
                                    dict.erase(word); 
                              }
                          }
                          word[j]=original; 
                    }
                }
                ++ans; 
          }
          return 0; 

      }
}; 
int main(){
    string beginWord = "hit"; 
    string endWord = "cog"; 
    vector<string> wordList={"hot","dot","dog","lot","log","cog"};
    Solution sol; 
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl; 

    return 0; 
}
