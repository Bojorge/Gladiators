import java.net.*;
import java.io.*;


//Clase que controla la comunicacion con el servidor
//en java y en cliente en C++, por medio de sockets
public class ConeccionC implements Runnable{
	
	static ClienteG clienteg = new ClienteG();
	private static String population = "";
	private static String stadoGladiador = "";
	private static String stadoTorreta= "";
	private static String nuevaGG = "";
	private static String nuevaGT = "";
	

	public ConeccionC() {
		Thread hilo = new Thread(this);
		hilo.start();
	}
	
	public static void main(String[] args) throws IOException{
		new ConeccionC();
	}
	static private void getP() throws IOException {
		population= clienteg.getPopulations();
		return;
	}
	//Funcion que retorna los estados de los gladiadores con la clase
	// CLienteG
	static private void getstatsG() throws IOException{
		stadoGladiador = clienteg.poblacionGladiadores();
	}
	//Funcion que retorna los estados de las Torretas con la clase
		// CLienteG
	static private void getstatsT() throws IOException{
		stadoTorreta = clienteg.poblacionTorretas();
	}
	//Funcion que con un string en formato JSON de Objetos Gladiador
	//Retorna una lista sometida a un algorimo Genetico ,gracias a la clase
	// CLienteG
	static private void nuevaGG(String n) {
		nuevaGG = clienteg.postPoblacionGladiadoresStats(n);	
	}
	//Funcion que con un string en formato JSON de Objetos Torreta
	//Retorna una lista sometida a un algorimo Genetico ,gracias a la clase
	// CLienteG
	static private void nuevaGT(String n) {
		nuevaGT = clienteg.postPoblacionTorretasStats(n);	
	}
	//Creacion y manejo de Sockets
	@Override
	public void run() {
		int port = 6611;
		try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Servidor esta escuchando en puerto: " + port);
            while(true){
                try{
                    System.out.println("Esperando una coneccion");
                    Socket socket = serverSocket.accept();
                    BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream())); 
                    System.out.println("------Se ha conectado un Cliente-----");
                    String inputLine; 
                    inputLine = in.readLine();
                    boolean confirmacion = false;
                    System.out.println("Cliente dice: " + inputLine);
                    if (inputLine.startsWith("1") && confirmacion == false) {
                        System.out.println("Cliente Hace comando: " + "1");
                        OutputStream output = socket.getOutputStream();
                        PrintWriter wr = new PrintWriter(output, true);
                    	getP();
                    	if(population != null) {
                    		System.out.println("Cliente Hizo Get Population");
                    		System.out.println("Se envia al Cliente: " + population);
                    		//System.out.println("tiene un peso de: " + population.length());
                    		wr.println(population);
                    	}
                    	confirmacion = true;
                    wr.close();
                    }//Get Gladiator Statis = 2
                    if (inputLine.startsWith("2")) {
                        System.out.println("Cliente Hace comando: 2");
                        OutputStream output = socket.getOutputStream();
                        PrintWriter wr = new PrintWriter(output, true);
                    	getP();
                    	getstatsG();
                		System.out.println("Cliente Hizo Get Gladiators");
                    	System.out.println("Se envia al Cliente: " + stadoGladiador);
                    	wr.println(stadoGladiador);
                    	wr.close();
                    }//Get Towers Stats = 3
                    if (inputLine.startsWith("3")) {
                        System.out.println("Cliente Hace comando: 3");
                        OutputStream output = socket.getOutputStream();
                        PrintWriter wr = new PrintWriter(output, true);
                    	getP();
                    	getstatsT();
                		System.out.println("Cliente Hizo Get Towers");
                    	System.out.println("Se envia al Cliente: " + stadoTorreta);
                    	wr.println(stadoTorreta);
                    	wr.close();
                    }//Post Gladiadores
                    if (inputLine.startsWith("8")) {
                        System.out.println("Cliente Hace comando: 8");
                        OutputStream output = socket.getOutputStream();
                        PrintWriter wr = new PrintWriter(output, true);
                    	String lista = inputLine.substring(1);
                    	System.out.println(lista);
                    	nuevaGG(lista);
                    	if(nuevaGG == null) {
                    		getP();
                    		String[] entrada2 = population.split("-");
                			String gladi = entrada2[0];
                    		nuevaGG(gladi);
                    	}
                		System.out.println("Cliente Hizo Post Gladiators");
                    	System.out.println("Se envia al Cliente: " + nuevaGG);
                    	wr.println(nuevaGG);
                    	wr.close();
                    }//Post GladiadoresTorretas
                    if (inputLine.startsWith("#")) {
                        System.out.println("Cliente Hace comando: #");
                        OutputStream output = socket.getOutputStream();
                        PrintWriter wr = new PrintWriter(output, true);
                    	String lista = inputLine.substring(1);
                    	System.out.println("ESTA ES LA LISTA QUE LLEGA"+lista);
                    	nuevaGT(lista);
                    	if(nuevaGT == null) {
                    		getP();
                    		String[] entrada2 = population.split("-");
                			String torr = entrada2[1];
                    		nuevaGT(torr);
                    	}if(nuevaGT == null) {
                    		
                    	}
                		System.out.println("Cliente Hizo Post Towers");
                    	System.out.println("Se envia al Cliente: " + nuevaGT);
                    	wr.println(nuevaGT);
                    	wr.close();
                    }
                    System.out.println("----Fin de la coneccion----"); 
                }catch(Exception e){
                    e.printStackTrace();
                }
            }
      
        } catch (IOException ex) {
            System.out.println("Server exception: " + ex.getMessage());
            ex.printStackTrace();
        }
}	
	

}
	
