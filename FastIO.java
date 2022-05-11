import java.io.*;
import java.util.*;

/**
 * Fast I/O combines the API of java.util.Scanner with System.out.println
 * to read and write input and output in a more performant manner 
 * using BufferedReader and PrintWriter. It is used to read user 
 * input or to print very long strings to the shell when optimisation is key.
 *
 * PrintWriter API:
 * fio.println("hello"); // stores "hello" string to the buffer
 * fio.flush();          // prints everything in the buffer. in this case, "hello"
 * fio.close();          // close after finishing fio for the whole program
 *
 * @source https://www.geeksforgeeks.org/fast-io-in-java-in-competitive-programming/
 */
class FastIO extends PrintWriter { 
    BufferedReader br; 
    StringTokenizer st;

    /**
     * Creates a FastIO object. Instantiate in main()
     *
     * Eg:
     * FastIO fio = new FastIO();
     */
    public FastIO() { 
        super(new BufferedOutputStream(System.out)); 
        br = new BufferedReader(new InputStreamReader(System.in));
    } 

    /**
     * Reads and returns the next token as a string.
     *
     * Eg:
     * String word = fio.next();
     */
    String next() { 
        while (st == null || !st.hasMoreElements()) { 
            try { 
                st = new StringTokenizer(br.readLine()); 
            } catch (IOException  e) { 
                e.printStackTrace(); 
            } 
        } 
        return st.nextToken(); 
    } 

    /**
     * Reads and returns the next line of user input as a string.
     *
     * Eg:
     * String sentence = fio.nextLine();
     */
    String nextLine() { 
        String str = ""; 
        try { 
            str = br.readLine(); 
        } catch (IOException e) { 
            e.printStackTrace(); 
        } 
        return str; 
    } 

    /**
     * Reads and returns the next number as an integer.
     *
     * Eg:
     * int n = fio.nextInt();
     */
    int nextInt() { 
        return Integer.parseInt(next()); 
    } 

    /**
     * Reads and returns the next number as a double.
     *
     * Eg:
     * double n = fio.nextDouble();
     */
    double nextDouble() { 
        return Double.parseDouble(next()); 
    } 

    /**
     * Reads and returns the next number as a long.
     *
     * Eg:
     * long n = fio.nextLong();
     */
    long nextLong() { 
        return Long.parseLong(next()); 
    } 
}

