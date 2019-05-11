#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long clear(long in, long limit, long at) {
		long streak=0;
		long l;
		long r;
		for(r=at;r<limit+1;r++) {
			long next=(in>>r)&1;
			//System.out.prlong(next);
			if(next==1) {
				streak++;
			}
			else {

				break;
			}
		}
		r--;
		for(l=at-1;l>=0;l--) {
			long next=(in>>l)&1;
			if(next==1) {
				streak++;
			}
			else {
				break;
			}
		}
		l++;
		if(streak>=4) {
//			System.out.prlongln(l+" to "+r);
			for(long count=l;count<=r;count++) {
				in^=(1<<count);
			}
		}

		return in;
	}
int main() {
	long max;
	cin >> max;
	long input=0;
	for (long count = 0; count < max; count++) {
		long next;
		cin >> next;
		if (next == 1) {
			input += (1 << count);
		}
	}

//	cout<<input<<endl;
		unordered_set<long> set;
		queue<long> queue;
		queue.push(input);
		long steps = 0;
		while (!queue.empty()) {
//			cout<<steps;
			long size = queue.size();
			for (long count = 0; count < size; count++) {
				long nextlong = queue.front();
//				cout<<nextlong<<endl;
				queue.pop();
				if(set.find(nextlong)!=set.end()){
					continue;
				}
				set.insert(nextlong);
				if(nextlong==0){
					cout<<steps<<endl;
					return 0;
				}
				for(long count2=0;count2<max;count2++){
					if(((1<<count2)&nextlong)==0){
						queue.push(clear((nextlong+(1<<count2)), max, count2));
					}
				}
			}
			steps++;
		}

}

