package hijava;

public class CBVR2 {
	int m=2;
	
	public static void main(String[] args) {
		int i=1;
		System.out.println("i1=" + i);
		
		change1(i);
		System.out.println("i2=" + i);
		
		Cbvr cb1= new Cbvr();
		System.out.println("cb1="+cb1.m);
		
		change2(i);
		System.out.println("cb2="+cb1.m);
		

	}

}
