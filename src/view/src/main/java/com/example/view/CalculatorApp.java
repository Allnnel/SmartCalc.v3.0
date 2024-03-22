package com.example.view;

import com.example.presenter.Presenter;
import com.example.presenter.impl.PresenterImpl;
import com.example.util.DataManager;
import com.example.util.DataObject;
import com.sun.jna.Pointer;
import javafx.application.Application;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.VPos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class CalculatorApp extends Application {

  private GridPane gridPane;

  private final Presenter presenter = new PresenterImpl();
  private final TextArea inputTextArea = new TextArea();

  private final TextArea xValueTextArea = new TextArea();

  private DataObject object;

  @Override
  public void start(Stage primaryStage) {
    object = DataManager.deserializeData("data.ser");
    setupGridPane();
    createInputTextArea();
    createButtons();
    createXValueTextArea();

    gridPane.setAlignment(Pos.CENTER);
    gridPane.setPadding(new Insets(10));

    Scene scene = new Scene(gridPane, 500, 500);
    primaryStage.setScene(scene);
    primaryStage.setTitle("Calculator");
    primaryStage.setResizable(false);
    primaryStage.show();
  }

  private void setupGridPane() {
    gridPane = new GridPane();
    gridPane.setHgap(5);
    gridPane.setVgap(5);
  }

  private void createXValueTextArea() {
    xValueTextArea.setPrefSize(10, 10);
    gridPane.add(xValueTextArea, 6, 0);
    GridPane.setHalignment(xValueTextArea, HPos.CENTER);
    GridPane.setValignment(xValueTextArea, VPos.BOTTOM);
    xValueTextArea
        .textProperty()
        .addListener(
            (observable, oldValue, newValue) -> {
              if (!newValue.matches("[0-9.-]*")) {
                xValueTextArea.setText(oldValue);
              }
            });
  }

  private void createInputTextArea() {
    inputTextArea.setEditable(false);
    inputTextArea.setPrefSize(350, 80);
    inputTextArea.setStyle("-fx-font-size: 20pt;");
    gridPane.add(inputTextArea, 0, 0, 7, 1);
  }

  private void createButtons() {
    String[] buttonLabels = {
      "AC", "C", "⌘", "⌘", "GRAPH", "sin", "asin",
      "+", "1", "2", "3", "(", "cos", "acos",
      "-", "4", "5", "6", ")", "tan", "atan",
      "*", "7", "8", "9", "^", "sqrt", "mod",
      "/", "0", "=", ".", "log", "ln", "x"
    };
    int row = 1, col = 0, id = 0;
    for (String label : buttonLabels) {
      Button button = new Button(label);
      button.setPrefSize(80, 80);
      if (id > 4 && id != 30) {
        button.setOnAction(event -> handleOperatorButtonClick(button.getText()));
      } else if (id == 0) {
        button.setOnAction(event -> handleClearButtonClick());
      } else if (id == 1) {
        button.setOnAction(event -> handleBackspaceButtonClick());
      } else if (id == 2) {
        button.setOnAction(event -> handleHistoryButtonClick());
      } else if (id == 3) {
        button.setOnAction(event -> handleClearHistoryButtonClick());
      } else if (id == 4) {
        button.setOnAction(event -> handleGraphButtonClick());
      } else if (id == 30) {
        button.setOnAction(event -> handleSpecialButtonClick());
      }
      gridPane.add(button, col, row);
      col++;
      if (col > 6) {
        col = 0;
        row++;
      }
      id++;
    }
  }

  private void handleOperatorButtonClick(String operator) {
    inputTextArea.appendText(operator);
  }

  private void handleBackspaceButtonClick() {
    int length = inputTextArea.getText().length();
    if (length > 0) {
      inputTextArea.deleteText(length - 1, length);
    }
  }

  private void handleClearButtonClick() {
    inputTextArea.clear();
  }

  private void handleClearHistoryButtonClick() {
    object.clearList();
    DataManager.serializeData(object, "data.ser");
  }

  private void handleSpecialButtonClick() {
    String text = inputTextArea.getText();
    String textX = xValueTextArea.getText();
    double x = 0.0;
    try {
      x = textX.isEmpty() ? 0.0 : Double.parseDouble(textX);
      Pointer resultPointer = presenter.s21_Input(text, x);
      double[] resultArray = resultPointer.getDoubleArray(0, 2);
      if (resultArray[1] > 0.0) {
        inputTextArea.setText("ERROR (´｡• 0 •｡) ♡");
      } else {
        inputTextArea.setText(String.valueOf(resultArray[0]));
      }
      object.setText("expression(" + text + ") x(" + textX + ")");

      DataManager.serializeData(object, "data.ser");
    } catch (NumberFormatException e) {
      inputTextArea.setText("ERROR (´｡• 0 •｡) ♡");
    }
  }

  private void handleGraphButtonClick() {
    String equation = inputTextArea.getText();
    GraphApp graphView = new GraphApp();
    Stage graphStage = new Stage();
    graphView.setEquation(equation);
    graphView.start(graphStage);
  }

  private void handleHistoryButtonClick() {
    HistoryApp historyApp = new HistoryApp();
    Stage historyStage = new Stage();
    historyApp.start(historyStage);
  }

  public void setX(String x) {
    xValueTextArea.setText(x);
  }

  public void setExpression(String expression) {
    inputTextArea.setText(expression);
  }

  public static void main(String[] args) {
    launch(args);
  }
}
