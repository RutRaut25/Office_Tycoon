// 3)	Write a Java program to create two threads using the Runnable interface & Thread class. One thread should display even numbers from 1 to 20, and the other should display odd numbers from 1 to 20.

class EvenThread extends Thread {

    public void run() {

        System.out.println("Even Numbers:");

        for (int i = 1; i <= 20; i++) {

            if (i % 2 == 0) {
                System.out.println(i);
            }
        }
    }
}

class OddThread implements Runnable {

    public void run() {

        System.out.println("Odd Numbers:");

        for (int i = 1; i <= 20; i++) {

            if (i % 2 != 0) {
                System.out.println(i);
            }
        }
    }
}

public class Ass_3 {

    public static void main(String[] args) {

        // Thread using Thread class
        EvenThread t1 = new EvenThread();

        // Thread using Runnable interface
        OddThread obj = new OddThread();
        Thread t2 = new Thread(obj);

        // Start threads
        t1.start();
        t2.start();
    }
}
