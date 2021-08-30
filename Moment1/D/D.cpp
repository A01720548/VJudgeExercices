void topView(Node *root)
{
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    int hd = 0, l = 0, r = 0;
    stack<int> s;
    vector<int> v;
    Node *node;
    while (q.size())
    {
        node = q.front().first;
        hd = q.front().second;
        if (hd < l)
        {
            s.push(node->data);
            l = hd;
        }
        else if (hd > r)
        {
            v.push_back(node->data);
            r = hd;
        }
        if (node->left)
        {
            q.push(make_pair(node->left, hd - 1));
        }
        if (node->right)
        {
            q.push(make_pair(node->right, hd + 1));
        }
        q.pop();
    }
    while (s.size())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << root->data << " ";
    for (auto x : v)
    {
        cout << x << " ";
    }
}