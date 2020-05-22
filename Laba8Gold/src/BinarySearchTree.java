public class BinarySearchTree {
    public int count = 0;
    private Node root;
    public BinarySearchTree() {
        root = null;
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    public Node insertRec(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }

        if (key < root.key)
            root.left = insertRec(root.left, key);
        else if (key > root.key)
            root.right = insertRec(root.right, key);
        return root;
    }

    public int minValue(Node root) {
        int minv = root.key;
        while (root.left != null) {
            minv = root.left.key;
            root = root.left;
        }
        return minv;
    }

    public int maxValue(Node root){
        int maxv = root.key;
        while(root.right != null) {
            maxv = root.right.key;
            root = root.right;
        }
        return maxv;
    }

    public Node search(Node node, int key) {
        if (node == null || node.key == key)
            return node;
        if (node.key > key)
            return search(node.left, key);
        return search(node.right, key);
    }

    public int depth(Node node, int key) {
        if (node == null || node.key == key)
            return 0;
        if (node.key > key)
            return 1 + depth(node.left, key);
        return 1 + depth(node.right, key);
    }

    public int height(Node node) {
        if (node == null)
            return 0;
        return 1+ Math.max(height(node.right),height(node.left));
    }

    public int level(Node node, int key) {
        return depth(node, key) - height(search(node, key));
    }

    void deleteKey(int key, int metod) {
        if (metod == 1)
            root = deleteRight(root, key);
        else if (metod == 2)
            root = deleteLeft(root, key);
    }

    Node deleteRight(Node root, int key) {
        if (root == null)
            return root;
        if (key < root.key)
            root.left = deleteRight(root.left, key);
        else if (key > root.key)
            root.right = deleteRight(root.right, key);
        else {
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;
            root.key = minValue(root.right);
            root.right = deleteRight(root.right, root.key);
        }
        return root;
    }

    Node deleteLeft(Node root, int key) {
        if (root == null)  return root;
        if (key < root.key)
            root.left = deleteLeft(root.left, key);
        else if (key > root.key)
            root.right = deleteLeft(root.right, key);
        else {
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;
            root.key = maxValue(root.left);
            root.left = deleteLeft(root.left, root.key);
        }
        return root;
    }

    public void walk(Node node, int l) {
        if (node == null) {
            for (int i = 0; i<l; ++i) {
                System.out.print("\t");
            }
            System.out.println("null");
            return;
        }

        walk(node.right, l+1);
        for (int i = 0; i<l; ++i) {
            System.out.print("\t");
        }
        System.out.println(node.key + " ----|");
        walk(node.left, l+1);
    }

    public Node getRoot() {
        return root;
    }


    public Node getSuccessor(Node node) {
        if (node == null) {
            return null;
        }
        Node temp = node.right;

        while(temp != null) {
            temp = temp.left;
        }

        return temp;
    }

    int i=0;
    public int summ(Node node) {
        if (node == null)
            return 0;
        int s=node.key;
        i++;
        s+=summ(node.left);
        return s;
    }
    public int summ1(Node node) {
        if (node == null)
            return 0;
        int s=node.key;
        i++;
        s+=summ(node.left);
        
        return s;
    }

    void symmetrical_detour(Node n){
        if (n == null){
            return;
        }
        else{
            symmetrical_detour(n.left);
            System.out.print(n.key + "  ");
            symmetrical_detour(n.right);
        }
    }

    void back_detour(Node n){
        if (n == null) {
            return;
        }
        else {
            back_detour(n.left);
            back_detour(n.right);
            System.out.print(n.key + "  ");
        }
    }

    void traight_detour(Node n){
        if (n == null){
            return;
        }
        else{
            System.out.print(n.key + "  ");
            traight_detour(n.left);
            traight_detour(n.right);
        }
    }

    void exe2(Node node) {
    	i=0;
        int sum = summ(node);
        int sum1 = summ(node.right);
        int value  =(int) Math.round((double)(sum+sum1)/i);
        
        System.out.println("\tСреднее значение из максимальной длины, у которого сумма ключей конечных вершин минимальна : " + value);
       
        if(i%2==0) {
        	System.out.println("Мы не можем удалить вершину, так как количество вершин в пути чётное");
        }else {
        	System.out.println("Удаляем "+value);
        	deleteKey(value, 1);
        }

        System.out.print("\tПрямой обход: ");
        traight_detour(node);
        System.out.println("");
        
    }
}
