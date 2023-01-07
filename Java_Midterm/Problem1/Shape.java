public class Shape {
    private double height;
    private double weight;

    public Shape() {
        this.height = 1.0;
        this.weight = 1.0;
    }

    public Shape(double height, double weight) {
        this.height = height;
        this.weight = weight;
    }

    public double getHeight() {
        return this.height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getWeight() {
        return this.weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public double getArea() {
        return this.height * this.weight;
    }

    public double getPerimeter() {
        return 2 * (this.height + this.weight);
    }

    @Override
    public String toString() {
        return "{" +
            " height='" + getHeight() + "'" +
            ", weight='" + getWeight() + "'" +
            "}";
    }


}
