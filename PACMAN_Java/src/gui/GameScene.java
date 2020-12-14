package gui;


import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Priority;
import javafx.scene.layout.RowConstraints;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Arc;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;
import org.junit.jupiter.params.shadow.com.univocity.parsers.common.processor.core.ColumnOrderDependent;

import java.io.File;
import java.net.MalformedURLException;


public class GameScene extends Scene {
    private static GridPane root = new GridPane();

    private static final int WIDTH = 50;
    private static final int HEIGHT= 50;
    private static final Paint borderColor = Color.DARKBLUE;
    private static final Paint blankColor = Color.WHITE;
    private static final Paint dotColor = Color.BLACK;


    public GameScene() {
        super(root,1250,1250);
        this.setColumnConstraints();
        this.setRowConstraints();
    }

    public void fill()  {
        
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

    private void addBorder(int column, int row){
        root.add(new Rectangle(WIDTH,HEIGHT,borderColor),column,row);
    }

    private void addBlank(int column,int row){
        root.add(new Rectangle(WIDTH,HEIGHT,blankColor),column,row);
    }
    private void addDot(int column,int row){
        root.add(new Circle(WIDTH/3,dotColor),column,row);
    }

}
