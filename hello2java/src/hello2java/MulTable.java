package hello2java;

public class MulTable {

	public static void main(String[]args) {
		int i, j ;
		for ( i=2 ; i<= 9; i++ ) {
			System.out.println(i + "´Ü----------" );
		    for( int j1 = 1; j1 <= 9; j1++ ) {
		    	System.out.println( i + "*" + j1 + " = "  + (i * j1));
		    }
		}
	}
}
