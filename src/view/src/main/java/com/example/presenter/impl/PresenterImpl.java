package com.example.presenter.impl;

import com.example.presenter.Presenter;
import com.sun.jna.Pointer;

public class PresenterImpl implements Presenter {
  @Override
  public Pointer s21_Input(String str, double x) {
    return INSTANCE.s21_Input(str, x);
  }
}
