package com.example.util;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class DataObject implements Serializable {

  private final List<String> list;
  private static final long serialVersionUID = 1L;

  public DataObject() {
    list = new ArrayList<String>();
  }

  public void setText(String text) {
    list.add(text);
  }

  public void clearList() {
    list.clear();
  }

  public List<String> getList() {
    return list;
  }
}
