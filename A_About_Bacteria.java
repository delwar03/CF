import java.util.*;

public class A_About_Bacteria {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long k = sc.nextLong();
        long b = sc.nextLong();
        long n = sc.nextLong();
        long t = sc.nextLong();

        if(k == 1) {
            long m = 0;
            long z = n * b;
            while(z >= t + m * b) {
                m++;
            }
            System.out.println(m);
        } else {
            int m = 0;
            double val = 1.0 * ((k - 1) * t + b) / (k - 1 + b);
            double cur = Math.pow(k, n - m);
            while(cur > val) {
                m++;
                cur = Math.pow(k, n - m);
            }
            System.out.println(m);
        }
    }
}