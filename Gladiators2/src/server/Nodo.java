package server;

/*
 * Clase necesaria para hacer las listas enlazadas
 */
public class Nodo<T> {
	/*
	 * @param data: es el dato que contiene el nodo de tipo generico
	 * @param next: es a donde esta apuntado el nodo, si no hay 
	 * nadie es nulo
	 */
	T data;
	Nodo<T> next;
	
	/*
	 * Constructor
	 * @param data2: es el dato que se desea que tenga el nodo.
	 */
	public Nodo(T data2) {
		this.data = data2;
		this.next = null;
	}
}
