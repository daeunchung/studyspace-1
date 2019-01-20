package hello2java;

public class OddSum1_100 {
	public static void main(String[]args) {
		int i = 0;
		int k = 0;
		
		while( ++i <= 100 ) {
			if( i % 2 == 0 ) 
				continue;
			
			k += i ;
		}
		
		System.out.println( k );
	}

}
