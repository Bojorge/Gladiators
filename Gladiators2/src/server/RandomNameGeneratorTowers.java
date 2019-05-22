package server;

public class RandomNameGeneratorTowers {
	/*
	 * @param listNames: lista enlazada de tipo String, con una lista de nombres
	 * @param listlastNames: lista enlazada de tipo String, con una lista de apellidos
	 */
	List<String> listNames = new List<String>();
	List<String> listlastNames = new List<String>();
	
	/*
	 * Constructor
	 * Agreaga los nombres a listNames y apellidos a listlastNames
	 */
	public RandomNameGeneratorTowers() {
		listNames.addLast("GTDN");listNames.addLast("HFBS");listNames.addLast("RSDG");
		listNames.addLast("RSDV");listNames.addLast("HFSV");listNames.addLast("QEAS");
		listNames.addLast("WASD");listNames.addLast("SPLO");listNames.addLast("YFJU");
		listNames.addLast("NFFG");listNames.addLast("ULOP");listNames.addLast("VMFG");
		listNames.addLast("DFGV");listNames.addLast("SFWE");listNames.addLast("SDFE");
		listNames.addLast("MNDT");listNames.addLast("GFHR");listNames.addLast("FGER");
		listNames.addLast("FGDE");listNames.addLast("YTIH");listNames.addLast("JKLO");
		
		
		listlastNames.addLast("3467");listlastNames.addLast("2675");listlastNames.addLast("4527");
		listlastNames.addLast("4210");listlastNames.addLast("4583");listlastNames.addLast("1235");
		listlastNames.addLast("4578");listlastNames.addLast("4572");listlastNames.addLast("3689");
		listlastNames.addLast("4530");listlastNames.addLast("1220");listlastNames.addLast("4763");
		listlastNames.addLast("6834");listlastNames.addLast("1289");listlastNames.addLast("1253");
		listlastNames.addLast("2133");listlastNames.addLast("1175");listlastNames.addLast("12536");
		listlastNames.addLast("2866");listlastNames.addLast("9986");listlastNames.addLast("6666");
		
	}
	
	/*
	 * Funcion que retorna un string con un nombre y un apellidos aleatorios
	 */
	public String getRandomName() {
		int randomNum = (int) (Math.random() * (listNames.length())) + 1;
		String N = listNames.getData(randomNum - 1);
		
		int randomNum2 = (int) (Math.random() * (listlastNames.length())) + 1;
		String L = listlastNames.getData(randomNum2 - 1);
		
		if(N == null || L == null) {
			N = "Odin";
			L = "Tennfjord";
		}
		String name = N + " " + L;
		return name;
	}
}
