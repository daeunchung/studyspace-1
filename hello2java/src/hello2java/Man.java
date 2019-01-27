package hello2java;

public class Man {
	public static final int COFFEE = 3000;
	public static final int DONUT = 2500;
	

	private String name;
	private int amount;
	
	public Man() {
		this.amount = 10000;
	}
	
	public Man(String name) {
		this();
		this.name = name;
	}

	public void BuyCoffee(int count) {
		//this.amount = this.amount - 3000 * count;
		this.amount -= COFFEE * count;
		
	}
	public void BuyDonut(int count) {
		//this.amount = this.amount - 3000 * count;
		this.amount -= DONUT * count;
		
	}
	
	
	
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAmount() {
		return amount;
	}

	public void setAmount(int amount) {
		this.amount = amount;
	}

	public void eatRice() {
System.out.println("π‰¿ª ∏‘Ω¿¥œ¥Ÿ");		
	}

	public void eatBread() {
System.out.println("Eat Bread");		
	}
}
