public class Main {
    public static void main(String[] args) {
        Person person = new Person("seakmeng", "address", 012235456, "loveyou3000@gmail.com");
        System.out.println(person);

        Student student = new Student("seakmeng", "address", 012235456, "loveyou3000@gmail.com", "1865", "18/3/2001");
        System.out.println(student);

        Employee employee = new Employee("seakmeng", "address", 012235456, "loveyou3000@gmail.com", 850, 1800);
        System.out.println(employee);
        
        Faculty faculty = new Faculty("seakmeng", "address", 012235456, "loveyou3000@gmail.com", 850, 1800, 903, "Supervisor");
        System.out.println(faculty);

        Staff staff = new Staff("seakmeng", "address", 012235456, "loveyou3000@gmail.com", 850, 1800, "teacher");
        System.out.println(staff);
        

    }
}
