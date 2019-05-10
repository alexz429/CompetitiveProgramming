package _06;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class S1_Maternity {
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String dad=br.readLine();
		String mom=br.readLine();
		HashMap<String, Boolean> lol=new HashMap<>();
		if(dad.contains("A")||mom.contains("A")) {
			lol.put("A", true);
		}
		else {
			lol.put("A",false);
		}
		if(dad.contains("B")||mom.contains("B")) {
			lol.put("B", true);
		}
		else {
			lol.put("B",false);
		}
		if(dad.contains("C")||mom.contains("C")) {
			lol.put("C", true);
		}
		else {
			lol.put("C",false);
		}
		if(dad.contains("D")||mom.contains("D")) {
			lol.put("D", true);
		}
		else {
			lol.put("D",false);
		}
		if(dad.contains("E")||mom.contains("E")) {
			lol.put("E", true);
		}
		else {
			lol.put("E",false);
		}
		if(dad.contains("a")&&mom.contains("a")) {
			lol.put("a", true);
		}
		else {
			lol.put("a",false);
		}
		if(dad.contains("b")&&mom.contains("b")) {
			lol.put("b", true);
		}
		else {
			lol.put("b",false);
		}
		if(dad.contains("c")&&mom.contains("c")) {
			lol.put("c", true);
		}
		else {
			lol.put("c",false);
		}
		if(dad.contains("d")&&mom.contains("d")) {
			lol.put("d", true);
		}
		else {
			lol.put("d",false);
		}
		if(dad.contains("e")&&mom.contains("e")) {
			lol.put("e", true);
		}
		else {
			lol.put("e",false);
		}
		int max=Integer.parseInt(br.readLine());
		for(int count=0;count<max;count++) {
			String next=br.readLine();
			boolean got=true;
			for(int count2=0;count2<next.length();count2++) {
				char haha=next.charAt(count2);
				if(!lol.get(haha+"")) {
					got=false;
					System.out.println("Not their baby!");
					break;
				}
			}
			if(got) {
				System.out.println("Possible baby.");
			}
		}
		
	}
	

}
