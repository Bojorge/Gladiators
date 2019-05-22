package server;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
//Servlet encargado de retornar una poblacion de torretas y de Gladiadores
//unidos por un "-"y en formato JSON


@WebServlet("/population")
public class GladiatorServer extends HttpServlet {
	private static final long serialVersionUID = 1L;
	public final ServerDirector serverDirector = new ServerDirector();
	public DataBase DB = DataBase.getInstance(); 
    public GladiatorServer() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String respuesta = serverDirector.getGeneracionCero();
		
		String p = respuesta;
		String[] gt = p.split("-");
		String G = gt[0];String T = gt[1];
		List<Gladiador> LAG = serverDirector.deserializarG(G);
		DataBase.changeLAG(LAG);
		List<Torreta> LAT = serverDirector.deserializarT(T);
		DataBase.changeLAT(LAT);
		
		response.getWriter().println(respuesta);
	}
}
