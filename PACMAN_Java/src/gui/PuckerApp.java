package gui;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class PuckerApp extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {

        primaryStage.setTitle("test");

        GameScene maze = new GameScene();


        primaryStage.setScene(maze);



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
