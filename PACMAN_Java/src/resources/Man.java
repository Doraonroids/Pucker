package resources;



import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;


public class Man extends Entity {

    private short points;
    private short dotsAte;
    private short lives;
    private String color;
    private String shape;
    private short originX =300;
    private short originY =300;
    public Man(){

        this.setX((short) 300);
        this.setY((short) 300);
        this.lives = 3;
        this.points = 0;
        this.dotsAte = 0;

    }

    public void setDotsAte(short dotsAte) {
        this.dotsAte = dotsAte;
    }


    public short getDotsAte(){return dotsAte;}

    public short getPoints(){return points;}

    public void displayPoints(){}
    public void displayLives(){}
    public void resetPosition(){this.setX(originX);
        this.setY(originY);}

    public void ateDot(){
        dotsAte++;
    }



}
