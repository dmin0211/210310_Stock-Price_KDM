#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    stack<pair<int,int>> colStack;
    int loopSize;
    colStack.push({prices[0],0});
    for(int i=1;i<prices.size()-1;i++){
        loopSize=colStack.size();
        for(int j=0;j<loopSize;j++){
            if(colStack.top().first>prices[i]) {
                answer[colStack.top().second] = i - colStack.top().second;
                colStack.pop();
            }else break;
        }
        colStack.push({prices[i],i});
    }
    loopSize=colStack.size();
    for(int i=0;i<loopSize;i++){
        answer[colStack.top().second]=prices.size()-1-colStack.top().second;
        colStack.pop();
    }
    return answer;
}

int main(){
    vector<int> prices={3,5,7,4,6,8,1,10,11};
    solution(prices);
}
