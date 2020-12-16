package gui;

import com.sun.javafx.geom.Rectangle;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Priority;
import javafx.scene.layout.RowConstraints;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Shape;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.animation.*;
import javafx.util.Duration;

import java.awt.*;

public class PuckerApp extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {

        primaryStage.setTitle("test");

        GameScene maze = new GameScene();

//
//        GridPane grid = new GridPane();
//        Text t4 = new Text("Scale Transition");
//        t4.setFont(Font.font("Tahoma", FontWeight.BOLD, 10));
//        grid.add(t4, 1, 2);
//
//        for(int i = 0 ;i < 25 ; i++) {
//            ColumnConstraints cc = new ColumnConstraints(40,40,40);
//            cc.setHgrow(Priority.NEVER);
//            grid.getColumnConstraints().add(cc);
//        }
//
//
//        for(int i = 0 ;i < 21 ; i++) {
//            RowConstraints rc = new RowConstraints(50,50,50);
//            rc.setVgrow(Priority.NEVER);
//            grid.getRowConstraints().add(rc);
//        }
//       // grid.add(startTranslateTransition(), 2, 3);
//
//        grid.setOnKeyTyped(e->{
//          //  grid.add()
//               grid.add(startTranslateTransition(), 2, 3);
//
//        });
//        Scene scene = new Scene(grid,1000,1100);
//        scene.getRoot().requestFocus();
//        primaryStage.setScene(scene);


        primaryStage.setScene(maze);


        primaryStage.setResizable(false);
        primaryStage.show();

    }

    @Override
    public void init() throws Exception {
        super.init();
    }

    @Override
    public void stop() throws Exception {
        super.stop();
    }

    public static void main(String[] args){launch(args);}
}
