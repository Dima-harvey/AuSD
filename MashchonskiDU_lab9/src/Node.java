public class Node implements Comparable<Node> {
    Integer key;
    int degree;
    Node parent;
    Node child;
    Node sibling;

    public Node() {
        key = null;
    }

    Node(Integer key) {
        this.key = key;
    }

    public int compareTo(Node other) {
        return this.key.compareTo(other.key);
    }

    void print(int level) {
        Node curr = this;
        if (curr.parent==null)
            System.out.println();
        while (curr != null) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < level; i++) {
                if (i==0)
                    sb.append("    ");
                else sb.append(ConsoleColors.GREEN_BRIGHT+ " |   "+ConsoleColors.BLACK_BOLD);
            }
            if (curr.parent!=null&&curr.child!=null)
                sb.append(ConsoleColors.GREEN_BRIGHT + " -- "+ConsoleColors.BLACK_BOLD).append(curr.key.toString());
            else sb.append(ConsoleColors.GREEN_BRIGHT + " -| " + ConsoleColors.BLACK_BOLD)
                    .append(curr.key.toString()).append(ConsoleColors.RESET);
            System.out.println(sb.toString());
            if (curr.child != null) {
                curr.child.print(level + 1);
            }
            curr = curr.sibling;
        }
    }
}