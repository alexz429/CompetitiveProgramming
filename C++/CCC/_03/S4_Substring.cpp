/*
 * Substring.cpp
 *
 *  Created on: May 13, 2019
 *      Author: Alex.Zhang
 */
#include <iostream>

#include <bits/stdc++.h>

 long long SENTINEL=(long long) 1.48764065e17;
	static std::unordered_map<int, int> hash;
	static void init() {
		int index=0;
		for(int i=48;i<58;i++) {
			hash[i]=index;
			index++;
		}
		for(int i=65;i<91;i++) {
			hash[i]=index;
			index++;
		}
		for(int i=97;i<123;i++) {
			hash[i]=index;
			index++;
		}
	}
	static long roll(long prev, char next) {
		int add=hash[(int)next];
		prev=(prev*62+add)%SENTINEL;
		return prev;
	}

int main(){
	int max;
	std::cin>>max;
	init();
	for(int count=0;count<max;count++){
//		std::cout<<count;
		std::string next;
		std::cin>>next;
		std::unordered_set<long long> set;
		set.insert((long)0);
					for(int count2=0;count2<next.length();count2++) {
						long init=0;
						for(int count3=count2;count3<next.length();count3++) {


							char nextC=next.at(count3);
							if(count3==count2) {
								init=hash[(int)nextC];
							}
							else {
								init=roll(init, nextC);
							}
							set.insert(init);
						}
					}
					std::cout<<set.size()<<std::endl;
	}

}
