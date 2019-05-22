package server;

//Funcion con atributos y metodos estaticos
//para que el webServise sepa cuales son las 
//listas de gladiadores y Torretas actualizadas
//en la comunicacion entre los diferentes direcciones URL
public class DataBase {

	static List<Gladiador> ListaGladiadores;
	static List<Torreta> ListaTorreta;
	
	private static DataBase single_instance = null; 
	
	private DataBase() {
		
	}
	//Sinlgetone, para la creacion de la base de datos
	public static DataBase getInstance(){ 
        if (single_instance == null) 
            single_instance = new DataBase(); 
        return single_instance; 
    } 
	
	//Cambia la lista de lagdiadores
	static void changeLAG(List<Gladiador> LAG) {
		ListaGladiadores = LAG;
	}
	//cambia la lista de TOrretas
	static void changeLAT(List<Torreta> LAT) {
		ListaTorreta = LAT;
	}
	static List<Gladiador> getLAG() {
		return ListaGladiadores;
	}
	static List<Torreta> getLAT() {
		return ListaTorreta;
	}
	

}
