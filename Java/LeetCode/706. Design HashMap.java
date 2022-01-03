class MyHashMap {
    int SIZE = 2693;
    node[] arr = new node[SIZE];

    public class node {
        public int key;
        public int val;
        public node next;

        public node(int key, int val) {
            this.key = key;
            this.val = val;
            this.next = null;
        }
    }

    public MyHashMap() {
        for (int i = 0; i < SIZE; i++) {
            arr[i] = new node(-1, -1);
        }
    }

    public void put(int key, int value) {
        int ind = hash(key);
        node head = arr[ind];
        while (head.next != null && head.next.key != key) {
            head = head.next;
        }
        if (head.next == null) {
            head.next = new node(key, value);
        } else {
            head.next.val = value;
        }
    }

    public int get(int key) {
        int ind = hash(key);
        node head = arr[ind];
        while (head != null && head.key != key) {
            head = head.next;
        }
        if (head == null)
            return -1;
        return head.val;
    }

    public void remove(int key) {
        int ind = hash(key);
        node head = arr[ind];
        while (head.next != null && head.next.key != key) {
            head = head.next;
        }
        if (head.next == null)
            return;
        else
            head.next = head.next.next;
        return;
    }

    public int hash(int in) {
        return in % SIZE;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such: MyHashMap obj
 * = new MyHashMap(); obj.put(key,value); int param_2 = obj.get(key);
 * obj.remove(key);
 */