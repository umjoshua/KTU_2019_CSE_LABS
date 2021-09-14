/*Simple calculator using java swing*/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class Calculator extends JFrame implements ActionListener{
    JTextField inputBox;
    JButton bPlus,bDivide,bMinus,bMultiply,bClear,bDot,bEquals;
    JButton b0,b1,b2,b3,b4,b5,b6,b7,b8,b9;
    double val1,val2,result=0;
    String operator=""; int l=0;

    public Calculator(){
        JFrame frame = new JFrame("Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        GridBagLayout layout = new GridBagLayout();
        GridBagConstraints gbc = new GridBagConstraints();
        frame.setLayout(layout);
        frame.setSize(200,200);
        frame.setVisible(true);
        
        inputBox = new JTextField(10);
        inputBox.setEditable(false);

        b0=new JButton("0");b1=new JButton("1");
        b2=new JButton("2");b3=new JButton("3");
        b4=new JButton("4");b5=new JButton("5");
        b6=new JButton("6");b7=new JButton("7");
        b8=new JButton("8");b9=new JButton("9");

        bPlus=new JButton("+");bMinus=new JButton("-");
        bDivide=new JButton("/");bMultiply=new JButton("x");
        bEquals=new JButton("=");bClear=new JButton("C");
        bDot=new JButton(".");

        b0.addActionListener(this);b1.addActionListener(this);
        b2.addActionListener(this);b3.addActionListener(this);
        b4.addActionListener(this);b5.addActionListener(this);
        b6.addActionListener(this);b7.addActionListener(this);
        b8.addActionListener(this);b9.addActionListener(this);

        bPlus.addActionListener(this);bMinus.addActionListener(this);
        bDivide.addActionListener(this);bMultiply.addActionListener(this);
        bEquals.addActionListener(this);bClear.addActionListener(this);
        bDot.addActionListener(this);

        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridwidth=3;
        gbc.gridx=0; gbc.gridy=0; frame.add(inputBox,gbc);
        gbc.gridwidth=1;
        gbc.gridx=3; gbc.gridy=0; frame.add(bEquals,gbc);        
        gbc.gridx=0; gbc.gridy=1; frame.add(b1, gbc);
        gbc.gridx=1; gbc.gridy=1; frame.add(b2, gbc);
        gbc.gridx=2; gbc.gridy=1; frame.add(b3, gbc);
        gbc.gridx=3; gbc.gridy=1; frame.add(bPlus, gbc);
        gbc.gridx=0; gbc.gridy=2; frame.add(b4, gbc);
        gbc.gridx=1; gbc.gridy=2; frame.add(b5, gbc);
        gbc.gridx=2; gbc.gridy=2; frame.add(b6, gbc);
        gbc.gridx=3; gbc.gridy=2; frame.add(bMinus, gbc);
        gbc.gridx=0; gbc.gridy=3; frame.add(b7, gbc);
        gbc.gridx=1; gbc.gridy=3; frame.add(b8, gbc);
        gbc.gridx=2; gbc.gridy=3; frame.add(b9, gbc);
        gbc.gridx=3; gbc.gridy=3; frame.add(bDivide, gbc);
        gbc.gridx=0; gbc.gridy=4; frame.add(bDot, gbc);
        gbc.gridx=1; gbc.gridy=4; frame.add(b0, gbc);
        gbc.gridx=2; gbc.gridy=4; frame.add(bClear, gbc);
        gbc.gridx=3; gbc.gridy=4; frame.add(bMultiply, gbc);
    }
    public void actionPerformed(ActionEvent ae){
        String temp = ae.getActionCommand();
        if(temp!="+" && temp!="-" && temp!="x" && temp!="=" && temp!="/" && temp!="C")
            inputBox.setText(inputBox.getText()+temp);

        if(temp=="+" || temp=="-" || temp=="x" || temp=="/" || temp=="C"){
            if(temp!="C"){
                l=inputBox.getText().length();
                val1=Double.parseDouble(inputBox.getText());
                operator=temp;
                inputBox.setText(inputBox.getText() + temp);
            }
            else{
                inputBox.setText("");                
                l=0;operator="";
            }
        }
        if(temp=="="){
            val2=Double.parseDouble(inputBox.getText().substring(l+1));
            try{
                switch(operator){
                    case "+": result=val1+val2; break;
                    case "-": result=val1-val2; break;
                    case "x": result=val1*val2; break;
                    case "/": result=val1/val2; break;
                }
                inputBox.setText(inputBox.getText()+"="+result);
            }
            catch(ArithmeticException e){
                System.out.println("Cannot Divide by Zero.");
            }
        }
     }
    public static void main(String[] args){
        SwingUtilities.invokeLater(new Runnable(){
            public void run(){
                new Calculator();
            }
        });
    }
}