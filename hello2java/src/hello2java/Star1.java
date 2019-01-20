package hello2java;

public class Star1 {

	public static void main(String[] args) {
		int line = 7;
		for (int i = 1; i <= line; i++) {
			
			for (int j = 1; j <= (line - i); j++) {
				System.out.print(' ');
			}
			for (int j = 1; j <= i ; j++) {
				System.out.print('*');
			}
			System.out.println();
		}
	}
	
}
