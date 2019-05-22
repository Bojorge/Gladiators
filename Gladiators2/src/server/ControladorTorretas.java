package server;
//Clase que maneja todo lo necesario para modificar las distintas
//Generaciones de las Torretas
//Principalmente la modificacion de las distintas geraciones por medio de 
//algorimos generticos
public class ControladorTorretas {
	//Para Primera Generacion
	int tamanoPrimeraRonda    = 2;
	int danoInferiorMax       = 10;
    int danoSuperiorMax       = 10;
    int potenciaMax           = 10;
    int tipobalaMax           = 3;
    int fuerzalanzadorMax     = 3;
    int velocidadlanzadorMax  = 3;
    int altotorreMax          = 3;
    RandomNameGeneratorTowers rn = new RandomNameGeneratorTowers();
    
  //Para genetico
    int cantidadEliminaryGenerar = 1;
    int cantidadMezclar = 1;
    int probabilidadMutacion = 40;
    int maximaMejoraEnMutacion = 5;
  //Funcion que retorna una lista de Torretas,
    //estos son aleatoriamente generados.
	public List<Torreta> primeraGeneracionT(){
		List<Torreta> list = new List<Torreta>();
		for (int i = 1; i <= tamanoPrimeraRonda; i++ ) {
    		String name = rn.getRandomName();
    		int danoInferior = (int) (Math.random() * (danoInferiorMax)) + 1;
    		int danoSuperior = (int) (Math.random() * (danoSuperiorMax)) + 1;
    		int generaciones = 1;
    		int potencia = (int) (Math.random() * (potenciaMax)) + 1;
    		int tipobala = (int) (Math.random() * (tipobalaMax)) + 1;
    		int fuerzalanzador = (int) (Math.random() * (fuerzalanzadorMax)) + 1;
    		int velocidadlanzador = (int) (Math.random() * (velocidadlanzadorMax)) + 1;
    		int altotorre = (int) (Math.random() * (altotorreMax)) + 1;
    		Torreta gl = new Torreta(name, generaciones, danoInferior,
    				danoSuperior, potencia, tipobala,
    				fuerzalanzador, velocidadlanzador , altotorre);
    		list.addLast(gl);
    	}
		return list;
	}
	
	public Torreta generarIndividuo() {
		String name = rn.getRandomName();
		int danoInferior = (int) (Math.random() * (danoInferiorMax)) + 1;
		int danoSuperior = (int) (Math.random() * (danoSuperiorMax)) + 1;
		int generaciones = 1;
		int potencia = (int) (Math.random() * (potenciaMax)) + 1;
		int tipobala = (int) (Math.random() * (tipobalaMax)) + 1;
		int fuerzalanzador = (int) (Math.random() * (fuerzalanzadorMax)) + 1;
		int velocidadlanzador = (int) (Math.random() * (velocidadlanzadorMax)) + 1;
		int altotorre = (int) (Math.random() * (altotorreMax)) + 1;
		Torreta gl = new Torreta(name, generaciones, danoInferior,
				danoSuperior, potencia, tipobala,
				fuerzalanzador, velocidadlanzador , altotorre);
		return gl;
	}
	//Fucion que aplica fitness a una lista de Torretas, para despues
    //ser utilizado en el algorimo genetico
	public List<Torreta> aplicarFitness(List<Torreta> list){
    	for(int i = 0; i < (list.length()); i++) {
    		int cf = list.getData(i).danoInferior;int e = list.getData(i).danoSuperior;
    		int pS = list.getData(i).potencia;int iE = list.getData(i).tipobala;
    		int fS = list.getData(i).fuerzalanzador;int fI = list.getData(i).velocidadlanzador;
    		int x = list.getData(i).altotorre;int y = list.getData(i).dano;
    		int alc = list.getData(i).fitness;
    		int fit = cf + e + pS + iE + fS + fI + x + y + alc;
    		fit = fit / 9;
    		list.getData(i).fitness = fit;
    	}
    	return list;
    }
    //Funcion que controla el procesos algorimo genetico de una lista de gladiadores
	public List<Torreta> algoritmoGenetico(List<Torreta> list){
    	aplicarFitness(list);
    	List<Torreta> listMejores = buscarMejores(list);
    	List<Torreta> nuevos = generarNuevosG(listMejores);
    	list = buscarPeoresyEliminarlos(list , nuevos);
    	return list;
    }
	//Fucion que busca los mejores objetos tomando en cuenta el fitness de 
    //miembro de la lista ingresada.
	public List<Torreta> buscarMejores(List<Torreta> list){
    	List<Torreta> listMejores = new List<Torreta>();
    	List<Torreta> list2 = selectionSort(list);
    	for (int i = 1; i <= cantidadMezclar; i++) {
    		listMejores.addLast(list2.getData(list2.length()-i));
    	}
    	return listMejores;
    }
	 //Funcion que detemina los objetos con menor fiteness, para ser reemplazados
    //por nuevos objetos del mismo tipo
	public List<Torreta> buscarPeoresyEliminarlos(List<Torreta> list, List<Torreta> nuevos){
    	List<Torreta> list2 = selectionSort(list);
    	for (int i = 0; i <= (cantidadEliminaryGenerar-1); i++) {
    		list2.changeData(i,nuevos.getData(i));
    	}
    	return list2;
    }
	//Funcion que toma una cantidad de Torretas, con estos genera otros con
    //los stats de los primeros. Esta Funcion es el CorssOver del algoritmo 
    //Genetico
	 public List<Torreta> generarNuevosG(List<Torreta> listMejores){
	    	List<Torreta> nuevos = new List<Torreta>();
	    	for(int i = 0; i <= (cantidadEliminaryGenerar-1); i++) {
	    		String name = rn.getRandomName();
	    		int e = (int) (Math.random() * (listMejores.length()));int ps = (int) (Math.random() * (listMejores.length()));
	    		int g = (int) (Math.random() * (listMejores.length()));int ie = (int) (Math.random() * (listMejores.length()));
	    		int cf = (int) (Math.random() * (listMejores.length()));int fs = (int) (Math.random() * (listMejores.length()));
	    		int fi = (int) (Math.random() * (listMejores.length()));
	    		int danoInferior = listMejores.getData(e).danoInferior;                  danoInferior = mutacion(danoInferior);
	    		int danoSuperior = listMejores.getData(ps).danoSuperior;               danoSuperior = mutacion(danoSuperior);
	    		int generaciones = listMejores.getData(g).generaciones;
	    		int potencia = listMejores.getData(ie).potencia;                         potencia = mutacion(potencia);
	    		int tipobala = listMejores.getData(cf).tipobala;                         tipobala = mutacionValoresImportantes(tipobala);
	    		int fuerzalanzador = listMejores.getData(fs).fuerzalanzador;             fuerzalanzador = mutacionValoresImportantes(fuerzalanzador);
	    		int velocidadlanzador = listMejores.getData(fi).velocidadlanzador;       velocidadlanzador = mutacionValoresImportantes(velocidadlanzador);
	    		int altotorre = listMejores.getData(fi).altotorre;                       altotorre = mutacionValoresImportantes(altotorre);
	    	
	    		Torreta gl = new Torreta(name, generaciones, danoInferior,
	    				danoSuperior, potencia, tipobala,
	    				fuerzalanzador, velocidadlanzador , altotorre);
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
	private int mutacionValoresImportantes(int valor) {
    	int valorMutado = 0;
    	int pm = (int) (Math.random() * (100)) + 1;
    	if(pm <= probabilidadMutacion ) {
    		int mejora = (int) (Math.random() * (3)) + 1;
    		valorMutado = valor + mejora;
    	}else {
    		valorMutado = valor;
    	}
    	return valorMutado;
    }
    //Selection sort que tona en cuenta el finess de los integrantes de la lista.
	private List<Torreta> selectionSort(List<Torreta> list) {
		int n = list.length();
		for (int i = 0; i < (n-1); i++) {
			int mIndex = i;
			for (int j = i+1; j < n; j++) {
				if(list.getData(j).fitness < list.getData(mIndex).fitness) {
					mIndex = j;
				}	
			}
			Torreta temp = list.getData(mIndex);
			list.changeData(mIndex,list.getData(i));
			list.changeData(i,temp);
		}
		return list;
}
    //Funcion que por medio de Sysout, muestra los fitnees de la lista
	public void printFitness(List<Torreta> list) {
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
	public String FitnessString(List<Torreta> list) {
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
	public String FitnessStringProm(List<Torreta> list) {
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
	public int FitnessPromEnInt(List<Torreta> list) {
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
