import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BinHeap heap = new BinHeap();
        int number;
        do {
            System.out.println("\nВыберете операцию:");
            System.out.println("1. Добавить ");
            System.out.println("2. Удалить ");
            System.out.println("3. Очистить ");
            System.out.print(" --> ");
            int a = scan.nextInt();
            switch (a) {
                case 1:
                    System.out.println("Введите целое число для добавления");
                    heap.insert(scan.nextInt());
                    break;
                case 2:
                    heap.Min();
                    break;
                case 3:
                    heap.clear();
                    break;
                default:
                    break;
            }
            heap.print();
            System.out.println("\nЕсли хотите продолжить нажмите 4");
            number=scan.nextInt();
        } while (number == 4 );
    }
}

