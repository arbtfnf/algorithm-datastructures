#include <bits/stdc++.h>
using namespace std;
long long int inp[10000], tree[10000], l,r; 

void make_seg_tree(int id, int start, int end){
	if(end < start)return ;
	if(start == end){
		
		tree[id] = inp[start];
	//	cout<<id<<" "<<tree[id]<<"\n";
		return;
	}
	int mid = (start+end)/2;
	make_seg_tree(2*id,start, mid);
	make_seg_tree(2*id+1,mid+1, end);
	tree[id] = min(tree[2*id], tree[2*id + 1]);
//	cout<<id<<" "<<tree[id]<<endl;
}

int min_query(int start, int end, int id){
	if(l > end || r<start) return INT_MAX;;
	if(l<=start && end<=r){
		return tree[id];
	}
	int mid = (start + end)/2;
	return min(min_query(start,mid,2*id), min_query(mid+1,end,2*id+1));
}

int main() {
	long long int n;
	cin>>n;
	for(long long int i=1; i<=2*n; i++){
		tree[i] = INT_MAX;
	}
	for(long long int i=1; i<=n; i++){
		cin>>inp[i];
	}

	cin>>l>>r;
	make_seg_tree(1,1,n);
//	for(int i=1;i<=n;i++)cout<<tree[i]<<" ";cout<<endl;
	cout << min_query( 1, n, 1);
	return 0;
}
