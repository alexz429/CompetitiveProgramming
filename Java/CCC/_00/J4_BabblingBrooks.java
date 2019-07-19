package CCC._00;


import java.util.ArrayList;
import java.util.Scanner;
public class J4_BabblingBrooks {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int max=sc.nextInt();
		ArrayList<Double> num=new ArrayList<Double>();
		for(int count=0;count<max;count++){
			num.add(sc.nextDouble());
		}
		int next=sc.nextInt();
		while(next!=77){
			if(next!=88){
				int where=sc.nextInt()-1;
				int num2=sc.nextInt();
				double temp=num.remove(where);
				num.add(where,temp*(100-num2)/100);
				temp=temp*num2/100;
				num.add(where, temp);
				
			}
			else{
				int where=sc.nextInt()-1;
				if(num.size()>where-1){
					double temp=num.remove(where);
					temp+=num.get(where);
					num.remove(where);
					num.add(where,temp);
				}
			}
			next=sc.nextInt();
		}
		for(int count=0;count<num.size();count++){
			System.out.print(num.get(count)+" ");
		}
		sc.close();
	}

}
