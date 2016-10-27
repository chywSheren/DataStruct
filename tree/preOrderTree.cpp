class Node{
	public:
		int val;
		Node left;
		Node right;
		Node(int val){
			this.val = val;
		}
};

//ǰ����� 
void preOrderTree(Node head){
	if(head == NULL) return;
	printf("%d ",head.val);
	preOrderTree(head.left);
	preOrderTree(head.right);
}

//������� 
void inOrderTree(Node head){
	if(head == NULL) return;
	inOrderTree(head.left);
	printf("%d ",head.val);
	inOrderTree(head.right);
}

//������� 
void postOrderTree(Node head){
	if(head == NULL) return;
	postOrderTree(head.left);
	postOrderTree(head.right);
	printf("%d ",head.val);
}
