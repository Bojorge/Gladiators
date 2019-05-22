

/*
 * Listas anidades de tipo Genericas
 * Funciones: getData, addLast, deleteData
 * length y changeData
 */

public class List<T> {
	
	/*
	 * @param first: indica el primer elemento de la lista
	 */
	Nodo<T> first = null;
	
	private int sortValue = 0;

	
	
	/*
	 * Añade un elemento a la ultima posicion de la lista
	 * @param data: dato que se desea añadir
	 */
	public void addLast(T data) {
		if (first == null) {
			first = new Nodo<T>(data);
		}else {
			Nodo<T> temp = this.first;
			while(temp.next != null) {
				temp= temp.next;
			}
			temp.next = new Nodo<T>(data);
			}
		}
	
	/*
	 * Funcion que retorna el dato que este en la posicion num
	 * @param num: Es la posicion del dato que se desea
	 */
	public T getData(int num) {
		if (first == null) {
			return null;
		}
		Nodo<T> temp = first;
		try {
			for(int i=0; i <= (num-1); i++) {
				temp = temp.next;
			}
			return temp.data;
			
		}catch(Exception ex) {
			return null;	
		}
	}		

	/*
	 * Borra lo el nodo que este en la posicion num
	 * @param num: posicion que se desea eliminar
	 */
	public void deleteData(int num) {
		if (first == null) {
			return;
		}
		Nodo<T> temp = first;
		try {
			for(int i=0; i <= (num-2); i++) {
				temp = temp.next;
			}
			if (temp.next != null) {
				Nodo<T> temp2 = temp.next;
				if(temp2.next != null) {
					temp.next = temp2.next;
				}
				else if (temp2.next == null){
					temp.next = null;
				}
			}	
		}catch(Exception ex) {
			throw new Error("La lista no tiene esa cantidad de datos");	
		}
		return;
	}
	
	/*
	 * Indica la cantidad de elementos que tiene la lista
	 */
	public int length() {
		if(first == null) {
			return 0;
		}
		Nodo<T> temp = first;
		int i = 1;
		while(temp.next != null) {
			temp = temp.next;
			i++;
		}
		return i;
	}

	/*
	 * cambia lo que sea que este en la posicion pos por el dato T
	 * @param pos: posicion que se desea hacer cambio
	 * @param data: dato que se quiere cambiar
	 */
	public void changeData(int pos, T data) {
		if (first == null) {
			return;
		}
		Nodo<T> temp = first;
		try {
			for(int i=0; i <= (pos-1); i++) {
				temp = temp.next;
			}
			temp.data = data;
			
		}catch(Exception ex) {
			return;	
		}
		
	}

	public int getSortValue() {
		return sortValue;
	}

	public void setSortValue(int sortValue) {
		this.sortValue = sortValue;
	}
		
}
