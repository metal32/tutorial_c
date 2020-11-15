
#pragma once

#include <iostream>
#include <vector>
#include "binary_tree.h"

template <typename T>
void BST<T>::createCompleteTree(const std::vector<T>& contents) {
	destroyWholeTree();

	if (contents.empty()) return;

	root = new TreeNode(contents[0]);

}

template<typename T>
const T& BST<T>::find(const T& key) {
	TreeNode*& node = _find(key, root);
	if (node == NULL) { throw std::runtime_error("error: key not found"); }

	return node->data;
}

template<typename T>
typename BST<T>::TreeNode*& BST<T>::_find(const T& key, TreeNode*& cur) const {
	if (cur == nullptr) { return cur; }

	if (cur->data == key) return cur;
	else if (cur->data > key) return _find(key, cur->left);
	else if (cur->data < key) return _find(key, cur->right);
}

template<typename T>
void BST<T>::insert(const T& key) {
	TreeNode*& node = _find(key, root);
	if (node) { throw std::runtime_error("error: insert() used on an existing key"); }
	node = new TreeNode(key);
}

template <typename T>
const T& BST<T>::remove(const T& key) {
	TreeNode*& node = _find(key, root);
  	if (!node) { throw std::runtime_error("error: remove() used on non-existent key"); }
  	return _remove(node);
}

template <typename T>
const T& BST<T>::_remove(TreeNode*& node) {
	if (!node) { throw std::runtime_error("error: _remove() used on non-existent key"); }
	// Zero child remove:
  	if (node->left == nullptr && node->right == nullptr) {
	    // Peek at the data referred to by the node so we can return a reference
	    // to the data later, after the tree node itself is already gone.
	    const T& data = node->data;
	    // The node is a leaf, so it has no descendants to worry about.
	    // We can just delete it. (The slides originally showed "delete(node)".
	    // Note that the syntax for "delete" is like an operator, not a function,
	    // so it's not necessary to put the () when you use it.)
	    delete node;
	    // It's very important to set "node" to nullptr here. The parent is still
	    // holding this same pointer, so we must mark that the child is gone.
	    node = nullptr;
	    return data;
  	} else if (node->left != nullptr && node->right == nullptr) {
	    // Similar to the previous case, except that we need to remap the "node"
	    // pointer to point to the node's child, so that the parent of the node
	    // being deleted will retain its connection to the rest of the tree
	    // below this point.
	    const T& data = node->data;
	    TreeNode* temp = node;
	    node = node->left;
	    delete temp;
	    return data;
  } else if (node->left == nullptr && node->right != nullptr) {
	    // Similar to the previous case, except that we need to remap the "node"
	    // pointer to point to the node's child, so that the parent of the node
	    // being deleted will retain its connection to the rest of the tree
	    // below this point.
	    const T& data = node->data;
	    TreeNode* temp = node;
	    node = node->right;
	    delete temp;
	    return data;
  } else {

  }
}

template<typename T>
void BST<T>::preOrder() {
	_preOrder(root);
}

template<typename T>
void BST<T>::inOrder() {
	_inOrder(root);
}

template<typename T>
void BST<T>::postOrder() {
	_postOrder(root);
}

template<typename T>
void BST<T>::_preOrder(TreeNode* cur) {
  // Only do anything if the pointer is not nullptr.
  if (cur) {
    // We'll act upon this node first, by "shouting it out" now. This is
    // our way of officially visiting this node at this time, as part of the
    // intended "pre-order" traversal.
    shout(cur);
    // Then, recurse on the left.
    _preOrder(cur->left);
    // Lastly, recurse on the right.
    _preOrder(cur->right);
  }
}

template<typename T>
void BST<T>::_inOrder(TreeNode* cur) {
  // Only do anything if the pointer is not nullptr.
  if (cur) {
    // First, recurse on the left.
    _inOrder(cur->left);
    // Now act upon this node, because we doing an "in-order" traversal.
    shout(cur);
    // Lastly, recurse on the right.
    _inOrder(cur->right);
  }
}


template<typename T>
void BST<T>::_postOrder(TreeNode* cur) {
  // Only do anything if the pointer is not nullptr.
  if (cur) {
    // First, recurse on the left.
    _postOrder(cur->left);
    // Next, recurse on the right.
    _postOrder(cur->right);
    // Now act upon this node last, because we doing a "post-order" traversal.
    shout(cur);
  }
}