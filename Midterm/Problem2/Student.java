public class Student extends Person {
    private String id;
    private String enrollmentDate;


    public Student(String name, String address, int phoneNumber, String email, String id, String enrollmentDate) {
        super(name, address, phoneNumber, email);
        this.id = id;
        this.enrollmentDate = enrollmentDate;
    }


    public String getId() {
        return this.id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getEnrollmentDate() {
        return this.enrollmentDate;
    }

    public void setEnrollmentDate(String enrollmentDate) {
        this.enrollmentDate = enrollmentDate;
    }

    @Override
    public String toString() {
        return "{" +
            " id='" + getId() + "'" +
            ", enrollmentDate='" + getEnrollmentDate() + "'" +
            "}";
    }

}
