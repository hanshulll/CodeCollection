package com;

import java.io.*;
import java.net.*;

class Cliente {
    static final String HOST = "localhost";
    static final int PUERTO = 2000;
    public Cliente( ) {
        try{
            // Me conecto al servidor en un determinado puerto
            Socket sCliente = new Socket( HOST, PUERTO );
            InputStream aux = sCliente.getInputStream();
            DataInputStream flujo_entrada = new DataInputStream( aux );
            System.out.println( flujo_entrada.readUTF() ); 
           
            // Cierro el socket
            sCliente.close();
        } catch( Exception e ) {
            System.out.println( e.getMessage() );
        }
    }
    public static void main( String[] arg ) {
        new Cliente();
    }
}
