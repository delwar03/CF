abstract class A {
    int i = 20;

    A(int i) {
        this.i = i;
    }

    int m(int j) {
        return i + j;
    }

    abstract int m2(int j, int k);

    int m4() {
        return i;
    }
}

class B extends A {
    B(int i) {
        super(i);
    }

    int m2(int x, int y) {
        return x + y;
    }
}

class C extends A {
    int j;

    C(int i, int j) {
        super(i);
        this.j = j;
    }

    // Remove @Override for m(), it's not overriding anything in class A
    int m() {  // Non-overriding method
        return i;
    }

    String m3(String s) {
        return "Hello " + s;
    }

    @Override
    int m2(int a, int b) {  // Overriding m2() method from A
        return a * b;
    }

    @Override
    int m4() {  // Overriding m4() method from A
        return this.j;
    }
}

public class TestA {
    static int testCounter = 1;

    static void tester(boolean b) {
        String status = "Failed";
        if (b)
            status = "Passed";
        System.out.printf("Test #%02d %s.%n", testCounter++, status);
    }

    public static void main(String[] args) {
        C c = new C(10, 20);
        B b = new B(5);
        tester(c.m3("java").equals("Hello java"));
        tester(c.m2(6, 6) == 36);
        tester(b.m2(6, 6) == 12);
        
        A a = b;
        tester(a.m(15) == 20);  // Test #04
        tester(a.i == 5);  // Test #05
        
        a = c;
        tester(a.m(15) == 25);  // Test #06
        tester(a.i == 10);  // Test #07
        tester(a.m4() == 20);  // Test #08
        
        c.i += 10;  // Modify i in C (a = c)
        tester(a.m4() == 30);  // Test #09 should now pass (a.m4() == 30)
        
        a.i += 10;  // Modify i again
        tester(a.m4() == 40);  // Test #10 should now pass (a.m4() == 40)
    }
}
