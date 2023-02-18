

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class FenetrePrincipale extends JFrame{
    private static final long serialVersionUID = 1L;

    private JButton bouton1;
    private JButton bouton2;
    private JButton bouton3;

    private JPanel boutonsPanel;

    private JTextArea zoneRequete;
    private JTextArea zoneReponse;
    //private JMenuBar barreMenu;

    private Client client;

    public static void main(String argv[]){
        FenetrePrincipale fp = new FenetrePrincipale();
    }

    // Constructeur
    public FenetrePrincipale() {

        super("Set-top box multimedia");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setPreferredSize(new Dimension(500, 500));

        // parametres par defaut
        this.setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));

        // Création des boutons
        bouton1 = new JButton("Bouton 1");
        bouton2 = new JButton("Bouton 2");
        bouton3 = new JButton("Quitter");

        // Création du panel contenant les boutons
        this.boutonsPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        boutonsPanel.add(this.bouton1);
        boutonsPanel.add(this.bouton2);
        boutonsPanel.add(this.bouton3);

        // Ajout de listeners aux boutons
        this.bouton1.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                zoneReponse.append("Ajout ligne 1\n");
            }
        });

        this.bouton2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                zoneReponse.append("Ajout ligne 2\n");
            }
        });

        this.bouton3.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                System.exit(0);
            }
        });

        // Panel pour les boutons
        boutonsPanel = new JPanel();
        boutonsPanel.add(this.bouton1);
        boutonsPanel.add(this.bouton2);
        boutonsPanel.add(this.bouton3);


        // zone de texte pour les requêtes
        this.zoneRequete = new JTextArea(10, 20);
        JScrollPane scrollRequete = new JScrollPane(this.zoneRequete);
        
        // zone de texte pour les requêtes
        this.zoneReponse = new JTextArea(10, 20);
        JScrollPane scrollReponse = new JScrollPane(this.zoneReponse);
        
        // Ajout des éléments à la fenêtre
        add(scrollRequete, BorderLayout.NORTH);
        add(scrollReponse, BorderLayout.CENTER);
        add(boutonsPanel, BorderLayout.SOUTH);

        
        /*this.bouton1 = new JButton("Afficher");
        this.bouton1.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent event ) {
                String requete = (String)JOptionPane.showInputDialog(FenetrePrincipale.this,"Tapez le nom du media : ",JOptionPane.PLAIN_MESSAGE);
                String reponse = FenetrePrincipale.this.client.send("printMultimedia" + requete);
                reponse = reponse.replace("|","\n");
                zoneReponse.append(reponse+"\n");
            } 
        });
        this.bouton2 = new JButton("Jouer");
        this.bouton2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent event ) {
                String requete = (String)JOptionPane.showInputDialog(FenetrePrincipale.this,"Tapez le nom du media : ",JOptionPane.PLAIN_MESSAGE);
                String reponse = FenetrePrincipale.this.client.send("play" + requete);
                reponse = reponse.replace("|","\n");
                zoneReponse.append(reponse+"\n");
            } 
        });
        this.bouton3 = new JButton("Quitter");
        this.bouton3.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent event ) {
                System.exit(0);
                } 
        });
        this.boutonsPanel = new JPanel();
        boutonsPanel.add(this.bouton1, BorderLayout.WEST);
        boutonsPanel.add(this.bouton2, BorderLayout.CENTER);
        boutonsPanel.add(this.bouton3, BorderLayout.EAST);
        add(this.boutonsPanel, BorderLayout.SOUTH);*/

        // Création de la barre de menus
        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("Menu");
        JMenuItem menuItem1 = new JMenuItem(new AbstractAction("Menu Item 1") {
            @Override
            public void actionPerformed(ActionEvent e) {
                zoneReponse.append("Menu Item 1 a été cliqué\n");
            }
        });

        JMenuItem menuItem2 = new JMenuItem(new AbstractAction("Menu Item 2") {
            @Override
            public void actionPerformed(ActionEvent e) {
                zoneReponse.append("Menu Item 2 a été cliqué\n");
            }
        });

        menu.add(menuItem1);
        menu.add(menuItem2);

        menuBar.add(menu);

        // Création de la barre d'outils
        JToolBar toolBar = new JToolBar();

        toolBar.add(new AbstractAction("Bouton 1", new ImageIcon("icon.png")) {
            @Override
            public void actionPerformed(ActionEvent e) {
                zoneReponse.append("Bouton 1 a été cliqué\n");
            }
        });

        toolBar.add(new AbstractAction("Bouton 2", new ImageIcon("icon.png")) {
            @Override
            public void actionPerformed(ActionEvent e) {
                zoneReponse.append("Bouton 2 a été cliqué\n");
            }
        });

        add(toolBar, BorderLayout.NORTH);

        // Ajout de la barre de menus à la fenêtre principale
        setJMenuBar(menuBar);
        
        
        pack();
        setVisible(true);

    }

}