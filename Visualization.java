import javax.swing.JFrame;
import java.awt.Dimension;
            this.setPreferredSize(new Dimension(800, 800));
            this.setMaximumSize(new Dimension(800, 800));
            this.setMinimumSize(new Dimension(800, 800));
            super.paintComponent(g);
        }
        frame.setSize(800, 800);
		frame.setResizable(false);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setFocusable(true);
        frame.add(panel);
        frame.setVisible(true);
        frame.pack();