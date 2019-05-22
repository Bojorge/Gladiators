package server;

import java.io.InputStream;
//Clase que maneja un archivo de tipo sting para Formar JSON Objects

public class FileHandle {
	
	public static InputStream inputStreamFromFile(String path) {
		try {
			InputStream inputStream = FileHandle.class.getResourceAsStream(path);
			return inputStream;
		} catch(Exception e) {
			e.printStackTrace();
		}
		return null;
	}
}
