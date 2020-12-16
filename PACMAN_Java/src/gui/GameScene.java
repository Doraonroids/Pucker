package gui;


import javafx.geometry.HPos;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;
import javafx.animation.*;
import javafx.util.Duration;
import java.math.BigDecimal;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class GameScene extends Scene {
    private static Group group = new Group();
    private static GridPane root = new GridPane();
    private static Circle man = new Circle(500,775,19,Color.YELLOW);
    private BigDecimal manX = BigDecimal.valueOf(12.000);
    private BigDecimal manY = BigDecimal.valueOf(15.000);

    private static String mapPath = "C:\\Users\\Zachary\\Documents\\GitHub\\Pucker\\PACMAN_Java\\src\\settings\\map.txt";
    private static File mapFile;
    private static final int WIDTH = 40;
    private static final int HEIGHT= 50;
    private static final Paint borderColor = Color.PINK;
    private static final Paint blankColor = Color.WHITE;
    private static final Paint dotColor = Color.BLACK;


    public void moveLeft() {
        manX = manX.subtract(BigDecimal.valueOf(.125));
         TranslateTransition translateMan = new TranslateTransition(Duration.millis(2), man);;
        translateMan.setByX(-5);
        translateMan.play();
    }
    public void moveRight() {
        TranslateTransition translateMan = new TranslateTransition(Duration.millis(2), man);;
        manX = manX.add(BigDecimal.valueOf(.125));
        translateMan.setByX(5);
        translateMan.play();
    }

    public void moveUp() {
         TranslateTransition translateMan = new TranslateTransition(Duration.millis(2), man);;
        manY = manY.subtract(BigDecimal.valueOf(0.1));
        translateMan.setByY(-5);
        translateMan.play();
    }
    public void moveDown() {
         TranslateTransition translateMan = new TranslateTransition(Duration.millis(2), man);;
        manY = manY.add(BigDecimal.valueOf(0.1));
        translateMan.setByY(5);
        translateMan.play();
    }

    public GameScene() throws FileNotFoundException {
        super(group,1000,1100);

        group.getChildren().addAll(root,man);

        group.setOnKeyPressed(e->{
            switch (e.getCode()){
                case D:
                    moveRight();
                    break;
                case A:
                    moveLeft();
                    break;
                case W:
                    moveUp();
                    break;
                case S:
                    moveDown();
                    break;
            }

            System.out.println(manX + ", " + manY);
        });


        group.requestFocus();
        this.setColumnConstraints();
        this.setRowConstraints();
        this.fill();

    }

    private void fill() throws FileNotFoundException {
        //sets file to file path
        mapFile = new File(mapPath);
        Scanner sc = new Scanner(mapFile);
        List<String> linesList = new ArrayList<>();
        sc.useDelimiter("\\r\\n");
        do {
            linesList.add(sc.next());
        }while(sc.hasNext());

        String line;
        for(int y = 0; y < linesList.size(); y++){
            line = linesList.get(y);
            for(int x = 0; x < line.length(); x++){
                String current = line.substring(x,x+1);
                switch(current) {
                    case "#":
                        addBorder(x,y);
                        break;
//                    case ".":
//                        addDot(x,y);
//                        break;
                    case " ":
                        addBlank(x,y);
                        break;
                }
            }
        }
    }

    //25 rows to start with
    private void setColumnConstraints(){

        for(int i = 0 ;i < 25 ; i++) {
            ColumnConstraints cc = new ColumnConstraints(WIDTH,WIDTH,WIDTH);
            cc.setHgrow(Priority.NEVER);
            root.getColumnConstraints().add(cc);
        }
    }

    private void setRowConstraints(){
        for(int i = 0 ;i < 21 ; i++) {
            RowConstraints rc = new RowConstraints(HEIGHT,HEIGHT,HEIGHT);
            rc.setVgrow(Priority.NEVER);
            root.getRowConstraints().add(rc);
        }
    }

    /*
     * addBorder(int column,int row)
     * addBorder inserts a rectangle into the gridpane root
     * the rectangle is colored as the borderColor variable
     * column and row decides where the rectangle goes on the gridpane
     *
     */
    private void addBorder(int column, int row){
        root.add(new Rectangle(WIDTH,HEIGHT,borderColor),column,row);
    }

    /*
    * addBlank(int column,int row)
    * addBlank inserts a rectangle into the gridpane root
    * the rectangle is colored as the blankColor variable
    * column and row decides where the rectangle goes on the gridpane
    *
    */
    private void addBlank(int column,int row){
        root.add(new Rectangle(WIDTH,HEIGHT,blankColor),column,row);
    }

    /*
     * addDot(int column,int row)
     * addDot inserts a circle into the gridpane root
     * the circle is colored as the dotColor variable
     * column and row decides where the circle goes on the gridpane
     */
    private void addDot(int column,int row){
        Circle c = new Circle(WIDTH/3,dotColor);
        GridPane.setHalignment(c,HPos.CENTER);
        root.add(c,column,row);
    }

    private void removeDot(int column, int row){
        addBlank(column,row);
    }

    /*
    * this should read the settings file set the editable variables
    *
    *
    */
    private void setVariables() throws FileNotFoundException{
        mapPath = "C:\\Users\\Zachary\\Documents\\GitHub\\Pucker\\PACMAN_Java\\src\\settings\\map.txt";
    }

}
