package _07;
import java.util.*;
public class S4_Waterpark {
	static HashMap<Integer, ArrayList<Integer>> num;
	static int[] scores;
	static int recurse(int at){
		//System.out.println("lol");
		if(at==0){
			return 1;
		}
		if(scores[at]!=0){
			return scores[at];
		}
		if(num.get(at).size()==0){
			return 0;
		}
		int score=0;
		for(int count=0;count<num.get(at).size();count++){
			score+=recurse(num.get(at).get(count));
		}
		scores[at]=score;
		return score;
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int nodes=sc.nextInt();
		scores=new int[nodes];
		Arrays.fill(scores, 0);
		num=new HashMap<Integer,ArrayList<Integer>>();
		for(int count=0;count<nodes;count++){
			num.put(count, new ArrayList<Integer>());
		}
		int from=sc.nextInt()-1;
		int to=sc.nextInt()-1;
		while(from!=-1){
			num.get(to).add(from);
			from=sc.nextInt()-1;
			to=sc.nextInt()-1;
		}
		int out=recurse(num.size()-1);
		System.out.println(out);
		sc.close();
	}

}
