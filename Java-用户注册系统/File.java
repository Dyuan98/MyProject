package com.liushuai;

/*
文件的读写操作
*/

import javax.swing.*;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Properties;

public class File {
    private static String fileName = "d:/data.txt";
    private static Properties pps;

    static {//加载文件
        pps = new Properties();
        FileReader reader = null;
        try {
            reader = new FileReader(fileName);
            pps.load(reader);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, "文件操作异常1");//找不到文件
            System.exit(0);
        } finally {
            try {
                reader.close();
            } catch (Exception ex) {
            }
        }
    }

    private static void listInfo() {
        PrintStream ps = null;
        try {
            ps = new PrintStream(fileName);
            pps.list(ps);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, "文件操作异常2");
            System.exit(0);
        } finally {
            try {
                ps.close();
            } catch (Exception ex) {
            }
        }
    }

    public static void getInfoByUsername(String username) {
        String dataInfo = pps.getProperty(username);
        if (dataInfo != null) {
            String[] infos = dataInfo.split("#");
            User.username = username;
            User.password = infos[0];
            User.id = infos[1];
        }
    }

    public static void updata(String username, String password, String id) {
        pps.setProperty(username, password + "#" + id);
        listInfo();
    }
}
