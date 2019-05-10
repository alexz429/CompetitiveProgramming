package _07;
import java.util.*;
public class S3_Friends {
	static int[] num;
	static int lol=0;
	static void recurse(int at,int goal,ArrayList<Integer> visited,int steps){
		if(num[at]==goal){
			lol=steps;
			return;
		}
		if(num[at]==0){
			lol=-1;
			return;
		}
		if(visited.contains(num[at])){
			lol=-1;
			return;
		}
		visited.add(num[at]);
		recurse(num[at],goal,visited,steps+1);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int max=sc.nextInt();
		num= new int[10000];
		Arrays.fill(num, 0);
	
		for(int count=0;count<max;count++){
			int from=sc.nextInt();
			int to=sc.nextInt();
			num[from]=to;
		}
		int next=sc.nextInt();
		int next2=sc.nextInt();
		while(next!=0){
			recurse(next, next2, new ArrayList<Integer>(),0);
			if(lol==-1){
				System.out.println("No");
			}
			else{
				System.out.println("Yes "+lol);
			}
			next=sc.nextInt();
			next2=sc.nextInt();
			
		}
		sc.close();
	}

}
