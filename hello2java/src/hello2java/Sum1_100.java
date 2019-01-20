package hello2java;

public class Sum1_100 {
	public static void main(String[]args) {
		int i = 0;
		int k = 0;
		
		while( i>= 0 && i<100 ) {
			i++;
			if( i<101 ) {
				k += i;
			}
		}
		System.out.println( k );
	}
	
}
