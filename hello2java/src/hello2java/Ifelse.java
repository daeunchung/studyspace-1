package hello2java;

public class Ifelse {
	public static void main(String[]args) {
		
		long ctm = System.currentTimeMillis() % 10;
		System.out.println(ctm);
		System.out.println("ctm =" + ctm);
		
		long sct = ctm % 3;
		
		if (sct == 1) {
			System.out.println("One");
		}
		else if (sct ==2 ) {
			System.out.println("Two");
		}
		else {
			System.out.println("Zero");
		}
	}
}

