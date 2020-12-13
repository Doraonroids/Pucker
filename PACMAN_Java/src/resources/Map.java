package resources;

import java.util.Vector;

public class Map {
    private int width;
    private int height;
    private int length;
    private String fileName;
    private Vector<Character> map_vec;

    public Map(){}

    public void goToXY(int x, int y){}

    public int getHeight() {
        return height;
    }

    public int getLength() {
        return length;
    }

    public int getWidth() {
        return width;
    }

    public String getFileName() {
        return fileName;
    }

    public Character getMapAt(int x, int y){
        Character c = 0;
        return c;
    }

    public void setWidth(int w){
        this.width = w;
    }

    public void setHeight(int h){
        this.height = h;
    }

    public void setLength(int length) {
        this.length = length;
    }

    public void setFileName(String fileName) {
        this.fileName = fileName;
    }

    public void setMap_vec(Vector<Character> map_vec) {
        this.map_vec = map_vec;
    }
    
}
