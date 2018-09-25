package com.liushuai;
/*
修改界面
*/
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Modify extends AbstractFrame implements ActionListener {
    private JFrame frame=new JFrame();
    private JPanel jp2 = new JPanel();
    private JButton btModify = new JButton("确认修改");
    private JButton btExit = new JButton("退出");
    private JLabel password1 = new JLabel("新密码:");
    private JLabel password2 = new JLabel("确认密码:");
    private JLabel id = new JLabel("新编号:");
    private JTextField jid = new JTextField();
    private JPasswordField jtxtpassword1 = new JPasswordField();
    private JPasswordField jtxtpassword2 = new JPasswordField();

    public Modify() {
        jp2.setLayout(null);
        jtxtpassword1.setBounds(140, 60, 180, 30);
        jtxtpassword2.setBounds(140, 115, 180, 30);
        jid.setBounds(140, 170, 180, 30);
        btModify.setBounds(80, 260, 110, 30);
        btExit.setBounds(230, 260, 80, 30);
        password1.setBounds(80, 60, 100, 30);
        password2.setBounds(80, 115, 100, 30);
        id.setBounds(80, 170, 100, 30);

        jp2.add(btExit);
        jp2.add(btModify);
        jp2.add(jid);
        jp2.add(jtxtpassword1);
        jp2.add(jtxtpassword2);
        jp2.add(password1);
        jp2.add(password2);
        jp2.add(id);

        password1.setFont(new Font("微软雅黑", Font.PLAIN, 15));
        password2.setFont(new Font("微软雅黑", Font.PLAIN, 15));
        id.setFont(new Font("微软雅黑", Font.PLAIN, 15));
        btExit.setFont(new Font("微软雅黑", Font.PLAIN, 15));
        btModify.setFont(new Font("微软雅黑", Font.PLAIN, 15));
        jtxtpassword1.setFont(new Font("微软雅黑", Font.BOLD, 15));
        jtxtpassword2.setFont(new Font("微软雅黑", Font.BOLD, 15));
        jid.setFont(new Font("微软雅黑", Font.BOLD, 15));

        btExit.addActionListener((ActionListener) this);
        btModify.addActionListener((ActionListener) this);

        frame.add(jp2);
        frame.setTitle("修改界面");
        frame.setResizable(false);
        frame.setBounds(100, 100, 400, 400);//窗口大小
        frame.setVisible(true);

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btExit) {
            frame.dispose();
        }
        if (e.getSource() == btModify) {
            String password1 = new String(jtxtpassword1.getPassword());
            String password2 = new String(jtxtpassword2.getPassword());
            if (!password1.equals(password2)) {
                JOptionPane.showMessageDialog(frame, "两次密码不相同");
                return;
            }
            String id = jid.getText();
            User.password = password1;
            User.id = id;
            File.updata(User.username, password1, id);
            JOptionPane.showMessageDialog(frame, "修改成功");
            frame.dispose();
        }
    }

    @Override
    public JFrame getFrame() {
        return frame;
    }
}
