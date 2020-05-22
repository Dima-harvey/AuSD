import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        BinarySearchTree tree = new BinarySearchTree();
        Scanner input = new Scanner(System.in);
 
        System.out.println("\t ��� ����: ");
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
            System.out.println("1)������� ���� (����� ���������);");
            System.out.println("2)������� ���� (������ ���������);");
            System.out.println("3)����� ������� ����;");
            System.out.println("4)����� ������ ����;");
            System.out.println("5)����� ������� ����;");
            System.out.println("6)���������� �� ����;");
            System.out.println("7)������;");
            System.out.println("8)������� 2;");
            System.out.println("9)�����;");
            System.out.println("������� �������: ");
            
            comand = input.nextInt();
            switch (comand) {
                case 1:
                    System.out.println("\t2)������� ���� (����� ���������);");
                    int deleteL = 0;
                    System.out.print("\t������ ����: ");
                    deleteL = input.nextInt();
                    tree.deleteKey(deleteL, 2);
                    break;
                case 2:
                    System.out.println("\t3)������� ���� (������ ���������);");
                    int deleteR = 0;
                    System.out.print("\t������ ����: ");
                    deleteR = input.nextInt();
                    tree.deleteKey(deleteR, 1);
                    break;
                case 3:
                    System.out.println("\t����� ������� ����");
                    int depth = 0;
                    System.out.print("\t������ ����: ");
                    depth = input.nextInt();
                    System.out.print("\t ������� ����: " + tree.depth(tree.getRoot(), depth));
                    System.out.println();
                    break;
                case 4:
                    System.out.println("\t����� ������ ����;");
                    int height = 0;
                    System.out.print("\t������ ����: ");
                    height = input.nextInt();
                    System.out.print("\t ������ ����: " + tree.height(tree.search(tree.getRoot(), height)));
                    System.out.println();
                    break;
                case 5:
                    System.out.println("\t����� ������� ����;");
                    int level = 0;
                    System.out.print("\t������ ����: ");
                    level = input.nextInt();
                    System.out.print("\t ������� ����: " + tree.level(tree.getRoot(), level));
                    System.out.println();
                    break;
                case 6:
                    tree.walk(tree.getRoot(), 0);
                    break;
                case 7:
                    System.out.print("\n\t������: ");
                    tree.traight_detour(tree.getRoot());
                    System.out.print("\n\t��������: ");
                    tree.back_detour(tree.getRoot());
                    System.out.print("\n\t������������: ");
                    tree.symmetrical_detour(tree.getRoot());
                    break;
                case 8:
                    System.out.println("\t������� 2");
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
