import java.util.ArrayList;
import java.util.Scanner;

public class Week6AssignmentSeakmeng {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Week6PetSeakmeng> getList = new ArrayList<>();

        while (true) {
            System.out.print("\nEnter your pet name: ");
            String petName = scanner.next();

            // convert name to lowercase so that the condition will work with both uppercase and lowercase
            if (petName.toLowerCase().equals("stop")) break;

            System.out.print("Enter your pet type: ");
            String petType = scanner.next();
            
            if (petType.toLowerCase().equals("cat")) {
                Week6PetSeakmeng cat = new Week6CatSeakmeng(petName, petType);
                getList.add(cat);
            } else if (petType.toLowerCase().equals("dog")) {
                Week6PetSeakmeng dog = new Week6DogSeakmeng(petName, petType);
                getList.add(dog);
            }
        }

        System.out.println("\nAll pet types and name");

        for (Week6PetSeakmeng object : getList) {
            System.out.println(object.toString());
        }
        
        scanner.close();
    }
}
