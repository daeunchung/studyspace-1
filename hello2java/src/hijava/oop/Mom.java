package hijava.oop;

	public class Mom {
		private String name;
		
		public Mom(String name) {
			this.name = name;
		}
		
		public Mom() {
			this("¾ö¸¶");
		}
		
		/*public void drinkBeer() {
			System.out.println("Drinking Beer!!");
		}*/
		
		
		
		
		public String getName() {
			return this.name;
		}
		
		public void eat() {
			System.out.println("EAT!!");
		}
		
		public void say() {
			System.out.println("Mom said...");
		}

		public void drinkBeer() {
			System.out.println("Drinking Beer!!");
			
		}

}
