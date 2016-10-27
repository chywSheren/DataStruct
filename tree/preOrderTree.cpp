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

//ʹ��ջ���б��� 
//ǰ����� 
void preOrderUnRecur(Node head){
	if(!head) return;
	stack<Node> s;
	s.push(head);
	while(!s.empty()){
		head = s.top();
		s.pop();
		printf("%d ",head.val);
		if(head.right != NULL){
			s.push(head.right);
		}
		if(head.left != NULL){
			s.push(head.left);
		}
	}
	printf("\n");
}

//�������
void inOrderUnRecur(Node head){
	if( head != NULL ){
		stack<Node> s;
		while(!s.empty() || head!=NULL){
			if(head != NULL){
				s.push(head);
				head = head.left;
			}else{
				head = s.top();
				s.pop();
				printf("%d ",head.val);
				head = head.right;
			}
		}
	}
	printf("\n");
} 

//������ջ s1 s2 ʵ�ֺ������ 
void postOrderUnRecur1(Node head){
	if(head != NULL){
		stack<Node> s1;
		stack<Node> s2;
		s1.push(head);
		while(!s1.empty()){
			Node cur = s1.top();
			s1.pop();
			s2.push(cur);
			if(cur.left != NULL){
				s1.push(cur.left);
			}
			if(cur.right != NULL){
				s1.push(cur.right);
			}
		}
		while(!s2.empty()){
			printf("%d ",s2.top().val);
		}
	}
	printf("\n");
}

//��һ��ջʵ�ֺ������ 
void postOrderUnRecur2(Node h){
	if(h != NULL){
		stack<Node> s;
		s.push(h);
		Node c = NULL;
		while(!s.empty()){
			c = s.top();
			if(c.left!=NULL && h!=c.left && h!=c.right){
				s.push(c.left);
			}else if(c.right!=NULL && h!=c.right){
				s.push(c.right);
			}else{
				printf("%d ",s.pop().val);
				h = c;
			}
		}
	}
	printf("\n");
}
