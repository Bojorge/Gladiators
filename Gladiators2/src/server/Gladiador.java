package server;
//Clase con los atributos necesarios para manejar
//el objeto gladiador en el algorimo genetico
public class Gladiador {
	
	    String name;
	    int edad;
	    int probSupervivencia;
	    int generaciones;
	    int inteligenciaEmocional;
	    int condFisica;
	    int fuerzaSuperior;
	    int fuerzaInferior;
	    int resistencia;
	    int x,y;
	    int fitness = 0;
	    
	    public Gladiador(String name, int edad, int probSupervivencia,
	    				int generaciones, int inteligenciaEmocional, 
	    				int condFisica, int fuerzaSuperior, 
	    				int fuerzaInferior, int x , int y) {
	    	this.name = name;
	    	this.edad = edad;
	    	this.probSupervivencia = probSupervivencia;
	    	this.generaciones = generaciones;
	    	this.inteligenciaEmocional = inteligenciaEmocional;
	    	this.condFisica = condFisica;
	    	this.fuerzaSuperior = fuerzaSuperior;
	    	this.fuerzaInferior = fuerzaInferior;
	    	this.resistencia = (probSupervivencia+generaciones+inteligenciaEmocional+condFisica+fuerzaSuperior+fuerzaInferior)/6;
	    	this.x = x;
	    	this.y = y;
	    	
	    }
	    
	    String getName(){
	        return name;
	    }
	    void setName(String name){
	        this.name = name;

	    }
	    int getEdad(){
	        return edad;
	    }
	    void setEdad(int edad){
	    	this.edad = edad;

	    }
	    int getprobSupervivencia(){
	        return probSupervivencia;
	    }
	    void setprobSupervivencia(int x){
	        probSupervivencia = x;

	    }
	    int getGeneraciones(){
	        return generaciones;
	    }
	    void setGeneraciones(int x){
	    	this.generaciones = x;

	    }
	    int getinteligenciaEmocional(){
	        return inteligenciaEmocional;
	    }
	    void setinteligenciaEmocional(int x){
	    	this.inteligenciaEmocional = x;

	    }
	    int getcondFisica(){
	        return condFisica;
	    }
	    void setcondFisica(int x){
	    	this.condFisica = x;

	    }
	    int getfuerzaSuperior(){
	        return fuerzaSuperior;
	    }
	    void setfuerzaSuperior(int x){
	    	this.fuerzaSuperior = x;

	    }
	    int getfuerzaInferior(){
	        return fuerzaInferior;
	    }
	    void setfuerzaInferior(int x){
	    	this.fuerzaInferior = x;

	}
}
