package server;

//Funcion que revela el comportamiento de las generaciones
//sometidas a un algoritmo genetico, por medio de muestra de
//datos y de generacion de Graficas
import java.io.IOException;
import java.util.Scanner;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartFrame;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

public class CheckGenerations {
	
	ServerDirector cliente;
	Scanner scan;
	String gladi;
	String torr;
	int gactual;
	
	//Grafica 
	XYSeries seriesGladia = new XYSeries("Fitness Promedio");
	XYSeries seriesTorres = new XYSeries("Fitness Promedio");

	public CheckGenerations() throws IOException {
		 this.cliente = new ServerDirector();
		 this.scan = new Scanner(System.in);
		 gactual = 1;
		 startmenu();
	}
	//Funcion que genera un menu en la consola para poder indicarle
	//que se desea hacer los las generaciones.
	private void startmenu() throws IOException {
		System.out.println("---------------Revisar Generaciones------------");
		System.out.println("    1.Comenzar Generacion");
		System.out.println("    2.Saltar 1 Generacion");
		System.out.println("    3.Saltar x Generaciones");
		System.out.println("    4.Generar Grafica Gladiadores (Fitness Promedio vs Generacion)");
		System.out.println("    5.Generar Grafica Torretas (Fitness Promedio vs Generacion)");
		String str=scan.nextLine();
		if (str.equals("1")) {
			String entrada = cliente.getGeneracionCero();
			String[] entrada2 = entrada.split("-");
			gladi = entrada2[0];
			torr = entrada2[1];
			String p = cliente.getestadoGladiadores();
			String z = cliente.getstadoTorretas();
			System.out.println("  Generacion 1: ");
			System.out.println("   = Poblacion de Gladiadores > " + p );
			System.out.println("     Poblacion de Torretas > " + z );
			seriesGladia.add(gactual,cliente.getestadoGladiadoresPromEnInt());
			seriesTorres.add(gactual,cliente.getstadoTorretasPromEnInt());
		}if (str.equals("2")) {
			gladi = cliente.obtenerNuevaGeneracionGladiadores(gladi);
			torr = cliente.obtenerNuevaGeneracionTorretas(torr);
			String p3 = cliente.getestadoGladiadores();
			String z3 = cliente.getstadoTorretas();
			gactual= gactual +1;
			System.out.println("  Siguiente Generacion: ");
			System.out.println("  >>Gen:" + gactual +"<<");
			System.out.println("   = Poblacion de Gladiadores > " + p3 );
			System.out.println("     Poblacion de Torretas > " + z3 );
			seriesGladia.add(gactual,cliente.getestadoGladiadoresPromEnInt());
			seriesTorres.add(gactual,cliente.getstadoTorretasPromEnInt());
		}if (str.equals("3")) {
			System.out.println("  Ingrese la cantidad de Generaciones");
			String str2=scan.nextLine();
			System.out.println("  Mostrar Promedio de cada generacion? s/n");
			String str4=scan.nextLine();
			int max = Integer.valueOf(str2);
			for(int i = 0; i < max;i++) {
				gactual= gactual +1;
				gladi = cliente.obtenerNuevaGeneracionGladiadores(gladi);
				torr = cliente.obtenerNuevaGeneracionTorretas(torr);
				String p4 = cliente.getestadoGladiadores();
				String z4 = cliente.getstadoTorretas();
				seriesGladia.add(gactual,cliente.getestadoGladiadoresPromEnInt());
				seriesTorres.add(gactual,cliente.getstadoTorretasPromEnInt());
				if (str4.equals("s")) {
					System.out.println("  >>Gen:" + gactual +"<<");
					System.out.println("   = Poblacion de Gladiadores > " + p4 );
					System.out.println("     Poblacion de Torretas > " + z4 );
				}
				
			}
			System.out.println("  Generaciones Adelante: " + str2);
			if (str4.equals("n")){
				String p1 = cliente.getestadoGladiadores();
				String z1 = cliente.getstadoTorretas();
				System.out.println("  >>Gen: " + gactual +"<<");
				System.out.println("   = Poblacion de Gladiadores > " + p1 );
				System.out.println("     Poblacion de Torretas > " + z1 );	
			}
		}if (str.equals("4")) {
			GraficaG();
		}if (str.equals("5")) {
			GraficaT();
		}
		
		startmenu();
	}
	//Funcion que muestra en una ventana emergente un grafica con los datos
	//Genreados en el menu, los datos son de la clase tipo Gladiador
	private void GraficaG() {
		XYSeriesCollection datase = new XYSeriesCollection();
		datase.addSeries(seriesGladia);
		JFreeChart chart = ChartFactory.createXYLineChart("Grafico Fitness Promedio por Generacion", 
				"Generacion", "Fitness Promedio", datase,
				PlotOrientation.VERTICAL, true, false, false);
		ChartFrame frame = new ChartFrame("Fitness por Generacion (GLADIADORES)", chart);
		frame.pack();
		frame.setVisible(true);
	}
	//Funcion que muestra en una ventana emergente un grafica con los datos
		//Genreados en el menu, los datos son de la clase tipo Torreta
	private void GraficaT() {
		XYSeriesCollection datase = new XYSeriesCollection();
		datase.addSeries(seriesTorres);
		
		JFreeChart chart = ChartFactory.createXYLineChart("Fitness Promedio por Generacion", 
				"Generacion", "Fitness Promedio", datase,
				PlotOrientation.VERTICAL, true, false, false);
		ChartFrame frame = new ChartFrame("Fitness por Generacion (Torretas)", chart);
		frame.pack();
		frame.setVisible(true);
	}
}
