package CCC._00;
import java.util.Scanner;
public class S4_Golf {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int length=sc.nextInt();
		int max=sc.nextInt();
		int[] num=new int[max];
		for(int count=0;count<max;count++){
			num[count]=sc.nextInt();
		}
		int[] poly=new int[length+1];
		poly[0]=0;
		for(int count=1;count<length+1;count++) {
			int bash=-1;
		
			for(int count2=0;count2<max;count2++) {
				if(count-num[count2]>=0) {
					int next=poly[count-num[count2]];
					if(next>-1&&(bash==-1||bash>next)){
						bash=next+1;
					}
				}
				
			}
			poly[count]=bash;
			System.out.println(bash);
		}
		if(poly[poly.length-1]==-1) {
			System.out.println("Roberta acknowledges defeat.");
		}
		else {
			System.out.println("Roberta wins in "+poly[poly.length-1]+" strokes.");
		}
		sc.close();
		
	}

}
