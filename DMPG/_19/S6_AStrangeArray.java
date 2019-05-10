package _19;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeSet;

public class S6_AStrangeArray {
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] first=br.readLine().split(" ");
		int max=Integer.parseInt(first[0]);
		int queries=Integer.parseInt(first[1]);
		int[] sums=new int[max+1];
		TreeSet<Integer> ones=new TreeSet<>();
		sums[0]=0;
		int current=0;
		String[] second=br.readLine().split(" ");
		for(int count=1;count<=max;count++) {
			int next=Integer.parseInt(second[count-1]);
			if(next==1) {
				ones.add(count);
			}
			current+=next;
			sums[count]=current;
		}
		for(int count=0;count<queries;count++) {
			String[] next=br.readLine().split(" ");
			int left=Integer.parseInt(next[0]);
			int right=Integer.parseInt(next[1]);
			int val=Integer.parseInt(next[2]);
			int pareVal=sums[right]-sums[left-1];
			if(pareVal<val) {
				System.out.println("NO");
			}
			else if((pareVal-val)%2==0) {
				System.out.println("YES");
			}
			else {
				Integer ldiff=ones.higher(left-1);
				Integer rdiff=ones.lower(right+1);
				if(ldiff!=null&&ldiff<=right&&sums[right]-sums[ldiff-1]>=val) {
					System.out.println("YES");
				}
				else if(rdiff!=null&&rdiff>=left&&sums[rdiff]-sums[left-1]>=val) {
					System.out.println("YES");
				}
				else {
					System.out.println("NO");
				}
			}
		}
	}

}
