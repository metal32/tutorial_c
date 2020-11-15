
#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>


template <typename T>
class BST {

	private:
    	class TreeNode{
    		public:
				T data;
				TreeNode* left;
				TreeNode* right;
				TreeNode(int val_) : data(val_), left(nullptr), right(nullptr) {}
		};
    	TreeNode* root;
    	TreeNode*& _find(const T& key, TreeNode*& cur) const;
    	const T& _remove(TreeNode*& node);

    	void _preOrder(TreeNode* cur);
    	void _inOrder(TreeNode* cur);
    	void _postOrder(TreeNode* cur);

	public:
		BST() : root(nullptr) {}

		~BST() {
			destroyWholeTree();
		}

		void createCompleteTree(const std::vector<T>& contents);

		BST(const std::vector<T>& contents) : BST() {
			createCompleteTree(contents);
		}

		void destroySubTree(TreeNode* subtreeRootPtr){

			if (subtreeRootPtr == nullptr) {
				return;
			}

			destroySubTree(subtreeRootPtr->left);
			destroySubTree(subtreeRootPtr->right);

			subtreeRootPtr->left = nullptr;
			subtreeRootPtr->right = nullptr;

			delete subtreeRootPtr;
		}

		void destroyWholeTree() {
	      	destroySubTree(root);
	      	root = nullptr;
    	}

    	void shout(TreeNode* cur) {
    		if(cur) {
    			std::cout<<cur->data;
    		}
    		std::cout << " ";
    	}

    	void preOrder();
    	void inOrder();
    	void postOrder();

    	const T& find(const T& key);
    	void insert(const T& key);
    	const T& remove(const T& key);

    	TreeNode* unsafe_getRootPtr() {
      		return root;
    	}

};

#include "binary_tree.hpp"