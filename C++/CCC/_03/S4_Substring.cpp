#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_CHILDREN 62
map<int, int> hm;

static void init()
{
	int index = 0;
	for (int i = 48; i < 58; i++)
	{
		hm[i] = index;
		index++;
	}
	for (int i = 65; i < 91; i++)
	{
		hm[i] = index;
		index++;
	}
	for (int i = 97; i < 123; i++)
	{
		hm[i] = index;
		index++;
	}
	cout<<index<<endl;
}
int tally = 0;
struct node
{
	struct node* children[MAX_CHILDREN];
};
typedef struct node Node;
Node* newNode(){
	Node *create =(Node*) malloc(sizeof(Node));
	for(int i=0;i<MAX_CHILDREN;i++){
		create->children[i] = NULL;
	}
	return create;
}
void kill(Node* at){
	for(int i=0;i<MAX_CHILDREN;i++){
		if(at->children[i]){
			kill(at->children[i]);
		}
	}
	free(at);
}
void add(Node* at, string in, int i){
	// cout<<&at<<" "<<i<<endl;
	if(i>=in.length())return;
	int point = hm[in[i]];
	// cout<<point<<" ";
	if(at->children[point]==NULL){
		// cout<<"ha"<<endl;
		tally++;
		at->children[point]=newNode();
	}
	add(at->children[point], in, i+1);
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int m;
	cin>>m;
	init();
	for(int i=0;i<m;i++){
		string next;
		cin>>next;

		tally= 1;
		Node* cur=newNode();
		for(int j=0;j<next.length();j++){
			add(cur, next, j);
		}
		cout<<tally<<"\n";
		kill(cur);
	}
}