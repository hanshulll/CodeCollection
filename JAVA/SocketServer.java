package com;

import java.io.* ;
import java.net.* ;

class Servidor {
    static final int PUERTO = 2000;
    public Servidor( ) {
    try {
        // Inicio la escucha del servidor en un determinado puerto
        ServerSocket skServidor = new ServerSocket(PUERTO);
        System.out.println("Escucho el puerto " + PUERTO );
       
        for ( int nCli = 0; nCli < 3; nCli++) {
           // Espero a que se conecte un cliente y creo un nuevo socket para el cliente
           Socket sCliente = skServidor.accept(); 
           System.out.println("Sirvo al cliente " + nCli);
           OutputStream aux = sCliente.getOutputStream();
           DataOutputStream flujo_salida= new DataOutputStream( aux );
           flujo_salida.writeUTF( "Hola cliente " + nCli );
        	
           
           // Cierro el socket
        	sCliente.close();
        }
    } catch( Exception e ) {
        System.out.println( e.getMessage() );
    }
}
public static void main( String[] arg ) {
     new Servidor();
 }
}
