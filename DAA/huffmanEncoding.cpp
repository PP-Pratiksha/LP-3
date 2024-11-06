#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode* left, *right;
    MinHeapNode(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

void printCodes(struct MinHeapNode* root, string str) {
    if (root == nullptr) {
        return;
    }
    if (root->data != '$') {
        cout << root->data << ": " << str << endl;
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

struct compare {
    bool operator()(MinHeapNode* a, MinHeapNode* b) {
        return (a->freq > b->freq);
    }
};

void HuffmanCode(vector<char>& data, vector<int>& freq, int size) {
    struct MinHeapNode *left, *right, *temp;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; i++) {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        temp = new MinHeapNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        minHeap.push(temp);
    }
    printCodes(minHeap.top(), "");
}

int main() {
    int size;
    cout << "Enter the number of characters: ";
    cin >> size;

    vector<char> data(size);
    vector<int> freq(size);

    cout << "Enter characters and their frequencies:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Character " << i + 1 << ": ";
        cin >> data[i];
        cout << "Frequency of " << data[i] << ": ";
        cin >> freq[i];
    }

    HuffmanCode(data, freq, size);
    return 0;
}
