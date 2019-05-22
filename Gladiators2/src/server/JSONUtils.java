package server;

import java.io.InputStream;
import java.util.Scanner;

import org.json.JSONObject;
//Clase necesaria para poder serializar y deserializar objetios de tipo JSon
//a objetos utilies para el programa
public class JSONUtils {
	//Funcion que obtiene los atributos necesarios de un objeto.
	public static String getJSONStringFromFile(String path) {
		Scanner scanner;
		InputStream in = FileHandle.inputStreamFromFile(path);
		scanner = new Scanner(in);
		String json = scanner.useDelimiter("\\Z").next();
		scanner.close();
		return json;
	}
	//Funcion que retorna un objeto JSON con atributos dados en un archivo de
	//texto
	public static JSONObject getJSONObjectFromFile(String path) {
		return new JSONObject(getJSONStringFromFile(path));
	}
	//Funcion que convierte de un String en formato JSON a un objeto JSON
	public static JSONObject getJSONObjectFromJSON(String json) {
		return new JSONObject(json);
	}
	//Funcion que retorna un booleano de si un objeto JSON esta creado o no.
	public static boolean objectExist(JSONObject jsonObject, String key) {
		Object o;
		try {
			o = jsonObject.get(key);
		} catch(Exception e) {
			return false;
		}
		return o != null;
	}

}
