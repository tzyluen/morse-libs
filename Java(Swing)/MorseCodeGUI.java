/**
 * Morse Code Translator
 * Java - Swing UI
 * Copyright (C) 2014 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under JDK 1.7.0_25
 */
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.text.*;
import layout.*;

public class MorseCodeGUI extends JPanel implements ActionListener, FocusListener {
    JTextArea inputTextArea;
    boolean inputTextSet = false;
    Font regularFont, italicFont;
    JLabel morseCodeDisplay;
    final static int GAP = 10;


    public MorseCodeGUI() {
        setLayout(new BoxLayout(this, BoxLayout.LINE_AXIS));

        JPanel leftHalf = new JPanel() {
            public Dimension getMaximumSize() {
                Dimension pref = getPreferredSize();
                return new Dimension(Integer.MAX_VALUE, pref.height);
            }
        };
        leftHalf.setLayout(new BoxLayout(leftHalf, BoxLayout.PAGE_AXIS));
        leftHalf.add(createEntryFields());
        leftHalf.add(createButtons());

        add(leftHalf);
        add(createAddressDisplay());
    }


    protected JComponent createButtons() {
        JPanel panel = new JPanel(new FlowLayout(FlowLayout.TRAILING));
        JButton button = new JButton("To Morse Code");

        button.addActionListener(this);
        panel.add(button);

        button = new JButton("Reset");
        button.addActionListener(this);
        button.setActionCommand("clear");

        panel.add(button);
        panel.setBorder(BorderFactory.createEmptyBorder(0, 0, GAP-5, GAP-5));

        return panel;
    }


    public void actionPerformed(ActionEvent e) {
        if ("clear".equals(e.getActionCommand())) {
            inputTextSet = false;
            inputTextArea.setText("");
        } else {
            inputTextSet = true;
        }

        updateDisplays();
    }


    protected void updateDisplays() {
        morseCodeDisplay.setText(formatMorseCode());

        if (inputTextSet) {
            morseCodeDisplay.setFont(regularFont);
        } else {
            morseCodeDisplay.setFont(italicFont);
        }
    }


    protected JComponent createAddressDisplay() {
        JPanel panel = new JPanel(new BorderLayout());
        morseCodeDisplay = new JLabel();

        morseCodeDisplay.setHorizontalAlignment(JLabel.CENTER);
        regularFont = morseCodeDisplay.getFont().deriveFont(Font.PLAIN, 16.0f);
        italicFont = regularFont.deriveFont(Font.ITALIC);

        updateDisplays();

        panel.setBorder(BorderFactory.createEmptyBorder(
                                GAP/2, //top
                                0,     //left
                                GAP/2, //bottom
                                0));   //right
        panel.add(new JSeparator(JSeparator.VERTICAL), BorderLayout.LINE_START);
        panel.add(morseCodeDisplay, BorderLayout.CENTER);
        panel.setPreferredSize(new Dimension(200, 150));

        return panel;
    }


    protected String formatMorseCode() {
        if (!inputTextSet) return "Empty input text";

        String inputText = inputTextArea.getText();
        String empty = "";
        String morses = "";

        if ((inputText == null) || empty.equals(inputText)) {
            morses = "<em>(no input)</em>";
        } else {
            morses = Morse.lineToMorse(inputText);
        }

        StringBuffer sb = new StringBuffer();
        sb.append("<html><p align=center>");
        sb.append(morses);
        sb.append("<br>");
        sb.append(" ");
        sb.append(" ");
        sb.append("</p></html>");

        return sb.toString();
    }


    //A convenience method for creating a MaskFormatter.
    protected MaskFormatter createFormatter(String s) {
        MaskFormatter formatter = null;

        try {
            formatter = new MaskFormatter(s);
        } catch (java.text.ParseException exc) {
            System.err.println("formatter is bad: " + exc.getMessage());
            System.exit(-1);
        }

        return formatter;
    }


    public void focusGained(FocusEvent e) {
        Component c = e.getComponent();
        if (c instanceof JFormattedTextField) {
            selectItLater(c);
        } else if (c instanceof JTextField) {
            ((JTextField)c).selectAll();
        } else if (c instanceof JTextArea) {
            ((JTextArea)c).selectAll();
        }
    }


    //Workaround for formatted text field focus side effects.
    protected void selectItLater(Component c) {
        if (c instanceof JFormattedTextField) {
            final JFormattedTextField ftf = (JFormattedTextField)c;
            SwingUtilities.invokeLater(new Runnable() {
                public void run() {
                    ftf.selectAll();
                }
            });
        } else if (c instanceof JTextArea) {
            final JTextArea txta = (JTextArea)c;
            SwingUtilities.invokeLater(new Runnable() {
                public void run() {
                    txta.selectAll();
                }
            });
        }
    }


    public void focusLost(FocusEvent e) { } //ignore; no lost focus handler


    protected JComponent createEntryFields() {
        JPanel panel = new JPanel(new SpringLayout());

        String[] labelStrings = {
            "Text Input: ",
        };

        JLabel[] labels = new JLabel[labelStrings.length];
        JComponent[] fields = new JComponent[labelStrings.length];
        int fieldNum = 0;

        //Create the text field and set it up.
        inputTextArea  = new JTextArea();
        inputTextArea.setColumns(20);
        inputTextArea.setRows(5);
        fields[fieldNum++] = inputTextArea;

        //Associate label/field pairs, add everything,
        //and lay it out.
        for (int i = 0; i < labelStrings.length; i++) {
            labels[i] = new JLabel(labelStrings[i], JLabel.TRAILING);
            labels[i].setLabelFor(fields[i]);
            panel.add(labels[i]);
            panel.add(fields[i]);

            //Add listeners to each field.
            if (fields[i] instanceof JSpinner) {
                JTextField jc = null;
                jc = getTextField((JSpinner)fields[i]);
                jc.addActionListener(this);
                jc.addFocusListener(this);
            } else if (fields[i] instanceof JTextArea) {
                JTextArea jc = null;
                jc = (JTextArea)fields[i];
                jc.addFocusListener(this);
            } else {
                JTextField jc = null;
                jc = (JTextField)fields[i];
                jc.addActionListener(this);
                jc.addFocusListener(this);
            }
        }

        SpringUtilities.makeCompactGrid(panel,
                                        labelStrings.length, 2,
                                        GAP, GAP, //init x,y
                                        GAP, GAP/2);//xpad, ypad
        return panel;
    }


    public JFormattedTextField getTextField(JSpinner spinner) {
        JComponent editor = spinner.getEditor();

        if (editor instanceof JSpinner.DefaultEditor) {
            return ((JSpinner.DefaultEditor)editor).getTextField();
        } else {
            System.err.println("Unexpected editor type: "
                               + spinner.getEditor().getClass()
                               + " isn't a descendant of DefaultEditor");
            return null;
        }
    }


    private static void createAndShowGUI() {
        JFrame frame = new JFrame("MorseCodeGUI");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(new MorseCodeGUI());
        frame.pack();
        frame.setVisible(true);
    }


    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
	        UIManager.put("swing.boldMetal", Boolean.FALSE);
                createAndShowGUI();
            }
        });
    }
}
