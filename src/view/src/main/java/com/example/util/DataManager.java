package com.example.util;

import java.io.*;

public class DataManager {

  public static void serializeData(DataObject object, String filePath) {
    try {
      FileOutputStream fos = new FileOutputStream(filePath);
      ObjectOutputStream oos = new ObjectOutputStream(fos);
      oos.writeObject(object);
      oos.flush();
      oos.close();
    } catch (IOException e) {
      System.out.println(e.getMessage());
    }
  }

  public static DataObject deserializeData(String filePath) {
    DataObject dataList = new DataObject();
    try {
      FileInputStream fis = new FileInputStream(filePath);
      ObjectInputStream oin = new ObjectInputStream(fis);
      dataList = (DataObject) oin.readObject();
    } catch (IOException | ClassNotFoundException e) {
      System.out.println(e.getMessage());
    }
    return dataList;
  }
}
