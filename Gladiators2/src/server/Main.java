package server;

import java.io.IOException;
public class Main {

	public static void main(String[] args) throws IOException {
		
		/*
		ServerDirector sd = new ServerDirector();
		System.out.println(sd.getGeneracionCero());
		
		System.out.println("\n");
		
		List<Gladiador> l1 = sd.cg.primeraGeneracionG();
		System.out.println("Generacion antes de genetico");
		System.out.println(l1.length());
		System.out.println(sd.serializarListaG(l1));
		sd.cg.printFitness(l1);
		
		l1 = sd.cg.algoritmoGenetico(l1);
		System.out.println("Generacion despues de genetico"+ l1.length());
		System.out.println(sd.serializarListaG(l1));
		sd.cg.printFitness(l1);		
		String listag = sd.serializarListaG(l1);
		List<Gladiador> l2 = sd.deserializarG(listag);
		for(int i = 0; i < (l2.length()); i++) {System.out.println(sd.serializarGladiador(l2.getData(i)));}
		
		System.out.println("\n");
		
		List<Torreta> T1 = sd.ct.primeraGeneracionT();
		System.out.println("Generacion antes de genetico");
		System.out.println(T1.length());
		System.out.println(sd.serializarListaT(T1));
		sd.ct.printFitness(T1);
		
		T1 = sd.ct.algoritmoGenetico(T1);
		System.out.println("Generacion despues de genetico"+ T1.length());
		System.out.println(sd.serializarListaT(T1));
		sd.ct.printFitness(T1);	
		
		String listat = sd.serializarListaT(T1);
		List<Torreta> t2 = sd.deserializarT(listat);
		for(int i = 0; i < (l2.length()); i++) {System.out.println(sd.serializarTorreta(t2.getData(i)));}
		*/
		CheckGenerations i = new CheckGenerations();
		System.out.println(i.cliente);
		
	}

}
//Cuando viene un String, solo hay que pasarlo en la clase de utils