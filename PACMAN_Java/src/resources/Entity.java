package resources;

public class Entity {
    private short x,y,lives;//short limits from -32768 to 32767
    private char symbol;// char limits from 0 to 65535


    //constructors
    public Entity(){
        this.x = 0;
        this.y = 0;
        this.lives = 1;
        this.symbol = '%';
    }

    public Entity(short x, short y, short lives, char symbol){
        this.x = x;
        this.y = y;
        this.lives = lives;
        this.symbol = symbol;
    }


    //setters
    public void setX(short x) {
        this.x = x;
    }

    public void setY(short y) {
        this.y = y;
    }

    public void setLives(short lives) {
        this.lives = lives;
    }

    public void setSymbol(char symbol) {
        this.symbol = symbol;
    }


    //Getters
    public short getX() {
        return x;
    }

    public short getY() {
        return y;
    }

    public short getLives() {
        return lives;
    }

    public char getSymbol() {
        return symbol;
    }

    public void setXY(short x, short y){

    }

    public void display(){

    }

    public void display(char symbol){

    }

    public void replace(){

    }

    public void move_up(){}
    public void move_down(){}
    public void move_left(){}
    public void move_right(){}
}
