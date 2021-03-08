#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    vector <int> downIndex;
    for(int i=0;i<prices.size()-1;i++){
        if(prices[i]>prices[i+1]){
            downIndex.push_back(i+1);
        }
    }
    int count=0;
    for(int i=0;i<prices.size()-1;i++){
        if(prices[downIndex[count]]<prices[i]){
            for(int j=i;j<downIndex[count];j++){
                answer[j]=downIndex[count]-j;
                i=j;
            }
            if(count<downIndex.size()-1){
                count++;ㅓㅓㅓㅓ
            }else break;

        }
    }
    for(int i=0;i<answer.size()-1;i++){
        if(answer[i]==0){
            for(int j=1;j<downIndex.size();j++){
                if(downIndex[j]>i&&prices[downIndex[j]]<prices[i]) {
                    answer[i] = downIndex[j]-i;
                    break;
                }
            }
            if(answer[i]==0) answer[i]=answer.size()-1-i;

        }
    }
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return answer;
}

int main(){
    vector<int> prices={3,5,7,4,6,8,1,10,11};
    solution(prices);
}