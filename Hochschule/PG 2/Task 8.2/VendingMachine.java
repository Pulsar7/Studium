

public class VendingMachine {
    public static enum BeverageType {
        COLA("Cola",0.80),
        WATER("Water",0.60),
        LEMONADE("Lemonade",0.70);

        private String label;
        private double costs;

        private BeverageType(String label, double costs) {
            this.lable = label;
            this.costs = costs;
        }
    };
    private Scanner scanner;

    public VendingMachine() {
        this.scanner = new Scanner();
    }

}
