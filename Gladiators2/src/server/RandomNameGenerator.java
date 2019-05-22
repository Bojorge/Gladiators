package server;
/*
 * Clase capas de crear nombres aleatorios
 * los crea como "Nombre apellido"
 */
public class RandomNameGenerator {
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
	public RandomNameGenerator() {
		listNames.addLast("Esben");listNames.addLast("Gerd");listNames.addLast("Gisli");
		listNames.addLast("Evar");listNames.addLast("Jorgen");listNames.addLast("Od�n");
		listNames.addLast("Sigurd");listNames.addLast("Thor");listNames.addLast("Viggo");
		listNames.addLast("Aren");listNames.addLast("Axe");listNames.addLast("Haakon");
		listNames.addLast("Niels");listNames.addLast("Olaf");listNames.addLast("Karen");
		listNames.addLast("Nilsa");listNames.addLast("Astrid");listNames.addLast("Erika");
		listNames.addLast("Valkiria");listNames.addLast("Siriana");listNames.addLast("Ondina");
		
		
		listlastNames.addLast("Abels");listlastNames.addLast("Adamsen");listlastNames.addLast("Irud");
		listlastNames.addLast("Dahl");listlastNames.addLast("Haakonsson");listlastNames.addLast("Erickson");
		listlastNames.addLast("Holt");listlastNames.addLast("Kristiansen");listlastNames.addLast("Lange");
		listlastNames.addLast("Noss");listlastNames.addLast("Nielsen");listlastNames.addLast("Oliversen");
		listlastNames.addLast("Ostberg");listlastNames.addLast("Rolvsson");listlastNames.addLast("Spillum");
		listlastNames.addLast("Tennfjord");listlastNames.addLast("Vilhjalmsson");listlastNames.addLast("Wolff");
		listlastNames.addLast("Sorensen");listlastNames.addLast("Raske");listlastNames.addLast("Spillum");
		
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
