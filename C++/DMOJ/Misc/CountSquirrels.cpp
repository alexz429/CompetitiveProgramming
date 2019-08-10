#include <bits/stdc++.h>

using namespace std;

	  int** dp;
	  int k;
	  int* parent;
	  map<int,vector<int>> direct;
	
	  void process(int at) {
        //   printf("test %d\n", at);
		for(auto&& next:direct[at]) {
            // printf("HAHA %d", next);
			if(parent[at]==next)continue;
			parent[next]=at;
			process(next);
			for(int count=1;count<=k;count++) {
				dp[at][count]+=dp[next][count-1];
			}
		}
	}
	  void reverse(int at) {
		if(parent[at]!=at) {
			for(int count=k;count>=2;count--) {
				dp[at][count]+=dp[parent[at]][count-1];
				dp[at][count]-=dp[at][count-2];
			}

			dp[at][1]+=dp[parent[at]][0];
		}
		for(auto&& next:direct[at]) {
			if(parent[at]!=next)
			reverse(next);
		}
	}
int main() {
		// TODO Auto-generated method stub
		int max;
        scanf("%d %d", &max,&k);
		parent = new int[max];
		dp=new int*[max];
        for(int count=0;count<max;count++){
            dp[count]=new int[k+1];
        }
		for(int count=0;count<max;count++) {
            vector<int> next;
            direct[count]=next;
            
		}
		for(int count=0;count<max-1;count++) {
            int from,to;
            scanf("%d %d", &from,&to);
            from--,to--;
			// printf("%d %d", from,to);
            direct[from].push_back(to);
            direct[to].push_back(from);
		}
		for(int count=0;count<max;count++) {
            int next;
            scanf("%d", &next);
			fill(&dp[count][0],&dp[count][k+1], next);
		}
		parent[0]=0;
		process(0);
		reverse(0);
		// for(int[] next:dp) {
//			for(int output:next) {
//				System.out.print(output+" ");
//			}
//			System.out.println();
//		}
		for(int count=0;count<max;count++) {
            // for(int count2=0;count2<=k;count2++){
            //     printf("%d ", dp[count][count2]);
            // }
            // printf("\n");
			printf("%d\n", dp[count][k]);
		}
		
	}


