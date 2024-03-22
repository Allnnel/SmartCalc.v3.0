package com.example.view;

import com.example.presenter.Presenter;
import com.example.presenter.impl.PresenterImpl;
import com.sun.jna.Pointer;
import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class GraphApp extends Application {
  private final Presenter presenter = new PresenterImpl();
  private String equation;
  private double minX = -20, maxX = 20;
  private double minY = -20, maxY = 20;

  @Override
  public void start(Stage primaryStage) {
    primaryStage.setResizable(false);
    primaryStage.setTitle("Graph");

    LineChart<Number, Number> lineChart = createLineChart();
    Slider xSlider = createSlider(-20, 20, minX);
    Slider ySlider = createSlider(-20, 20, minY);

    configureSliders(xSlider, ySlider, lineChart);

    VBox vbox = new VBox();
    vbox.getChildren()
        .addAll(lineChart, new Label("X Range"), xSlider, new Label("Y Range"), ySlider);
    vbox.setPadding(new Insets(10));
    Scene scene = new Scene(vbox, 400, 400);
    primaryStage.setScene(scene);
    primaryStage.centerOnScreen();
    primaryStage.show();
  }

  private LineChart<Number, Number> createLineChart() {
    NumberAxis xAxis = new NumberAxis(minX, maxX, 1);
    NumberAxis yAxis = new NumberAxis(minY, maxY, 1);
    LineChart<Number, Number> lineChart = new LineChart<>(xAxis, yAxis);
    XYChart.Series<Number, Number> series = new XYChart.Series<>();
    series.setName(equation);
    populateSeries(series);
    lineChart.getData().add(series);
    return lineChart;
  }

  private void populateSeries(XYChart.Series<Number, Number> series) {
    for (double x = minX; x <= maxX; x += 0.1) {
      double y = calculateResult(x);
      series.getData().add(new XYChart.Data<>(x, y));
    }
  }

  private Slider createSlider(double min, double max, double initialValue) {
    Slider slider = new Slider(min, max, initialValue);
    slider.setShowTickLabels(true);
    slider.setShowTickMarks(true);
    slider.setMajorTickUnit(10);
    slider.setMinorTickCount(5);
    slider.setBlockIncrement(1);
    return slider;
  }

  private void configureSliders(
      Slider xSlider, Slider ySlider, LineChart<Number, Number> lineChart) {
    xSlider
        .valueProperty()
        .addListener(
            new ChangeListener<Number>() {
              public void changed(
                  ObservableValue<? extends Number> ov, Number old_val, Number new_val) {
                minX = new_val.doubleValue();
                maxX = ((NumberAxis) lineChart.getXAxis()).getUpperBound();
                refreshChart(lineChart);
              }
            });

    ySlider
        .valueProperty()
        .addListener(
            new ChangeListener<Number>() {
              public void changed(
                  ObservableValue<? extends Number> ov, Number old_val, Number new_val) {
                minY = new_val.doubleValue();
                maxY = ((NumberAxis) lineChart.getYAxis()).getUpperBound();
                refreshChart(lineChart);
              }
            });
  }

  private void refreshChart(LineChart<Number, Number> chart) {
    chart.getData().clear();
    XYChart.Series<Number, Number> series = new XYChart.Series<>();
    series.setName(equation);
    populateSeries(series);
    chart.getData().add(series);
  }

  private double calculateResult(double x) {
    Pointer resultPointer = presenter.s21_Input(equation, x);
    double[] resultArray = resultPointer.getDoubleArray(0, 2);
    return (resultArray[1] > 0.0) ? 0.0 : resultArray[0];
  }

  public void setEquation(String equation) {
    this.equation = equation;
  }

  public static void main(String[] args) {
    launch(args);
  }
}
