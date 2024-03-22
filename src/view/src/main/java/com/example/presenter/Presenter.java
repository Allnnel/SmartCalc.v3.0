package com.example.presenter;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Platform;
import com.sun.jna.Pointer;

public interface Presenter extends Library {
  String LIBRARY_NAME =
      Platform.isMac()
          ? "/libs/libfunctions.dylib"
          : Platform.isWindows() ? "/libs/functions.dll" : "/libs/libfunctions.so";
  Presenter INSTANCE = Native.load(LIBRARY_NAME, Presenter.class);

  Pointer s21_Input(String str, double x);
}
