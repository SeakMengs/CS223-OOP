public class Student {
    private String studentId;
    private String studentName;
    private String studentGradeLevel;

    public Student() {
        this.studentId = "Unassigned";
        this.studentName = "Unassigned";
        this.studentGradeLevel = "Unassigned";
    }

    public Student(String studentId, String studentName, String studentGradeLevel) {
        this.studentId = studentId;
        this.studentName = studentName;
        this.studentGradeLevel = studentGradeLevel;
    }

    public String getStudentId() {
        return this.studentId;
    }

    public void setStudentId(String studentId) {
        this.studentId = studentId;
    }

    public String getStudentName() {
        return this.studentName;
    }

    public void setStudentName(String studentName) {
        this.studentName = studentName;
    }

    public String getStudentGradeLevel() {
        return this.studentGradeLevel;
    }

    public void setStudentGradeLevel(String studentGradeLevel) {
        this.studentGradeLevel = studentGradeLevel;
    }

    @Override
    public boolean equals(Object o) {
        Student student = (Student) o;
        return studentId.equals(student.studentId);
    }

    @Override
    public int hashCode() {
        return studentId.hashCode();
    }

    @Override
    public String toString() {
        return "\n{" +
                " studentId='" + getStudentId() + "'" +
                ", studentName='" + getStudentName() + "'" +
                ", studentGradeLevel='" + getStudentGradeLevel() + "'" +
                "}";
    }

}