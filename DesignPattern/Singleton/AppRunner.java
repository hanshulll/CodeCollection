package DesignPattern.Singleton;

public class AppRunner {

    public static void main(String[] args) throws InterruptedException {
        singleThreaded();
        multipleThreaded();
    }

    private static void multipleThreaded() throws InterruptedException {
        // As you can see t1 thread changes the employee name and t2 also access the same due to singleton object.
        Thread t1 = new Thread(()-> {
            try {
                Thread.sleep(3000);
                System.out.println(Thread.currentThread().getName());
                Employee.GETINSTANCE.setEmployeeName("Hanshul Chandel - HacktoberFest");
                System.out.println(Employee.GETINSTANCE.getEmployeeName());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        Thread t2 = new Thread(()-> {
            try {
                Thread.sleep(4000);
                System.out.println(Thread.currentThread().getName());
                System.out.println(Employee.GETINSTANCE.getEmployeeName());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        t1.start();
        t2.start();

        t1.join();
        t2.join();
    }

    private static void singleThreaded() {
        Employee employee = Employee.GETINSTANCE;
        employee.setEmployeeName("Gaurav Gupta- HacktoberFest 2021");

        System.out.println(Thread.currentThread().getName());
        System.out.println(employee.getEmployeeName());
    }
}
