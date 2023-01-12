import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Set<Student> student = new HashSet<>();

        Student student1 = new Student("1023213", "Yato", "Freshman");
        Student student2 = new Student("1023214", "Naruto", "Freshman");
        Student student3 = new Student("1023215", "Kakashi", "Junior");
        Student student4 = new Student("1023216", "Itachi", "Senior");
        // same duplicate with student 1
        Student student5 = new Student("1023213", "Yato", "Freshman");
        // Same id with different name
        Student student6 = new Student("1023215", "EavlongMusk", "Junior");
        // Same name with different id
        Student student7 = new Student("1023219", "EavlongMusk", "Junior");

        student.add(student1);
        student.add(student2);
        student.add(student3);
        student.add(student4);
        student.add(student5);
        student.add(student6);
        student.add(student7);

        System.out.println("Our students are " + student);
    }
}
