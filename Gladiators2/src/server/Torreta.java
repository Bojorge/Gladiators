package server;
//Clase con los atributos necesarios para manejar
//el objeto Torre en el algorimo genetico
public class Torreta {
	String nombre;
    int generaciones;
    int danoInferior;
    int danoSuperior;
    int potencia;
    int tipobala;
    int fuerzalanzador;
    int velocidadlanzador;
    int altotorre;
    int dano;
    int alcance;
    int fitness;
    
    public Torreta(String nombre, int generaciones, int danoInferior, 
    		       int danoSuperior, int potencia, int tipobala, 
    		       int fuerzalanzador, int velocidadlanzador, int altotorre) {
    	this.nombre = nombre;
    	this.generaciones = generaciones;
    	this.danoInferior = danoInferior;
    	this.danoSuperior = danoSuperior;
    	this.potencia = potencia;
    	this.tipobala = tipobala;
    	this.fuerzalanzador = fuerzalanzador;
    	this.velocidadlanzador = velocidadlanzador;
    	this.altotorre = altotorre;
    	this.dano = (danoInferior+danoSuperior+potencia+tipobala)/4;
    	this.alcance = (fuerzalanzador+velocidadlanzador+altotorre+tipobala)/4;
    }
}
