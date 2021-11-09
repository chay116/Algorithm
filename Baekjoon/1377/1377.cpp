#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;


int main() {
	fastio;
	int N, tmp; cin >> N;
	vector<pair<int, int>> array;
	int answer = 0;
	for (int i=0; i < N; i++) {
		cin >> tmp;
		array.push_back(make_pair(tmp, i));
	}
	stable_sort(array.begin(), array.end());
	for (int i=0; i < N; i++) {
		answer = max(answer, array[i].second - i);
	}
	cout << answer + 1<< endl;
}


// int answer = 0;

// struct node {
// 	node* left;
// 	node* right;
// 	int	value;
// 	int rvalue;
// };

// node *new_node(int value) {
// 	node *tree;
// 	tree = new node();
// 	tree->value = value;
// 	tree->left = NULL;
// 	tree->right = NULL;
// 	tree->rvalue = 1;
// 	return tree;
// }

// void node_insert(node *main, node *sub, int left_time) {
// 	if (main->value > sub->value) {
// 		// cout << "left" << endl;
// 		// cout << "left" << main->value << main->rvalue << endl;
// 		if (main->left) node_insert(main->left, sub, left_time + main->rvalue);
// 		else {
// 			main->left = sub;
// 			if (answer < left_time + main->rvalue) answer = left_time + main->rvalue;
// 		}
// 	} else {
// 		main->rvalue += 1;
// 		// cout << "right" << main->value << main->rvalue << endl;
// 		if (main->right) node_insert(main->right, sub, left_time);
// 		else main->right = sub;
// 		if (answer < left_time) answer = left_time;
// 	}
// }

// int main() {
// 	node *binary_tree, *tmp_node;
// 	fastio;
// 	int N, tmp; cin >> N;
// 	cin >> tmp;
// 	binary_tree = new_node(tmp);
// 	for (int j=1; j < N; j++) {
// 		cin >> tmp;
// 		tmp_node = new_node(tmp);
// 		node_insert(binary_tree, tmp_node, 0);
// 	}
// 	answer++;
// 	cout << answer << endl;
// }
