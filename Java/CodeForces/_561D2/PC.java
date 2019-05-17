package CodeForces._561D2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.TreeSet;

public class PC {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		long[] nums=new long[max];
		String[] second=br.readLine().split(" ");
		TreeSet<Long> compare=new TreeSet<>();
		
		for(int count=0;count<max;count++) {
			nums[count]=Math.abs(Integer.parseInt(second[count]));
			compare.add(nums[count]);
		}
		Arrays.sort(nums);
		HashMap<Long, Integer> order=new HashMap<>();
		for(int count=0;count<max;count++) {
			order.put(nums[count], count);
		}
		long tally=0;
		for(int count=0;count<max;count++) {
			long target=compare.floor(nums[count]*2);
			tally+=(order.get(target)-count);
		}
		System.out.println(tally);
		
	}

}
