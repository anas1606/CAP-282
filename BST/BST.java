
public class BST {
	
	private class Node{
		private int value;
		private Node Left;
		private Node Right;
		
		public Node(int value) {
			this.value = value;
			Left=Right=null;
		}
	}//end of Node
	
	private Node Root;
	
	public void insert(int value) {
		
		var node = new Node(value);
		//if tree is empty
		if(Root == null) {
			Root = node;
			return;
		}
		else {
			var loc = Root;
			
			while(true) {
				if(value < loc.value) {
					//1st node on left side
					if(loc.Left == null) {
						loc.Left = node;
						break;
					}
					//else shift to next left
					loc = loc.Left;
				}
				else {
					//1st node on Right
					if(loc.Right == null) {
						loc.Right = node;
						break;
					}
					//else shift to next Right
					loc = loc.Right;
				}
			}//end of while
		}//else end
	}//end of insert()

	public boolean find(int value) {
		
		if(Root == null) {
			System.out.print("Empty Tree");
			return false;
		}
		
		var loc = Root;
		
		while(loc != null) {
			
			if(loc.value == value)
				return true;
			
			if(value < loc.value)
				loc = loc.Left;
			else
				loc = loc.Right;
		}//end of while
		return false;
	}//end of find()
	
	public void preOrder() {
		System.out.println("PreOrder:");
		preOrder(Root);
		System.out.println("");
	}
	private void preOrder(Node ptr) {
		if(ptr == null)
			return;
		System.out.print(ptr.value+" ");
		preOrder(ptr.Left);
		preOrder(ptr.Right);
	}
	
	public void postOrder() {
		System.out.println("PostOrder:");
		postOrder(Root);
		System.out.println("");
	}
	private void postOrder(Node ptr) {
		if(ptr == null)
			return;
		postOrder(ptr.Left);
		postOrder(ptr.Right);
		System.out.print(ptr.value+" ");
	}
	
	public void inOrder() {
		System.out.println("inOrder:");
		inOrder(Root);
		System.out.println("");
	}
	private void inOrder(Node ptr) {
		if(ptr == null)
			return;
		inOrder(ptr.Left);
		System.out.print(ptr.value+" ");
		inOrder(ptr.Right);
	}
	
	public int height() {
		return height(Root)-1;
	}
	private int height(Node ptr) {
		if(ptr==null)
			return 0;
		
		return 1+(Math.max(height(ptr.Left),height(ptr.Right))); 
	}
	
	public boolean compare(BST other) {
		if(other == null)
			return false;
		
		return compare(this.Root,other.Root);
	}
	
	private boolean compare(Node First,Node Second) {
		if(First == null && Second == null) {
			return true;
		}
		
		if(First != null && Second != null) {
			return First.value == Second.value
					&& compare(First.Left,Second.Left)
					&& compare(First.Right,Second.Right);
		}
		return false;
	}
	
	//testing...
	public void swap() {
		var temp = Root.Left;
		Root = Root.Left;
		Root.Left = temp;
	}
	public boolean isBST() {
		return isBST(Root,Integer.MIN_VALUE,Integer.MAX_VALUE);
	}
	
	private boolean isBST(Node test,int min,int max) {
		if(test==null)
			return true;
		
		if(test.value < min || test.value > max)
			return false;
		
		return isBST(test.Left,min,test.value-1)
				&& isBST(test.Right,test.value+1,max);
	}

	public void nodeKdistance(int dist) {
		nodeKdistance(Root,dist);
	}
	
	private void nodeKdistance(Node test,int dist) {
		if(test == null)
			return;
		
		if(dist == 0)
			System.out.print(test.value+" ");
		
		nodeKdistance(test.Left,dist-1);
		nodeKdistance(test.Right,dist-1);
		
	}
	
	public void levelorder() {
		
		if(Root==null)
			return;
		
		for(int i=0;i<=height();i++) {
			nodeKdistance(i);
		}
	}

}

