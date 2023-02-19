
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class FenetrePrincipale extends JFrame {
    private static final long serialVersionUID = 1L;

    private AbstractAction bouton1;
    private AbstractAction bouton2;
    private AbstractAction bouton3;

    private JPanel boutonsPanel;

    private JTextArea zoneTexte;

    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;
    static Client client;

    public static void main(String argv[]) {
        new FenetrePrincipale();
        // Java client
        String host = DEFAULT_HOST;
        int port = DEFAULT_PORT;
        if (argv.length >= 1)
            host = argv[0];
        if (argv.length >= 2)
            port = Integer.parseInt(argv[1]);

        // Client client = null;

        try {
            client = new Client(host, port);
        } catch (Exception e) {
            System.err.println("Client: Couldn't connect to " + host + ":" + port);
            System.exit(1);
        }
    }

    // Constructeur
    public FenetrePrincipale() {

        super("Set-top box multimedia");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setPreferredSize(new Dimension(500, 500));

        // parametres par defaut
        this.setLayout(new BoxLayout(this.getContentPane(), BoxLayout.Y_AXIS));

        // Création des boutons
        bouton1 = new ActionSearchMultimedia();
        bouton2 = new ActionPlay();
        bouton3 = new ActionExit();

        // Création du panel contenant les boutons
        this.boutonsPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        boutonsPanel.add(new JButton(bouton1));
        boutonsPanel.add(new JButton(bouton2));
        boutonsPanel.add(new JButton(bouton3));

        // zone de texte pour les requêtes
        this.zoneTexte = new JTextArea(10, 20);
        JScrollPane scrollTexte = new JScrollPane(this.zoneTexte);

        // Ajout des éléments à la fenêtre
        add(scrollTexte, BorderLayout.NORTH);
        add(boutonsPanel, BorderLayout.SOUTH);

        // Création de la barre de menus
        JMenuBar menuBar = new JMenuBar();
        setJMenuBar(menuBar);

        // Création du menu déroulant
        JMenu menu = new JMenu("Menu");
        menuBar.add(menu);

        // Ajout des actions aux items du menu déroulant
        JMenuItem item1 = new JMenuItem(new AbstractAction("Rechercher") {
            public void actionPerformed(ActionEvent e) {
                zoneTexte.append("Rechercher\n");
            }
        });
        JMenuItem item2 = new JMenuItem(new AbstractAction("Play") {
            public void actionPerformed(ActionEvent e) {
                zoneTexte.append("Play\n");
            }
        });
        JMenuItem item3 = new JMenuItem(new AbstractAction("Quitter") {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        menu.add(item1);
        menu.add(item2);
        menu.add(item3);

        // Création de la barre d'outils
        JToolBar toolBar = new JToolBar();
        menuBar.add(toolBar, BorderLayout.NORTH);

        // Ajout des actions à la barre d'outils
        toolBar.add(new JButton(new AbstractAction("Rechercher") {
            public void actionPerformed(ActionEvent e) {
                zoneTexte.append("Rechercher\n");
            }
        }));

        pack();
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

    class ActionPlay extends AbstractAction {
        private static final long serialVersionUID = 1L;

        public ActionPlay() {
            this.putValue(AbstractAction.NAME, "Play");
        }

        public void actionPerformed(ActionEvent e) {
            String text = zoneTexte.getText();
            String name = JOptionPane.showInputDialog(null, "Media or group name to play", "Media/Group input",
                    JOptionPane.QUESTION_MESSAGE);

            try {
                zoneTexte.setText(text + "play " + name + "\n" + client.send("play " + name) + "\n");
            } catch (Exception err) {
                System.err.println("Client: IO erreur");
            }
        }
    }

    class ActionSearchMultimedia extends AbstractAction {
        private static final long serialVersionUID = 1L;

        public ActionSearchMultimedia() {
            this.putValue(AbstractAction.NAME, "Recherche");
        }

        public void actionPerformed(ActionEvent e) {
            String text = zoneTexte.getText();
            String name = JOptionPane.showInputDialog(null, "Media or group name to play", "Media/Group input",
                    JOptionPane.QUESTION_MESSAGE);

            try {
                zoneTexte.setText(text + "Recherche " + name + "\n" + client.send("searchMultimedia " + name) + "\n");
            } catch (Exception err) {
                System.err.println("Client: IO erreur");
            }
        }
    }

}