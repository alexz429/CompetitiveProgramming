package CCC._05;
import java.util.*;
public class J3_ReturningHome {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		Stack<String> list=new Stack<>();
		list.push("HOME");
		
		while(sc.hasNextLine()) {
			String next=sc.nextLine();
			if(next.equals("SCHOOL")) {
				break;
			}
			if(next.equals("R")) {
				next="LEFT";
			}
			else if(next.equals("L")) {
				next="RIGHT";
			}
			list.push(next);
		}
		while(!list.isEmpty()) {
			if(list.size()==2) {
				System.out.println("Turn "+ list.pop()+" into your HOME.");
				sc.close();
				return;
			}
			
			System.out.println("Turn "+list.pop()+" onto "+list.pop()+" street.");
		}
		sc.close();
	}

}
