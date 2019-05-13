package CCC._01;
import java.util.*;
public class S3_StrategicBombing {
	static int recurse(int start, int[][] num, int max){
		//System.out.println(max);
		if(max>26){
			return 0;
		}
		if(start==1){
			return 1;
		}
		for(int count=0;count<26;count++){
			if(num[start][count]==1){
				num[start][count]=0;
				int lol=recurse(count,num,max+1);
				num[start][count]=1;
				if(lol==1){
					return 1;
				}
				
			}
		}
		for(int count=0;count<26;count++){
			if(num[count][start]==1){
				num[count][start]=0;
				int lol=recurse(count,num,max+1);
				num[count][start]=1;
				if(lol==1){
					return 1;
				}
			}
		}
		return 0;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		String next=sc.next();
		ArrayList<String> out=new ArrayList<String>();
		int[][] num=new int[26][26];	
		while(!next.equals("**")){
			//System.out.println(next);
			int first=next.charAt(0)-65;
			int second=next.charAt(1)-65;
			num[first][second]=1;
			
			next=sc.next();
		}
		int check=recurse(0,num,1);
		if(check!=1){
			System.out.println("There are 0 disconnecting roads.");
		}
		else{
			for(int count=0;count<26;count++){
				for(int count2=0;count2<26;count2++){
					if(num[count][count2]==1){
						num[count][count2]=0;
						int lol=recurse(0,num,1);
						if(lol==0){
							char first=(char)(count+65);
							char second=(char)(count2+65);
							String end=first+""+second;
							out.add(end);
						}
						num[count][count2]=1;
					}
				}
			}
			for(int count=0;count<out.size();count++){
				System.out.println(out.get(count));
			}
			System.out.println("There are "+out.size()+" disconnecting roads.");
		}
		sc.close();
		
	}

}
