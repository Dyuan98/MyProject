package com.liushuai;
/*
主页
*/
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainFrame extends AbstractFrame implements ActionListener {
    private JFrame frame=new JFrame();
    private JPanel jp = new JPanel();
    private JButton jlogin = new JButton("登录");
    private JButton jregister = new JButton("注册");
    private JButton jexit = new JButton("退出");
    private JLabel meg = new JLabel("用户登录注册系统");
    private Frame login;
    private Frame register;
    private Modify modify;

    public MainFrame() {
        jp.setLayout(null);
        meg.setBounds(130, 50, 250, 30);
        jlogin.setBounds(100, 100, 180, 30);
        jregister.setBounds(100, 150, 180, 30);
        jexit.setBounds(100, 200, 180, 30);

        jp.add(meg);
        jp.add(jlogin);
        jp.add(jregister);
        jp.add(jexit);

        jlogin.addActionListener(this);
        jregister.addActionListener(this);
        jexit.addActionListener(this);

        meg.setFont(new Font("微软雅黑", Font.BOLD, 15));
        jlogin.setFont(new Font("微软雅黑", Font.BOLD, 15));
        jregister.setFont(new Font("微软雅黑", Font.BOLD, 15));
        jexit.setFont(new Font("微软雅黑", Font.BOLD, 15));

        frame.add(jp);
        frame.setTitle("主界面");
        frame.setResizable(false);
        frame.setBounds(100, 100, 400, 300);//窗口大小
        frame.setVisible(true);
    }
    @Override
    //外观模式
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == jregister) {
            register=Factory.getFrame("注册").getFrame();
        }
        if (e.getSource() == jlogin) {
            login = Factory.getFrame("登录").getFrame();
        }
        if (e.getSource() == jexit) {
            System.exit(0);
        }
    }

    @Override
    public JFrame getFrame() {
        return frame;
    }
}
