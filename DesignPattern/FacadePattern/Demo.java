package FacadePattern;

public class Demo {
    public static void main(String[] args) {
        FacadeMaker ob = new FacadeMaker();

        ob.drawCircle();
        ob.drawRectangle();
        ob.drawTriangle();
    }
}
