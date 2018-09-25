package com.liushuai;

/*
主类调用登录界面
*/

import java.awt.*;

public class main {
    public static void main(String[] args) {
        Frame mainFrame;
        mainFrame = Factory.getFrame("主界面").getFrame();
    }
}
