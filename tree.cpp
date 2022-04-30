#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
struct node
{
	int data;
	node* lchild;
	node* rchild;
    node* parent = NULL;
};
// struct node
// {
//     int weight;
// 	vector<node*> children; // 结点个数不固定
// };
void preorder(node* root) {
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void postorder(node* root) {
    if(root == NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
}
void inorder(node* root, vector<int> &in) {
    if(root == NULL)
        return;
    inorder(root->lchild, in);
    in.push_back(root->data);
    inorder(root->rchild, in);
}
void levelorder(node* root, vector<int> &level) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* now = q.front(); //取队首元素
        q.pop();
        level.push_back(now->data); //访问队首元素
        if(now->lchild) q.push(now->lchild);
        if(now->rchild) q.push(now->rchild);
    }
}
// void dfs(node* root, int noww, int w) {
//     if(noww == w && root->children.empty()) { // 到达叶结点（递归边界）
//         printf("%d", *ans.begin());
//         for(int i = 1; i < ans.size(); i++) 
//             printf(" %d", ans[i]);
//         printf("\n");
//         return;
//     }
//     if(noww > w || root->children.empty()) { 
//         return; 
//     }
//     sort(root->children.begin(), root->children.end(), cmp);
//     for(vector<node*>::iterator it = root->children.begin(); it != root->children.end(); it++) {
//         ans.push_back((*it)->weight);    
//         dfs(*it, noww + (*it)->weight, w);
//         ans.pop_back();
//     }
// }
int main()
{
	int n;
    cin >> n; // num of nodes
    node nodes[n];
    char a, b;    
    for(int i = 0; i < n; i++) { //建树时invert
        nodes[i].data = i; 
        cin >> a >> b;
        if(a == '-') {
            nodes[i].rchild = NULL;
        } else {
            nodes[i].rchild = &nodes[a - '0'];
            nodes[a - '0'].parent = &nodes[i];
        }
        if(b == '-') {
            nodes[i].lchild = NULL;
        } else {
            nodes[i].lchild = &nodes[b - '0'];
            nodes[b - '0'].parent = &nodes[i];
        }
    }
    int root;
    for(int i = 0; i < n; i++) {
        if(nodes[i].parent == NULL) //找根结点
            root = i;
    }
    // printf("Levelorder:");
    vector<int> level, in;
	// levelorder(&nodes[root], level);
    // printf("%d", level[0]);
	// for(vector<int>::iterator it = level.begin() + 1; it != level.end(); it++)
	// 	printf(" %d", *it);
    // printf("\n");
    // printf("\nInorder:");    
	inorder(&nodes[root], in);
    printf("%d", in[0]);
	for(int i = 1; i < n; i++)
		printf(" %d", in[i]);
    
    return 0;
}




