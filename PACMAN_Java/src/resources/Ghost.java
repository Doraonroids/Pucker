package resources;

public class Ghost extends Entity {
    private boolean edible;
    private short lastMove;

    public Ghost(){
        this.lastMove = 0;
        this.edible = false;
        setX((short) 12);
        setY((short) 7);
        setLives((short) 1);
        setSymbol('?');
    }

    public void moveRand(){
//        short nextX = 0, nextY = 0;
//        short direction = this.lastMove;
//        while (true) {
//            switch (direction) {
//                case 0: nextY = getY() - 1; nextX = getX();     break;
//                case 1: nextY = getY() + 1; nextX = getX();     break;
//                case 2: nextY = getY();     nextX = getX() - 1; break;
//                case 3: nextY = getY();     nextX = getX() + 1; break;
//            }
//            if (m.getmapat(nextY, nextX) != '#') {
//                setY(nextY);
//                setX(nextX);
//                lastMove = direction;
//                break;
//            }
//            else {
//                direction = rand() % 4;
//            }
//        }
    }

    public void reset(){
        setX((short) 12);
        setY((short) 7);

    }



}
