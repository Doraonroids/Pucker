package gui;




import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.scene.control.*;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

import java.awt.*;


public class GameScene extends Scene {
    private static GridPane root = new GridPane();


    public GameScene() {
        super(root,600,800);
    }

   public void addStuff(){
       root.add(new Line(0,0,2,2),0,0);

   }
}
