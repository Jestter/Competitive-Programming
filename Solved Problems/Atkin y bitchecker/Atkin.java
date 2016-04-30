



/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jestter
 */
public class Atkin
{
    
    public class BitChecker //Deje esta clase anidada para poder usar un solo archivo.
    {
        int limit;  //numero maximo al que se quiere llegar a "chequear".
        int size;   //Tamaño del arreglo necesario.
        byte[] table;   //arreglo de bytes(8 bits) en el que se marcaran los numeros.
    
        public BitChecker(int limit)//recibe int correspondiente al limite numerico a marcar
        {
//            long aux = System.nanoTime();
            this.limit = limit;
            this.size = ((int)limit/8)+1;   //el tamaño de table corresponde al limite dividido por 8 (los bits que tiene un byte).
            this.table = new byte[size];
        
            for(int i=0;i<size;i++) //se llena la tabla con 0s (simbolizan falso o que no esta marcado).
            {
                this.table[i] = 0;
            }
//            System.out.println("cons: "+(System.nanoTime()-aux));
        }
    
       public void check(int n) //esta funcion deja un numero perteneciente a [0,limit] marcado en su bit correspondiente del arreglo con un 1 (verdadero)
       {
//           long aux = System.nanoTime();
            int a = (int)n/8; //con esto se sabe en que casilla del arreglo está el bit del numero
            int b = n%8;    // esto corresponde a la posicion del bit (b) en la casilla (a)
            //ejemplo: n= 64 -> a = 8 por lo tanto va en table[a] -> b = 0 por lo tanto le corresponde el primer bit de table[a].
            int tmp = table[a] & 0xFF;//los bytes de java son siempre signed por lo tanto para obtenerlos como entero unsigned se hace la operacion & 0xFF.
            int[] num = new int[8]; //este pequeño arreglo servira para guardar la descomposicion binaria de la casilla table[a].
        
            for(int i=7;i>=0;i--) //se hace la descomposicion binaria. esto es similar a cuando quieres descomponer un numero en
                //centena, decena, unidad , etc etc.
            {
                int exp = (int)Math.pow(2, i);
                num[i] = (int) (tmp/exp);
         
                tmp = (int) (tmp%exp);
            }
       
            num[b] = 1; //se marca el bit en el mini arreglo que guarda la descomposicion binaria.
            tmp = 0;
            for(int i=7;i>=0;i--) //se vuelve a componer el numero de la casilla table[a], esta vez con el nuevo bit marcado. 
                //es el proceso inverso al for anterior.
            {
                int exp = (int)Math.pow(2, i);
                tmp += num[i]* exp;
           
            }
            table[a] = (byte) tmp; //se guarda finalmente el numero correspondiente en la casilla.
//            System.out.println("ch: "+(System.nanoTime()-aux));
        }
    
        public void uncheck(int n) //esta funcion deja un numero perteneciente a [0,limit] desmarcado en su bit correspondiente del arreglo
                //es exactamente lo mismo que el metodo anterior, solo que esta en vez de marcar el bit con un 1 , lo hace con un 0 simbolizando el falso.
        {
            int a = (int)n/8;
            int b = n%8;
            int tmp = table[a] & 0xFF;
            int[] num = new int[8];
        
            for(int i=7;i>=0;i--)
            {
                int exp = (int)Math.pow(2, i);
                num[i] = (int) (tmp/exp);
           
                tmp = (int) (tmp%exp);
            }
            num[b] = 0;
            tmp = 0;
            for(int i=7;i>=0;i--)
            {
                int exp = (int)Math.pow(2, i);
                tmp += num[i]* exp;
           
            }
            table[a] = (byte) tmp;

        }
    
        public void flip(int n)//esta funcion usa el mismo algoritmo que las anteriores pero da vuelta el valor del bit
                //si es 1 lo hace 0 y si es 0 lo hace 1.
        {
//            long aux = System.nanoTime();
            int a = (int)n/8;
            int b = n%8;
            int tmp = table[a] & 0xFF;
            int[] num = new int[8];
        
            for(int i=7;i>=0;i--)
            {
                int exp = (int)Math.pow(2, i);
                num[i] = (int) (tmp/exp);
                tmp = (int) (tmp%exp);
            }
        
            if(num[b]==0)num[b] = 1;
            else if(num[b]==1)num[b]=0;
            tmp = 0;
            for(int i=0;i<8;i++)
            {
                int exp = (int)Math.pow(2, i);
                tmp += num[i]* exp;
            }
            table[a] = (byte) tmp;
//            System.out.println("flip: "+(System.nanoTime()-aux));
        }
    
        public boolean isChecked(int n)//este metodo retorna true si el bit correspondiente a un numero es 1 (esta marcado) o false (no esta marcado) si no lo es.
        {
//            long aux = System.nanoTime();
            int a = (int)n/8; //utiliza lo mismo que los metodos anteriores solo que no necesita componer el numero, solo revisar el bit.
            int b = n%8;
            int tmp = table[a] & 0xFF;
            int[] num = new int[8];
        
            for(int i=7;i>=0;i--)
            {
                int exp = (int)Math.pow(2, i);
                num[i] = (int) (tmp/exp);
                tmp = (int) (tmp%exp);
            }
//            System.out.println("isc: "+(System.nanoTime()-aux));
            if(num[b]==1)return true;
            else return false;
        }
        
    }

    
    public static void main(String[] args)
    {
        new Atkin().start();
    }
    
    public void start()
    {
        int limite = 100000000;
        int limitRoot = (int) Math.sqrt(limite)+1;
        BitChecker primos = new BitChecker(limite);

        primos.check(2);
        primos.check(3);
        int n;
        
        long aux = System.nanoTime();
        for(int x = 1 ; x < limitRoot ; x ++ )
        {
            int a = x*x;
            
            for(int y = 1 ; y < limitRoot ; y++)
            {
                int b = y*y;
                n = (4*a + b);
                
                if( n <= limite && (n%12 == 1 || n%12 ==5))
                {
                    primos.flip(n);
                    
                }
                
                n = (3*a + b);
                
               
                if(n <= limite && n%12 == 7)
                {
                    primos.flip(n);
                    
                }
                
                n = (3*a - b);
                
                if( x > y && n <= limite && n%12 == 11)
                {
                    primos.flip(n);
                    
                }
            }
        }
        System.out.println("1: "+(System.nanoTime()-aux));
        aux = System.nanoTime();
        
        for(int i = 5 ; i < limitRoot ; i++)
        {
            if(primos.isChecked(i))
            {
                int pow = i*i;
                for(int k = pow; k < limite ; k += pow)
                {
                    primos.uncheck(k);
                }
            }
        }
        System.out.println("2: "+(System.nanoTime()-aux));
        int cc=0;
        for (int i = 0; i < limite; i++)
        {
            if(primos.isChecked(i))
                cc++;
        }
        System.out.println("primos="+cc);
    }
}
    



