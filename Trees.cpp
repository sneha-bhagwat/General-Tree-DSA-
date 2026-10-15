#include <iostream>
using namespace std;

struct Node {
string name;
Node *child[3];
int count;
};

int main() {
Node a = {"Computer", {}, 3};
Node b = {"Documents", {}, 2};
Node c = {"Pictures", {}, 1};
Node d = {"Downloads", {}, 1};
Node e = {"Resume", {}, 0};
Node f = {"Notes", {}, 0};
Node g = {"Photos", {}, 0};
Node h = {"Software", {}, 0};

a.child[0] = &b;
a.child[1] = &c;
a.child[2] = &d;
b.child[0] = &e;
b.child[1] = &f;
c.child[0] = &g;
d.child[0] = &h;

string key;
cout << "Enter folder name: ";
cin >> key;

Node *p = NULL;
Node *nodes[] = {&a, &b, &c, &d, &e, &f, &g, &h};

for (int i = 0; i < 8; i++)
    if (nodes[i]->name == key)
        p = nodes[i];

if (p == NULL) {
    cout << "Folder not found!";
    return 0;
}

int height = 0, depth = 0, leaves = 4;

if (p->count > 0) {
    height = 1;
    for (int i = 0; i < p->count; i++)
        if (p->child[i]->count > 0)
            height = 2;
}

if (p == &b || p == &c || p == &d)
    depth = 1;
else if (p == &e || p == &f || p == &g || p == &h)
    depth = 2;

cout << "Degree = " << p->count << endl;
cout << "Height = " << height << endl;
cout << "Depth = " << depth << endl;
cout << "Total Leaf Nodes = " << leaves << endl;

return 0;

}

