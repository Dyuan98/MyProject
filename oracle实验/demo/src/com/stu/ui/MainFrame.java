/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.stu.ui;

import com.stu.model.Student;
import com.stu.model.StudentTableModel;
import com.stu.util.DaoFactory;
import com.stu.util.Tools;
import javax.swing.JOptionPane;

/**
 *
 * @author Administrator
 */
public class MainFrame extends javax.swing.JFrame {

    /**
     * Creates new form MainFrame
     */
    public MainFrame() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        sexbuttonGroup1 = new javax.swing.ButtonGroup();
        jLabel1 = new javax.swing.JLabel();
        querystuTextField = new javax.swing.JTextField();
        jScrollPane1 = new javax.swing.JScrollPane();
        studentTable = new javax.swing.JTable();
        queryButton = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        jPanel1 = new javax.swing.JPanel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        snoText = new javax.swing.JTextField();
        manRadioButton1 = new javax.swing.JRadioButton();
        womanRadioButton2 = new javax.swing.JRadioButton();
        addstuButton2 = new javax.swing.JButton();
        modifystuButton3 = new javax.swing.JButton();
        snameText = new javax.swing.JTextField();
        sageText = new javax.swing.JTextField();
        sdeptText = new javax.swing.JTextField();
        DeletestuButton4 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("请输入要查询的学号：");

        querystuTextField.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                querystuTextFieldActionPerformed(evt);
            }
        });

        studentTable.setModel(stuModel);
        studentTable.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        studentTable.getTableHeader().setResizingAllowed(false);
        studentTable.getTableHeader().setReorderingAllowed(false);
        studentTable.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                studentTableMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(studentTable);

        queryButton.setText("查询");
        queryButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                queryButtonActionPerformed(evt);
            }
        });

        jLabel2.setText("作者信息：   学号：201500781   姓名：刘帅");

        jLabel3.setText("姓名：");

        jLabel4.setText("性别：");

        jLabel5.setText("学号：");

        jLabel6.setText("年龄：");

        jLabel7.setText("系部：");

        snoText.setEditable(false);

        sexbuttonGroup1.add(manRadioButton1);
        manRadioButton1.setSelected(true);
        manRadioButton1.setText("男");

        sexbuttonGroup1.add(womanRadioButton2);
        womanRadioButton2.setText("女");

        addstuButton2.setText("添加信息");
        addstuButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                addstuButton2ActionPerformed(evt);
            }
        });

        modifystuButton3.setText("修改信息");
        modifystuButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                modifystuButton3ActionPerformed(evt);
            }
        });

        snameText.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                snameTextActionPerformed(evt);
            }
        });

        DeletestuButton4.setText("删除信息");
        DeletestuButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                DeletestuButton4ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                        .addGroup(jPanel1Layout.createSequentialGroup()
                            .addComponent(jLabel4)
                            .addGap(21, 21, 21)
                            .addComponent(manRadioButton1)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                            .addComponent(womanRadioButton2))
                        .addGroup(jPanel1Layout.createSequentialGroup()
                            .addComponent(jLabel7)
                            .addGap(18, 18, 18)
                            .addComponent(sdeptText))
                        .addGroup(jPanel1Layout.createSequentialGroup()
                            .addComponent(jLabel6)
                            .addGap(18, 18, 18)
                            .addComponent(sageText))
                        .addGroup(jPanel1Layout.createSequentialGroup()
                            .addComponent(jLabel3)
                            .addGap(18, 18, 18)
                            .addComponent(snameText))
                        .addGroup(jPanel1Layout.createSequentialGroup()
                            .addComponent(jLabel5)
                            .addGap(16, 16, 16)
                            .addComponent(snoText, javax.swing.GroupLayout.PREFERRED_SIZE, 182, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(addstuButton2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(modifystuButton3)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(DeletestuButton4)))
                .addContainerGap(131, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(snoText, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel5))
                .addGap(39, 39, 39)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(snameText, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(47, 47, 47)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(manRadioButton1)
                    .addComponent(womanRadioButton2))
                .addGap(50, 50, 50)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6)
                    .addComponent(sageText, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 47, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(sdeptText, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(25, 25, 25)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(addstuButton2)
                    .addComponent(modifystuButton3)
                    .addComponent(DeletestuButton4))
                .addContainerGap())
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 136, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(querystuTextField, javax.swing.GroupLayout.PREFERRED_SIZE, 160, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(queryButton, javax.swing.GroupLayout.PREFERRED_SIZE, 84, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 398, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(querystuTextField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(queryButton)
                    .addComponent(jLabel2))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 358, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void snameTextActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_snameTextActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_snameTextActionPerformed

    private void addstuButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_addstuButton2ActionPerformed
        // TODO add your handling code here:
        AddStudentDialog dialog = new AddStudentDialog(this, true);
        dialog.setLocationRelativeTo(this);
        dialog.setVisible(true);
        if (AddStudentDialog.RET_OK == dialog.getReturnStatus()) {
            stuModel = new StudentTableModel();
            studentTable.setModel(stuModel);
        }
    }//GEN-LAST:event_addstuButton2ActionPerformed

    private void querystuTextFieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_querystuTextFieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_querystuTextFieldActionPerformed

    private void studentTableMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_studentTableMouseClicked
        // TODO add your handling code here:
        // 获取表格选定行的索引；如果没有选定的行，则返回 -1
        int rowNum = studentTable.getSelectedRow();
        if (rowNum >= 0) {
// 获取所选择行的第0 列的值，也就是学号的值
            String sno = (String) studentTable.getValueAt(rowNum, 0);
            if (snoText.getText().trim().equals(sno)) {
                return;
            }
            String sname = (String) studentTable.getValueAt(rowNum, 1);
            String ssex = (String) studentTable.getValueAt(rowNum, 2);
            int sage = (int) studentTable.getValueAt(rowNum, 3);
            String sdept = (String) studentTable.getValueAt(rowNum, 4);
            snoText.setText(sno);
            snameText.setText(sname);
            if ("男".equals(ssex)) {
                manRadioButton1.setSelected(true);
            } else {
                womanRadioButton2.setSelected(true);
            }
            sageText.setText(String.valueOf(sage));
            sdeptText.setText(sdept);
        }


    }//GEN-LAST:event_studentTableMouseClicked

    private void queryButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_queryButtonActionPerformed
        // TODO add your handling code here:
        // 获取要查询的学生学号
        String sno = querystuTextField.getText().trim();
        if ("".equals(sno)) {
            stuModel = new StudentTableModel();
        } else {
            stuModel = new StudentTableModel(sno);
        }
// 设置表格模型
        studentTable.setModel(stuModel);
        querystuTextField.setText("");

    }//GEN-LAST:event_queryButtonActionPerformed

    private void modifystuButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_modifystuButton3ActionPerformed
        // TODO add your handling code here:
        String sno = snoText.getText().trim();
        String sname = snameText.getText().trim();
        String ssex;
        if (manRadioButton1.isSelected()) {
            ssex = manRadioButton1.getText();
        } else {
            ssex = womanRadioButton2.getText();
        }
        String sage = sageText.getText().trim();
        String sdept = sdeptText.getText().trim();
        if ("".equals(sno) || sno == null) {
            JOptionPane.showMessageDialog(this, "请选择一条要修改的学生记录！");
            return;
        }
// 验证修改信息的有效性
        if (!validateData(sno, sname, ssex, sage, sdept)) {
            return;
        }

        Student stu = new Student(sno, sname, ssex, Integer.parseInt(sage), sdept);
//如果数据验证正确，则插入学生记录内容
        if (!DaoFactory.getStudentDao().updateStudent(stu)) {
            JOptionPane.showMessageDialog(this, "学生记录更新失败，请检查输入的数据内容！");
        }
// 数据发生变化，更新表格模型
        stuModel = new StudentTableModel();
        studentTable.setModel(stuModel);
    }
// 验证输入信息的有效性

    private boolean validateData(String sno, String sname, String ssex, String sage, String sdept) {
        if ("".equals(sno) || !Tools.isNumeric(sno) || sno.length() != 7) {
            JOptionPane.showMessageDialog(this, "请输入正确的学号，并且学号为数字！");
            snoText.requestFocus();
            return false;
        }
        if ("".equals(sname)) {
            JOptionPane.showMessageDialog(this, "请输入学生姓名！");
            snameText.requestFocus();
            return false;
        }
        try {
            if (Integer.parseInt(sage) < 15 || Integer.parseInt(sage) > 45) {
                JOptionPane.showMessageDialog(this, "学生年龄范围在15 到45 岁之间！");
                sageText.requestFocus();
                return false;
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "请输入正确的年龄！");
            sageText.requestFocus();
            return false;
        }
        if ("".equals(sdept)) {
            JOptionPane.showMessageDialog(this, "请输入系部名称！");
            sdeptText.requestFocus();
            return false;
        }
        return true;


    }//GEN-LAST:event_modifystuButton3ActionPerformed

    private void DeletestuButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_DeletestuButton4ActionPerformed
        // TODO add your handling code here:

        int rowNum = studentTable.getSelectedRow();

        if (rowNum >= 0) {
            String sno = snoText.getText().trim();
            int choise = JOptionPane.showConfirmDialog(this, "是否要删除学生的信息内容", "提示", JOptionPane.YES_NO_OPTION);
            if (choise == JOptionPane.YES_OPTION) {
                if (!DaoFactory.getStudentDao().deleteStudent(sno)) {
                    JOptionPane.showMessageDialog(this, "学生信息删除失败，请与系统管理员联系！");
                }
                stuModel = new StudentTableModel();
                studentTable.setModel(stuModel);
            }
        } else {
            JOptionPane.showMessageDialog(this, "请选择要删除的学生信息！");
        }
        snoText.setText(null);
        snameText.setText(null);
        manRadioButton1.setSelected(true);
        sageText.setText(null);
        sdeptText.setText(null);
    }//GEN-LAST:event_DeletestuButton4ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(MainFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(MainFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(MainFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(MainFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new MainFrame().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton DeletestuButton4;
    private javax.swing.JButton addstuButton2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JRadioButton manRadioButton1;
    private javax.swing.JButton modifystuButton3;
    private javax.swing.JButton queryButton;
    private javax.swing.JTextField querystuTextField;
    private javax.swing.JTextField sageText;
    private javax.swing.JTextField sdeptText;
    private javax.swing.ButtonGroup sexbuttonGroup1;
    private javax.swing.JTextField snameText;
    private javax.swing.JTextField snoText;
    private javax.swing.JTable studentTable;
    private javax.swing.JRadioButton womanRadioButton2;
    // End of variables declaration//GEN-END:variables

    private StudentTableModel stuModel = new StudentTableModel();

}
