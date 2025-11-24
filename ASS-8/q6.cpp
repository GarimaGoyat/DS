#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
    vector<int> h;

public:

    void push(int x){
        h.push_back(x);
        int i = h.size()-1;

        // move up
        while(i>0){
            int p=(i-1)/2;
            if(h[p] < h[i]) swap(h[p], h[i]);
            else break;
            i=p;
        }
    }

    int top(){
        if(h.empty()) return -1;
        return h[0];
    }

    void pop(){
        if(h.empty()) return;

        h[0] = h.back();
        h.pop_back();
        int n = h.size();
        int i = 0;

        while(true){
            int l = 2*i+1;
            int r = 2*i+2;
            int largest = i;

            if(l<n && h[l] > h[largest]) largest = l;
            if(r<n && h[r] > h[largest]) largest = r;

            if(largest != i){
                swap(h[i], h[largest]);
                i = largest;
            } else break;
        }
    }

    bool empty(){
        return h.size()==0;
    }
};

int main(){
    MaxHeap pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout<<"Top: "<<pq.top()<<endl;

    pq.pop();
    cout<<"After pop top: "<<pq.top()<<endl;
}
