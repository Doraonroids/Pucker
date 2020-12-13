package resources;

public class Man extends Entity {
    private short points;
    private short dotsAte;

    public Man(){
        setX((short) 12);
        setY((short) 15);
        setLives((short) 3);
        setSymbol('@');
        points = 0;
        dotsAte = 0;
    }

    public void setDotsAte(short dotsAte) {
        this.dotsAte = dotsAte;
    }

    public short getDotsAte(){return dotsAte;}

    public short getPoints(){return points;}

    public void displayPoints(){}
    public void displayLives(){}
    public void reset(){}

}
