import java.io.IOException;

public class Main {

	public static void main(String[] args) throws IOException {
		
		ClienteG clienteG = new ClienteG();
		String p = clienteG.getPopulations();
		System.out.println(p);
		String[] gt = p.split("-");
		System.out.println(gt[0]);
		System.out.println(gt[1]);
		
		String G = gt[0];
		String T = gt[1];
		System.out.println("Stats Primera generacion");
	    String statsGladiadores = clienteG.poblacionGladiadores();
		System.out.println(statsGladiadores);
		
		String statsTorres = clienteG.poblacionTorretas();
		System.out.println(statsTorres);
		
		String nuevapoblaGladiadores = clienteG.postPoblacionGladiadoresStats(G);
		System.out.println(nuevapoblaGladiadores);
	
		String nuevapoblaTorretas = clienteG.postPoblacionTorretasStats(T);
		System.out.println(nuevapoblaTorretas);
		
		System.out.println("Stats Segunda generacion");
		statsGladiadores = clienteG.poblacionGladiadores();
		System.out.println(statsGladiadores);
		
		statsTorres = clienteG.poblacionTorretas();
		System.out.println(statsTorres);
		
		
		//CheckGenerations i = new CheckGenerations();
	}

}
