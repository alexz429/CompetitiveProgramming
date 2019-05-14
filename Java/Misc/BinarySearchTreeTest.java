package Misc;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BinarySearchTreeTest {
	static class node {
		int value;
		int height;
		int amount;
		node left;
		node right;
		int l;
		int r;

		public node(int value, int height, node left, node right) {
			super();
			this.value = value;
			this.height = height;
			this.left = left;
			this.right = right;
		}

		public node(int value, int height) {
			this.value = value;
			this.height = height;

		}

		public node(int value) {
			this.value = value;
			height = 1;
			l = 0;
			r = 0;
			amount = 1;
		}

	}

	static class bbst {
		node head;
		boolean found;

		public String toString() {
			return stringify(head);
		}

		private String stringify(node root) {
			String result = "";
			if (root == null)
				return "";
			result += stringify(root.left);
			result += root.value + " ";
			result += stringify(root.right);

			return result;
		}

		public node rotateRight(node at) {
			node temp = at.left;
			at.left = at.left.right;
			temp.right = at;
			at.l = getNum(at.left);
			temp.r = getNum(at);
			at.height = Math.max(getHeight(at.left), getHeight(at.right)) + 1;
			temp.height = Math.max(getHeight(temp.left), getHeight(at.right)) + 1;
			return temp;
		}

		public node rotateLeft(node at) {
			node temp = at.right;
			at.right = at.right.left;
			temp.left = at;
			at.r = getNum(at.right);
			temp.l = getNum(at);

			at.height = Math.max(getHeight(at.left), getHeight(at.right)) + 1;
			temp.height = Math.max(getHeight(temp.left), getHeight(at.right)) + 1;
			return temp;
		}

		public void addTop(int key) {

			head = pass(head, key);

		}

		public void remove(int key) {
			found = false;
			head = kill(head, key);
		}

		static int getNum(node n) {
			return n == null ? 0 : (n.l + n.r + n.amount);
		}

		static int getHeight(node n) {
			return n == null ? 0 : n.height;
		}

		public node kill(node at, int key) {
			if (at == null) {
				return null;
			}
			if (key < at.value) {

				at.left = kill(at.left, key);
				if (found) {
					at.l--;
				}
			} else if (key == at.value) {
				found = true;
				at.amount--;
				System.out.println("???");
				if (at.amount == 0) {
					if (at.left == null)
						return at.right;
					else if (at.right == null)
						return at.left;

					// node with two children: Get the inorder successor (smallest
					// in the right subtree)
					at.value = recurseLeft(at.right);

					// Delete the inorder successor
					at.right = kill(at.right, at.value);

				}
			} else {

				at.right = kill(at.right, key);
				if (found) {
					at.r--;
				}
			}
			int leftHeight = getHeight(at.left);
			int rightHeight = getHeight(at.right);
			at.height = 1 + Math.max(leftHeight, rightHeight);
			int balance = leftHeight - rightHeight;
			System.out.println(balance + " a " + at.value);
			if (Math.abs(balance) < 2) {
				return at;
			}
			if (balance > 1 && key < at.left.value) {
				return rotateLeft(at);
			} else if (balance < -1 && key > at.right.value) {
				return rotateRight(at);
			} else if (balance > 1 && key > at.left.value) {
				at.left = rotateRight(at.left);
				return rotateLeft(at);
			} else {
				at.right = rotateLeft(at.right);
				return rotateRight(at);
			}

		}

		public int recurseLeft(node at) {
			int out = at.value;
			while (at.left != null) {
				at = at.left;
				out = at.value;
			}
			return out;
		}

		public node pass(node at, int key) {

			if (at == null) {
				return new node(key);
			}
//			System.out.println(at.value);
			if (key < at.value) {
//				System.out.println(at.value+" l "+(at.r+at.amount));
				at.l++;

				at.left = pass(at.left, key);
			} else if (key == at.value) {
				at.amount++;

				return at;
			} else {
//				System.out.println(at.value+" r");
				at.r++;
				at.right = pass(at.right, key);
			}
			int leftHeight = getHeight(at.left);
			int rightHeight = getHeight(at.right);
			at.height = 1 + Math.max(leftHeight, rightHeight);
			int balance = leftHeight - rightHeight;
//			System.out.println(balance+" a "+at.value);
			if (Math.abs(balance) < 2) {
				return at;
			}
			if (balance > 1 && key < at.left.value) {
				return rotateRight(at);
			} else if (balance < -1 && key > at.right.value) {
				return rotateLeft(at);
			} else if (balance > 1 && key > at.left.value) {
				at.left = rotateLeft(at.left);
				return rotateRight(at);
			} else {
				at.right = rotateRight(at.right);
				return rotateLeft(at);
			}

		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int max = Integer.parseInt(br.readLine());
		bbst test = new bbst();
		for (int count = 0; count < max; count++) {
			String next[] = br.readLine().split(" ");
			switch (next[0]) {
			case "put":
				test.addTop(Integer.parseInt(next[1]));
				break;
			case "take":
				test.remove(Integer.parseInt(next[1]));
				break;
			}
			System.out.println(test);
		}
	}
}
