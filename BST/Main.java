public class Main {
	public static void main(String[] args) {
		BST bst = new BST();
		bst.insert(7);
		bst.insert(4);
		bst.insert(1);
		bst.insert(9);
		bst.insert(6);
		bst.insert(8);
		bst.insert(10);
		bst.insert(5);
		bst.insert(3);
		System.out.println(bst.find(10));

		bst.preOrder();
		bst.inOrder();
		bst.postOrder();
		
		System.out.println("Height is= "+bst.height());
		
		BST bst2 = new BST();
		bst2.insert(7);
		bst2.insert(4);
		bst2.insert(1);
		bst2.insert(9);
		bst2.insert(6);
		bst2.insert(8);
		bst2.insert(10);
		bst2.insert(5);
		
		System.out.println(bst2.compare(bst));
		//bst.swap();
		System.out.print(bst.isBST()+"\n");
		bst.nodeKdistance(3);
		System.out.println();
		bst.levelorder();
	}
}
