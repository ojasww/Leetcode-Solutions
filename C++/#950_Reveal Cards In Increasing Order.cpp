class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> dq;
        sort(deck.rbegin(), deck.rend());
        dq.push_back(deck[0]);
        for(int i=1; i<deck.size(); i++){
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[i]);
        }
        vector<int> v(dq.begin(), dq.end());
        return v;
    }
};