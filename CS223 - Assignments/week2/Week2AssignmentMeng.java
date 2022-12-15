import java.util.Scanner;

public class Week2AssignmentMeng {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Please input your first name: ");
        String first = scanner.nextLine();

        System.out.print("Please input your middle name: ");
        String middle = scanner.nextLine();

        System.out.print("Please input your last name: ");
        String last = scanner.nextLine();

        // String temp = "";
        // temp += Character.toUpperCase(first.charAt(0));
        // temp += first.substring(1, first.length());
        // System.out.println(temp);

        System.out.print(first.charAt(0) + " " + middle.charAt(0) + " " + last.charAt(0));

        scanner.close();

        // * Take input at once */
        // Scanner scanner = new Scanner(System.in);
        // String input = scanner.nextLine();

        // for (int i = 0; i < input.length(); i++) {
        //     if (i == 0) {
        //         System.out.print(input.charAt(i) + " ");
        //     } else {
        //         if (input.charAt(i) == ' ') {
        //             System.out.print(input.charAt(i + 1) + " ");
        //         }
        //     }
        // }

        // scanner.close();

    }
}