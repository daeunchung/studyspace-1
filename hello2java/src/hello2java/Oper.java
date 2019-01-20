package hello2java;

public class Oper {

	public static void main(String[]args) {
		int i=0;
		System.out.println(i);
		
		/*i++; //i=i+1;
		i--; //i=i-1;*/
		int k = !(i>0) ? 100 : 1000;
		System.out.println(i++);
		
	}
}
