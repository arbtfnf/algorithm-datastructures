//https://codeforces.com/contest/706/problem/D
#include <iostream>
using namespace std;

#define all(a)                      a.begin(), a.end()
#define pb                          push_back
#define ll							long long
#define index(a)            		order_of_key(a)
#define value(a)					find_by_order(a)
#define count_1 					__builtin_popcount
#define mod(x, m)					((((x) % (m)) + (m)) % (m))

typedef struct node{
	node* bit[2];
	int cnt=0;
}trie;

trie* head;

void in(int x){
	trie* curr = head;

	for(int i=30;i>=0;i--){
		int b=(x>>i)&1;
		if(curr->bit[b]==NULL)
			curr->bit[b]=new trie();
		curr=curr->bit[b];
		curr->cnt++;
	}
}


void er(int x){
	trie* curr=head;

	for(int i=30;i>=0;i--){
		int b=(x>>i)&1;
		curr=curr->bit[b];
		curr->cnt--;
	}
}

int query(int x){
	trie* curr=head;
	int ans=0;
	for(int i=30;i>=0;i--){
		int b=(x>>i)&1;
		if(curr->bit[b^1]!=NULL && curr->bit[b^1]->cnt>0){
			ans+=(1LL<<i);
			curr=curr->bit[b^1];
		}
		else{
			curr=curr->bit[b];
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	head = new trie();
	in(0);
	cin>>n;
	while(n--){
		int x;char ch;
		cin>>ch>>x;
		if(ch=='+'){
			in(x);
		}
		else if(ch=='-'){
			er(x);
		}
		else{
			cout<<query(x)<<endl;
		}
	}
	return 0;
}