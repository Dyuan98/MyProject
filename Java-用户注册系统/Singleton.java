package com.liushuai;

/*
单例模式
*/

import javax.swing.*;

public class Singleton {
    private static Singleton instance;
    private static Object myLock = new Object();

    private Singleton() {
    }

    public static Singleton GetInstance() {
        if (instance == null) {
            lock(myLock);
            {
                if (instance == null) {
                    instance = new Singleton();
                }
            }
        } else {
            JOptionPane.showMessageDialog(null,"帐号已经被注册，不允许再次被注册");
        }
        return instance;
    }

    private static void lock(Object myLock) {

    }
}



