public class BinHeap {
    private Node head;

    BinHeap() {
        head = null;
    }

    BinHeap(Node head) {
        this.head = head;
    }

    void clear() {
        head = null;
    }

    void insert(Integer key) {
        Node node = new Node(key);
        BinHeap tempHeap = new BinHeap(node);
        head = union(tempHeap);
    }

    Integer Min() {  //минимальный элемент удаляем
        if (head == null)
            return null;
        Node min = head;
        Node minPrev = null;
        Node next = min.sibling;
        Node nextPrev = min;

        while (next != null) {
            if (next.compareTo(min) < 0) {
                min = next;
                minPrev = nextPrev;
            }
            nextPrev = next;
            next = next.sibling;
        }
        removeTreeRoot(min, minPrev);
        return min.key;
    }

    private void removeTreeRoot(Node root, Node prev) {
        if (root == head) {
            head = root.sibling;
        } else {
            prev.sibling = root.sibling;
        }
        Node newHead = null;
        Node child = root.child;
        while (child != null) {
            Node next = child.sibling;
            child.sibling = newHead;
            child.parent = null;
            newHead = child;
            child = next;
        }
        BinHeap newHeap = new BinHeap(newHead);
        head = union(newHeap);
    }

    private void linkTree(Node minNodeTree, Node other) {
        other.parent = minNodeTree;
        other.sibling = minNodeTree.child;
        minNodeTree.child = other;
        minNodeTree.degree++;
    }

    private Node union(BinHeap heap) {
        Node newHead = merge(this, heap);
        head = null;
        heap.head = null;

        if (newHead == null) {
            return null;
        }
        Node prev = null;
        Node curr = newHead;
        Node next = newHead.sibling;

        while (next != null) {
            if (curr.degree != next.degree || (next.sibling != null &&
                    next.sibling.degree == curr.degree)) {
                prev = curr;
                curr = next;
            } else {
                if (curr.compareTo(next) < 0) {
                    curr.sibling = next.sibling;
                    linkTree(curr, next);
                } else {
                    if (prev == null) {
                        newHead = next;
                    } else {
                        prev.sibling = next;
                    }

                    linkTree(next, curr);
                    curr = next;
                }
            }
            next = curr.sibling;
        }
        return newHead;
    }


    private static Node merge (BinHeap heap1, BinHeap heap2) {

        if (heap1.head == null) {
            return heap2.head;
        } else if (heap2.head == null) {
            return heap1.head;
        } else {
            Node head;
            //корень второго дерева
            Node heap1Next = heap1.head;
            //корень добавляемого дерева
            Node heap2Next = heap2.head;
            if (heap1.head.degree <= heap2.head.degree) {
                head = heap1.head;
                heap1Next = heap1Next.sibling;
            } else {
                head = heap2.head;
                heap2Next = heap2Next.sibling;
            }

            Node tail = head;

            while (heap1Next != null && heap2Next != null) {
                if (heap1Next.degree <= heap2Next.degree) {
                    tail.sibling = heap1Next;
                    heap1Next = heap1Next.sibling;
                } else {
                    tail.sibling = heap2Next;
                    heap2Next = heap2Next.sibling;
                }

                tail = tail.sibling;
            }

            if (heap1Next != null) {
                tail.sibling = heap1Next;
            } else {
                tail.sibling = heap2Next;
            }

            return head;
        }
    }

    void print() {
        if (head != null) {
            head.print(0);
        }
    }
}