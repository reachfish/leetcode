
//先序遍历
void preorder(treenode* t){
	stack<treenode*> stk;
	if(t){
		stk.push(t);
	}

	while(!stk.empty()){
		treenode *p = stk.top();
		stk.pop();
		visit(p);
		if(p->right){
			stk.push(p->right);
		}
		if(p->left){
			stk.push(p->left);
		}
	}
}

//中序遍历
void inorder(treenode* t){
	stack<treenode*> stk;
	while(t){
		stk.push(t);
		t = t->left;
	}

	while(!stk.empty()){
		treenode* p = stk.top();
		stk.pop();

		visit(p);
		p = p->right;
		while(p){
			stk.push(p);
			p = p->left;
		}
	}
}

//后序遍历
void postorder(treenode* t){
	stack<treenode*> stk;
	treenode* last = nullptr;
	if(t){
		stk.push(t);
	}

	while(!stk.empty()){
		treenode* p = stk.top();
		if((!p->left && !p->right) || (last && (last==p->right || !p->right && last==p->left))){
			stk.pop();
			visit(p);
			last = p;
		}
		else{
			if(p->right){
				stk.push(p->right);
			}
			if(p->left){
				stk.push(p->left);
			}
		}
	}
}
