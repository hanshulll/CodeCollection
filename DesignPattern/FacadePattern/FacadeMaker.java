package FacadePattern;

public class FacadeMaker {
    private Shape circle;
    private Shape rectangle;
    private Shape triangle;

    public FacadeMaker() {
        circle=new Circle();
        rectangle=new Rectangle();
        triangle=new Triangle();
    }

    public void drawCircle(){
        circle.draw();
    }

    public void drawRectangle(){
        rectangle.draw();
    }

    public void drawTriangle(){
        triangle.draw();
    }
}
