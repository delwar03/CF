import java.util.Scanner;

public class E_Cardboard_for_Pictures {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {

            long n = sc.nextLong();
            long k = sc.nextLong();
            double sum = 0.0, sq_sum = 0.0;

            for(int i = 0; i < n; i++) {
                long x = sc.nextLong();
                sum += x;
                sq_sum += x * x;
            }

            double a = 4 * n;
            double b = 4 * sum;
            double c = sq_sum - k;

            double ans = (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a);

            System.out.println(Math.round(ans));
        }
    }
}