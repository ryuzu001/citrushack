#include"BSTree.h"BSTree::BSTree(){
	root = 0;
}
BSTree::~BSTree(){
	//if(root!=0){
		
		//deleteroot->getLeft();
		//cout << "1" << endl;
		//deleteroot->getRight();
		//cout << "2" << endl;
		//deleteroot;
		//cout << "3" << endl;
		//root = 0;
		//cout << "destructor finished" << endl;
		/}
	
}
voidBSTree::preOrder(Node*n) const{
	if(n!=0){
		cout << n->getData() << "(" << n->getCount() << "),  ";
		preOrder(n->getLeft());
		preOrder(n->getRight());
	}
}
voidBSTree::inOrder(Node*n) const{
	if(n!=0){
		inOrder(n->getLeft());
		cout << n->getData() << "(" << n->getCount() << "),  ";
		inOrder(n->getRight());
	}
}
voidBSTree::postOrder(Node*n) const{
	if(n!=0){
		postOrder(n->getLeft());
		postOrder(n->getRight());
		cout << n->getData() << "(" << n->getCount() << "),  ";
	}
}
Node*BSTree::search(Node*x, conststring &s) const{
	if(x!=0){
		if(s == x->getData()){
			return x;
		}
		elseif(s<x->getData()){
			if(x->getLeft()!=0){
				return search(x->getLeft(), s);
			}
		}
		else{
			if(x->getRight()!=0){
				return search(x->getRight(), s);
			}
		}
	}
	return 0;
}
//TreeInsert(tree, node){
	
	//if(tree->rootis0)
	//tree->root = node
	//node->left = 0
	//node->right = 0
	//else
	//cur = tree->root
	//while(curisnot0)
	//if(node->key<cur->key)
	//if(cur->leftis0)
	//cur->left = node
	//cur = 0
	//else
	//cur = cur->left
	//else
	//if(cur->rightis0)
	//cur->right = node
	//cur = 0
	//else
	//cur = cur->right
	//node->left = 0
	//node->right = 0
	/}

voidBSTree::insert(conststring &s){
	Node*toInsert = newNode(s);
	//if(search(s)){
		
		//search(root, s)->incrementCount();
		/}
	
	if(root == 0){
		root = toInsert;
		root->incrementCount();
	}
	else{
		Node*current = root;
		while(current!=0){
			if(current->getData() == s){
				current->incrementCount();
				return ;
			}
			if(toInsert->getData()<current->getData()){
				//iftoInsert'sstringissmallerthantheroot / node'sstring
				if(current->getLeft() == 0){
					//ifcurrentnode'sleftisempty
					current->setLeft(toInsert);
					//setcurrent'slefttotoInsert
					current->getLeft()->incrementCount();
					//incrementstring'scount
					toInsert->setParent(current);
					//setparentpoint ertopreviousnode
					current = 0;
					//setcurrentto0
				}
				else{
					current = current->getLeft();
				}
			}
			else{
				if(current->getRight() == 0){
					//ifcurrentnode'srightisempty
					current->setRight(toInsert);
					//setcurrent'srighttotoInsert
					current->getRight()->incrementCount();
					//incrementstring'scount
					toInsert->setParent(current);
					current = 0;
					//setcurrentto0
				}
				else{
					current = current->getRight();
				}
			}
		}
	}
}
//TreeSearch(tree, key){
	
	//cur = tree->root
	//while(curisnot0)
	//if(key == cur->key)
	//return cur//Found
	//elseif(key<cur->key)
	//cur = cur->left
	//else
	//cur = cur->right
	//return 0//Notfound
	/}

boolBSTree::search(conststring &s) const{
	if(root == 0){
		return false;
	}
	//elseif(s<root->getData()){
		
		//if(root->getLeft()!=0){
			
			//if(search(root->getLeft(), s)!=0){
				
				//return true;
				/}
			
			/}
		
		/}
	
	//else{
		
		//if(root->getRight()!=0){
			
			//if(search(root->getRight(), s)!=0){
				
				//return true;
				/}
			
			/}
		
		/}
	
	else{
		if(search(root, s)!=0){
			return true;
		}
	}
	return false;
}
voidBSTree::inOrder() const{
	if(root == 0){
		cout << endl;
		return ;
	}
	inOrder(root);
	cout << endl;
}
voidBSTree::postOrder() const{
	if(root == 0){
		cout << endl;
		return ;
	}
	postOrder(root);
	cout << endl;
}
voidBSTree::preOrder() const{
	if(root == 0){
		cout << endl;
		return ;
	}
	preOrder(root);
	cout << endl;
}
stringBSTree::largest() const{
	if(root == 0){
		return "";
	}
	stringlargest = findLargest(root)->getData();
	return largest;
}
stringBSTree::smallest() const{
	if(root == 0){
		return "";
	}
	stringsmallest = findSmallest(root)->getData();
	return smallest;
}
int BSTree::height(conststring &s) const{
	if(!search(s)){
		return -1;
	}
	//if(s == root->getData()){
		
		//return 0;
		/}
	
	else{
		Node*toFind = search(root, s);
		return height(toFind);
	}
}
int BSTree::height(Node*x) const{
	if(x == 0){
		return 0;
	}
	if(x->getLeft() == 0 && x->getRight() == 0){
		return 0;
	}
	else{
		int heightLeft = 1 + height(x->getLeft());
		int heightRight = 1 + height(x->getRight());
		if(heightLeft> heightRight){
			return heightLeft;
		}
		else{
			return heightRight;
		}
	}
}
voidBSTree::remove(conststring &s){
	if(root == 0){
		return ;
	}
	if(!search(s)){
		return ;
	}
	else{
		Node*toRemove = search(root, s);
		if(toRemove->getCount() > 1){
			toRemove->decrementCount();
			return ;
		}
		else{
			remove(toRemove);
		}
	}
}
voidBSTree::remove(Node*x){
	//if(s> x->getData()){
		
		//remove(x->getRight(), s);
		/}
	
	//elseif(s<x->getData()){
		
		//remove(x->getLeft(), s);
		/}
	
	//else{
		
		//if(x->getRight()!=0){
			
			//Node*t = findSmallest(x->getRight());
			//x->setData(t->getData());
			//remove(x->getRight(), x->getData());
			/}
		
		//elseif(x->getLeft()!=0){
			
			//Node*t = findLargest(x->getLeft());
			//x->setData(t->getData());
			//remove(x->getLeft(), x->getData());
			/}
		
		//else{
			
			//deletex;
			//x = 0;
			/}
		
		/}
	
	if(x == root && x->getLeft() == 0 && x->getRight() == 0){
		deletex;
		root = 0;
	}
	elseif(x->getLeft() == 0 && x->getRight() == 0){
		if(x == x->getParent()->getLeft()){
			//Node*parentLeft = x->getParent()->getLeft();
			x->getParent()->setLeft(0);
			return ;
		}
		else{
			//Node*parentRight = x->getParent()->getRight();
			x->getParent()->setRight(0);
			return ;
		}
	}
	elseif(!x->getLeft()){
		stringsmallestRight = findSmallest(x->getRight())->getData();
		//findthesmalleststringontherightofx
		Node*smallestRightNode = search(x->getRight(), smallestRight);
		//findthesmallestnodeontherightofx
		x->setData(smallestRight);
		//setx'sdatatothatstring
		x->setCount(smallestRightNode->getCount());
		//setx'scounttothatnode's
		remove(smallestRightNode);
	}
	else{
		stringbiggestLeft = findLargest(x->getLeft())->getData();
		//findthelargeststringontheleftofx
		Node*biggestLeftNode = search(x->getLeft(), biggestLeft);
		//findthelargestnodeontheleftofx
		x->setData(biggestLeft);
		//setx'sdatatothatstring
		x->setCount(biggestLeftNode->getCount());
		//setx'scounttothatnode's
		remove(biggestLeftNode);
	}
}
Node*BSTree::findSmallest(Node*x) const{
	if(x == 0){
		return x;
	}
	while(x->getLeft()!=0){
		x = x->getLeft();
	}
	return x;
}
Node*BSTree::findLargest(Node*x) const{
	if(x == 0){
		return x;
	}
	while(x->getRight()!=0){
		x = x->getRight();
	}
	return x;
}