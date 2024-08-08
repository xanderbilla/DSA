//Implementing listeners using lambda expressions is a common practice in Java,
// especially when dealing with event-driven programming,
//,. such as GUI (Graphical User Interface) applications.
// Lambda expressions provide a concise and expressive way to
// define the implementation of functional interfaces, like listeners.


import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class LambdaListenerEx {

    public static void main(String[] args) {
        JFrame frame = new JFrame("Lambda Listener Example");

        JButton button = new JButton("Click Me!");

        // Using lambda expression to implement ActionListener
        button.addActionListener((ActionEvent e) -> {
            System.out.println("Button clicked!");
        });

        frame.getContentPane().add(button);
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
