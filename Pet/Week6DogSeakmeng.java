public class Week6DogSeakmeng extends Week6PetSeakmeng {
    
    private Double weight;

    public Week6DogSeakmeng(String name, String type, Double weight) {
        super(name, type);
        this.weight = weight;
    }

    public Double getWeight() {
        return this.weight;
    }

    public void setWeight(Double weight) {
        this.weight = weight;
    }

    @Override
    public String toString() {
        return " name= '" + getName() + "' type= 'dog' weight= '" + getWeight() + "' from Week6DogSeakmeng toString() function";
    }
}
