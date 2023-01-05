public class Employee extends Person {
    private int officeNumber;
    private int salary;
    

    public Employee(String name, String address, int phoneNumber, String email, int officeNumber, int salary) {
        super(name, address, phoneNumber, email);
        this.officeNumber = officeNumber;
        this.salary = salary;
    }


    public int getOfficeNumber() {
        return this.officeNumber;
    }
    
    public void setOfficeNumber(int officeNumber) {
        this.officeNumber = officeNumber;
    }
    
    public int getSalary() {
        return this.salary;
    }
    
    public void setSalary(int salary) {
        this.salary = salary;
    }
    

    @Override
    public String toString() {
        return "{" +
            " officeNumber='" + getOfficeNumber() + "'" +
            ", salary='" + getSalary() + "$'" +
            "}";
    }

}

