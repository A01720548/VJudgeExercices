#include <bits/stdc++.h>

void topView(node *root)
{
    if (root == NULL)
        return;
    unordered_map<int, int> m;
    queue<int, int> q;

    q.push(make_pair(root, 0);

    while (!q.empty()) {
        pair<Node *, int> p = q.front();
        Node *n = p.first;
        int val = p.second;
        q.pop();

        if (m.find(val) == m.end())
        {
            m[val] = n->data;
            cout << n->data << " ";
        }

        if (n->left != NULL)
            q.push(make_pair(n->left, val - 1));
        if (n->right != NULL)
            q.push(make_pair(n->right, val + 1));    
    }
}