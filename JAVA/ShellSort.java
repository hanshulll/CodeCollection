public static void shell(int A[]) {

        int salto, aux, i;
        boolean cambios;
  
        for (salto = A.length / 2; salto != 0; salto /= 2) {
            cambios = true;
            while (cambios) {                                            
                cambios = false;
                for (i = salto; i < A.length; i++)  
                {
                    if (A[i - salto] > A[i]) {      
                        aux = A[i];                
                        A[i] = A[i - salto];
                        A[i - salto] = aux;
                        cambios = true;                                              
                    }
                }
            }
        }
}