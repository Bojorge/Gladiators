package server;

//Clase que maneja todo lo necesario para modificar las distintas
//Generaciones de los gladiadores
//Principalmente la modificacion de las distintas geraciones por medio de 
//algorimos generticos
public class ControladorGladiadores {
	
	//Para Primera Generacion
	int tamanoPrimeraRonda  =         2;
	int edadMaxima =                  100;
	int probSupervivenciaMaxima =     100;
    int inteligenciaEmocionalMaxima = 100;
    int condFisicaMaxima =            100;
    int fuerzaSuperiorMaxima =        100;
    int fuerzaInferiorMaxima =        100;
    RandomNameGenerator rn = new RandomNameGenerator();
    
    //Para genetico
    int cantidadEliminaryGenerar = 1;
    int cantidadMezclar = 1;
    int probabilidadMutacion = 50;
    int maximaMejoraEnMutacion = 50;
    
    //Funcion que retorna una lista de gladiadores,
    //estos son aleatoriamente generados.
    public List<Gladiador> primeraGeneracionG(){
    	List<Gladiador> list = new List<Gladiador>();
    	for (int i = 1; i <= tamanoPrimeraRonda; i++ ) {
    		String name = rn.getRandomName();
    		int edad = (int) (Math.random() * (edadMaxima)) + 1;
    		int probSupervivencia = (int) (Math.random() * (probSupervivenciaMaxima)) + 1;
    		int generaciones = 1;
    		int inteligenciaEmocional = (int) (Math.random() * (inteligenciaEmocionalMaxima)) + 1;
    		int condFisica = (int) (Math.random() * (condFisicaMaxima)) + 1;
    		int fuerzaSuperior = (int) (Math.random() * (fuerzaSuperiorMaxima)) + 1;
    		int fuerzaInferior = (int) (Math.random() * (fuerzaInferiorMaxima)) + 1;
    		int x = 0;
    		int y = 0;
    		Gladiador gl = new Gladiador(name, edad, probSupervivencia,
    				generaciones, inteligenciaEmocional, condFisica,
    				fuerzaSuperior, fuerzaInferior , x , y);
    		list.addLast(gl);
    	}
    	return list;
    }
    //Fucion que aplica fitness a una lista de Gladiadores, para despues
    //ser utilizado en el algorimo genetico
    public List<Gladiador> aplicarFitness(List<Gladiador> list){
    	for(int i = 0; i < (list.length()); i++) {
    		int cf = list.getData(i).condFisica;int e = list.getData(i).edad;
    		int pS = list.getData(i).probSupervivencia;int iE = list.getData(i).inteligenciaEmocional;
    		int fS = list.getData(i).fuerzaSuperior;int fI = list.getData(i).fuerzaInferior;
    		int x = list.getData(i).x;int y = list.getData(i).y;
    		int fit = cf + e + pS + iE + fS + fI + x*100 + y*100;
    		fit = fit / 8;
    		list.getData(i).fitness = fit;
    		//System.out.println(list.getData(i).fitness);
    	}
    	return list;
    }
    //Funcion que controla el procesos algorimo genetico de una lista de gladiadores
    public List<Gladiador> algoritmoGenetico(List<Gladiador> list){
    	aplicarFitness(list);
    	List<Gladiador> listMejores = buscarMejores(list);
    	List<Gladiador> nuevos = generarNuevosG(listMejores);
    	list = buscarPeoresyEliminarlos(list , nuevos);
    	return list;
    }
    //Fucion que busca los mejores objetos tomando en cuenta el fitness de 
    //miembro de la lista ingresada.
    public List<Gladiador> buscarMejores(List<Gladiador> list){
    	List<Gladiador> listMejores = new List<Gladiador>();
    	List<Gladiador> list2 = selectionSort(list);
    	for (int i = 1; i <= cantidadMezclar; i++) {
    		listMejores.addLast(list2.getData(list2.length()-i));
    	}
    	return listMejores;
    }
    //Funcion que detemina los objetos con menor fiteness, para ser reemplazados
    //por nuevos objetos del mismo tipo
    public List<Gladiador> buscarPeoresyEliminarlos(List<Gladiador> list, List<Gladiador> nuevos){
    	List<Gladiador> list2 = selectionSort(list);
    	for (int i = 0; i <= (cantidadEliminaryGenerar-1); i++) {
    		list2.changeData(i,nuevos.getData(i));
    	}
    	return list2;
    }
    //Funcion que toma una cantidad de Gladiadores, con estos genera otros con
    //los stats de los primeros. Esta Funcion es el CorssOver del algoritmo 
    //Genetico
    public List<Gladiador> generarNuevosG(List<Gladiador> listMejores){
    	List<Gladiador> nuevos = new List<Gladiador>();
    	for(int i = 0; i <= (cantidadEliminaryGenerar-1); i++) {
    		String name = rn.getRandomName();
    		int e = (int) (Math.random() * (listMejores.length()));int ps = (int) (Math.random() * (listMejores.length()));
    		int g = (int) (Math.random() * (listMejores.length()));int ie = (int) (Math.random() * (listMejores.length()));
    		int cf = (int) (Math.random() * (listMejores.length()));int fs = (int) (Math.random() * (listMejores.length()));
    		int fi = (int) (Math.random() * (listMejores.length()));
    		int edad = listMejores.getData(e).edad;                                    edad = mutacion(edad);
    		int probSupervivencia = listMejores.getData(ps).probSupervivencia;         probSupervivencia = mutacion(probSupervivencia);
    		int generaciones = listMejores.getData(g).generaciones;
    		int inteligenciaEmocional = listMejores.getData(ie).inteligenciaEmocional; inteligenciaEmocional = mutacion(inteligenciaEmocional);
    		int condFisica = listMejores.getData(cf).condFisica;                       condFisica = mutacion(condFisica);
    		int fuerzaSuperior = listMejores.getData(fs).fuerzaSuperior;               fuerzaSuperior = mutacion(fuerzaSuperior);
    		int fuerzaInferior = listMejores.getData(fi).fuerzaInferior;               fuerzaInferior = mutacion(fuerzaInferior);
    		
    		int x = 0; int y = 0;
    		Gladiador gl = new Gladiador(name, edad, probSupervivencia,
    				generaciones, inteligenciaEmocional, condFisica,
    				fuerzaSuperior, fuerzaInferior , x , y);
    		nuevos.addLast(gl);
    		
    	}
    	return nuevos;
    }
    //Funcion que recibe un valor, y con una porbabilidad
    //y una mejor asignadas, altera o deja igual al valor
    private int mutacion(int valor) {
    	int valorMutado = 0;
    	int pm = (int) (Math.random() * (100)) + 1;
    	if(pm <= probabilidadMutacion ) {
    		int mejora = (int) (Math.random() * (maximaMejoraEnMutacion)) + 1;
    		valorMutado = valor + mejora;
    	}else {
    		valorMutado = valor;
    	}
    	return valorMutado;
    }
    //Selection sort que tona en cuenta el finess de los integrantes de la lista.
    private List<Gladiador> selectionSort(List<Gladiador> list) {
		int n = list.length();
		for (int i = 0; i < (n-1); i++) {
			int mIndex = i;
			for (int j = i+1; j < n; j++) {
				if(list.getData(j).fitness < list.getData(mIndex).fitness) {
					mIndex = j;
				}	
			}
			Gladiador temp = list.getData(mIndex);
			list.changeData(mIndex,list.getData(i));
			list.changeData(i,temp);
		}
		return list;
}
    //Funcion que por medio de Sysout, muestra los fitnees de la lista
    public void printFitness(List<Gladiador> list) {
    	String fit = "";
    	int suma = 0;
    	list = aplicarFitness(list);
    	for (int i = 0; i <= (list.length()-1);i++) {
    		if(fit == "") {
    			fit = Integer.toString(list.getData(i).fitness);
    		}else {
    		fit = fit + " - " + Integer.toString(list.getData(i).fitness);
    		}
    		suma = suma + list.getData(i).fitness;
    	}
    	
    	System.out.println("Lista: " + fit + ", Promedio General: " + (suma/(list.length()-1)) );
    }
    //Funcion que retorna los fitness promedio y los finess de los integrantes de la lista
    public String FitnessString(List<Gladiador> list) {
    	String fit = "";
    	int suma = 0;
    	list = aplicarFitness(list);
    	for (int i = 0; i <= (list.length()-1);i++) {
    		if(fit == "") {
    			fit = Integer.toString(list.getData(i).fitness);
    		}else {
    		fit = fit + " - " + Integer.toString(list.getData(i).fitness);
    		}
    		suma = suma + list.getData(i).fitness;
    	}
    	String ret = "Lista: " + fit + ", Promedio General: " + (suma/(list.length()-1));
    	return ret;
    }
    //Funcion que calcula el promedio del fitness de los integrantes de la lista
    //y los retorna en forma de string
    public String FitnessStringProm(List<Gladiador> list) {
    	String fit = "";
    	int suma = 0;
    	list = aplicarFitness(list);
    	for (int i = 0; i <= (list.length()-1);i++) {
    		if(fit == "") {
    			fit = Integer.toString(list.getData(i).fitness);
    		}else {
    		fit = fit + " - " + Integer.toString(list.getData(i).fitness);
    		}
    		suma = suma + list.getData(i).fitness;
    	}
    	String ret = Integer.toString((suma/(list.length()-1)));
    	return ret;
    }
  //Funcion que calcula el promedio del fitness de los integrantes de la lista
   //y los retorna en forma de int
    public int FitnessPromEnInt(List<Gladiador> list) {
    	int fit = 0;
    	int suma = 0;
    	list = aplicarFitness(list);
    	for (int i = 0; i <= (list.length()-1);i++) {
    		if(fit == 0) {
    			fit = list.getData(i).fitness;
    		}else {
    		fit = fit + list.getData(i).fitness;
    		}
    		suma = suma + list.getData(i).fitness;
    	}
    	int ret = (suma/(list.length()-1));
    	return ret;
    }
    
}
