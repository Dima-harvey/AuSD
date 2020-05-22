import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        BinarySearchTree tree = new BinarySearchTree();
        Scanner input = new Scanner(System.in);
 
        System.out.println("\t Наш граф: ");
        tree.insert(5);
        tree.insert(9);
        tree.insert(10);
        tree.insert(8);
        tree.insert(7);
        tree.insert(6);
        tree.insert(3);
        tree.insert(4);
        tree.insert(2);
        System.out.println("\n");
        tree.walk(tree.getRoot(), 0);
        int comand = 0;

        while (true) {
            System.out.println("1)Удалить узел (левым удалением);");
            System.out.println("2)Удалить узел (правым удалением);");
            System.out.println("3)Найти глубину узла;");
            System.out.println("4)Найти высоту узла;");
            System.out.println("5)Найти уровень узла;");
            System.out.println("6)Посмотреть на граф;");
            System.out.println("7)Обходы;");
            System.out.println("8)Задание 2;");
            System.out.println("9)Выход;");
            System.out.println("Введите команду: ");
            
            comand = input.nextInt();
            switch (comand) {
                case 1:
                    System.out.println("\t2)Удалить узел (левым удалением);");
                    int deleteL = 0;
                    System.out.print("\tВвести узел: ");
                    deleteL = input.nextInt();
                    tree.deleteKey(deleteL, 2);
                    break;
                case 2:
                    System.out.println("\t3)Удалить узел (правым удалением);");
                    int deleteR = 0;
                    System.out.print("\tВвести узел: ");
                    deleteR = input.nextInt();
                    tree.deleteKey(deleteR, 1);
                    break;
                case 3:
                    System.out.println("\tНайти глубину узла");
                    int depth = 0;
                    System.out.print("\tВвести узел: ");
                    depth = input.nextInt();
                    System.out.print("\t Глубина узла: " + tree.depth(tree.getRoot(), depth));
                    System.out.println();
                    break;
                case 4:
                    System.out.println("\tНайти высоту узла;");
                    int height = 0;
                    System.out.print("\tВвести узел: ");
                    height = input.nextInt();
                    System.out.print("\t Высота узла: " + tree.height(tree.search(tree.getRoot(), height)));
                    System.out.println();
                    break;
                case 5:
                    System.out.println("\tНайти уровень узла;");
                    int level = 0;
                    System.out.print("\tВвести узел: ");
                    level = input.nextInt();
                    System.out.print("\t Уровень узла: " + tree.level(tree.getRoot(), level));
                    System.out.println();
                    break;
                case 6:
                    tree.walk(tree.getRoot(), 0);
                    break;
                case 7:
                    System.out.print("\n\tПрямой: ");
                    tree.traight_detour(tree.getRoot());
                    System.out.print("\n\tОбратный: ");
                    tree.back_detour(tree.getRoot());
                    System.out.print("\n\tСимметричный: ");
                    tree.symmetrical_detour(tree.getRoot());
                    break;
                case 8:
                    System.out.println("\tЗадание 2");
                    tree.walk(tree.getRoot(), 0);
                    tree.exe2(tree.getRoot());
                    break;
                case 9:
                    System.out.println("\tExit");
                    return;
            }
        }
    }
}
