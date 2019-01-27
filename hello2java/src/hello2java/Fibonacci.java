package hello2java;

public class Fibonacci {

	public static void main(String[] args) {
		int inum = 10;
		for (int i = 0; i <= inum; i++) {
			System.out.print(fibo(i) + " ");
		}
	}

	private static int fibo(int num) {
//		if (num <= 1) return num;
		
		if (num > 1)
			return fibo(num - 1) + fibo(num - 2);
		else 
			return num;
	}
}




