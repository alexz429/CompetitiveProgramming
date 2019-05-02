package _15;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class R1P1_Smarties {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		for(int count=0;count<10;count++) {
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
//			BufferedReader why=new BufferedReader(new InputStreamReader(System.in));
			HashMap<String, Integer> lol=new HashMap<>();
			String next=br.readLine();
			lol.put("orange",0);
			lol.put("green",0);
			lol.put("blue",0);
			lol.put("yellow",0);
			lol.put("pink",0);
			lol.put("violet",0);
			lol.put("brown",0);
			lol.put("red",0);
			while(!next.equals("end of box")) {
				
				lol.put(next, lol.get(next)+1);
				next=br.readLine();
			}
			int out=0;
			//take each color
			int in=lol.get("orange");
			out+=(int)Math.ceil((double)in/7)*13;
			 in=lol.get("blue");
				out+=(int)Math.ceil((double)in/7)*13;
				 in=lol.get("green");
					out+=(int)Math.ceil((double)in/7)*13;
					 in=lol.get("yellow");
						out+=(int)Math.ceil((double)in/7)*13;
						 in=lol.get("pink");
							out+=(int)Math.ceil((double)in/7)*13;
							 in=lol.get("violet");
								out+=(int)Math.ceil((double)in/7)*13;
								 in=lol.get("brown");
									out+=(int)Math.ceil((double)in/7)*13;
									 in=lol.get("red");
										out+=in*16;
										System.out.println(out);
//										br.readLine();
		}
		
								
	}

}
