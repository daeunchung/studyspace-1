package hijava;

public class N {
	
	int t;
	int x =10;
	int y =20;

	public void swap() {
		t=x;
		x=y;
		y=t;
		
	}

	public static void main(String[] args) {
		N n = new N();
		System.out.println("x=" +n.x);
		System.out.println("y=" +n.y);
		n.swap();
		System.out.println("x=" +n.x);
		System.out.println("y=" +n.y);
	}
	
}
