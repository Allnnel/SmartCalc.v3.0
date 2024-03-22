package com.example.view;

import com.example.util.DataManager;
import com.example.util.DataObject;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class HistoryApp extends Application {

  @Override
  public void start(Stage primaryStage) {
    DataObject dataObject = DataManager.deserializeData("data.ser");
    VBox vBox = new VBox();
    vBox.setAlignment(Pos.CENTER);
    vBox.setSpacing(10);

    List<String> strings = dataObject.getList();

    for (String s : strings) {
      Button button = new Button("⌘");
      Label label = new Label(s);

      HBox hBox = new HBox(button, label);
      hBox.setAlignment(Pos.CENTER_LEFT);

      button.setOnAction(event -> handleHistoryButtonClick(s));

      vBox.getChildren().add(hBox);
    }

    ScrollPane scrollPane = new ScrollPane(vBox);
    scrollPane.setFitToWidth(true);

    Scene scene = new Scene(scrollPane, 400, 300);
    primaryStage.setResizable(false);
    primaryStage.setTitle("History");
    primaryStage.setScene(scene);
    primaryStage.centerOnScreen();
    primaryStage.show();
  }

  private void handleHistoryButtonClick(String text) {
    CalculatorApp calculatorApp = new CalculatorApp();
    Pattern pattern = Pattern.compile("expression\\(([^|]*)\\)\\s+x\\(([^|]*)\\)");
    Matcher matcher = pattern.matcher(text);

    if (matcher.find()) {
      String expression = matcher.group(1);
      expression = (expression != null && !expression.isEmpty()) ? expression : "0";
      String x = matcher.group(2);
      x = (x != null && !x.isEmpty()) ? x : "0";
      calculatorApp.setExpression(expression);
      calculatorApp.setX(x);
      Stage calculatorStage = new Stage();
      calculatorApp.start(calculatorStage);
    } else {
      System.out.println("Совпадения не найдены.");
    }
  }

  public static void main(String[] args) {
    launch(args);
  }
}
