import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class FenetrePrincipale extends JFrame {
    private static final long serialVersionUID = 1L;

    private AbstractAction butShow;
    private AbstractAction butSearchM;
    private AbstractAction butSearchG;
    private AbstractAction butPlay;
    private AbstractAction butExit;
    

    private JPanel boutonsPanel;

    private JTextArea zoneTexte;

    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;
    static Client client;

    public static void main(String argv[]) {
        new FenetrePrincipale();
         // Client
        String host = DEFAULT_HOST;
        int port = DEFAULT_PORT;
        // Si host et port sont passes en parametres
        if (argv.length >= 1)
            host = argv[0];
        if (argv.length >= 2)
            port = Integer.parseInt(argv[1]);

        try {
            client = new Client(host, port);
        } catch (Exception e) {
            System.err.println("Client: connection impossible a : " + host + ":" + port);
            System.exit(1);
        }
    }
    

    // Constructeur
    public FenetrePrincipale() {

        super("Set-top box multimedia");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setPreferredSize(new Dimension(600, 600));

        // Création des boutons
        butShow = new ActionShow();
        butSearchM = new ActionSearchMultimedia();
        butSearchG = new ActionSearchGroup();
        butPlay = new ActionPlay();
        butExit = new ActionExit();

        // Création du panel contenant les boutons
        this.boutonsPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
        JButton buttonSearchM = new JButton(butSearchM);
        JButton buttonSearchG = new JButton(butSearchG);
        JButton buttonPlay = new JButton(butPlay);
        JButton buttonExit = new JButton(butExit);
        boutonsPanel.add(buttonSearchM);
        boutonsPanel.add(buttonSearchG);
        boutonsPanel.add(buttonPlay);
        boutonsPanel.add(buttonExit);

        // Ajout de quelques elements de mise en forme
        buttonSearchM.setBackground(new Color(0x2dce98)); buttonSearchM.setForeground(Color.white);
        buttonSearchG.setBackground(new Color(0x2dce98)); buttonSearchG.setForeground(Color.white);
        buttonPlay.setBackground(new Color(0x2dce98)); buttonPlay.setForeground(Color.white);
        buttonExit.setBackground(new Color(0xb83b5e)); buttonExit.setForeground(Color.white);

        // zone de texte pour les requêtes
        this.zoneTexte = new JTextArea();
        zoneTexte.setEditable(false);
        zoneTexte.setLineWrap(true);
        this.zoneTexte.setText(" -- BIENVENUE SUR MEDIAPLAYER -- \n" + "Appuyez sur un bouton pour choisir une action.\n");
        JScrollPane scrollTexte = new JScrollPane(this.zoneTexte);

        // Ajout des éléments à la fenêtre
        getContentPane().setLayout(new BorderLayout());
        getContentPane().add(boutonsPanel, BorderLayout.SOUTH);
        getContentPane().add(scrollTexte, BorderLayout.CENTER);

        // Création de la barre de menus
        JMenuBar menuBar = new JMenuBar();
        setJMenuBar(menuBar);

        // Création du menu déroulant
        JMenu menu = new JMenu("Menu");
        menuBar.add(menu);

        menu.add(butShow);
        menu.add(butSearchM);
        menu.add(butSearchG);
        menu.add(butPlay);
        menu.add(butExit);

        // Création de la barre d'outils
        JToolBar outilsBarre = new JToolBar();
        outilsBarre.add(new ActionShow());
        outilsBarre.add(new ActionSearchMultimedia());
        outilsBarre.add(new ActionSearchGroup());
        outilsBarre.add(new ActionPlay());
        outilsBarre.add(new ActionExit());
        menuBar.add(outilsBarre, BorderLayout.NORTH);
        
        pack();
        
        //Centrer la fenêtre
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        int centerX = (int) screenSize.getWidth() / 2;
        int centerY = (int) screenSize.getHeight() / 2;
        setLocation(centerX - getSize().width / 2, centerY - getSize().height / 2);


        setVisible(true);

    }

    class ActionExit extends AbstractAction {
        private static final long serialVersionUID = 1L;

        public ActionExit() {
            this.putValue(AbstractAction.NAME, "Quitter");
        }

        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }

    class ActionShow extends AbstractAction {
        private static final long serialVersionUID = 1L;

        public ActionShow() {
            this.putValue(AbstractAction.NAME, "Liste");
        }

        public void actionPerformed(ActionEvent e) {
            String text = zoneTexte.getText();
            zoneTexte.setText(text + "* Liste : \n  .MEDIAS DISPONIBLES : " + "photo1 | video1" + "\n" + "  .GROUPES DISPONIBLES : " + "group1" +"\n");
        }
    }
    
    class ActionPlay extends AbstractAction {
        private static final long serialVersionUID = 1L;

        public ActionPlay() {
            this.putValue(AbstractAction.NAME, "Play");
        }

        public void actionPerformed(ActionEvent e) {
            String text = zoneTexte.getText();
            String name = JOptionPane.showInputDialog(null, "Tapez le nom du media a jouer", "Barre de recherche",
                    JOptionPane.QUESTION_MESSAGE);

            try {
                zoneTexte.setText(text + "* Play : " + name + "\n" + client.send("play " + name) + "\n");
            } catch (Exception err) {
                System.err.println("Client: IO erreur");
            }
        }
    }

    class ActionSearchMultimedia extends AbstractAction {
        private static final long serialVersionUID = 1L;

        public ActionSearchMultimedia() {
            this.putValue(AbstractAction.NAME, "Recherche Media");
        }

        public void actionPerformed(ActionEvent e) {
            String text = zoneTexte.getText();
            String name = JOptionPane.showInputDialog(null, "Tapez le nom du media a chercher", "Barre de recherche",
                    JOptionPane.QUESTION_MESSAGE);

            try {
                zoneTexte.setText(text + "* Recherche Media : " + name + "\n" + client.send("searchMultimedia " + name) + "\n");
            } catch (Exception err) {
                System.err.println("Client: IO erreur");
            }
        }
    }

    class ActionSearchGroup extends AbstractAction {
        private static final long serialVersionUID = 1L;

        public ActionSearchGroup() {
            this.putValue(AbstractAction.NAME, "Recherche Groupe");
        }

        public void actionPerformed(ActionEvent e) {
            String text = zoneTexte.getText();
            String name = JOptionPane.showInputDialog(null, "Tapez le nom du groupe a chercher", "Barre de recherche",
                    JOptionPane.QUESTION_MESSAGE);

            try {
                zoneTexte.setText(text + "Recherche Groupe: " + name + "\n" + client.send("searchGroup " + name) + "\n");
            } catch (Exception err) {
                System.err.println("Client: IO erreur");
            }
        }
    }

}